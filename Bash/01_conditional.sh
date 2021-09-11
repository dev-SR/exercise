#!/bin/bash, #!C:\Git\bin\bash.exe
# !COMPARISON
echo -e "${RED}....COMPARISON........${NC}"
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

#  Write a Shell program to find all integer numbers for a given number (e.g., 100), that aren’t Divisible by either 2 or 3 but divisible by 5.

# Enter any number: 100
# Output:
# The desired integers are: 5, 25, 35, 55, 65, 85, 95

echo "Enter the range: "
read N

for (( i=0; i<N; i++ ))
do
   if [ $((i % 5)) -eq 0 ] ; then
     if [ $((i % 2)) -ne 0 ] && [ $((i % 3)) -ne 0 ]; then
       echo $i
     fi
   fi
done

