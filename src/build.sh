#!/bin/bash

echo "Building..."
g++ -O2 {*.cpp,*.h} -o m -Wall -Wextra -pedantic
echo "Built"
