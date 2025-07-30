#!/bin/sh

N=$2
PROGRAM="./bsq $1"

if [[ -z "$PROGRAM" || -z "$N" ]]; then
  echo "Usage: $0 <map_file> <number_of_runs>"
  exit 1
fi

total=0

for i in $(seq 1 $N); do
    echo "Run $i..."
    start=$(date +%s.%N)
    $PROGRAM
    end=$(date +%s.%N)
    duration=$(echo "$end - $start" | bc)
    echo "Duration: $duration seconds"
    total=$(echo "$total + $duration" | bc)
done

average=$(echo "scale=4; $total / $N" | bc)
echo "Average time: $average seconds"