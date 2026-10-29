"""Generate the template TEMPLATE (argv[1]) into OUTPUT_DIR (argv[2]) with the
extra context given as JSON in $CONTEXT, hooks included, and print the project
path.
"""

import json
import os
import sys
from pathlib import Path

from cookiecutter.main import cookiecutter

template = Path(__file__).resolve().parents[2] / sys.argv[1]
context = json.loads(os.environ.get("CONTEXT") or "{}")

print(cookiecutter(str(template), no_input=True, extra_context=context, output_dir=sys.argv[2]))
