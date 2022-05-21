# Play with Pythons

- [Play with Pythons](#play-with-pythons)
  - [🚀Unpacking Argument Lists](#unpacking-argument-lists)
  - [Callback: functions with parameters, class methods as callback](#callback-functions-with-parameters-class-methods-as-callback)


```python
"""
cd .\Py\15tips_n_trics\
jupyter nbconvert --to markdown tt.ipynb --output README.md
"""

```

## 🚀Unpacking Argument Lists

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


## Callback: functions with parameters, class methods as callback


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

