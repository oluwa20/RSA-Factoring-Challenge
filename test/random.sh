#!/bin/bash

# Specify the number of files you want to create
num_files=60

# Loop through the desired number of files
for ((i=1; i<=num_files; i++)); do
    # Generate a random number (adjust the range as needed)
    random_number=$((RANDOM % 100 + 1))

    # Write the random number to the file
    echo $random_number > "rsa-$i"
done

