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

# Change directory to the test directory
cd "$test_dir" || exit

# Execute all .sh files except runtest.sh
shopt -s nullglob
for test_file in *.sh; do
    if [ "$test_file" != "runtest.sh" ]; then
        echo "Running test: $test_file"
        if [ -x "$test_file" ]; then
            ./"$test_file" # Execute the test file if it's executable
        else
            bash "$test_file" # Execute using bash interpreter if not executable
        fi
        echo "Finished test: $test_file"
        echo "-------------------------"
    fi
done
