# Dictionary

- stores data in key-value pair
- unordered
- unindexable
- access the values, with help of keys

- [Dictionary](#dictionary)
  - [Accessing elements](#accessing-elements)
    - [use `dic.get()` to avoid error](#use-dicget-to-avoid-error)
  - [Dictionary Functions](#dictionary-functions)
  - [Iterate](#iterate)
  - [Add/Modify data in dictionary](#addmodify-data-in-dictionary)
  - [Delete element](#delete-element)
  - [Nested Dictionary](#nested-dictionary)
  - [Dictionary Comprehensions](#dictionary-comprehensions)
  - [Unpacking Operator](#unpacking-operator)

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



## Accessing elements


```python
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


### use `dic.get()` to avoid error


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


## Dictionary Functions


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



## Iterate


```python
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


## Add/Modify data in dictionary


```python
# add data into dict

user_info['hobby'] = ['Gamming', 'Coding', 'Football']

print(user_info)

# modifying the element

user_info['name'] = 'unknown'

print(user_info)
```

    {'name': 'Soikat', 'age': 69, 'hobby': ['Gamming', 'Coding', 'Football']}
    {'name': 'unknown', 'age': 69, 'hobby': ['Gamming', 'Coding', 'Football']}


## Delete element


```python
deleted_value = user_info.pop('hobby')

print(deleted_value)

print(user_info)



del user_info["age"]

print(user_info)
```

    ['Gamming', 'Coding', 'Football']
    {'name': 'unknown', 'age': 69}
    {'name': 'unknown'}



```python
# if key in no present

user_info.pop('nationality')
```


    ---------------------------------------------------------------------------

    KeyError                                  Traceback (most recent call last)

    <ipython-input-10-eac004c78ec1> in <module>
          1 # if key in no present
    ----> 2 user_info.pop('nationality')


    KeyError: 'nationality'


## Nested Dictionary


```python
canteen_menu={

	'samosa':10,

	'pizza':200,

	'burger':50,

	'fruits':{

		"mango":25,

		'apple':25,

		"grapes":30

	}

}

print(canteen_menu)

print(canteen_menu['fruits'])

print()

print(canteen_menu['fruits']['mango'])
```

    {'samosa': 10, 'pizza': 200, 'burger': 50, 'fruits': {'mango': 25, 'apple': 25, 'grapes': 30}}
    {'mango': 25, 'apple': 25, 'grapes': 30}

    25



```python
canteen_menu['juice'] = [25, 40, 50]

canteen_menu
```




    {'samosa': 10,
     'pizza': 200,
     'burger': 50,
     'fruits': {'mango': 25, 'apple': 25, 'grapes': 30},
     'juice': [25, 40, 50]}




```python
canteen_menu['fruits'][-1]
```


    ---------------------------------------------------------------------------

    KeyError                                  Traceback (most recent call last)

    <ipython-input-23-609ce31324f6> in <module>
    ----> 1 canteen_menu['fruits'][-1]


    KeyError: -1



```python
canteen_menu['juice'][-1]
```




    50



## Dictionary Comprehensions


```python
values = []

for x in range(5):

    values.append(x*2)

print(values)



# generate `list` using list comprehensions:

values = [x*2 for x in range(4)]

print(values)



print()



# generate dict with  dict comprehensions:

# values = {}

# for x in range(5):

#     values[x] = x*2

values = {x: x*2 for x in range(4)}

print(values)



d= {

    "name":"Jhon",

    "pass":"pass",

    "id":191

}

values = [d[key] for key in d]

keys = [key for key in d]

keys_str = "-".join([key for key in d])



print(values)

print(keys)

print(keys_str)



print()

# Creating a new dictionary with only pairs where the value is larger than 2

d = {'a': 1, 'b': 2, 'c': 3, 'd': 4}

new_dict = {k:v for k, v in d.items() if v > 2}

print(new_dict)



# Operations on the key value pairs

d = {'a':1,'b':2,'c':3,'d':4,'e':5}

d = {k + 'c':v * 2 for k, v in d.items() if v > 2}

print(d)
```

    [0, 2, 4, 6, 8]
    [0, 2, 4, 6]

    {0: 0, 1: 2, 2: 4, 3: 6}
    ['Jhon', 'pass', 191]
    ['name', 'pass', 'id']
    name-pass-id

    {'c': 3, 'd': 4}
    {'cc': 6, 'dc': 8, 'ec': 10}


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

