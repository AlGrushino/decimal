#!/bin/bash

# прекратил работать, когда распихали по директориям
clang-format -i *.h *.c
# find . -type f -name '*.c' -o -name '*.h' -print0 | xargs -0 clang-format -i