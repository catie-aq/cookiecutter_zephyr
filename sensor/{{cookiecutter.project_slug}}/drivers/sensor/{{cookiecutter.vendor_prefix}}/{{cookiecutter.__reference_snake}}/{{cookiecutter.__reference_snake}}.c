/*
 * Copyright (c) {{cookiecutter.copyright_year}}, {{cookiecutter.copyright_holder}}
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT {{cookiecutter.__vendor_prefix_snake}}_{{cookiecutter.__reference_snake}}

#include <zephyr/drivers/sensor.h>
#include <zephyr/logging/log.h>

#include "{{cookiecutter.__reference_snake}}.h"

LOG_MODULE_REGISTER({{cookiecutter.__reference_snake.upper()}}, CONFIG_SENSOR_LOG_LEVEL);

static int {{cookiecutter.__reference_snake}}_attr_set(const struct device *dev, enum sensor_channel chan,
			      enum sensor_attribute attr, const struct sensor_value *val)
{
	return -ENOTSUP;
}

static int {{cookiecutter.__reference_snake}}_sample_fetch(const struct device *dev, enum sensor_channel chan)
{
	struct {{cookiecutter.__reference_snake}}_data *data = dev->data;
	const struct {{cookiecutter.__reference_snake}}_config *config = dev->config;

	return -ENOTSUP;
}

static int {{cookiecutter.__reference_snake}}_channel_get(const struct device *dev, enum sensor_channel chan,
				 struct sensor_value *val)
{
	struct {{cookiecutter.__reference_snake}}_data *data = dev->data;

	// TODO: Update val with the sensor value
	val->val1 = 0;
	val->val2 = 0;

	return 0;
}

static int {{cookiecutter.__reference_snake}}_init(const struct device *dev)
{
	const struct {{cookiecutter.__reference_snake}}_config *config = dev->config;
	struct {{cookiecutter.__reference_snake}}_data *data = dev->data;

	return 0;
}

static DEVICE_API(sensor, {{cookiecutter.__reference_snake}}_driver_api) = {
	.attr_set = {{cookiecutter.__reference_snake}}_attr_set,
	.sample_fetch = {{cookiecutter.__reference_snake}}_sample_fetch,
	.channel_get = {{cookiecutter.__reference_snake}}_channel_get,
};

#define {{cookiecutter.__reference_snake.upper()}}_INIT(n)  \
{%- if cookiecutter.bus == "NONE" %}
	static const struct {{cookiecutter.__reference_snake}}_config {{cookiecutter.__reference_snake}}_config_##n = {};  \
{%- else %}
	static const struct {{cookiecutter.__reference_snake}}_config {{cookiecutter.__reference_snake}}_config_##n = {  \
{%- endif %}
{%- if cookiecutter.bus == "I2C" %}
		.i2c = I2C_DT_SPEC_INST_GET(n),  \
{%- elif cookiecutter.bus == "SPI" %}
		.spi = SPI_DT_SPEC_INST_GET(n, SPI_OP_MODE_MASTER | SPI_WORD_SET(8), 0),  \
{%- elif cookiecutter.bus == "SERIAL" %}
		.uart = DEVICE_DT_GET(DT_INST_BUS(n)),  \
{%- endif %}
{%- if cookiecutter.bus != "NONE" %}
	};  \
{%- endif %}
	static struct {{cookiecutter.__reference_snake}}_data {{cookiecutter.__reference_snake}}_data_##n;  \
	SENSOR_DEVICE_DT_INST_DEFINE(n, {{cookiecutter.__reference_snake}}_init, NULL, &{{cookiecutter.__reference_snake}}_data_##n, &{{cookiecutter.__reference_snake}}_config_##n,  \
			      POST_KERNEL, CONFIG_SENSOR_INIT_PRIORITY, &{{cookiecutter.__reference_snake}}_driver_api);

DT_INST_FOREACH_STATUS_OKAY({{cookiecutter.__reference_snake.upper()}}_INIT)
