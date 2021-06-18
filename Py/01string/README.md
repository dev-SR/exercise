```python
s = "Hello World"
print(s);
print(type(s))
```

    Hello World
    <class 'str'>
    

# Indexing a String

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
    

## Negative Indexing

- writting `len(str)` is optional
- That's how Python give rise to Negative Indexing


```python
print(s[-1]) # last character
print(s[-5]) # 5th last character
```

    d
    W
    

# String Slicing

- extracting multiple characters from a string(sub string)
- Syntax: `str[start_idx : end_idx + 1]`

> NOTE: **slice is exclusive**


```python
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
    

**Slicing with Negative Numbers**


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
    

### Using a Step in a Slice


```python
print(s[::1])
print(s[::2])
print(s[1:10:2])
```

    Hello World
    HloWrd
    el ol
    

### Slicing Backwards


```python
print(s[::-1])   # in reverse order
print(s[:-4:-1]) # last 3 char, in reverse order.
print(s[::-2])
```

    dlroW olleH
    dlr
    drWolH
    

# Iterating through string


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
    

# Methods related to Strings


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




```python
# returns the first index of the world , -1 otherwise

s.find("llo")
```




    2




```python
s.split(" ")
```




    ['Hello', 'World']




```python

```

# String Replacement Fields and F-String


```python
name= "Soikat"
age=22
print("Myself {0}. My age is {1} years".format(name,age))
print(f"Myself {name}. My age is {age} years")
print("""Myself {0}. 
My age is {1} years""".format(name,age))
```

    Myself Soikat. My age is 22 years
    Myself Soikat. My age is 22 years
    Myself Soikat. 
    My age is 22 years
    

# String Formatting


```python
for i in range(1,10):
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
    

# Few Operations on Strings


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




```python

```
