# Optimization-Algorithms

Optimizing Matrix chain multiplication and Floyd warshell Algo

Optimizing the code for Matrix chain multiplication and Floydwarshell algorithm
to find the shortest distance.

Assignment 1, optimizing matrix chain multiplication and Flyodwarshell algorithms

Assignment 2: Optimizing matrix chain multiplication even more using parallelization techniques and tiling methods.

We use perf,cachegrind ,prof and clock_gettime for checking the performance of a program.

Understanding perf,cachegrind,prof and clock_gettime.
1. perf
• perf is a performance analyzer in linux.
• Makes use of data from the Performance Monitoring Unit (PMU) in
CPUs.
• To install:
• sudo apt-get install linux-tools-’kernel version’
• Eg : sudo apt-get install linux-tools-4.15.0.136
2. cachegrind
• cachegrind simulates how your program interacts with a machine's cache
hierarchy and (optionally) branch predictor. It simulates a machine with
independent first-level instruction and data caches (I1 and D1), backed by
a unified second-level cache (L2).
• Usage:
• valgrind --tool=cachegrind <program>
•
3. gprof
• Gprof is a free profiler from GNU
• determine where most of the execution time is spent
• it locates code regions suited for optimization
• analyzes connections between individual functions
• Usage:
• gcc -pg test_gprof.c -o test_gprof
• -pg allows for profiling
• ./test_gprof
• Run once to get the gnom.out file• gprof test_gprof gmon.out > analysis.txt
• Run with gprof to get the analysis report in the output file
4. Clock_gettime()
• This is used to calculate time taken for the entire program to run. we
record start and stop time and calculate the difference between them to
print the total time taken by the program to run.
