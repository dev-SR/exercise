# Types Of Functions

1. Built-in Functions

2. User-defined Functions

- [Types Of Functions](#types-of-functions)
  - [Built-in Functions](#built-in-functions)
    - [1. abs()](#1-abs)
    - [2. all()](#2-all)
- [return value of all() function](#return-value-of-all-function)
    - [dir()](#dir)
    - [divmod()](#divmod)
    - [enumerate()](#enumerate)
    - [filter()](#filter)
    - [isinstance()](#isinstance)
    - [map()](#map)
    - [reduce()](#reduce)
  - [2. User-defined Functions](#2-user-defined-functions)
    - [Advantages](#advantages)
    - [Example](#example)
  - [Python program to make a simple calculator that can add, subtract, multiply and division](#python-program-to-make-a-simple-calculator-that-can-add-subtract-multiply-and-division)


## Built-in Functions

### 1. abs()

```py
# find the absolute value

num = -100

print(abs(num))

```

    100

### 2. all()

# return value of all() function

True: if all elements in an iterable are true

False: if any element in an iterable is false

```py
lst = [1, 2, 3, 4]
print(all(lst)) 

```

    True

```py
lst = (0, 2, 3, 4)    # 0 present in list 
print(all(lst))

```

    False

```py
lst = []              #empty list always true
print(all(lst))

```

    True

```py
lst = [False, 1, 2]   #False present in a list so all(lst) is False
print(all(lst))

```

    False

### dir()

The dir() tries to return a list of valid attributes of the object.

If the object has __dir__() method, the method will be called and must return the list of attributes.

If the object doesn't have __dir()__ method, this method tries to find information from the __dict__ attribute (if defined), and from type object. In this case, the list returned from dir() may not be complete.

```py
numbers = [1, 2, 3]

print(dir(numbers))

```

    ['__add__', '__class__', '__contains__', '__delattr__', '__delitem__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__getitem__', '__gt__', '__hash__', '__iadd__', '__imul__', '__init__', '__init_subclass__', '__iter__', '__le__', '__len__', '__lt__', '__mul__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__reversed__', '__rmul__', '__setattr__', '__setitem__', '__sizeof__', '__str__', '__subclasshook__', 'append', 'clear', 'copy', 'count', 'extend', 'index', 'insert', 'pop', 'remove', 'reverse', 'sort']

### divmod()

The divmod() method takes two numbers and returns a pair of numbers (a tuple) consisting of their quotient and remainder.

```py
print(divmod(9, 2)) #print quotient and remainder as a tuple

#try with other number

```

    (4, 1)

### enumerate()

The enumerate() method adds counter to an iterable and returns it

syntax: enumerate(iterable, start=0)

```py
numbers = [10, 20, 30, 40]

for index, num in enumerate(numbers,10):
    print("index {0} has value {1}".format(index, num))
    
```

    index 10 has value 10
    index 11 has value 20
    index 12 has value 30
    index 13 has value 40

### filter()

The filter() method constructs an iterator from elements of an iterable for which a function returns true.

syntax: filter(function, iterable)

```py
def find_positive_number(num):
    """
    This function returns the positive number if num is positive
    """
    if num > 0:
        return num
    
```

```py
number_list = range(-10, 10) #create a list with numbers from -10 to 10
print(list(number_list))

positive_num_lst = list(filter(find_positive_number, number_list))

print(positive_num_lst)

```

    [-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    [1, 2, 3, 4, 5, 6, 7, 8, 9]

### isinstance()

The isinstance() function checks if the object (first argument) is an instance or subclass of classinfo class (second argument).

syntax: isinstance(object, classinfo)

```py
lst = [1, 2, 3, 4]
print(isinstance(lst, list))

#try with other datatypes tuple, set
t = (1,2,3,4)
print(isinstance(t, list))
```

    True
    False

### map()

Map applies a function to all the items in an input_list.

syntax: map(function_to_apply, list_of_inputs)

```py
numbers = [1, 2, 3, 4]

#normal method of computing num^2 for each element in the list.
squared = []
for num in numbers:
    squared.append(num ** 2)

print(squared)

```

    [1, 4, 9, 16]

```py
numbers = [1, 2, 3, 4]

def powerOfTwo(num):
    return num ** 2

#using map() function
squared = list(map(powerOfTwo, numbers))
print(squared)

```

    [1, 4, 9, 16]

### reduce()

reduce() function is for performing some computation on a list and returning the result.

It applies a rolling computation to sequential pairs of values in a list.

```py
#product of elemnts in a list
product = 1
lst = [1, 2, 3, 4]

# traditional program without reduce()
for num in lst:
    product *= num
print(product)

```

    24

```py
#with reduce()
from functools import reduce # in Python 3.

def multiply(x,y):
    return x*y;

product = reduce(multiply, lst)
print(product)

```

    24

## 2. User-defined Functions

Functions that we define ourselves to do certain specific task are referred as user-defined functions

If we use functions written by others in the form of library, it can be termed as library functions.

### Advantages

1. User-defined functions help to decompose a large program into small segments which makes program easy to understand, maintain and debug.

2. If repeated code occurs in a program. Function can be used to include those codes and execute when needed by calling that function.

3. Programmars working on large project can divide the workload by making different functions.

### Example

```py
def product_numbers(a, b):
    """
    this function returns the product of two numbers
    """
    product = a * b
    return product

num1 = 10
num2 = 20
print "product of {0} and {1} is {2} ".format(num1, num2, product_numbers(num1, num2))
```

    product of 10 and 20 is 200 

## Python program to make a simple calculator that can add, subtract, multiply and division

```py
def add(a, b):
    """
    This function adds two numbers
    """
    return a + b

def multiply(a, b):
    """
    This function multiply two numbers
    """
    return a * b

def subtract(a, b):
    """
    This function subtract two numbers
    """
    return a - b

def division(a, b):
    """
    This function divides two numbers
    """
    return a / b

print("Select Option")
print("1. Addition")
print ("2. Subtraction")
print ("3. Multiplication")
print ("4. Division")

#take input from user
choice = int(input("Enter choice 1/2/3/4"))

num1 = float(input("Enter first number:"))
num2 = float(input("Enter second number:"))
if choice == 1:
    print("Addition of {0} and {1} is {2}".format(num1, num2, add(num1, num2)))
elif choice == 2:
    print("Subtraction of {0} and {1} is {2}".format(num1, num2, subtract(num1, num2)))
elif choice == 3:
    print("Multiplication of {0} and {1} is {2}".format(num1, num2, multiply(num1, num2)))
elif choice == 4:
    print("Division of {0} and {1} is {2}".format(num1, num2, division(num1, num2)))
else:
    print("Invalid Choice")
```

    Select Option
    1. Addition
    2. Subtraction
    3. Multiplication
    4. Division
    Enter choice 1/2/3/43
    Enter first number:12.2
    Enter second number:2.3
    Multiplication of 12.2 and 2.3 is 28.059999999999995

```

```
