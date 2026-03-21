#!/bin/bash

echo "=== BUILD TESTS ==="

g++ -std=c++17 tests/test.cpp -o test

if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
fi

echo "=== RUN TESTS ==="
./test

exit $?