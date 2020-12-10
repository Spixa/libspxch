#!/bin/bash

echo "Building..."
g++ -O2 {*.cpp,*.h} -o m
echo "Built"
