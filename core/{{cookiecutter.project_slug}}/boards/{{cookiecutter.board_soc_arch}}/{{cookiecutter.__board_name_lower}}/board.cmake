# Copyright (c) {{cookiecutter.copyright_year}} {{cookiecutter.copyright_holder}}
# SPDX-License-Identifier: Apache-2.0

board_runner_args(jlink "--device=stm32l4a6rg" "--speed=4000")

include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
