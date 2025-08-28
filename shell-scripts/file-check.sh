#!/usr/bin/env bash
# Usage: ./file-check.sh <path>
# If no path is given, default to directory_log.txt to match your earlier task.
TARGET=${1:-directory_log.txt}

if [ -e "$TARGET" ]; then
  echo "✅ '$TARGET' exists."

  # Tell what type
  if   [ -f "$TARGET" ]; then TYPE="regular file"
  elif [ -d "$TARGET" ]; then TYPE="directory"
  else TYPE="other"
  fi
  echo "Type: $TYPE"

  echo
  echo "--- ls -lh ---"
  ls -lh "$TARGET"

  echo
  echo "--- stat ---"
  stat "$TARGET"
else
  echo "❌ '$TARGET' does not exist."
  exit 1
fi
