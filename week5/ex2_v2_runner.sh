rm -f numbers
rm -f numbers.lock

touch numbers
ln numbers numbers.lock

bash ex2_v2.sh &
bash ex2_v2.sh