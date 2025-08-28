#!/usr/bin/env bash
# Count files by extension in a directory and write file-count.log here.

DIR="${1:-.}"          # directory to scan (default = current dir)
LOG="file-count.log"   # always log to ./file-count.log (current dir)

# Validate directory
if [ ! -d "$DIR" ]; then
  echo "Directory '$DIR' not found."
  exit 1
fi

declare -A count
total=0

# Walk DIR and count by extension
while IFS= read -r -d '' f; do
  ((total++))
  base="$(basename "$f")"
  if [[ "$base" == *.* ]]; then
    ext="${base##*.}"
    ext="${ext,,}"   # lowercase
  else
    ext="(noext)"
  fi
  ((count["$ext"]++))
done < <(find "$DIR" -type f -print0)

# Output and write to log
{
  echo "File type counts for: $DIR"
  echo "Run at: $(date)"
  echo "--------------------------------"
  for k in "${!count[@]}"; do
    printf "%-10s : %d\n" "$k" "${count[$k]}"
  done | sort
  echo "--------------------------------"
  echo "Total files : $total"
} | tee "$LOG"

echo "Wrote results to $(pwd)/$LOG"
