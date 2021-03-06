#!/bin/bash

. tools/shell_utils.sh

set -e

VENV_DIR="pyformat"
SCRIPTPATH=$(realpath "$(dirname $0)")
cd "$SCRIPTPATH"

if [ "${CIRCLECI}" != "true" ]; then
  source_venv "$VENV_DIR"
  echo "Installing requirements..."
  pip3 install -r requirements.txt
fi

echo "Running Python format check..."
./format_python_tools.py $1

echo "Running Python3 flake8 check..."
flake8 . --count --select=E901,E999,F821,F822,F823 --show-source --statistics