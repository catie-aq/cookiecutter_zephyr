# Copyright (c) {{cookiecutter.copyright_year}} {{cookiecutter.copyright_holder}}
# SPDX-License-Identifier: Apache-2.0

add_subdirectory_ifdef(CONFIG_{{ cookiecutter.__reference_snake.upper() }} {{ cookiecutter.__reference_snake }})
