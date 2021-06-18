> **`my_custom.py`**

```python
def greetings(name):
    """greetings

    Args:
        name (string): Your name

    Returns:
        string: returns your name with greetings

    NOTES: use 'generate docstring' commands to generate DocStr


    """
    return "Hello, " + name
```


> **`py_custom_mod.ipynb`**
```python
import my_custom
print(dir(my_custom))
```

    ['__builtins__', '__cached__', '__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', 'greetings']
    


```python
my_custom.greetings("soikat")
```




    'Hello, soikat'


