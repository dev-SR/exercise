# Play with Pythons

- [Play with Pythons](#play-with-pythons)
  - [Functions](#functions)
    - [🚀Unpacking Argument Lists and Keyword Arguments](#unpacking-argument-lists-and-keyword-arguments)
    - [🚀🚀Using Unpacking Argument Lists and Keyword Arguments to build 📢Callbacks📢](#using-unpacking-argument-lists-and-keyword-arguments-to-build-callbacks)
  - [DSA](#dsa)
    - [Merging Dictionaries](#merging-dictionaries)
    - [Exclude Dictionary Keys](#exclude-dictionary-keys)
    - [find elements in one list that are `not in` the other : `subtraction`](#find-elements-in-one-list-that-are-not-in-the-other--subtraction)
    - [find elements in one list that are `in` the other : `intersection`](#find-elements-in-one-list-that-are-in-the-other--intersection)
    - [check if a list contains any item from another list python](#check-if-a-list-contains-any-item-from-another-list-python)
    - [check if an item is a subset of another list](#check-if-an-item-is-a-subset-of-another-list)
    - [List of Dictionaries](#list-of-dictionaries)
      - [find the index of a value in a list of dictionaries](#find-the-index-of-a-value-in-a-list-of-dictionaries)
      - [list of dictionaries search](#list-of-dictionaries-search)
        - [Check if element/dictionary already exists within list of dictionaries?](#check-if-elementdictionary-already-exists-within-list-of-dictionaries)
      - [add key for each dictionary in a list of dictionaries](#add-key-for-each-dictionary-in-a-list-of-dictionaries)

```python
"""
cd .\Py\15tips_n_trics\
jupyter nbconvert --to markdown tt.ipynb --output README.md
"""

```

## Functions

### 🚀Unpacking Argument Lists and Keyword Arguments

The reverse situation occurs when the arguments are already in a `list` or `tuple` but need to be unpacked for a function call requiring separate positional arguments. For instance, the built-in `range()` function expects separate start and stop arguments. If they are not available separately, write the function call with the `*-operator` to unpack the arguments out of a list or tuple:




```python
def multipleParam(*param):
	print(param)


multipleParam(1, 2)
args= [1, 2, 3]
multipleParam(*args)

```

    (1, 2)
    (1, 2, 3)


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


### 🚀🚀Using Unpacking Argument Lists and Keyword Arguments to build 📢Callbacks📢

Using Unpacking Argument Lists: pass list/tuple as positional arguments to a callback function:


```python
def fun(a, b):
	return a + b
def fun2(a, b,c):
	return a + b+c
# takes n arguments as n size List/Tuple
def withListOrTupleAsParam(cb, param):
	print(param)
	return cb(*param)


print(withListOrTupleAsParam(fun, [1, 2]))
print(withListOrTupleAsParam(fun, (1, 2)))
print(withListOrTupleAsParam(fun2, [1, 2,3]))
```

    [1, 2]
    3
    (1, 2)
    3
    [1, 2, 3]
    6


Using Unpacking Keyword Arguments: pass dictionary as keyword arguments to a callback function:


```python
def fun(a,b = 0, c = 0):
	return a + b + c

def withDictAsParam(cb, param):
    return cb(**param)


print(withDictAsParam(fun, {'a': 1, 'b': 2}))
print(withDictAsParam(fun, {'a': 1, 'b': 2, 'c': 3}))
print(withDictAsParam(fun, {'a': 1}))

```

    3
    6
    1


With class methods


```python
class Tester:
    def __init__(self):
        pass

    def fun(self,a, b):
        return a + b

t = Tester()
withListOrTupleAsParam(t.fun,[1,2])

```

Example:


```python
from time import sleep
from rich.console import Console
console = Console()

def withLoaderWithParam(cb, param, message="", spinner='aesthetic'):
    done = False
    returns = None
    with console.status(f"[bold yellow] {message}...", spinner=spinner) as s:
        while not done:
            returns = cb(*param)
            done = True
    return returns


withLoaderWithParam(sleep, [5], message="Sleeping for 5 seconds", spinner='dots')

```

## DSA

### Merging Dictionaries


```python
def merge_dicts(*dict_args):
    result = {}
    for dictionary in dict_args:
        result.update(dictionary)
    return result

merge_dicts({1:2}, {3:4})
```




    {1: 2, 3: 4}



### Exclude Dictionary Keys


```python
def exclude_dict_keys(d, keys):
    return {k: v for k, v in d.items() if k not in keys}


exclude_dict_keys({1: 2, 3: 4}, [1])

```




    {3: 4}



### find elements in one list that are `not in` the other : `subtraction`

- [https://stackoverflow.com/questions/41125909/python-find-elements-in-one-list-that-are-not-in-the-other](https://stackoverflow.com/questions/41125909/python-find-elements-in-one-list-that-are-not-in-the-other)


```python
base_list = [0, 1, 2, 3, 4, 5, 6, 7, 8]
checking_list = [1, 3, 5]
```

Native: `O(n^2)` solution:


```python
elements_not_in_checking_list = []
for elem in base_list:
	if elem not in checking_list:
		elements_not_in_checking_list.append(elem)
elements_not_in_checking_list
```


    [0, 2, 4, 6, 7, 8]



```python
[x for x in base_list if x not in checking_list]
```


    [0, 2, 4, 6, 7, 8]


Like mentioned in the comments below, with large lists, the above is not the ideal solution. When that's the case, a better option would be converting `checking_list` to a `set` first:


```python
checking_set = set(checking_list)  # this reduces the lookup time from O(n) to O(1)
[item for item in base_list if item not in checking_set]

```


    [0, 2, 4, 6, 7, 8]


Native: `O(n)` two pointer solution:


```python
j = 0
i = 0
elements_not_in_checking_list = []
while i < len(base_list):
    if j < len(checking_list) and base_list[i] == checking_list[j]:
        i += 1
        j += 1
    else:
        elements_not_in_checking_list.append(base_list[i])
        i += 1
elements_not_in_checking_list

```


    [0, 2, 4, 6, 7, 8]


🧠🧠🧠Shortcut: using `set`🧠🧠🧠


```python
list(set(base_list) - set(checking_list))

```


    [0, 2, 4, 6, 7, 8]



```python
[b for a, b in zip(base_list, checking_list) if a != b]

```


    [1, 3, 5]


Shortcut: using `np.setdiff1d


```python
import numpy as np
main_list = np.setdiff1d(base_list, checking_list)
main_list
```


    array([0, 2, 4, 6, 7, 8])


### find elements in one list that are `in` the other : `intersection`


```python
base_list = [0, 1, 2, 3, 4, 5, 6, 7, 8]
checking_list = [1, 3, 10, 12, 5]

```


```python
checking_set = set(checking_list)  # this reduces the lookup time from O(n) to O(1)
[item for item in base_list if item in checking_set]
```


    [1, 3, 5]



```python
list(set(base_list) & set(checking_list))

```


    [1, 3, 5]


### check if a list contains any item from another list python



```python
base_list = [0, 1, 2, 3, 4, 5, 6, 7, 8]
checking_list = [1, 3, 10, 12, 5]

```


```python
check = any(item in base_list for item in checking_list)
print(check)

```

    True



```python
check = all(item in base_list for item in checking_list)
print(check) #checking_list = [1, 3, 10, 12, 5]


```

    False



```python
set_A = set(base_list)
set_B = set(checking_list)
output = False if (set_A.intersection(set_B) == set()) else True
print(output)

```

    True


### check if an item is a subset of another list


```python
L = [[2, 4, 6, 8, 10], [1, 3, 5, 7, 9], [4, 8, 12, 16, 20]]
search_item = 16
if search_item in (item for sublist in L for item in sublist):
   print("Element is Present")
else:
   print("Element Not Present")

```

    Element is Present



```python
[item for sublist in L for item in sublist]

```


    [2, 4, 6, 8, 10, 1, 3, 5, 7, 9, 4, 8, 12, 16, 20]


### List of Dictionaries

#### find the index of a value in a list of dictionaries


```python
# find the index of a value in a list of dictionaries
L = [ {'name': 'John', 'age': 23}, {'name': 'Jane', 'age': 21}, {'name': 'Joe', 'age': 25} ]
for i, d in enumerate(L):
	if d['name'] == 'Jane':
		print(i)
		break
```

    1


#### list of dictionaries search



```python
l = [{'uuid': 1, 'p': "a"}, {'uuid': 2, "p": "b"}]
[ d for d in l if d['uuid'] == 1 ]
```




    [{'uuid': 1, 'p': 'a'}]




```python
list(filter(lambda d: d['p'] == 'a', l))
```




    [{'uuid': 1, 'p': 'a'}]




```python
l = [{'uuid': 1, 'p': "a"}, {'uuid': 2, "p": "b"}]
[ d['p'] for d in l if d['uuid'] == 1 ]
```




    ['a']




```python
l = [{'uuid': 1, 'p': "a"}, {'uuid': 2, "p": "b"}]
[{**d,"found":True} for d in l if d['uuid'] == 1]

```




    [{'uuid': 1, 'p': 'a', 'found': True}]




```python
def dsearch(lod, **kw):
    return filter(lambda i: all((i[k] == v for (k, v) in kw.items())), lod)


lod = [{'a': 33, 'b': 'test2', 'c': 'a.ing333'},
       {'a': 22, 'b': 'ihaha', 'c': 'fbgval'},
       {'a': 33, 'b': 'TEst1', 'c': 's.ing123'},
       {'a': 22, 'b': 'ihaha', 'c': 'dfdvbfjkv'}]


list(dsearch(lod, a=22)), list(dsearch(lod, a=22, b='ihaha')), list(
    dsearch(lod, a=22, c='fbgval'))

```




    ([{'a': 22, 'b': 'ihaha', 'c': 'fbgval'},
      {'a': 22, 'b': 'ihaha', 'c': 'dfdvbfjkv'}],
     [{'a': 22, 'b': 'ihaha', 'c': 'fbgval'},
      {'a': 22, 'b': 'ihaha', 'c': 'dfdvbfjkv'}],
     [{'a': 22, 'b': 'ihaha', 'c': 'fbgval'}])



##### Check if element/dictionary already exists within list of dictionaries?



```python
d = {'main_color': 'red', 'second_color': 'blue'}
a = [d,
     {'main_color': 'yellow', 'second_color': 'green'},
     {'main_color': 'yellow', 'second_color': 'blue'}]

a
```




    [{'main_color': 'red', 'second_color': 'blue'},
     {'main_color': 'yellow', 'second_color': 'green'},
     {'main_color': 'yellow', 'second_color': 'blue'}]




```python
if d in a:
	print("Found")
```

    Found



```python
list(filter(lambda d: d['main_color'] == 'red', a))
```




    [{'main_color': 'red', 'second_color': 'blue'}]




```python
list(filter(lambda d: d['main_color'] != 'red', a))
```




    [{'main_color': 'yellow', 'second_color': 'green'},
     {'main_color': 'yellow', 'second_color': 'blue'}]




```python
found = list(filter(lambda d: d['main_color'] == 'black', a))
found

```




    []




```python
if not found:
	print('Item does not exist')

```

    Item does not exist


#### add key for each dictionary in a list of dictionaries


```python
[{**d,"new": 0 } for d in l ]
```




    [{'uuid': 1, 'p': 'a', 'new': 0}, {'uuid': 2, 'p': 'b', 'new': 0}]


