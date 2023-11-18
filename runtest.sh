#!/bin/bash

# Array of test file names
test_files=(
    "0-no_argument.sh"
    "1-checker.sh"
    "1-file_doesnt_exist.sh"
    "2-checker.sh"
    "2-empty_file.sh"
    "3-checker.sh"
    "3-invalid_instructions.sh"
    "4-checker.sh"
    "4-spaces_1.sh"
    "5-checker.sh"
    "5-spaces_2.sh"
    "6-checker.sh"
    "7-checker.sh"
)

# Iterate through the test files and execute each one
for test_file in "${test_files[@]}"; do
    echo "Running test: $test_file"
    # Assuming your test files are executable, if not, use: bash "$test_file"
    ./"$test_file" # Execute the test file
    echo "Finished test: $test_file"
    echo "-------------------------"
done
