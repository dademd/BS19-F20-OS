rm -f _ex1* ex1.txt
touch _ex1.txt

f1=_ex1.txt
f11=_ex1_1.txt
f12=_ex1_2.txt
out=ex1.txt

ln $f1 $f11
ln $f1 $f12

get_inode(){
  local fname="$1"
  echo $( ls -i $fname ) | awk '{ print $1;}'
}

show(){
  local fname="$1"
  echo $fname\'s id: $( get_inode $fname) >> $out
}

show $f1
show $f11
show $f12