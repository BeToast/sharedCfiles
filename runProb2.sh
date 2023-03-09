#!/bin/bash
RUNS=50
./timer_memlock 750000 12
mkdir csvout/problem2
mkdir csvout/problem2/${RUNS}runs
for (( i = 0; i < $RUNS; i++ ))
do
./timer_mem_use 750000 12 > csvout/problem2/${RUNS}runs/run${i}.csv &
done