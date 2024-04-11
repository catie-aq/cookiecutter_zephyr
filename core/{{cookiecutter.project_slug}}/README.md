# Zest_Core_STM32L4A6RG

[Zest_Core_STM32L4A6RG](https://6tron.io/zest_core/zest_core_stm32l4a6rg_3_1_0) board support for Zephyr OS.

## Dependencies

This module depends on:
- [6TRON connector definition](https://github.com/catie-aq/zephyr_6tron-connector)

## Supported Features

The Zephyr Zest_Core_STM32L4A6RG board configuration supports the following hardware features:

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
| USB       | [CP2102N](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) | console                                        |
| USBOTG_FS | on-chip                                                                     | usb                                            |
| VBAT      | on-chip                                                                     | sensor                                         |
| VREF      | on-chip                                                                     | sensor                                         |
| IWDG      | on-chip                                                                     | watchdog                                       |
| WWDG      | on-chip                                                                     | watchdog                                       |

See [STMicroelectronics vendor bindings](https://docs.zephyrproject.org/latest/build/dts/api/bindings.html#dt-vendor-st) for additional information.

## Usage

1. Add the Zest_Core_STM32L4A6RG board to your workspace using the [6TRON module](https://github.com/catie-aq/zephyr_6tron-manifest.git).
2. Compile and flash application using `west` tool:
   - Board name: `zest_core_stm32l4a6rg`
