>ex3.txt
>_ex3.txt
echo After creation: >> ex3.txt
ls -l _ex3.txt >> ex3.txt

echo Step 1 >> ex3.txt
chmod -x _ex3.txt
ls -l _ex3.txt >> ex3.txt

echo Step 2 >> ex3.txt
chmod u=rwx _ex3.txt
chmod o=rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt

echo Step 3 >> ex3.txt
chmod g=rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt