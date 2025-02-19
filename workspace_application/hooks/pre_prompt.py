import re
import requests

from cookiecutter.prompt import prompt_for_config
from cookiecutter.generate import generate_context

# Define repo details
WEST_PATH = "{{cookiecutter.project_slug}}/west.yml"
GITHUB_OWNER = "catie-aq"
REPO_NAME = "zephyr_6tron-manifest"
FILE_PATH = "west.yml"
COOKIECUTTER_NAME = "cookiecutter_zephyr"
COOKIECUTTER_PATH = "workspace_application/cookiecutter.json"

TERMINATOR = "\x1b[0m"
WARNING = "\x1b[1;33m[WARNING]: "
SUCCESS = "\x1b[1;32m[SUCCESS]: "

def get_west_content():
    """Reads the Git file URL from a local file."""
    with open(WEST_PATH, "r") as f:
        return f.read().strip()

def get_manifest_version():
    pattern = r"revision:\s*([\w.-]+\+\w+)"

    content = get_west_content()
    match = re.search(pattern, content)

    return match.group(1)

def fetch_file(version):
    """Fetches a file from a specific GitHub release."""
    url = f"https://raw.github.com/{GITHUB_OWNER}/{REPO_NAME}/{version}/{FILE_PATH}"

    response = requests.get(url)
    if response.status_code != 200:
        raise Exception(f"Failed to fetch file: {response.status_code}")

    return response.text.strip().split("\n")

def parse_file(lines):
    """Parses a file and returns a list of zest_core names."""
    pattern = r"- name:\s+(zest_core_\S+)"
    zest_core_list = [match.group(1) for line in lines if (match := re.search(pattern, line))]

    return zest_core_list

def add_nrf(core_list):
    """Add nrf5340 cores to the list."""
    updated_list = []
    for core in core_list:
        if "nrf5340" in core:
            updated_list.extend([
                f"{core}/nrf5340/cpunet",
                f"{core}/nrf5340/cpuapp",
                f"{core}/nrf5340/cpuapp/ns"
            ])
        else:
            updated_list.append(core)
    
    return updated_list

def add_none(core_list):
    """Add NONE at the start of the list."""
    updated_list = ["NONE"]
    updated_list.extend(core_list)

    return updated_list

def modify_defaults():
    """Fetching west.yml."""
    version = get_manifest_version()

    """Fetching file from release {version}."""
    options = fetch_file(version)

    """Generating zest_core_list."""
    zest_core_list = parse_file(options)
    nrf_list = add_nrf(zest_core_list)
    complete_list = add_none(nrf_list)

    """Generating and Updating cookiecutter context."""
    context = generate_context()
    context['cookiecutter']['board'] = complete_list
    new_context = prompt_for_config(context)

    return new_context

if __name__ == "__main__":
    modify_defaults()
