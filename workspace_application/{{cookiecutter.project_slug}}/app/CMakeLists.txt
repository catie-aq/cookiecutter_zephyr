# Copyright (c) {{cookiecutter.copyright_year}} {{cookiecutter.copyright_holder}}
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project({{cookiecutter.application|lower|replace(' ','_')}} LANGUAGES C)

{% if cookiecutter.secure_app|lower == "true" -%}
zephyr_include_directories(include)
{% endif -%}

file(GLOB_RECURSE app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
