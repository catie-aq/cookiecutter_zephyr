# {{cookiecutter.board_name}}

[{{cookiecutter.board_name}}](https://6tron.io/zest_core/{{cookiecutter.__board_name_with_version}}) board support for Zephyr OS.

## Dependencies

This module depends on:
- [6TRON connector definition](https://github.com/catie-aq/zephyr_6tron-connector)

## Supported Features

The Zephyr {{cookiecutter.board_name}} board configuration supports the following hardware features:

| Interface | Controller                                                                  | Driver/Component                               |
| :-------- | :-------------------------------------------------------------------------- | :--------------------------------------------- |
| ADC       | on-chip                                                                     | adc                                            |
| AES       | on-chip                                                                     | crypto                                         |
| CAN       | on-chip                                                                     | can                                            |
| CLOCK     | on-chip                                                                     | clock_control                                  |
| DAC       | on-chip                                                                     | dac                                            |
| DIE_TEMP  | on-chip                                                                     | sensor                                         |
| DMA       | on-chip                                                                     | dma                                            |
| EXTI      | on-chip                                                                     | interrupt_controller                           |
| FLASH     | on-chip                                                                     | flash                                          |
| GPIO      | on-chip                                                                     | gpio                                           |
| I2C       | on-chip                                                                     | i2c                                            |
| LPTIM     | on-chip                                                                     | timer                                          |
| LPUART    | on-chip                                                                     | serial                                         |
| NVIC      | on-chip                                                                     | arch/arm                                       |
| PINCTRL   | on-chip                                                                     | pinctrl                                        |
| QSPI      | on-chip                                                                     | qspi, flash                                    |
| RNG       | on-chip                                                                     | entropy                                        |
| RTC       | on-chip                                                                     | rtc                                            |
| SDMMC     | on-chip                                                                     | disk                                           |
| SMBUS     | on-chip                                                                     | smbus                                          |
| SPI       | on-chip                                                                     | spi                                            |
| TIMER     | on-chip                                                                     | counter, pwm, timer                            |
| UART      | on-chip                                                                     | serial                                         |
| USART     | on-chip                                                                     | serial                                         |
| USB       | [<SERIAL_ADAPTER_COMPONENT>](<LINK_TO_COMPONENT>)                           | console                                        |
| USBOTG_FS | on-chip                                                                     | usb                                            |
| VBAT      | on-chip                                                                     | sensor                                         |
| VREF      | on-chip                                                                     | sensor                                         |
| IWDG      | on-chip                                                                     | watchdog                                       |
| WWDG      | on-chip                                                                     | watchdog                                       |

See [<VENDOR_NAME> vendor bindings](https://docs.zephyrproject.org/latest/build/dts/api/bindings.html#<VENDOR_NAME>) for additional information.

## Usage

1. Add the {{cookiecutter.board_name}} board to your workspace using the [6TRON module](https://github.com/catie-aq/zephyr_6tron-manifest.git).
2. Compile and flash application using `west` tool:
   - Board name: `{{cookiecutter.__board_name_lower}}`
