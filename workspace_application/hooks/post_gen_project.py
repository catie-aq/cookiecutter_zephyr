import os
import shutil
import subprocess

TERMINATOR = "\x1b[0m"
WARNING = "\x1b[1;33m[WARNING]: "
SUCCESS = "\x1b[1;32m[SUCCESS]: "


def git_init():
    return subprocess.check_call(["git", "init"], stdout=subprocess.DEVNULL)


def git_add_all():
    return subprocess.check_call(["git", "add", "."], stdout=subprocess.DEVNULL)


def git_commit():
    return subprocess.run(
        ["git", "commit", "-m", "Initial commit"], stdout=subprocess.DEVNULL
    )


def create_repository():
    git_init()
    git_add_all()
    git_commit()


def cleanup_secure():
    secure_files = [
        'app/include/'
    ]
    project_dir = os.path.realpath(os.path.curdir)

    for file in secure_files:
        path = os.path.join(project_dir, file)
        if os.path.isdir(path):
            shutil.rmtree(path)
        elif os.path.isfile(path):
            os.remove(path)


def main():
    if {{cookiecutter.create_repository}}:
        create_repository()

    if not {{cookiecutter.secure_app}}:
        cleanup_secure()

    print(
        SUCCESS + "Project generated in `{{ cookiecutter.project_slug }}`" + TERMINATOR
    )


if __name__ == "__main__":
    main()
