#!/bin/bash, #!C:\Git\bin\bash.exe
clear
RED='\e[0;91m'
NC='\033[0m' # No Colo


# !FUNCTION
function sayHello() {
	echo "Hello World"
}
sayHello

# !FUNCTION WITH PARAMS
echo -e "${RED}FUNCTION WITH PARAMS ${NC}"
function greet() {
	echo "Hello, I am $1 and I am $2"
	# $#
	echo -e "Total number of arg:${RED} $#"
	# $*
	echo -e "${NC}String representation of all arg: ${RED} $*"
	echo -e "${NC}Store as an array: ${RED}"
	# $@
	ar="$@"
    echo "${ar[@]}"
	echo -e -n "${NC}"
}

greet "Soikat" "22"

echo

# !RETURNING FROM FUNCTIONS
echo -e "${RED}RETURNING FROM FUNCTIONS${NC}"

print () {
	return 200
	# return "Hello World" #Can only return upto 0-255
}
print Mars Jupiter 10 World  #passing arg
returned=$? # capture return value
echo $returned


# !EXAMPLE
echo
echo -e "${RED}EXAMPLE${NC}"
function Sum(){
sum=0
for i in "$@"
do
    sum=$((sum+i))
	# sum=`expr $sum + $i`
done
echo "SUM: $sum"

}
Sum 1 2 3 4


function FindGreater(){
echo "Enter Num1"
read num1
echo "Enter Num2"
read num2

if [ "$num1" -gt "$num2" ];
then
    echo "$num1 is greater than $num2"
else
    echo "$num2 is greater than $num1"
fi
}

FindGreater