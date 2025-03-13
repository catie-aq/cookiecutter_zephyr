# {{cookiecutter.board_name}}

{{cookiecutter.board_name}} board support for Zephyr OS.

## Usage

This board enables the following components:

- List {{cookiecutter.board_name}} sensors here :warning:

:bulb: These drivers should also be added to your workspace:

- List Zephyr OS drivers here :warning:

:pushpin: This shield defines:

- List Zephyr chosen or aliases :warning:

:triangular_ruler: To use this shield:

- Update your device tree by adding the `{{cookiecutter.__board_name_macro}}(port)` macro to the `app.overlay` file.\
  Replace `port` with the number of the Zest_Core port to which the shield is connected, e.g.:
  
  ```c
  {{cookiecutter.__board_name_macro}}(1) /* {{cookiecutter.board_name}} connected to Zest_Core first port */
  ```

- Activate support for the shield by adding `--shield {{cookiecutter.project_slug}}` to the west command.

## Advanced Usage

This shield can be hardware-modified to suit your application.

In that case, use instead the alternate variant of the shield:

- Update your device tree by adding the `{{cookiecutter.__board_name_macro}}_ALT(inst, port, ...)` macro to the `app.overlay` file, with:
  - `inst`: number of the shield instance,
  - `port`: number of the Zest_Core port to which the shield is connected,
  - List macro parameters for shield variation :warning:
- Activate support for the shield by adding `--shield {{cookiecutter.project_slug}}_alt` to the west command.
