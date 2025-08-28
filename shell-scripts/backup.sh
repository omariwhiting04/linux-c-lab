#!/user/bin/env bash 
set -o errexit 
set -o pipefail 
trap 'echo "error!"' ERR 

shopt -s nullglob 
txts=( *.txt ) 

if (( ${#txts[@]} == 0 )); then 
  echo "no .txt file to back up." 
  exit 0 
fi 

out="backup-$(date +%y%m%d-%H%M%S).tar.gz" 
tar -czf "$out" "${txts[@]}"
echo "Created $out with ${#txts[@] .txt file(s)." 
