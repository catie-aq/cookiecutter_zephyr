/*
 * Copyright (c) {{cookiecutter.copyright_year}}, {{cookiecutter.copyright_holder}}
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT {{cookiecutter.__vendor_prefix_snake}}_{{cookiecutter.__reference_snake}}_adc

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/adc.h>

LOG_MODULE_REGISTER(adc_{{cookiecutter.__reference_snake.lower()}}, CONFIG_ADC_LOG_LEVEL);

static int {{cookiecutter.__reference_snake}}_setup(const struct device *dev,
				const struct adc_channel_cfg *channel_cfg)
{
	ARG_UNUSED(dev);

	return 0;
}

static int {{cookiecutter.__reference_snake}}_read(const struct device *dev, const struct adc_sequence *seq)
{
	struct {{cookiecutter.__reference_snake}}_data *data = dev->data;

	return 0;
}

static int {{cookiecutter.__reference_snake}}_init(const struct device *dev)
{
	const struct {{cookiecutter.__reference_snake}}_config *config = dev->config;
	struct {{cookiecutter.__reference_snake}}_data *data = dev->data;

	return 0;
}

static DEVICE_API(adc, {{cookiecutter.__reference_snake}}_api) = {
	.channel_setup = {{cookiecutter.__reference_snake}}_channel_setup,
	.read = {{cookiecutter.__reference_snake}}_read,
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
	DEVICE_DT_INST_DEFINE(n, {{cookiecutter.__reference_snake}}_init, NULL, &{{cookiecutter.__reference_snake}}_data_##n, &{{cookiecutter.__reference_snake}}_config_##n,  \
			      POST_KERNEL, CONFIG_ADC_INIT_PRIORITY, &{{cookiecutter.__reference_snake}}_api);

DT_INST_FOREACH_STATUS_OKAY({{cookiecutter.__reference_snake.upper()}}_INIT)
