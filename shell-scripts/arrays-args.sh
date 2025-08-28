#!/usr/bin/env bash 
ARGS=("$@") 
echo "First arg: ${ARGS[0]}"
echo "All args (loop):"
for arg in "$@"; do 
 echo " - $arg" 
done 
