# Play with Pythons

- [Play with Pythons](#play-with-pythons)
  - [Passing variables number of arguments to functions](#passing-variables-number-of-arguments-to-functions)
  - [Callback: functions with parameters, class methods as callback](#callback-functions-with-parameters-class-methods-as-callback)


```python
# jupyter nbconvert --to markdown tt.ipynb --output README.md
```

## Passing variables number of arguments to functions


```python
def multipleParam(*param):
	print(param)


multipleParam(1, 2)
multipleParam(1, 2, 3)

```

    (1, 2)
    (1, 2, 3)


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

