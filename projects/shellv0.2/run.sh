#!/bin/bash

gcc -g -o shell shell.c utils.c
./shell
alias run="bash ./run.sh"
