#!/bin/bash
RUNS=600
mkdir csvout
mkdir csvout/problem2
mkdir csvout/problem2/${RUNS}runs
./timer_memlock 500000 13 > csvout/problem2/${RUNS}runs/b_output.csv &
sleep 5
for i in $(seq ${RUNS})
do
  ./timer_mem_use 500000 12 > csvout/problem2/${RUNS}runs/thread${i}.csv &
done  
sleep 125
echo "done"
