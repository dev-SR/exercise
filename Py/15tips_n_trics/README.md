# Play with Pythons

- [Play with Pythons](#play-with-pythons)
  - [Functions](#functions)
    - [🚀Unpacking Argument Lists and Keyword Arguments](#unpacking-argument-lists-and-keyword-arguments)
    - [🚀🚀Using Unpacking Argument Lists and Keyword Arguments to build 📢Callbacks📢](#using-unpacking-argument-lists-and-keyword-arguments-to-build-callbacks)
  - [DSA](#dsa)
    - [Merging Dictionaries](#merging-dictionaries)
    - [Exclude Dictionary Keys](#exclude-dictionary-keys)

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


