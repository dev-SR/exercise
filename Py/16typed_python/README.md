# Advance Topics in Python

- [Advance Topics in Python](#advance-topics-in-python)
  - [Type Hints & Annotations](#type-hints--annotations)
    - [Adding type hints to variables](#adding-type-hints-to-variables)
      - [Forcing Type Checks on Runtime](#forcing-type-checks-on-runtime)
        - [Using with jupyter notebook:](#using-with-jupyter-notebook)
    - [Adding types hints to functions](#adding-types-hints-to-functions)
    - [Adding union type hints in function parameters](#adding-union-type-hints-in-function-parameters)
    - [Adding type hints to optional function parameters](#adding-type-hints-to-optional-function-parameters)
    - [Type Aliases](#type-aliases)
    - [Annotating constants with Final](#annotating-constants-with-final)
    - [Annotate instances of a class](#annotate-instances-of-a-class)
    - [Annotate Class Type](#annotate-class-type)
    - [`TypeVar`](#typevar)
    - [`NewType`](#newtype)


```python
"""
cd .\Py\12advanced_python\
jupyter nbconvert --to markdown padv.ipynb --output README.md
"""

```

## Type Hints & Annotations

Static typing in Python is optional and can be introduced gradually (this is known as gradual typing). With gradual typing, you can choose to specify the portion of your code that should be dynamically or statically typed. The static type-checkers will ignore the dynamically-typed portions of your code and will not give out warnings on code that does not have type hints nor prevents inconsistent types from compiling during runtime.

- [logrocket.com/understanding-type-annotation-python](https://blog.logrocket.com/understanding-type-annotation-python/#:~:text=With%20type%20hints%2C%20you%20can,them%20to%20your%20Python%20code.)
- [https://dev.to/dan_starner/using-pythons-type-annotations-4cfe](https://dev.to/dan_starner/using-pythons-type-annotations-4cfe)
- [https://towardsdatascience.com/type-annotations-in-python-d90990b172dc](https://towardsdatascience.com/type-annotations-in-python-d90990b172dc)

### Adding type hints to variables

In Python, you can define a variable with a type hint using the following syntax:

```py
variable_name: type = value
```


```python
# Built-in class examples
an_int: int = 3
a_float: float = 1.23
a_str: str = 'Hello'
a_bool: bool = False
a_list: list = [1, 2, 3]
a_set: set = set([1, 2, 3])  # or {1, 2, 3}
a_dict: dict = {'a': 1, 'b': 2}
```

- If you’re using Python `≤3.8`, you need to import `List` from the typing module:
- If you’re using Python `≤3.8`, you need to import `Dict` from the typing module.





```python
name: str = "soikat"

```

In Python, you can read the type hints defined on variables using the `__annotations__` dictionary:


```python
__annotations__
```




    {'name': str,
     'g': dict[str, int],
     'an_int': int,
     'a_float': float,
     'a_str': str,
     'a_bool': bool,
     'a_list': list,
     'a_set': set,
     'a_dict': dict}



#### Forcing Type Checks on Runtime

As mentioned earlier, the Python interpreter does not enforce types, so defining a variable with a wrong type won’t trigger an error:


```python
name: int = "soikat"
name

```




    'soikat'



Since Python is by default, a dynamically-typed language, tools like `mypy` were created to give us the benefits of a statically-typed environment. `mypy` is a optional static type checker created by Jukka Lehtosalo. It checks for annotated code in Python and emits warnings if annotated types are used inconsistently.

You can force type checks on runtime with mypy (documentation). Before doing so, install it with either pip or conda:



```
pip install mypy
conda install mypy
```

Then Run the following command to check your code:

```
# deactivate inside vscode notebook
# conda deactivate
mypy script.py
```

##### Using with jupyter notebook:

 [https://gitlab.tue.nl/jupyter-projects/nb_mypy/-/blob/master/Nb_Mypy.ipynb](https://gitlab.tue.nl/jupyter-projects/nb_mypy/-/blob/master/Nb_Mypy.ipynb)


```python
# installation
# !pip install nb_mypy
```


```python
%load_ext nb_mypy

```

    Version 1.0.3



```python
answer: str = 30
```

    <cell>1: error: Incompatible types in assignment (expression has type "int", variable has type "str")


Other options: [https://stackoverflow.com/questions/58976685/type-check-jupyter-notebooks-with-mypy/72331068#72331068](https://stackoverflow.com/questions/58976685/type-check-jupyter-notebooks-with-mypy/72331068#72331068)

### Adding types hints to functions

To annotate a function, declare the annotation after each parameter and the return value:

```python
def function_name(param1: param1_type, param2: param2_type) -> return_type:
```


```python
def announcement(language: str, version: float) -> str:
    print(f"{language} {version} has been released")

announcement("Python", 3.10)
```

    <cell>1: error: Missing return statement


    Python 3.1 has been released


### Adding union type hints in function parameters


```python
def show_type(num: str | int) -> None:
	pass

show_type('hello')
show_type(3)
```

    <cell>1: error: X | Y syntax for unions requires Python 3.10



    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    ~\AppData\Local\Temp/ipykernel_14388/883972686.py in <module>
    ----> 1 def show_type(num: str | int) -> None:
          2         pass
          3
          4 show_type('hello')
          5 show_type(3)


    TypeError: unsupported operand type(s) for |: 'type' and 'type'


If you’re using Python ≤3.9, you need to `import Union` from the typing module. The parameter can be annotated as follows:




```python
from typing import Union


def show_type(num: Union[str, int]) -> None:
	print(type(num))


show_type('hello')
show_type(3)
show_type([3])
```

    <cell>10: error: Argument 1 to "show_type" has incompatible type "List[int]"; expected "Union[str, int]"


    <class 'str'>
    <class 'int'>
    <class 'list'>


### Adding type hints to optional function parameters

Not all parameters in a function are required; some are optional. Here’s an example of a function that takes an optional parameter:


```python
from typing import Optional
def format_name(name: str, title: Optional[str] = None) -> str:
    if title:
        return f"Name: {title}. {name.title()}"
    else:
        return f"Name: {name.title()}"


format_name("john doe", "Mr")

```




    'Name: Mr. John Doe'



### Type Aliases

If you want to work with custom type names, you can use type aliases.


```python
from typing import Tuple


# Declare a point type annotation using a tuple of ints of [x, y]
Point = Tuple[int, int]


# Create a function designed to take in a list of Points
def print_points(points: list[Point]):
    for point in points:
        print("X:", point[0], "  Y:", point[1])

print_points([(1, 2), (3, 4)])
print_points([("1", "2"), ("3", "4")])

```

    <cell>14: error: List item 0 has incompatible type "Tuple[str, str]"; expected "Tuple[int, int]"
    <cell>14: error: List item 1 has incompatible type "Tuple[str, str]"; expected "Tuple[int, int]"


    X: 1   Y: 2
    X: 3   Y: 4
    X: 1   Y: 2
    X: 3   Y: 4


### Annotating constants with Final

At the time of writing, Python does not have an inbuilt way of defining constants. Starting with Python `3.10`, you can use the Final type from the typing module. This will mean mypy will emit warnings if there are attempts to change the variable value.


```python
from typing import Final
MIN: Final = 10
MIN = MIN + 3
```

    <cell>3: error: Cannot assign to final name "MIN"


### Annotate instances of a class


```python
from dataclasses import dataclass

@dataclass
class Animal:
    name: str
    age: int

# instance type: Animal
dog:Animal = Animal(name="Kevin", age="3")
dog="lol"
```

    <cell>9: error: Argument "age" to "Animal" has incompatible type "str"; expected "int"
    <cell>10: error: Incompatible types in assignment (expression has type "str", variable has type "Animal")


### Annotate Class Type


```python
from dataclasses import dataclass

@dataclass
class Animal:
    name: str
    age: int

# take Animal class and return instance of Animal
def make_animal(animal_class: Animal, name: str,age:int) -> Animal:
    return animal_class(name=name, age=age)


dog = make_animal(Animal, "Kevin",3)

```

    <cell>10: error: "Animal" not callable
    <cell>13: error: Argument 1 to "make_animal" has incompatible type "Type[Animal]"; expected "Animal"


The type of `animal_class` looks the same as the return type though, even though we know the first is a `class` and the second an `instance`. What we should use instead is `type[Animal]`:


```python
from typing import Type
def make_animal(animal_class: Type[Animal], name: str,age:int) -> Animal:
    return animal_class(name=name, age=age)

dog = make_animal(Animal, "Kevin",3)
```

### `TypeVar`

`TypeVar` is a generic type variable. It can be used to define a generic type.


```python
from typing import TypeVar

T = TypeVar('T')
def get_item(lst: list[T], index: int) -> T:
	return lst[index]

print(get_item([1, 2, 3], 1))
print(get_item(['a', 'b', 'c'], 1))
```

    2
    b


### `NewType`

`NewType` is a generic type that can be used to define a new type.


```python
from typing import NewType

UserId = NewType('UserId', int)

def get_user(x: UserId):
	print(x)

get_user(UserId(123456)) # this is fine
get_user(123456) # that's an int, not a UserId
```

    <cell>9: error: Argument 1 to "get_user" has incompatible type "int"; expected "UserId"


    123456
    123456

