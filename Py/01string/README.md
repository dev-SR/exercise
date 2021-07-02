# String

- [String](#string)
  - [Multiline String](#multiline-string)
  - [String Concatenation](#string-concatenation)
    - [String Concatenation using + Operator](#string-concatenation-using--operator)
    - [String concatenation using join() function](#string-concatenation-using-join-function)
    - [String Concatenation using f-string](#string-concatenation-using-f-string)
    - [String Concatenation using format() function and % operator](#string-concatenation-using-format-function-and--operator)
  - [Indexing a String](#indexing-a-string)
    - [Negative Indexing](#negative-indexing)
  - [Iterating through string](#iterating-through-string)
  - [Methods related to Strings](#methods-related-to-strings)
    - [Boolean String Methods](#boolean-string-methods)
    - [Starts With and Ends With](#starts-with-and-ends-with)
    - [find()](#find)
    - [index()](#index)
    - [replace()](#replace)
    - [Split and Join Strings](#split-and-join-strings)
    - [strip()](#strip)
  - [Substring](#substring)
    - [string slicing](#string-slicing)
      - [Slicing with Negative index](#slicing-with-negative-index)
      - [Using a Step in a Slice](#using-a-step-in-a-slice)
      - [Slicing Backwards](#slicing-backwards)
    - [Checking if substring is found](#checking-if-substring-is-found)
    - [Count of Substring Occurrence](#count-of-substring-occurrence)
    - [Find all indexes of substring](#find-all-indexes-of-substring)
  - [Reverse a String](#reverse-a-string)
    - [Python Reverse String using Slicing](#python-reverse-string-using-slicing)
    - [for loop](#for-loop)
    - [list.reverse()](#listreverse)
  - [String Replacement Fields and F-String](#string-replacement-fields-and-f-string)
  - [More on String Formatting](#more-on-string-formatting)
  - [Raw String](#raw-string)
  - [String Conversion](#string-conversion)
  - [Few Operations on Strings](#few-operations-on-strings)
  - [String Module](#string-module)
  - [Python Generate Random String](#python-generate-random-string)
    - [Random UUID Generation](#random-uuid-generation)

```python
s = "Hello World"
print(s);
print(type(s))
```

    Hello World
    <class 'str'>
    

## Multiline String


```python
#  using triple quotes
ms = """My Name is Jhon.
I am the owner of dev.com
Dev is a very popular website in Developers community."""

# using brackets
ms = ("My Name is Jhon. "
     "I am the owner of dev.com"
     "Dev is a very popular website in Developers community.")

# using backslash
ms = "My Name is Jhon. " \
    "I am the owner of JournalDev.com and " \
    "JournalDev is a very popular website in Developers community."

```

##  String Concatenation

### String Concatenation using + Operator


```python

s1 = 'Apple'
s2 = 'Pie'
s3 = 'Sauce'
s4 = s1 + s2 + s3
print(s4)


#  However, the arguments must be a string.
# Let’s see how to concatenate a string to integer or another object.
print('Hello' + str(4))

class Demo:
    id = 0
    def __init__(self, i):
        self.id = i
    def __str__(self):
        return 'Demo[' + str(self.id) + ']'

print('Hello ' + str(Demo(10)))
```

    ApplePieSauce
    Hello4
    Hello Demo[10]
    

### String concatenation using join() function

We can use join() function to concatenate string with a separator. It’s useful when we have a sequence of strings, for example list or tuple of strings.

If you don’t want a separator, then use join() function with an empty string.


```python
s1 = 'Hello'
s2 = 'World'
print('Concatenated String using join() =', "".join([s1, s2]))
print('Concatenated String using join() and whitespaces =', " ".join([s1, s2]))
```

    Concatenated String using join() = HelloWorld
    Concatenated String using join() and whitespaces = Hello World
    

### String Concatenation using f-string


```python

s1 = 'Hello'
s2 = 'World'

s3 = f'{s1} {s2}'
print('String Concatenation using f-string =', s3)

name = 'Jhon'
age = 34
d = Demo(10)

print(f'{name} age is {age} and d={d}')

```

    String Concatenation using f-string = Hello World
    Jhon age is 34 and d=Demo[10]
    

### String Concatenation using format() function and % operator

We can use string format() function for string concatenation and formatting too.


```python

s1 = 'Hello'
s2 = 'World'

s3 = "{}-{}".format(s1, s2)
print('String Concatenation using format() =', s3)

s3 = "{in1} {in2}".format(in1=s1, in2=s2)
print('String Concatenation using format() =', s3)


# We can use % operator for string formatting, it can be used for string concatenation too. It’s useful when we want to concatenate strings and perform simple formatting.

print()
s1 = 'Hello'
s2 = 'World'

s3 = "%s %s" % (s1, s2)
print('String Concatenation using % Operator =', s3)

s3 = "%s %s from Me - %d" % (s1, s2, 2021)
print('String Concatenation using % Operator =', s3)

```

    String Concatenation using format() = Hello-World
    String Concatenation using format() = Hello World
    
    String Concatenation using % Operator = Hello World
    String Concatenation using % Operator = Hello World from Me - 2021
    

## Indexing a String

- accessing one character based on the position


```python
print(s[0])
print(s[1])
```

    H
    e
    


```python
# total number of character in a string
print(len(s))
```

    11
    


```python
# last element of string
print(s[len(s) -1])
```

    d
    

### Negative Indexing

- writting `len(str)` is optional
- That's how Python give rise to Negative Indexing


```python
print(s[-1]) # last character
print(s[-5]) # 5th last character
```

    d
    W
    

## Iterating through string


```python
print("hello" "World")
print("*" * 10)
```

    helloWorld
    **********
    


```python
print("Hell" in s)
print("Haven" in s)
```

    True
    False
    


```python
for e in "ABCD":
    print(e)

print()

# To get also indexes use enumerate()
for e in enumerate("ABCD"):
    print(e)

print()

for i,v in enumerate("ABCD"):
    print(f"{i+1} : {v}")
```

    A
    B
    C
    D
    
    (0, 'A')
    (1, 'B')
    (2, 'C')
    (3, 'D')
    
    1 : A
    2 : B
    3 : C
    4 : D
    

## Methods related to Strings

### Boolean String Methods
- `str.isupper()`: String’s alphabetic characters are all uppercase
- `str.islower()`: String’s alphabetic characters are all lower case
- `str.istitle()`: String is in title case
str.isspace(): String only consists of whitespace characters
- `str.isnumeric()`: String only contains numeric characters
- `str.isalnum()`: String contains only alphanumeric characters (no symbols)
- `str.isalpha()`: String contains only alphabetic characters (no numbers or symbols)



```python
# to lowercase:
s.lower()
```




    'hello world'




```python
# to uppercase:
s.upper()
```




    'HELLO WORLD'




```python
# Capital first char of each Word
s.title()
```




    'Hello World'



### Starts With and Ends With


```python
full_name = "Bill Jefferson"
print(full_name.startswith("Bill"))
full_name = "Bill Jefferson"
print(full_name.startswith("Bill", 3))
```

    True
    False
    

### find()

- `find(searchText, [starting_position, [ ending_position]])
`
- returns the first index of the world , -1 otherwise



```python
# define a string data
str = 'Learn Python programming'
# Search the position of the word 'python' from the starting
print(str.find('python'))  

# Search the string 'program' from the position 10
print(str.find('program', 10))

# Search the word 'earn' from 0 position and within next 5 characters  
print(str.find('earn', 0, 5))
```

    -1
    13
    1
    

### index()

- `string.index(search_text [, start [, end]])`

index() method works like find() method but there is a single difference between these methods. Both methods return the position of the search text if the string exists in the main string. If the search text does not exist in the main string then `find()` method returns  `-1` but `index()` method generates a `ValueError.`


```python
strVal = 'Python is a powerful programming language.'

# Apply index() method with different arfuments
try:
   
    print(strVal.index('powerful'))
    print(strVal.index('program',10))
    print(strVal.index('is', 5, 15))
    print(strVal.index('his', 0, 25))
# Catch value error and print the custom message
except ValueError:

    print("The search string is not found")
```

    12
    21
    7
    The search string is not found
    

### replace()

- `string.replace(search_string, replace_string [,counter])`



```python
# Define a string data
str = "I like PHP but I like Python more"

replace_str1 = str.replace("PHP", "Java")
print("Original string:", str)
print("Replaced string:", replace_str1)

replace_str2 = str.replace("like", "dislike",1)
print("\nOriginal string:",str)
print("Replaced string:",replace_str2)
```

    Original string: I like PHP but I like Python more
    Replaced string: I like Java but I like Python more
    
    Original string: I like PHP but I like Python more
    Replaced string: I dislike PHP but I like Python more
    

### Split and Join Strings


```python
print("x".join(["A", "B","C"]))
print("".join(["A", "B","C"]))
```

    AexBexC
    ABC
    

What has happened is the join() string has gone through each letter in the string variable and added an X after each letter.


```python
# Apply join on string data
print('Joining each character with comma:', ','.join('python'))
# Apply join on list of strings
print('Joining list of strings with space:', ' '.join(['I','like', 'programming']))
# Apply join on tuple of strings
print('Joining tuple of strings with colon:', ':'.join(('011156432','Mehnaz', '10','45')))
```

    Joining each character with comma: p,y,t,h,o,n
    Joining list of strings with space: I like programming
    Joining tuple of strings with colon: 011156432:Mehnaz:10:45
    


```python
s= "Hello, World"
r=s.split(" ")
print(r)
s= "Hello, World"
r=s.split(", ")
print(r)
```

    ['Hello,', 'World']
    ['Hello', 'World']
    

### strip() 

- `strip()` method is used to remove white spaces from both sides of a string. 
- This method does not take any argument.

There are two related methods for removing white spaces. 

- `lstrip()` method to remove the white space from the left side 
- `rstrip()` method to remove the white space from the right side of the string. 


```python
strVal = "      Welcome to Py     "

# Print output before and after strip
print("The output before strip():", strVal)
print("The output after strip():", strVal.strip(),"(Added to check)")
```

    The output before strip():       Welcome to Py     
    The output after strip(): Welcome to Py (Added to check)
    

## Substring 

- We can create a substring using `string slicing`. 
- We can use `split()` function to create a `list of substring`s based on specified `delimiter`.

```python
s = 'My Name is Jhon'

# create substring using slice
name = s[11:]
print(name) #Jhon

# list of substrings using split
l1 = s.split()
print(l1) # ['My', 'Name', 'is', 'Jhon']
```

### string slicing
- extracting multiple characters from a string(sub string)
- Syntax: `str[start_idx : end_idx + 1]`

> NOTE: **slice is exclusive**


```python
s = "Hello World"
print(s[:2]) 
print(s[0:2])
```

    He
    He
    


```python
print(s[2:]) 
print(s[:]) 
print(s[:2]+s[2:]) 
```

    llo World
    Hello World
    Hello World
    

#### Slicing with Negative index


```python
print(s[:-2]) # all char exept last 2
print(s[-1])
print(s[-6:])
print(s[-6:-1]) # left to right
```

    Hello Wor
    d
     World
     Worl
    

#### Using a Step in a Slice


```python
print(s[::1])
print(s[::2])
print(s[1:10:2])
```

#### Slicing Backwards


```python
print(s[::-1])   # in reverse order
print(s[:-4:-1]) # last 3 char, in reverse order.
print(s[::-2])
```

    dlroW olleH
    dlr
    drWolH
    

### Checking if substring is found


```python

s = 'My Name is Jhon'

if 'Name' in s:
    print('Substring found')

if s.find('Name') != -1:
    print('Substring found')
```

    Substring found
    Substring found
    

### Count of Substring Occurrence

-We can use count() function to find the number of occurrences of a substring in the string.


```python
s = 'My Name is Jhon'

print('Substring count =', s.count('a'))

s = 'This Is The Best Theorem'
print('Substring count =', s.count('Th'))
```

    Substring count = 1
    Substring count = 3
    

### Find all indexes of substring


```python
def find_all_indexes(input_str, substring):
    l2 = []
    length = len(input_str)
    index = 0
    while index < length:
        i = input_str.find(substring, index)
        if i == -1:
            return l2
        l2.append(i)
        index = i + 1
    return l2


s = 'This Is The Best Theorem'
print(find_all_indexes(s, 'Th'))
```

    [0, 8, 17]
    

## Reverse a String

### Python Reverse String using Slicing


```python

def reverse_slicing(s):
    return s[::-1]

input_str = 'ABç∂EF'
print('Reverse String using slicing =', reverse_slicing(input_str))


def reverse_recursion(s):
    if len(s) == 0:
        return s
    else:
        return reverse_recursion(s[1:]) + s[0]
print('Reverse String using recursion =', reverse_recursion(input_str))

```

    Reverse String using slicing = FE∂çBA
    Reverse String using recursion = FE∂çBA
    

### for loop


```python
def reverse_for_loop(s):
    s1 = ''
    for c in s:
        s1 = c + s1  # appending chars in reverse order
    return s1

input_str = 'ABç∂EF'
print('Reverse String using for loop =', reverse_for_loop(input_str))

```

    Reverse String using for loop = FE∂çBA
    

### list.reverse()


```python
def reverse_list(s):
    temp_list = list(s)
    temp_list.reverse()
    return ''.join(temp_list)
```

## String Replacement Fields and F-String


```python
name= "Soikat"
age=22
print("Myself {0}. My age is {1} years".format(name,age))
print()
#  Multiline String using triple quotes
print("""Myself {0}. 
My age is {1} years""".format(name,age))

# Literal String Interpolation
print(f"Myself {name}. My age is {age} years")

# Lambda expressions with f-strings
print()
x = -20.45
print(f'Lambda Example: {(lambda x: abs(x)) (x)}')
print(f'Lambda Square Example: {(lambda x: pow(x, 2)) (5)}')

print()
# f-strings miscellaneous examples

print(f'{"quoted string"}')
print(f'{{ {4*10} }}')
print(f'{{{4*10}}}')


```

    Myself Soikat. My age is 22 years
    
    Myself Soikat. 
    My age is 22 years
    Myself Soikat. My age is 22 years
    
    Lambda Example: 20.45
    Lambda Square Example: 25
    
    quoted string
    { 40 }
    {40}
    

## More on String Formatting


```python
#for i in range(1,10):
    print("No. {0} squared is {1} and cubed is {2}".format(i,i**2,i**3))
```

    No. 1 squared is 1 and cubed is 1
    No. 2 squared is 4 and cubed is 8
    No. 3 squared is 9 and cubed is 27
    No. 4 squared is 16 and cubed is 64
    No. 5 squared is 25 and cubed is 125
    No. 6 squared is 36 and cubed is 216
    No. 7 squared is 49 and cubed is 343
    No. 8 squared is 64 and cubed is 512
    No. 9 squared is 81 and cubed is 729
    


```python
for i in range(1,10):
    print("No. {0:2} squared is {1:4} and cubed is {2:4}".format(i,i**2,i**3))
```

    No.  1 squared is    1 and cubed is    1
    No.  2 squared is    4 and cubed is    8
    No.  3 squared is    9 and cubed is   27
    No.  4 squared is   16 and cubed is   64
    No.  5 squared is   25 and cubed is  125
    No.  6 squared is   36 and cubed is  216
    No.  7 squared is   49 and cubed is  343
    No.  8 squared is   64 and cubed is  512
    No.  9 squared is   81 and cubed is  729
    


```python
for i in range(1,10):
    print("No. {0:2} squared is {1:<4} and cubed is {2:<4}".format(i,i**2,i**3)) # left align
```

    No.  1 squared is 1    and cubed is 1   
    No.  2 squared is 4    and cubed is 8   
    No.  3 squared is 9    and cubed is 27  
    No.  4 squared is 16   and cubed is 64  
    No.  5 squared is 25   and cubed is 125 
    No.  6 squared is 36   and cubed is 216 
    No.  7 squared is 49   and cubed is 343 
    No.  8 squared is 64   and cubed is 512 
    No.  9 squared is 81   and cubed is 729 
    


```python
for i in range(1,10):
    print("No. {0:2} squared is {1:<4} and cubed is {2:^4}".format(i,i**2,i**3)) # center align
```

    No.  1 squared is 1    and cubed is  1  
    No.  2 squared is 4    and cubed is  8  
    No.  3 squared is 9    and cubed is  27 
    No.  4 squared is 16   and cubed is  64 
    No.  5 squared is 25   and cubed is 125 
    No.  6 squared is 36   and cubed is 216 
    No.  7 squared is 49   and cubed is 343 
    No.  8 squared is 64   and cubed is 512 
    No.  9 squared is 81   and cubed is 729 
    


```python
print("Pi is ~ {0}".format(22/7))
print("Pi is ~ {0:20f}".format(22/7))
print("Pi is ~ {0:<20f}".format(22/7))
print("Pi is ~ {0:<20.20f}".format(22/7))
```

    Pi is ~ 3.142857142857143
    Pi is ~             3.142857
    Pi is ~ 3.142857            
    Pi is ~ 3.14285714285714279370
    

## Raw String


```python
raw_s = r'Hi\nHello'
print(raw_s)
raw_s = r'\''
print(raw_s)

raw_s = r'ab\\'
print(raw_s)

raw_s = R'\\\"'  # prefix can be 'R' or 'r'
print(raw_s)
```

    Hi\nHello
    \'
    ab\\
    \\\"
    

## String Conversion

## Few Operations on Strings


```python
"abc" + "pqr"
```




    'abcpqr'




```python
# cannnot concatenate other data type
"abc" + 1
```


    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    <ipython-input-34-67b336e1625b> in <module>
          1 # cannnot concatenate other data type
    ----> 2 "abc" + 1
    

    TypeError: can only concatenate str (not "int") to str



```python
# type conversion is the way
"abc " + str(1)

# Note: TypeError: 'str' object is not callable (Python)

# You can get this error if you have variable `str` and trying to call `str() function.

# Resolve with: `del str` 

```




    'abc 1'




```python
"*"*5
```




    '*****'



## String Module


```python

import string

# string module constants
print(string.ascii_letters)
print(string.ascii_lowercase)
print(string.ascii_uppercase)
print(string.digits)
print(string.hexdigits)
print(string.whitespace)  # ' \t\n\r\x0b\x0c'
print(string.punctuation)
```

    abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
    abcdefghijklmnopqrstuvwxyz
    ABCDEFGHIJKLMNOPQRSTUVWXYZ
    0123456789
    0123456789abcdefABCDEF
     	
    
    !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
    

## Python Generate Random String

Let’s define the utility function to generate a random string from the given sequence of characters and specified size.


```python

import random
import string

def generate(str_size, allowed_chars):
    return ''.join(random.choice(allowed_chars) for x in range(str_size))

chars = string.ascii_letters + string.punctuation
print(chars)

size = 12
print('Random String of length 12 =', generate(size, chars))
```

    abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
    Random String of length 12 = }.]~Hpem%^_:
    

We are using `random.choice()` function to select a random character from the provided sequence of characters. Then we are using for loop to run it given number of times. Then we are using string join() function to concatenate them and return the randomly generated string.

What if we want to keep the random string size as variable, say between 8 and 12 characters. Let’s tweak our function little bit to randomly select the size of the random string.


```python

import random
from random import randint
import string

def random_string_generator_variable_size(min_size, max_size, allowed_chars):
    return ''.join(random.choice(allowed_chars) for x in range(randint(min_size, max_size)))


chars = string.ascii_letters + string.punctuation
print('Random String of random length (6-12) =', random_string_generator_variable_size(6, 12, chars))

```

    Random String of random length (6-12) = ,GBJOn}gI:
    

### Random UUID Generation

If you want a Unique ID based on RFC-4122 specifications, then you can use Python uuid module.


```python

import uuid

print('Random UUID from uuid1() =', uuid.uuid1())
print('Random UUID from uuid4() =', uuid.uuid4())
```

    Random UUID from uuid1() = 702ea43f-db64-11eb-97e3-cea4caa3e803
    Random UUID from uuid4() = c33e26c0-ad16-416f-8777-422134629fa9
    
