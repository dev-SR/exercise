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
```

    6
    


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
    

#### Note: Function can return multiple values in form of a tuple


```python
def cal(a,b):
    return(a+b,a-b,a*b,a/b)
```


```python
res = cal(2,3)
print(res)
print(res[2])
print(type(res))
```

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
    

## args and kargs

**arbitary arguments :** it can receive, any number of arguments


```python
def random_func(*args):
    print(args)
    print(type(args))
    for i in args:
        print(i**2,end=" ")
```


```python
random_func(1,2,3,4,5,1)
```

    (1, 2, 3, 4, 5, 1)
    <class 'tuple'>
    1 4 9 16 25 1 

**keyword arguments :** it also takes any number of arguments and stroe them in dictionary
- `parameter` name is manadatory while calling funciton


```python
def intro(**kargs):
    print(kargs)
    print(type(kargs))
    
    for k,v in kargs.items():
        print(k," : ",v)
```


```python
intro(name="soikat",age=69,hoby=["cricket","football"])
```

    {'name': 'soikat', 'age': 69, 'hoby': ['cricket', 'football']}
    <class 'dict'>
    name  :  soikat
    age  :  69
    hoby  :  ['cricket', 'football']
    

# In-built Funtions

 - `abs()`
 - `round()`
 - `abs()`
 - Aggregation funtions: `abs()`
 - `filter()`
 - `map()`


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



**`map()`**


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
    

**`filter()`**


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

```
