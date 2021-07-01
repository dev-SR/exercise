# Dictionary

- stores data in key-value pair
- unordered 
- unindexable
- access the values, with help of keys



```python
user_info = {
    "name": "Soikat",
    "age":69,
}
print(user_info)
type(user_info)
```

    {'name': 'Soikat', 'age': 69}
    




    dict




```python
# accessing elements
print(user_info['name'])
print(user_info['age'])
```

    Soikat
    69
    


```python
# unkown key gives error
print(user_info['loves'])
```


    ---------------------------------------------------------------------------

    KeyError                                  Traceback (most recent call last)

    <ipython-input-6-af324ebbdb71> in <module>
          1 # unkown key gives error
    ----> 2 print(user_info['loves'])
    

    KeyError: 'loves'



```python
# no error with .get()
user_info.get('loves')
u = user_info.get('loves')
print(u)

u = user_info.get('loves','default_value')
print(u)
```

    None
    default_value
    


```python
# add data into dict
user_info['hobby'] = ['Gamming','Coding','Football']
print(user_info) 
```

    {'name': 'Soikat', 'age': 69, 'hobby': ['Gamming', 'Coding', 'Football']}
    


```python
# displays all keys
user_info.keys()
```




    dict_keys(['name', 'age', 'hobby'])




```python
# displays all values
user_info.values()
```




    dict_values(['Soikat', 69, ['Gamming', 'Coding', 'Football']])




```python
# displays (key,value) pair in tuples
user_info.items()
```




    dict_items([('name', 'Soikat'), ('age', 69), ('hobby', ['Gamming', 'Coding', 'Football'])])




```python
# iterate
for k,v in user_info.items():
    print(k," : ",v)

print()

for k in user_info:
    print(k," : ",user_info[k])
```

    name  :  Soikat
    age  :  69
    hobby  :  ['Gamming', 'Coding', 'Football']
    
    name  :  Soikat
    age  :  69
    hobby  :  ['Gamming', 'Coding', 'Football']
    


```python
# delete key with value
deleted_value = user_info.pop('hobby')
print(deleted_value)
print(user_info)

del user_info["age"]
print(user_info)
```

    ['Gamming', 'Coding', 'Football']
    {'name': 'Soikat', 'age': 69}
    {'name': 'Soikat'}
    


```python
# update
user_info['name'] = "DevSR"
print(user_info)
```

    {'name': 'DevSR'}
    

## Dictionary Comprehensions


```python
values = []
for x in range(5):
    values.append(x*2)
print(values)

# using list comprehensions:
values = [x*2 for x in range(4)]
print(values)

print()

# dict comprehensions:
# values = {}
# for x in range(5):
#     values[x] = x*2
values = {x: x*2 for x in range(4)}
print(values)
```

    [0, 2, 4, 6, 8]
    [0, 2, 4, 6]
    
    {0: 0, 1: 2, 2: 4, 3: 6}
    

## Unpacking Operator

`**` is used for dictionaries ...



```python
## Unpaking Operator
num_dict = {'a': 1, 'b': 2, 'c': 3}
print(*num_dict) # keys
print()


new_dict = {**num_dict}
print(new_dict)
print()

f= {"x":1}
sec ={ "x":10,"y":2}
comb={**f,**sec}
print(comb) # last 'x' is used
```

    a b c
    
    {'a': 1, 'b': 2, 'c': 3}
    
    {'x': 10, 'y': 2}
    


```python

# A Python program to demonstrate packing of
# dictionary items using **
def fun(**kwargs):
 
    # kwargs is a dict
    print(type(kwargs))
 
    # Printing dictionary items
    for key in kwargs:
        print("%s = %s" % (key, kwargs[key]))
 
# Driver code
fun(name="Apple", ID="101", language="Python")
```

    <class 'dict'>
    name = Apple
    ID = 101
    language = Python
    
