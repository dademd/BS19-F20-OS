gcc -o ex2 ex2.c

./ex2 &
vmstat 1

#  swpd, si, and so remain unchangedly 0, which may mean that no Swap space was used(no swaps in and out of Swap space)
# free -h demonstrates 0 used and free Swap. Probably, Swap space isn't used here at all