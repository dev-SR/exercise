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

echo -e "${RED}....if..fi........${NC}"
# !IF
if [ "$NAME" == "soikat" ]; then
	echo "if[]: Your name is Soikat"
fi

echo -e "${RED}....if..elif_else..fi........${NC}"
# !ELSE-IF
if [ "$NAME" == "soikat" ]; then
	echo "else-if[]: Your name is soikat"
elif [ "$NAME" == "bob" ]; then
	echo "else-if[]:our name is Bob"
else
	echo "else-if[]:our name is not Soikot or Bob"
fi


# !Arithmetic Operations
echo -e "${RED}....Arithmetic Operations........${NC}"
echo "ex1"
# ?Example – 1: Using ‘expr’ command
# expr '10 + 30'# Works as string
# expr 10+30 # Works as string
# expr 10 + 30 #Perform the addition
# expr 30 % 9 #Find out the remainder value
v1=`expr 30 / 10`#Using expr with backtick
echo $v1
v2=$( expr 30 - 10 ) #Using expr within command substitute
echo $v2
echo

# ?Example – 3: Using double brackets
echo "ex3"

# Calculate the mathematical expression
val1=$((10*5+15))
echo $val1

# Using post or pre increment/decrement operator
((val1++))
echo $val1
val2=41
((--val2))
echo $val2

# Using shorthand operator
(( val2 += 60 ))
echo $val2

# Dividing 40 by 6
(( val3 = 40/6 ))
echo $val3
echo

# ?Example – 2: Using ‘let’ command
echo "ex2"
let v1=9*3
echo $v1

let "v2 = v1 / 3"
echo $v2

let v3=9-3
echo $v3

let v4=7
let v4++
echo $v4
i=10
let "v5=50+$i"
echo $v5
echo
