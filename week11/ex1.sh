echo $(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w $(( ( RANDOM % 100 )  + 1 )) | head -n 1) > ex1.txt

make ex1; ./ex1

echo "$(<ex1.txt)"
