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

# Get all .sh files in the specified directory
test_files=("$test_dir"/*.sh)

# Iterate through the .sh files and execute each one
for test_file in "${test_files[@]}"; do
    if [ "$test_file" != "$test_dir/runtest.sh" ]; then
        echo "Deleting: $test_file"
        rm "$test_file"
    fi
done
