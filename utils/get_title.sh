#!/bin/bash

SESSION_ID="53616c7465645f5fa682e99157d2679b97328076831afe67053f465d234e3b3df4df03e9f8e7d7d997d3bbe9c8fb4d57fbe226cab1995a29d9f0c647e7d0e5ef"
YEAR=$1
DAY=$2

if [ -z "$YEAR" ]; then
    echo "Please provide a year"
    exit 1
fi

if [ -z "$DAY" ]; then
    echo "No day specified. Defaulting to download all the days"
fi

get_linux_style () { \
    curl -s -H "Cookie: session=$SESSION_ID" "https://adventofcode.com/$YEAR/day/$DAY" | \
    grep -o -E "\-\-\- Day [0-9][0-9]?: .+ ---" | \
    sed -E "s/---\sDay\s(.*)\s---$/\1/g" | \
    sed -E "s/[\:\<\>\"\?\*]//g" | \
    sed -E "s/\s/-/g" | \
    tr '[:upper:]' '[:lower:]' | \
    sed -E "s/\<([0-9])-/0\1-/g" \
    ; \
}

get_python_style () {
    python 'title_helper_script.py' "$(curl -s -H "Cookie: session=$SESSION_ID" https://adventofcode.com/$YEAR/day/$DAY)"
}

get_dir_names () {
    get_linux_style
    get_python_style
}

if [ -z "$YEAR" ]; then
    echo "Please enter the year as the first argument"
    exit 1
fi

if [ -z "$DAY" ]; then
    for DAY in {1..25}; do
        out=$(get_dir_names)
        echo "$out" >> "$YEAR".txt
        echo "" >> "$YEAR".txt
    done
else
    # Process the single day
    out=$(get_dir_names)
    echo "$out" >> "$YEAR".txt
    echo "" >> "$YEAR".txt
    sed -i '/^$/d' "$YEAR".txt
    mv "$YEAR".txt ../
fi

echo "Directory names for year $YEAR and day(s) $DAY have been written to $YEAR.txt"
