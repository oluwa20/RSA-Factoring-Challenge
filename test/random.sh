#!/bin/bash

# Specify the number of files you want to create
num_files=54

# Function to generate a random prime number
generate_prime() {
    echo $(shuf -i 10-100 -n 1)
}

# Loop through the desired number of files
for ((i=1; i<=num_files; i++)); do
    # Generate two random prime numbers
    prime1=$(generate_prime)
    prime2=$(generate_prime)

    # Calculate the factorizable number
    factorizable_number=$((prime1 * prime2))

    # Write the factorizable number to the file
    echo $factorizable_number > "rsa-$i"
done

