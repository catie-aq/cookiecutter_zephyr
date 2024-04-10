/*
 * Copyright (c) {{cookiecutter.copyright_year}}, {{cookiecutter.copyright_holder}}
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

int main(void)
{
	while (1) {
		printk("Alive\n");
		k_sleep(K_MSEC(1000));
	}

	return 0;
}
