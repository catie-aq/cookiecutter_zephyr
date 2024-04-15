# Copyright (c) {{cookiecutter.copyright_year}} {{cookiecutter.copyright_holder}}
# SPDX-License-Identifier: Apache-2.0

board_check_revision(
  FORMAT MAJOR.MINOR.PATCH
  DEFAULT_REVISION {{cookiecutter.board_default_version}}
  VALID_REVISIONS {{cookiecutter.board_all_compatible_versions}}
)
