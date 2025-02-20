# Cookiecutter Zephyr OS Driver

[Cookiecutter](https://github.com/audreyr/cookiecutter) template for a Zephyr OS driver.

## Requirements

Install Cookiecutter from the command line with [pipx](https://pypa.github.io/pipx/):

```shell
pipx install cookiecutter
```

## Usage

Generate a new Zephyr OS driver from template:

```shell
cookiecutter gh:catie-aq/cookiecutter_zephyr
```

Answer the prompts to fill in the template variables. 🚀

## Template variables

### Sensor
Generate a Zephyr OS sensor driver

- `vendor`: Manufacturer's name
- `vendor_prefix`: Manufacturer's short name, as in vendor-prefixes.txt
- `reference`: Reference of the component
- `sensor_type`: Type of sensor (e.g. temperature, humidity, etc.)
- `project_slug`: Project slug
- `copyright_holder`: Copyright holder
- `copyright_year`: Copyright year
- `create_repository`: Initialize a Git repository?

### Shield
Generate a Zephyr OS shield driver

- `board_name`: Name of the board
- `project_slug`: Slug of the project
- `copyright_holder`: Copyright holder
- `copyright_year`: Copyright year
- `create_repository`: Initialize a git repository

### Core
Generate a Zephyr OS core driver

- `board_vendor`: Name of the vendor
- `vendor_description`: Vendor description
- `board_soc_arch`: Type of SoC architecture, e.g.
- `board_soc`: Name of the board SoC, for naming purpose, e.g.
- `zephyr_board_soc`: Name of the SoC defined in Zephyr, for kconfig setup (from zephyr/soc/soc.yml) e.g.
- `jlink_device`: Name of the jlink device to debug/flash the SoC
- `board_name`: Name of the Zest Core board
- `board_default_version`: Last valid version of the board (default revision)
- `zest_full_size`: Is the zest core a full size board with 2 different sixtron bus?
- `project_slug`: Slug of the project (or name of the repo)
- `copyright_holder`: Copyright holder
- `copyright_year`: Copyright year
- `create_repository`: Initialize a git repository?

### Workspace application
Generate a Zephyr OS workspace application

- `application`: Application name
- `description`: Description of the application
- `project_slug`: Slug of the project
- `board`: Target for the project
- `copyright_holder`: Copyright holder
- `copyright_year`: Copyright year
- `create_repository`: Initialize a git repository

> [!NOTE]
>
> cookiecutter 2.4.0 and earlier are required for this template.
