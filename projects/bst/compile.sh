#!/bin/bash
gcc -o bst main.c bst.c allocator.c utils.c
echo "Running the compiled file -> ./bst"
./bst
