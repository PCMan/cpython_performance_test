#!/bin/bash
set -e

# clean up previus build
rm -f dispatcher.so
rm -rf build

# build the extension
python2 setup.py build_ext --inplace
