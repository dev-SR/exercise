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
```

    None
    


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
```

    name  :  Soikat
    age  :  69
    hobby  :  ['Gamming', 'Coding', 'Football']
    


```python
# delete key with value
deleted_value = user_info.pop('hobby')
print(deleted_value)
print(user_info)
```

    ['Gamming', 'Coding', 'Football']
    {'name': 'Soikat', 'age': 69}
    


```python
# update
user_info['name'] = "DevSR"
print(user_info)
```

    {'name': 'DevSR', 'age': 69}
    
