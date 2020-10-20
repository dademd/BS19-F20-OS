rm -f link1 link2 
mkdir -p tmp;
touch tmp/file1 tmp/file2

ln tmp/file1 link1

>ex4.txt

gcc -o ex4 ex4.c
./ex4 >> ex4.txt