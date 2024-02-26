/*
 * Copyright (c) {{cookiecutter.copyright_year}}, {{cookiecutter.copyright_holder}}
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT {{cookiecutter.short_manufacturer|lower}}_{{cookiecutter.__reference}}

#include <zephyr/logging/log.h>

#include "{{cookiecutter.__reference}}.h"

LOG_MODULE_REGISTER({{cookiecutter.__reference.upper()}}, CONFIG_SENSOR_LOG_LEVEL);

struct {{cookiecutter.__reference}}_config {
};

struct {{cookiecutter.__reference}}_data {
};

static int {{cookiecutter.__reference}}_attr_set(const struct device *dev, enum sensor_channel chan,
			   enum sensor_attribute attr, const struct sensor_value *val)
{
	return 0;
}

static int {{cookiecutter.__reference}}_sample_fetch(const struct device *dev, enum sensor_channel chan)
{
	struct {{cookiecutter.__reference}}_data *dev_data = dev->data;
	const struct {{cookiecutter.__reference}}_cfg *dev_cfg = dev->config;

	return 0;
}

static int {{cookiecutter.__reference}}_channel_get(const struct device *dev, enum sensor_channel chan,
			      struct sensor_value *val)
{
	struct {{cookiecutter.__reference}}_data *dev_data = dev->data;

    // TODO: Update val with the sensor value
	val->val1 = 0;
	val->val2 = 0;

	return 0;
}

static int {{cookiecutter.__reference}}_init(const struct device *dev)
{
	const struct {{cookiecutter.__reference}}_cfg *cfg = dev->config;
	struct {{cookiecutter.__reference}}_data *dev_data = dev->data;

	return 0;
}

static const struct sensor_driver_api {{cookiecutter.__reference}}_driver_api = {
	.attr_set = {{cookiecutter.__reference}}_attr_set,
	.sample_fetch = {{cookiecutter.__reference}}_sample_fetch,
	.channel_get = {{cookiecutter.__reference}}_channel_get,
};

#define {{cookiecutter.__reference.upper()}}_INIT(n)                                                                             \
	static struct {{cookiecutter.__reference}}_cfg {{cookiecutter.__reference}}_config_##n = {                                             \
	};                                                                                         \
	static struct {{cookiecutter.__reference}}_data {{cookiecutter.__reference}}_data_##n;                                                 \
	DEVICE_DT_INST_DEFINE(n, {{cookiecutter.__reference}}_init, NULL, &{{cookiecutter.__reference}}_data_##n, &{{cookiecutter.__reference}}_config_##n,          \
			      POST_KERNEL, CONFIG_SENSOR_INIT_PRIORITY, &{{cookiecutter.__reference}}_driver_api);

DT_INST_FOREACH_STATUS_OKAY({{cookiecutter.__reference.upper()}}_INIT)
