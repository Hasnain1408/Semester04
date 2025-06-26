#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <Enter directory>"
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "Directory '$1' not found."
    echo "Enter a valid path"
    exit 1
fi

echo "Directory '$1' exists."

files=$(find "$1" -type f -name "*.c" -o -name "*.cpp")


for file in $files; do
  
    filename=$(basename "$file")

    size=$(du -h "$file" | awk '{print $1}')

    lines=$(wc -l < "$file")

    echo "File: $filename | Size: $size | Lines of code: $lines"
done

