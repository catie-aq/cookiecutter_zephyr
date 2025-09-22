/*
 * Copyright (c) {{cookiecutter.copyright_year}}, {{cookiecutter.copyright_holder}}
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
{%- if cookiecutter.secure_app|lower == "true" %}
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#include "stselib.h"

const struct gpio_dt_spec stsafe_reset = GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, stsafereset_gpios);
{%- endif %}

int main(void)
{
{%- if cookiecutter.secure_app|lower == "true" %}
	int ret = STSE_OK;
	if (!gpio_is_ready_dt(&stsafe_reset)) {
		printk("STSafe reset GPIO is not ready!\n");
		return -1;
	}
	if (gpio_pin_configure_dt(&stsafe_reset, GPIO_OUTPUT_ACTIVE) < 0) {
		printk("Failed to configure STSafe reset GPIO!\n");
		return -1;
	}

	stse_Handler_t stse_handler;
	ret = stse_set_default_handler_value(&stse_handler);
	if (ret != STSE_OK) {
		printk("Failed to set default handler value: %d\n", ret);
		return -1;
	}

#ifdef CONFIG_STSAFE_A110
	stse_handler.device_type = STSAFE_A110;
#elif defined(CONFIG_STSAFE_A120)
	stse_handler.device_type = STSAFE_A120;
#endif

	ret = stse_init(&stse_handler);
	if (ret != STSE_OK) {
		printk("Failed to initialize STSafe handler: %d\n", ret);
		return -1;
	}

	char buffer[] = {1, 2, 3, 4};
	char buffer_out[sizeof(buffer)] = {0};
	ret = stse_device_echo(&stse_handler, (uint8_t *)buffer, (uint8_t *)buffer_out,
			       sizeof(buffer));
	if (ret != STSE_OK) {
		printk("Echo command failed: %d\n", ret);
		return -1;
	}
	if (memcmp(buffer, buffer_out, sizeof(buffer)) != 0) {
		printk("Echo response does not match input data\n");
		return -1;
	}
	printk("Echo command successful\n");
{%- endif %}

	while (1) {
		printk("Alive\n");
		k_sleep(K_MSEC(1000));
	}

	return 0;
}
