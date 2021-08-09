#!/bin/bash, #!C:\Git\bin\bash.exe

echo
# !SIMPLE FOR LOOP
NAMES="Brad Kevin Alice Mark"
for NAME in $NAMES; do
	echo "Hello $NAME"
done
echo
echo

for i in 1 2 3 4
do
	echo $i
done

# !FOR LOOP TO RENAME FILES
# for item in [LIST]
# do
#   [COMMANDS]
# done

echo -e "$RED ex: for i in Hello World $NC"
for i in Hello World
do
	echo $i
done
echo -e "$RED ! WatchOut for ';' if do is in the same line $NC"
for i in Hello World; do
	echo $i
done


echo -e "$RED ex: for i in 1234 $NC"

for i in 1234
do
	echo $i
done
echo -e "$RED ex: for i in 1 2 3 4 $NC"

for i in 1 2 3
do
	echo $i
done


echo -e "$RED ex: for i in 1..3 $NC"
for i in 1..3
do
	echo $i
done

echo -e "$RED ex:{START..END} for i in {1..3} $NC"
for i in {1..3}
do
	echo $i
done


echo -e "$RED ex: for i in {10..7} $NC"
for i in {10..7}
do
	echo $i
done

echo -e "$RED ex: {START..END..STEP} $NC"

for i in {10..5..2}
do
	echo $i
done

echo -e "$RED ex: (seq START STEP END) $NC"

for i in $(seq 1 2 6)
do
	echo $i
done

for i in $(seq 10 -2 6);
do
	echo $i
done

echo -e "$RED ex: C-style for loop $NC"


for ((i = 0 ; i <= 3 ; i++))
do
  echo "i: $i"
done

echo -e "$RED ex: Summation and Even Odd=> $NC"

sum=0
echo -n "Enter no. of el to sum:"
read n

# for i in $(seq 1 $n)
for i in $( eval echo {1..$n} )
do
    read -p  "Enter value:" n2
#    sum=$(($sum+$i ))
   sum=$((sum+n2 ))
done

echo "SUM: " $sum

r=$(( $sum % 2 ))

if [ $r -eq 0 ]
then
  echo "$sum is even number"
else
  echo "$sum is odd number"
fi


# # rename files [1.loop 2.loop 3.loop] to [new-1.loop new-2.loop new-3.loop]
# FILES=$(ls *.loop)
# NEW="new"
# for FILE in $FILES; do
# 	echo "Renaming $FILE to new-$FILE"
# 	mv $FILE $NEW-$FILE
# done

echo
echo

# !WHILE LOOP - READ THROUGH A FILE LINE BY LINE
i=1
# while [ $i -le 3 ]
while ((i<=3))
do
	echo $i
	((i++))
	# let i++
	# i=$(($i+1))
done


LINE=1
while read -r CURRENT_LINE; do
	echo "$LINE: $CURRENT_LINE"
	((LINE++))
done <"./read_file.txt"

echo
echo