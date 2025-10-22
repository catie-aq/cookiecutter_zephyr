/*
 * Copyright (c) {{cookiecutter.copyright_year}}, {{cookiecutter.copyright_holder}}
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_SENSOR_{{cookiecutter.__reference_snake.upper()}}_{{cookiecutter.__reference_snake.upper()}}_H_
#define ZEPHYR_DRIVERS_SENSOR_{{cookiecutter.__reference_snake.upper()}}_{{cookiecutter.__reference_snake.upper()}}_H_
{% if cookiecutter.bus == "I2C" %}
#include <zephyr/drivers/i2c.h>
{% elif cookiecutter.bus == "SPI" %}
#include <zephyr/drivers/spi.h>
{% elif cookiecutter.bus == "SERIAL" %}
#include <zephyr/drivers/uart.h>
{% endif %}
struct {{cookiecutter.__reference_snake}}_config {
{%- if cookiecutter.bus == "I2C" %}
    struct i2c_dt_spec i2c;
{%- elif cookiecutter.bus == "SPI" %}
    struct spi_dt_spec spi;
{%- elif cookiecutter.bus == "SERIAL" %}
    const struct device *uart;
{%- endif %}
};

struct {{cookiecutter.__reference_snake}}_data {
};

#endif /* ZEPHYR_DRIVERS_SENSOR_{{cookiecutter.__reference_snake.upper()}}_{{cookiecutter.__reference_snake.upper()}}_H_ */
