#!/bin/bash
RUNS=50
mkdir csvout/problem2
mkdir csvout/problem2/${RUNS}runs
# ./timer_memlock 750000 12 > csvout/problem2/${RUNS}runs/b_output.csv &
i=0
while [ "$i" -lt ${RUNS}]; do
# for ((i=1; i<=$RUNS; i++))
# do
# ./timer_mem_use 750000 12 > csvout/problem2/${RUNS}runs/run${i}.csv &
  ./timer_mem_use 750000 1 > csvout/problem2/${RUNS}runs/run${i}.csv &
  i=$(( i + 1 ))
done