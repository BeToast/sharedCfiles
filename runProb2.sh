#!/bin/bash
RUNS=50
mkdir csvout
mkdir csvout/problem2
mkdir csvout/problem2/${RUNS}runs
./timer_memlock 10000 12 > csvout/problem2/${RUNS}runs/b_output.csv &

for i in $(seq 50)
do
  ./timer_mem_use 10000 12 > csvout/problem2/${RUNS}runs/run${i}.csv &
done  