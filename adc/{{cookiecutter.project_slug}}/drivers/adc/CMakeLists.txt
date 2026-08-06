# Copyright (c) {{cookiecutter.copyright_year}} {{cookiecutter.copyright_holder}}
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_ADC_{{ cookiecutter.__reference_snake.upper() }} adc_{{ cookiecutter.__reference_snake.lower() }}.c)
