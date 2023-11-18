#!/bin/bash

# Check if the number of arguments provided is not equal to 1
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <test_directory>"
    exit 1
fi

# Assign the first argument to the test directory variable
test_dir="$1"

# Check if the directory exists
if [ ! -d "$test_dir" ]; then
    echo "Directory '$test_dir' not found!"
    exit 1
fi

# Find all .sh files in the specified directory and its subdirectories
sh_files=$(find "$test_dir" -type f -name "*.sh" ! -name "runtest.sh")

echo "Found the following test files:"
echo "$sh_files"

# Iterate through the .sh files and execute each one
for test_file in $sh_files; do
    echo "Running test: $test_file"
    if [ -x "$test_file" ]; then
        ./"$test_file" # Execute the test file if it's executable
    else
        bash "$test_file" # Execute using bash interpreter if not executable
    fi
    echo "Finished test: $test_file"
    echo "-------------------------"
done
