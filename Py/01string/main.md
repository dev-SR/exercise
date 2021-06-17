```python
#      012345678910
str = "Hello World"
```

# SLICE

### slice is exclusive


```python
print(str[:2]) 
print(str[0:2])
```

    He
    He
    


```python
print(str[2:]) 
print(str[:]) 
print(str[:2]+str[2:]) 
```

    llo World
    Hello World
    Hello World
    

### Slicing with Negative Numbers


```python
print(str[-1])
print(str[-6:])
print(str[-6:-1]) # left to right
```

    d
     World
     Worl
    

### Using a Step in a Slice


```python
print(str[::1])
print(str[::2])
print(str[1:10:2])
```

    Hello World
    HloWrd
    el ol
    

### Slicing Backwards


```python
print(str[::-1])   # in reverse order
print(str[:-4:-1]) # last 3 char, in reverse order.
print(str[::-2])
```

    dlroW olleH
    dlr
    drWolH
    

# STRING Operators


```python
print("hello" "World")
print("*" * 10)
```

    helloWorld
    **********
    


```python
print("Hell" in str)
print("Haven" in str)
```

    True
    False
    


```python
for e in enumerate("ABCD"):
    print(e)

print()

for i,v in enumerate("ABCD"):
    print(f"{i+1} : {v}")
```

    (0, 'A')
    (1, 'B')
    (2, 'C')
    (3, 'D')
    
    1 : A
    2 : B
    3 : C
    4 : D
    

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
    


```python

```
