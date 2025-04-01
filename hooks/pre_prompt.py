import os, re
import json
import urllib.request
from pathlib import Path

WEST_PATH = "workspace_application/{{cookiecutter.project_slug}}/west.yml"
GITHUB_OWNER = "catie-aq"
REPO_NAME = "zephyr_6tron-manifest"
FILE_PATH = "west.yml"
CACHE_DIRECTORY = os.path.expanduser("~/.cache/cookiecutter/6tron_zephyr")
MANIFESTS_DIRECTORY = "/manifests"
CORES_DIRECTORY = "/cores"

def get_west_content():
    """Reads the Git file from a local file."""
    with open(WEST_PATH, "r") as f:
        return f.read().strip()

def get_manifest_version():
    pattern = r"revision:\s*([\w.-]+\+\w+)"

    content = get_west_content()
    match = re.search(pattern, content)

    return match.group(1)

def update_manifest(version):
    """Checking file {version} in resources"""
    file_name = f"west-{version}.yml"

    for file in os.listdir(CACHE_DIRECTORY + MANIFESTS_DIRECTORY):
        if (file == file_name):
            return True

    print("Updating manifest file")
    """Fetches a file from a specific GitHub release."""
    url = f"https://raw.github.com/{GITHUB_OWNER}/{REPO_NAME}/{version}/{FILE_PATH}"
    try:
        with urllib.request.urlopen(url) as response:
            content = response.read().decode('utf-8')
            # Write the content to a 'west.yml' file
            with open(CACHE_DIRECTORY + MANIFESTS_DIRECTORY + "/" + file_name, 'w') as file:
                file.write(content)
            return True
    except Exception:
        return False

def update_core(version):
    file_name = f"cores-{version}.yml"
    for file in os.listdir(CACHE_DIRECTORY + CORES_DIRECTORY):
        if (file == file_name):
            return True

    print("Updating core file")
    file_name = f"west-{version}.yml"
    zest_core_pattern = r'name:\s*(zest_core_[\w\d-]+).*?repo-path:\s*([a-zA-Z0-9_-]*zest-core-[\w\d-]+).*?revision:\s*([a-f0-9]{40})'
    content = []
    with open(CACHE_DIRECTORY + MANIFESTS_DIRECTORY + "/" + file_name, 'r') as file:
        content = file.read()

    core_list = {}
    matches = re.findall(zest_core_pattern, content, re.DOTALL)
    for name, repo, commit in matches:
        directory = f"boards/catie/{name}"

        """Fetches a file from a specific GitHub release."""
        api_url = f"https://api.github.com/repos/{GITHUB_OWNER}/{repo}/contents/{directory}?ref={commit}"
        try:
            # Fetch the directory contents
            with urllib.request.urlopen(api_url) as response:
                content = response.read().decode('utf-8')
                files = json.loads(content)
                # Filter files that end with .dts
                cores = []
                for file in files:
                    if file['name'].endswith('.dts'):
                        core = file['name'].split(".")[0]
                        if core.startswith(name):
                            result = name + core[len(name):].replace("_", "/")
                        cores.append(result)
                core_list[name] = cores
        except Exception as e:
            print(f"Error fetching file list: {e}")

    if (core_list != []):
        with open(CACHE_DIRECTORY + CORES_DIRECTORY + f"/cores-{version}.yml", 'w') as core_file:
            # Convert the dictionary to a YAML-like format
            yaml_content = ""
            for key, values in core_list.items():
                yaml_content += f"{key}:\n"
                for value in values:
                    yaml_content += f"  - {value}\n"
            core_file.write(yaml_content)

def update_cache(version):
    """Update west-{version}.yaml in cache"""
    valid = update_manifest(version)

    """Update dual-core file in cache"""
    if (valid):
        update_core(version)


def main():
    """Creating cache directory."""
    Path(CACHE_DIRECTORY + MANIFESTS_DIRECTORY).mkdir(parents=True, exist_ok=True)
    Path(CACHE_DIRECTORY + CORES_DIRECTORY).mkdir(parents=True, exist_ok=True)

    """Fetching west.yml."""
    version = get_manifest_version()

    """Fetching file from release {version}."""
    update_cache(version)

if __name__ == "__main__":
    main()
