# {{cookiecutter.board_name}}

{{cookiecutter.board_name}} board support for Zephyr OS.

## Usage

This board enables the following components:

- [Vendor Reference](https://link-to-component) kind of sensor :warning:

:bulb: These drivers should also be added to your workspace:

- [Vendor Reference driver](https://link-to-repository) :warning:

:pushpin: This shield defines:

- the default chosen-node-purpose: `zephyr,chosen-node-label` to `reference-node` :warning:
<!-- Get chosen node purpose and chosen node label from [Zephyr documentation](https://docs.zephyrproject.org/latest/build/dts/api/api.html#zephyr-specific-chosen-nodes). -->
- a node-purpose device: `reference-node` :warning:

:triangular_ruler: To use this shield:

- Update your device tree by adding the `{{cookiecutter.__board_name_snake|upper}}(port)` macro to the `app.overlay` file.\
  Replace `port` with the number of the Zest_Core port to which the shield is connected, e.g.:
  
  ```c
  {{cookiecutter.__board_name_snake|upper}}(1) /* {{cookiecutter.board_name}} connected to Zest_Core first port */
  ```

- Activate support for the shield by adding `--shield {{cookiecutter.board_name_lower}}` to the west command.

## Advanced Usage

This shield can be hardware-modified to suit your application.

In that case, use instead the alternate variant of the shield:

- Update your device tree by adding the `{{cookiecutter.__board_name_snake|upper}}_ALT(inst, port, ...)` macro to the `app.overlay` file, with:
  - `inst`: number of the shield instance,
  - `port`: number of the Zest_Core port to which the shield is connected,
  - List macro parameters for shield variation :warning:
- Activate support for the shield by adding `--shield {{cookiecutter.board_name_lower}}_alt` to the west command.
