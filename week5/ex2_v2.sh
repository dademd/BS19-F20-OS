i=0
while [ $i -le 5 ]
do
	last_num=$(grep -Eo '^[0-9]+$' numbers.lock | tail -1)
	expr $last_num + 1 >> numbers.lock
done
