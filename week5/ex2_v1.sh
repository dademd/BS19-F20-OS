touch numbers

for i in {1..50}
do
	last=$(grep -Eo '^[0-9]+$' numbers | tail -1)
	expr $last + 1 >> numbers
done


# It takes not much time for a race to start
# usually, race becomes visible after a couple of numbers written in the file numbers. There appear duplicates which means that not one script accesses it
# Since both scripts acess the same file, this file is a critical region