#!/bin/bash
# Final integration script for the Linux, Shell, and C Lab

# Step 1: Compile contacts.c
echo "=== Compiling contacts.c ==="
gcc ../c-programs/contacts.c -o contacts

# Step 2: Run contacts (view existing contacts file)
echo "=== Running contacts (view) ==="
./contacts view

# Step 3: Create a backup of all C programs
echo "=== Creating backup archive ==="
tar -czf contacts-backup.tar.gz ../c-programs/*

# Step 4: Log output
echo "Output logged at $(date)" >> project-log.txt
echo "=== Project complete. Log updated in project-log.txt ==="
