# Play with Pythons

- [Play with Pythons](#play-with-pythons)
  - [Functions](#functions)
    - [🚀Unpacking Argument Lists](#unpacking-argument-lists)
    - [Callback: functions with parameters, class methods as callback](#callback-functions-with-parameters-class-methods-as-callback)
  - [DSA](#dsa)
    - [Merging Dictionaries](#merging-dictionaries)


```python
"""
cd .\Py\15tips_n_trics\
jupyter nbconvert --to markdown tt.ipynb --output README.md
"""

```

## Functions

### 🚀Unpacking Argument Lists

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


### Callback: functions with parameters, class methods as callback


```python
def CallMe():
    print("CallMe()")

def CallMe3(a, b, c):
    print(f"CallMe({a}, {b}, {c})")

class Tester:
    def __init__(self):
        pass

    def test(self, a, b):
        print(f"test({a}, {b})")


def callback(cb):
    cb()

def callbackWithParam(cb, param):
    print(*param) # unpack
    cb(*param)



callback(CallMe)
callbackWithParam(CallMe3, [1, 2, 3])
# or
callbackWithParam(CallMe3, (1, 2, 3))

t = Tester()
callbackWithParam(t.test, [1, 2])

```

    CallMe()
    1 2 3
    CallMe(1, 2, 3)
    1 2 3
    CallMe(1, 2, 3)
    1 2
    test(1, 2)



```python
def withParam(cb, param):
    return cb(*param)

def fun(a,b):
	print(a+b)


print(withParam(fun, [1, 2]))

```

    3
    None



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


