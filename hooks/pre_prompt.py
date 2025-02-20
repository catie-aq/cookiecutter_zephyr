import os, re
import json
import urllib.request

from cookiecutter.config import get_user_config
from cookiecutter.generate import generate_context

MANIFESTS_PATH = "resources/manifests/"
WEST_PATH = "workspace_application/{{cookiecutter.project_slug}}/west.yml"
GITHUB_OWNER = "catie-aq"
REPO_NAME = "zephyr_6tron-manifest"
FILE_PATH = "west.yml"
COOKIECUTTER_PATH = "workspace_application/cookiecutter.json"

def get_west_content():
    """Reads the Git file URL from a local file."""
    with open(WEST_PATH, "r") as f:
        return f.read().strip()

def get_manifest_version():
    pattern = r"revision:\s*([\w.-]+\+\w+)"

    content = get_west_content()
    match = re.search(pattern, content)

    return match.group(1)

def update_resources(version):
    """Checking file {version} in resources"""
    file_name = f"west-{version}.yml"

    for file in os.listdir(get_user_config()["cookiecutters_dir"] + "cookiecutter_zephyr/" + MANIFESTS_PATH):
        if (file == file_name):
            return

    """Fetches a file from a specific GitHub release."""
    url = f"https://raw.github.com/{GITHUB_OWNER}/{REPO_NAME}/{version}/{FILE_PATH}"
    try:
        with urllib.request.urlopen(url) as response:
            content = response.read().decode('utf-8')
            # Write the content to a 'west.yml' file
            with open(get_user_config()['cookiecutters_dir'] + 'cookiecutter_zephyr/' + MANIFESTS_PATH + "/" + file_name, 'w') as file:
                file.write(content)
    except Exception:
        return

def fetch_file(version):
    """Fetches a file"""
    file_path = get_user_config()["cookiecutters_dir"] + "cookiecutter_zephyr/" + MANIFESTS_PATH + f"west-{version}.yml"
    default_path = get_user_config()["cookiecutters_dir"] + "cookiecutter_zephyr/" + MANIFESTS_PATH + f"default.yml"

    if os.path.exists(file_path):
        with open(file_path, 'r') as file:
            return file.readlines()
    else:
        with open(default_path, 'r') as file:
            return file.readlines()

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

def modify_workspace_context(version):
    """Fetching file from release {version}."""
    options = fetch_file(version)

    """Generating zest_core_list."""
    zest_core_list = parse_file(options)
    nrf_list = add_nrf(zest_core_list)

    """Generating and Updating cookiecutter context."""
    context_path = get_user_config()["cookiecutters_dir"] + "cookiecutter_zephyr/" + COOKIECUTTER_PATH
    context = generate_context(context_path)
    context['cookiecutter']['board'].extend(nrf_list)
    with open(COOKIECUTTER_PATH, 'w') as file:
        json.dump(context["cookiecutter"], file, indent=4)

def main():
    """Fetching west.yml."""
    version = get_manifest_version()

    """Fetching file from release {version}."""
    update_resources(version)

    """Update workspace parameter according to west-{version}.yml"""
    modify_workspace_context(version)

if __name__ == "__main__":
    main()
