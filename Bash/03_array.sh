#!/bin/bash, #!C:\Git\bin\bash.exe

# !ARRAY

ar=(1 "hello" 2 3 4 1000)
 # print first element
echo "${ar}"
echo "${ar[0]}"
# print particular element
echo "${ar[1]}"
echo "${ar[3]}"
# print all elements of array
echo "${ar[@]}" #as array
echo "${ar[@]:0}" #as array
echo "${ar[*]}" #as string represntation
echo
# print elements from a particular index
# ${ARRAYNAME[WHICH_ELEMENT]:STARTING_INDEX}
echo "ar[@]:2->" "${ar[@]:2}"

#  print elements in range
# ${ARRAYNAME[WHICH_ELEMENT]:STARTING_INDEX:COUNT_ELEMENT}
echo "ar[@]:1:3->" "${ar[1]:1:3}"

#  Length of in Array
echo
echo "len: " "${#ar[@]}"
# Length of Particular element
echo "len of 'hello': " "${#ar[1]}"
echo "len of '1000': " "${#ar[5]}"

# !assign
echo
ar[2]="sad"
ar+=(arr concat)
echo "${ar[@]}"

# !read
# read -a ar
# echo "${ar[@]}"


# !iterate
echo
echo "iterate with for...."
for i in "${ar[@]}"
do
    echo -n $i" "
done

echo
echo "iterate with while...."
i=0
while [ $i -lt ${#ar[@]} ]
do
    # echo -n ${ar[$i]}" "
	echo -n ${ar[i]}" "
    # i=$(expr $i + 1)
	# let i++
	((i++))
done

# !Print the keys of an array
echo
for i in "${!ar[@]}" # index
do
    echo -n $i" "
done

# !Search in Array
# !Replacing Substring Temporary

# !To delete Array Variable
# To delete index-1 element: `unset arr[1]`
# To delete the whole Array: `unset arr`


# !associative arrays
echo
echo -e ${RED}"assos:"${NC}
declare -A arr # important
arr=([one]=1 [two]=2 [three]=3)
echo
for v in "${arr[@]}"; do echo -n "$v"; done
echo
for key in "${!arr[@]}"; do echo -n "$key"; done
echo
echo "${arr[@]}"
echo "${arr[foo]}"
echo

# !EX:

ar=(1 2 3 4 5)
greatest=0
for i in "${ar[@]}"
do
#    if [ "${ar[i]}" -gt "$greatest" ]; then #[: : integer expression expected
   if [ $((ar[i])) -gt $((greatest)) ]; then
      greatest="${ar[i]}"
   fi
done
echo "greatest number in an array is $greatest"

# ? Using variable condition "${#ar[@]}", "${m}", $((ar[i])) -gt "1"
ar=(1 2 3 4 5)
m=5
for((i=0; i<"${#ar[@]}"; i++))
do
	for((j=0;j<"${m}";j++))
	do
		if [ $((ar[i])) -gt "1" ]; then
			echo -n "${i}"
		fi
	done
done