# MLFQ Scheduler

A mini Multi-Level Feedback Queue (MLFQ) CPU scheduler simulation implemented in C++.

## Overview

This program simulates the MLFQ scheduling algorithm, which uses multiple queues with different priority levels to optimize both response time and turnaround time.

## How It Works

The scheduler uses **3 priority queues** with increasing time quantums:

| Queue | Priority | Time Quantum |
|-------|----------|--------------|
| Q0    | Highest  | 4 ms         |
| Q1    | Medium   | 8 ms         |
| Q2    | Lowest   | 16 ms        |

### Rules

1. All processes start in the highest priority queue (Q0)
2. If a process uses its entire time quantum, it moves down to the next queue
3. Higher priority queues are always serviced first
4. Processes in the lowest queue (Q2) run with the largest quantum

## Building

```bash
make
```

## Running

```bash
./mlfq
```

## Sample Output

```
time 0 : P1 running in Q0 for 4ms
time 4 : P2 running in Q0 for 3ms
time 7 : P2 finished
time 7 : P3 running in Q0 for 4ms
...
```

## Cleaning

```bash
make clean
```
