import os, re
import json

from cookiecutter.config import get_user_config
from cookiecutter.generate import generate_context

WEST_PATH = "{{cookiecutter.project_slug}}/west.yml"
CACHE_DIRECTORY = os.path.expanduser("~/.cache/cookiecutter/6tron_zephyr")
MANIFESTS_DIRECTORY = "/manifests"
CORES_DIRECTORY = "/cores"
COOKIECUTTER_NAME = "cookiecutter_zephyr/"
COOKIECUTTER_TEMPLATE = "workspace_application/"
COOKIECUTTER_PATH = "cookiecutter.json"

def get_west_content():
    """Reads the Git file URL from a local file."""
    with open(WEST_PATH, "r") as f:
        return f.read().strip()

def get_manifest_version():
    pattern = r"revision:\s*([\w.-]+\+\w+)"

    content = get_west_content()
    match = re.search(pattern, content)

    return match.group(1)

def get_release(filename):
    return int(filename.split('.')[-2].split('+')[1])

def fetch_file(version, directory, file_name):
    """Fetches a file"""
    pattern = rf"{re.escape(file_name.split('-')[0])}-{re.escape(version.split('+')[0])}"
    
    try:
        file = open(directory + "/" + file_name, 'r')
        print("File found in cache: " + file_name)
        return file.readlines()
    except FileNotFoundError:
        print(f"No up-to-date file: {file_name}")
        file_list = []
        for file in os.listdir(directory):
            if re.search(pattern, file):
                file_list.append(file)
        file_list.sort(key=get_release, reverse=True)
        release = get_release(file_name)
        for file in file_list:
            if (get_release(file) < release):
                content = open(directory + "/" + file, 'r')
                print(f"Using cached file: {file_name.split('-')[0]}-{version.split('+')[0]}+{get_release(file)}.yml")
                return content.readlines()

    print("Prompt information might be outdated")
    return []

def parse_file(lines):
    """Parses a file and returns a list of zest_core names."""
    pattern = r"- name:\s+(zest_core_\S+)"
    zest_core_list = [match.group(1) for line in lines if (match := re.search(pattern, line))]

    return zest_core_list

def parse_to_dict(lines):
    result = {}
    current_key = None
    for line in lines:
        line = line.strip()
        if line.endswith(":") and not line.startswith("-"):
            # Extract the key (remove the colon at the end)
            current_key = line[:-1]
            result[current_key] = []
        elif line.startswith("-") and current_key:
            # Extract the value (remove the dash and leading spaces)
            value = line[1:].strip()
            result[current_key].append(value)

    return result

def get_base_list(version):
    """Returns a list of zest_core names."""
    option = fetch_file(version, CACHE_DIRECTORY + MANIFESTS_DIRECTORY, f"west-{version}.yml")

    if (option != []):
        return parse_file(option)
    return option

def get_complete_list(version, zest_core_list):
    """Returns a list of zest_core names."""
    try:
        option = fetch_file(version, CACHE_DIRECTORY + CORES_DIRECTORY, f"cores-{version}.yml")       
        if (option != []):
            cores = parse_to_dict(option)
        else:
            return zest_core_list
    except FileNotFoundError:
        return zest_core_list

    result = []
    for board in zest_core_list:
        result.extend(cores[board])

    return result

def modify_workspace_context(version):
    """Generating zest_core_list."""
    zest_core_list = get_base_list(version)
    if (zest_core_list != []):
        zest_core_list = get_complete_list(version, zest_core_list)

    """Generating and Updating cookiecutter context."""
    context_path = get_user_config()["cookiecutters_dir"] + COOKIECUTTER_NAME + COOKIECUTTER_TEMPLATE + COOKIECUTTER_PATH
    context = generate_context(context_path)
    context['cookiecutter']['board'].extend(zest_core_list)
    with open(COOKIECUTTER_PATH, 'w') as file:
        json.dump(context["cookiecutter"], file, indent=4)

def main():
    """Fetching west.yml."""
    version = get_manifest_version()

    """Update workspace parameter according to west-{version}.yml"""
    modify_workspace_context(version)

if __name__ == "__main__":
    main()
