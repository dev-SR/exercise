#!/bin/bash, #!C:\Git\bin\bash.exe
clear
# !VARIABLE
# Uppercase by concention
# letter,number,underscore
NAME="soikat"
RED='\e[0;91m'
NC='\033[0m' # No Color
printf "I love ${RED}red${NC}\n"
echo "My name is $NAME"
# -e flag to allow backslash escapes.
echo -e "My name is${RED} ${NAME}${NC}"

# !USER INPUT
# ex1
echo -n "Enter your name: "
read NAME

# ex2
read -r -p "Enter your id: " ID
# read without -r will mangle backslashes.

# -s flags for secret password
read -r -sp "Enter your passowrd: " PASS
echo

# echo into a file:
echo -e " NAME: ${RED}$NAME${NC}, ID: ${RED}$ID${NC}, PASS: ${RED}$PASS${NC}" >00_file_1.any
cat 00_file_1.any

# !IF
if [ "$NAME" == "soikat" ]; then
	echo "if[]: Your name is Soikat"
fi

# !ELSE-IF
if [ "$NAME" == "soikat" ]; then
	echo "else-if[]: Your name is Soikat"
elif [ "$NAME" == "bob" ]; then
	echo "else-if[]:our name is Bob"
else
	echo "else-if[]:our name is not Soikot or Bob"
fi

# !COMPARISON
########
# val1 -eq val2 Returns true if the values are equal
# val1 -ne val2 Returns true if the values are not equal
# val1 -gt val2 Returns true if val1 is greater than val2
# val1 -ge val2 Returns true if val1 is greater than or equal to val2
# val1 -lt val2 Returns true if val1 is less than val2
# val1 -le val2 Returns true if val1 is less than or equal to val2
########

NUM1=31
NUM2=5
if [ "$NUM1" -gt "$NUM2" ]; then
	echo "$NUM1 is greater than $NUM2"
else
	echo "$NUM1 is less than $NUM2"
fi

# !FILE CONDITIONS
########
# -d file   True if the file is a directory
# -e file   True if the file exists (note that this is not particularly portable, thus -f is generally used)
# -f file   True if the provided string is a file
# -g file   True if the group id is set on a file
# -r file   True if the file is readable
# -s file   True if the file has a non-zero size
# -u    True if the user id is set on a file
# -w    True if the file is writable
# -x    True if the file is an executable
########
FILE="test.txt"
if [ -e "$FILE" ]; then
	echo "$FILE exists"
else
	echo "$FILE does NOT exist"
fi
echo
echo
# !CASE STATEMENT
read -r -p "Are you 21 or over? Y/N " ANSWER
case "$ANSWER" in
[yY] | [yY][eE][sS])
	# any char 'y' or word 'yes'
	echo "You can have a beer :)"
	;;
[nN] | [nN][oO])
	echo "Sorry, no drinking"
	;;
*)
	echo "Please enter y/yes or n/no"
	;;
esac
echo
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

for i in $(seq 10 -2 6)
do
	echo $i
done

echo -e "$RED ex: Loop over array elements $NC"

BOOKS=('In Search of Lost Time' 'Don Quixote' 'Ulysses' 'The Great Gatsby')

for book in "${BOOKS[@]}"
do
  echo "Book: $book"
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
   sum=$(($sum+$n2 ))
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
LINE=1
while read -r CURRENT_LINE; do
	echo "$LINE: $CURRENT_LINE"
	((LINE++))
done <"./read_file.txt"

echo
echo
# !FUNCTION
function sayHello() {
	echo "Hello World"
}
sayHello

# FUNCTION WITH PARAMS
function greet() {
	echo "Hello, I am $1 and I am $2"
}

greet "Soikat" "22"

echo
echo
