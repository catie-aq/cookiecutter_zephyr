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
		printk("STSafe reset GPIO is not ready!");
		return -1;
	}
	if (gpio_pin_configure_dt(&stsafe_reset, GPIO_OUTPUT_ACTIVE) < 0) {
		printk("Failed to configure STSafe reset GPIO!");
		return -1;
	}

#ifdef CONFIG_STSAFE_A110
	stse_handler.device_type = STSAFE_A110;
#elif defined(CONFIG_STSAFE_A120)
	stse_handler.device_type = STSAFE_A120;
#endif

	ret = stse_init(&stse_handler);
	if (ret != STSE_OK) {
		printk("Failed to initialize STSafe handler: %d", ret);
		return -1;
	}
{%- endif %}

	while (1) {
		printk("Alive\n");
		k_sleep(K_MSEC(1000));
	}

	return 0;
}
