#! /bin/sh

ARG="$@"
# Verify if the pushswap program does in fact sort the list
./push_swap $ARG | ./checker $ARG
# Gives the number of operations that pushswap made
./push_swap $ARG | wc -l
