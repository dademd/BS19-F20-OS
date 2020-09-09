clang -std=c11 -o ex2 ex2.c

./ex2 &
# pstree only sometimes shows all 32 processes that should be created in ex2. 
# This is because the line with pstree is sometimes executed erlier than some processes created in ex2. 
# After ex2 sleep ends, pstree shows only one parent process ex2
for i in {1..4};
  do pstree; sleep 1;
done
