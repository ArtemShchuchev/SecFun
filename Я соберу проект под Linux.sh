#!/bin/bash
cmake -S . -B build
cd build
cmake --build . --config debug
cmake --build . --config release
exec $SHELL
