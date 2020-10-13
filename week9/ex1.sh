gcc -o ex1 ex1.c

# argument 1: number of page frames
# argumment 2: number of page references read during a tick

./ex1 10 5 < sequence.txt
./ex1 50 10 < sequence.txt
./ex1 100 42 < sequence.txt