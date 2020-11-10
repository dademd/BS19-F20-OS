echo $(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w $(( ( 5000)  + 1 )) | head -n 1) > fileA

echo changing -DBUF_SIZE

run_with_buf(){
  local buf_size="$1" 
  gcc -DBUF_SIZE=$buf_size -o copy copy.c
  time ./copy fileA fileB
}

run_with_buf 20 && run_with_buf 100 && run_with_buf 100000

echo
echo using O_SYNC


run_with_buf(){
  local buf_size="$1"
  gcc -DSYNC -DBUF_SIZE=$buf_size -o copy copy.c
  # gcc -DSYNC -o copy copy.c
  time ./copy fileA fileB
}

run_with_buf 20 && run_with_buf 100 && run_with_buf 100000