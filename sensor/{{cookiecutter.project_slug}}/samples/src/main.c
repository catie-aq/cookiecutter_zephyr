/*
 * Copyright (c) {{cookiecutter.copyright_year}}, {{cookiecutter.copyright_holder}}
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

int main(void)
{
	const struct device *const dev = DEVICE_DT_GET_ANY({{cookiecutter.short_manufacturer.lower()}}_{{cookiecutter.reference.lower()}});
	struct sensor_value value;

	if (!device_is_ready(dev)) {
		printk("Device %s is not ready\n", dev->name);
		return 1;
	}

	while (1) {
		sensor_sample_fetch(dev);
        // Example for ambiant stemperature sensor
		sensor_channel_get(dev, SENSOR_CHAN_AMBIENT_TEMP, &value);
		printk("Value: %d.%06d\n", value.val1, value.val2);
		k_sleep(K_MSEC(1000));
	}
}
