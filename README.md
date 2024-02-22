# Cookiecutter Zephyr OS Driver

[Cookiecutter](https://github.com/audreyr/cookiecutter) template for an Zephyr OS driver.

## Requirements

Install Cookiecutter from the command line with [pipx](https://pypa.github.io/pipx/):

```shell
pipx install cookiecutter
```

## Usage

Generate a new Zephyr OS driver from template:

```shell
cookiecutter gh:catie-aq/cookiecutter_zephyr-driver
```

## Template variables

### Sensor
- `manufacturer`: Name of the manufacturer
- `short_manufacturer`: "Short name of the manufacturer
- `reference`: "Reference of the component
- `description`: "Description of the component
- `project_slug`: "Slug of the project
- `copyright_holder`: "Copyright holder
- `copyright_year`: "Copyright year
- `create_repository`: "Initialize a git repository
