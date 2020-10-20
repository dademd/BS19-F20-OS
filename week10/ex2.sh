os=~/BS19-F20-OS
week1=${os}/week1

rm -f ex2.txt
echo 1. Create file.txt: >> ex2.txt

rm -f $week1/file.txt _ex2.txt
touch $week1/file.txt
link $week1/file.txt _ex2.txt


# returns inode of file
get_inode(){
  local fname="$1"
  echo $( ls -i $fname ) | awk '{ print $1;}'
}


echo 2. Trace links: >> ex2.txt

find $os -inum $( get_inode _ex2.txt ) >> ex2.txt


echo 3. Remove links: >> ex2.txt
find $week1 -inum $( get_inode _ex2.txt ) -exec rm {} \;