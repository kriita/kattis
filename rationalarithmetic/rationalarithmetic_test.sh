#!/bin/bash

# Navigate to the directory where the script is located.
cd "$(dirname "$0")"

# Run the binary with sample1.in as input and store the output in a temp file.
./RationalArithmetic < sample.in > temp_output.txt

# Compare the output with the expected output.
if diff -u temp_output.txt sample.out; then
    echo "Test passed."
else
    echo "Test failed."
    exit 1
fi

# Clean up
rm temp_output.txt

