#!/usr/bin/env bash 
set -o errexit 
set -o pipefail 
trap 'echo "Error!"' ERR

echo "this will run."
false 
echo "you won't see this line"

