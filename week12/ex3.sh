echo $(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w $(( ( 1000000)  + 1 )) | head -n 1) > fileA

rm -f ex3.txt

run_with_buf(){
  local buf_size="$1"
  
  gcc -DBUF_SIZE=$buf_size -o copy copy.c
  echo -DBUF_SIZE=$buf_size >> ex3.txt
  { time ./copy fileA fileB ; } 2>> ex3.txt
  echo >> ex3.txt 
}

# gcc -DBUF_SIZE=20 -o copy copy.c
# echo -DBUF_SIZE=20 >> ex3.txt
# time ./copy fileA fileB | tee -a ex3.txt

run_with_buf 20
sleep 3
run_with_buf 100
# { time ./copy fileA fileB ; } 2>> time.txt

# gcc -DBUF_SIZE=100 -o copy copy.c
# echo -DBUF_SIZE=100 >> ex3.txt
# time ./copy fileA fileB >> ex3.txt