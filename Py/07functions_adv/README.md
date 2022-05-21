# Python Functions

- [Python Functions](#python-functions)
  - [Intro](#intro)
    - [Doc String](#doc-string)
    - [Returning multiple values in form of a tuple](#returning-multiple-values-in-form-of-a-tuple)
  - [Default Parameters](#default-parameters)
  - [Argument](#argument)
    - [Arbitrary arguments](#arbitrary-arguments)
    - [Keyword arguments (`**kwargs`)](#keyword-arguments-kwargs)
    - [🚀Unpacking Argument Lists](#unpacking-argument-lists)
  - [Scope and Life Time of Variables](#scope-and-life-time-of-variables)
  - [Lambda](#lambda)
  - [In-built Functions](#in-built-functions)
    - [math](#math)
    - [Aggregation Functions](#aggregation-functions)
    - [`all()` and `any()`](#all-and-any)
    - [`dir`](#dir)
    - [`enumerate()`](#enumerate)
    - [`map()`](#map)
    - [`filter()`](#filter)
    - [`reduce()`](#reduce)


```python
"""
cd .\Py\07functions_adv\
jupyter nbconvert --to markdown py_function.ipynb --output README.md
"""

```

## Intro

Syntax:
```py
    def function_name(parameters):

        """
        Doc String
        """
        Statement(s)
```

1. keyword "def" marks the start of function header

2. Parameters (arguments) through which we pass values to a function. These are optional

3. A colon(:) to mark the end of funciton header

4. Doc string describe what the function does. This is optional

5. "return" statement to return a value from the function. This is optional


```python
# funciton definition
def greeting(name):
    print("Good Morning ",name)
```


```python
print(greeting)
print(type(greeting))
```

    <function greeting at 0x000002298CFA0E50>
    <class 'function'>



```python
# function calling
greeting("Jhon")
```

    Good Morning  Jhon


### Doc String

The first string after the function header is called the docstring and is short for documentation string.
Although optional, documentation is a good programming practice, always document your code
Doc string will be written in triple quotes so that docstring can extend up to multiple lines


```python
def add(a,b):
    """
     this is doc string

     returns sum of 2 numbers
    """
    return(a+b)
```


```python
res = add(3,3)
print(res)
print(add.__doc__)  # print doc string of the function
```

    6

         this is doc string

         returns sum of 2 numbers




```python
def product(lst):
    """
        lst : it is list

        return : product of all elements in a list
    """
    s = 1
    for i in lst:
        s*=i
    return s
```


```python
res = product([1,2,3,4,5])
print(res)
```

    120


### Returning multiple values in form of a tuple


```python
def cal(a,b):
    return(a+b,a-b,a*b,a/b)


def cal2(a, b):
    return a+b, a-b, a*b, a/b

```


```python
res = cal(2,3)
print(res)
print(res[2])
print(type(res))

res = cal2(2, 3)
print(res)
print(res[2])
print(type(res))

```

    (5, -1, 6, 0.6666666666666666)
    6
    <class 'tuple'>
    (5, -1, 6, 0.6666666666666666)
    6
    <class 'tuple'>


## Default Parameters


```python
def intro(name,age=20):
    print("Hello",name)
    print("I'm ",age," years old.")
```


```python
intro("Soikat")
print()
intro("Soikat",69)
```

    Hello Soikat
    I'm  20  years old.

    Hello Soikat
    I'm  69  years old.


## Argument

### Arbitrary arguments

it can receive any number of arguments and store them in a `tuple`


```python
def args_func(*args):
    print(args)
    print(type(args))
    for i in args:
        print(i*2,end=" ")


args_func(1, 2, 3, 4,"Soikat",True)

```

    (1, 2, 3, 4, 'Soikat', True)
    <class 'tuple'>
    2 4 6 8 SoikatSoikat 2

### Keyword arguments (`**kwargs`)

- it also takes any number of arguments and store them in `dictionary`
- `parameter` name is mandatory while calling function


```python
def intro(**kwargs):
    print(kwargs)
    print(type(kwargs))

    for k,v in kwargs.items():
        print(k," : ",v)


intro(name="soikat", age=69, hobby=["cricket", "football"])

```

    {'name': 'soikat', 'age': 69, 'hobby': ['cricket', 'football']}
    <class 'dict'>
    name  :  soikat
    age  :  69
    hobby  :  ['cricket', 'football']



```python
def combined(a,b,age=20,*args,**kwargs):
	print(a,b,age)
	print(args)
	print(kwargs)

combined('a','b',22,1,2,3,x=10,y=20)
```

    a b 22
    (1, 2, 3)
    {'x': 10, 'y': 20}


### 🚀Unpacking Argument Lists

The reverse situation occurs when the arguments are already in a `list` or `tuple` but need to be unpacked for a function call requiring separate positional arguments. For instance, the built-in `range()` function expects separate start and stop arguments. If they are not available separately, write the function call with the `*-operator` to unpack the arguments out of a list or tuple:




```python
print(list(range(3, 6)))             # normal call with separate arguments)
args = [3, 6]
print(list(range(*args)))           # call with arguments unpacked from a list

```

    [3, 4, 5]
    [3, 4, 5]


In the same fashion, `dictionaries` can deliver keyword arguments with the `**-operator`:




```python
def info(name, country='Bangladesh', country_code='BD'):
	print(name, country, country_code)

info_dic = {
	'name': 'Soikat',
	'country': 'Germany',
	'country_code': 'DE'
}

info(**info_dic)
```

    Soikat Germany DE


## Scope and Life Time of Variables

- Scope of a variable is the portion of a program where the variable is recognized
- variables defined inside a function is not visible from outside. Hence, they have a local scope.
- Lifetime of a variable is the period throughout which the variable exits in the memory.
- The lifetime of variables inside a function is as long as the function executes.
- Variables are destroyed once we return from the function.


```python
global_var = "This is global variable"


def test_life_time():
    """
    This function test the life time of a variables
    """
    local_var = "This is local variable"
    print(local_var)  # print local variable local_var

    print(global_var)  # print global variable global_var


#calling function
test_life_time()

#print global variable global_var
print(global_var)

#print local variable local_var
print(local_var)

```

    This is local variable
    This is global variable
    This is global variable



    ---------------------------------------------------------------------------

    NameError                                 Traceback (most recent call last)

    <ipython-input-8-88f8916cf7d7> in <module>
         19
         20 #print local variable local_var
    ---> 21 print(local_var)


    NameError: name 'local_var' is not defined


## Lambda

In Python, anonymous function is a function that is defined without a name.

While normal functions are defined using the def keyword, in Python anonymous functions are defined using the lambda keyword.

Lambda functions are used extensively along with built-in functions like filter(), map()

**syntax:**
```py
    lambda arguments: expression
```



```python
# def add(a,b):
	# return a+b

add = lambda a,b : a+b
sub = (lambda a,b : a-b)
print(add(1,2))
print(sub(2,1))
```

    3
    1



```python
(lambda x,y : x+y if x+y>0 else 0)(5,-40)
```




    0




```python
func = (lambda x, y: x+y if x+y > 0 else 0)
func(5, 40)
```




    45




```python
names = [('B',5),('C',2),('A',6)]
sorted(names)
```




    [('A', 6), ('B', 5), ('C', 2)]




```python
sorted(names,key=lambda x:x[1])
```




    [('C', 2), ('B', 5), ('A', 6)]



## In-built Functions

 - `abs()`
 - `round()`
 - Aggregation functions: `sum(),max(),min()`
 - `all()` and `any()`
 - `enumerate()`
 - `filter()`
 - `map()`
 - `reduce()`

### math


```python
abs?
```

    [1;31mSignature:[0m [0mabs[0m[1;33m([0m[0mx[0m[1;33m,[0m [1;33m/[0m[1;33m)[0m[1;33m[0m[1;33m[0m[0m
    [1;31mDocstring:[0m Return the absolute value of the argument.
    [1;31mType:[0m      builtin_function_or_method



```python
abs(-1.2)
```




    1.2




```python
n = round(5.67876,2)
print(n)
round(5.67876333)
```

    5.68





    6



### Aggregation Functions


```python
l = [2,6,3,2,6,2]

sum(l)
```




    21




```python
max(l)
```




    6




```python
min(l)
```




    2



### `all()` and `any()`

- `all()`
  - `True`: if all elements in an iterable are true.
  - `False`: if any elements in an iterable is true.

- `any()`
  - `True`: if any one of the element in an iterable are true.
  - `False`: otherwise.


```python
lst = [1,2,3,4]
print(all(lst))
print()
tup = (0,1,2,3) # 0 is present
print(all(tup))
print()
lst = []
print(all(lst)) # no el that is false
```

    True

    False

    True



```python
lst = [1,2,3,4]
print(any(lst))
print()
tup = (0,1,2,3) # 0 is present
print(any(tup))
print()
lst = []
print(any(lst)) # no el that is true
```

    True

    True

    False


### `dir`

- displays all the functions associated with an object


```python
lst = [1,2,3]
dir(lst)
print()
# ['__add__',
#  '__class__',
#  '__contains__',
#  .............
# 'append',
# 'clear',
# 'copy',
# 'count',
# 'extend',
# 'index',
# 'insert',
# 'pop',
# 'remove',
# 'reverse',
# 'sort']

```




### `enumerate()`

- adds a counter to an iterable and returns it in a form of enumerate object.


```python
f = ['apple','mango','banana','grapes']

for idx,el in enumerate(f):
	print(idx,el)
```

    0 apple
    1 mango
    2 banana
    3 grapes


### `map()`

- Map applies a function to all the items of an iterable


```python
l = [1, 2, 3, 4, 5]

new_l = []
for el in l:
	new_l.append(el+1)

print(new_l)
```

    [2, 3, 4, 5, 6]



```python
l =[1,2,3,4,5]
def add_one(x):
    return x+1;
new_l = map(add_one,l)
print(new_l)
print(list(new_l))
```

    <map object at 0x000002298D65F7F0>
    [2, 3, 4, 5, 6]



```python
m = map(lambda x : x+1,l)
list(m)
```




    [2, 3, 4, 5, 6]



### `filter()`

- The filter() method construct an iterator from elements of an iterable for which a function returns true.


```python
l = [1,2,3,4,5,6]
new_l = []
for el in l:
    if el%2 == 0:
        new_l.append(el)
new_l


```




    [2, 4, 6]




```python
l = [1,2,3,4,5,6]

# filter even elements
def is_even(x):
    return x%2==0;

filtered_el = filter(is_even,l)
print(filtered_el)
print(list(filtered_el))
```

    <filter object at 0x000002298D323E50>
    [2, 4, 6]



```python
list(filter(lambda x:x%2==0,l))
```




    [2, 4, 6]



### `reduce()`

- perform some computation on a list and returns the result.
- It applies a rolling computation to a sequential pairs of a values in a list.


```python
# product of elements in a list
lst = [1,2,3,4,5]

product = 1
for num in lst:
	product *= num

print(product)
```

    120


```
[ 1, 2, 3, 4, 5]
  [ 2, 3, 4, 5]
    [ 6, 4, 5]
      [ 24, 5]
        120
```


```python
from functools import reduce

def mul(x,y):
	return x*y

product = reduce(mul,lst)
product
```




    120




```python
product_lst = reduce(lambda x, y: x*y, lst)
product_lst
```




    120


