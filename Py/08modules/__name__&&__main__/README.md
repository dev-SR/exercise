
# What `__name__ == __main__` means ??

`__name__` is a built-in variable which evaluates **to the name of the current module**. Thus it can be used to check whether the current script **is being run on its own or being imported somewhere else** by combining it with if statement.

`my_module.py`


```python
def greeting(name):
    return "Hello, "+name
print("I'm inside a module my_module.py and __name__ = ", __name__)
```


`project.py`


```python
import my_module
print(my_module.greeting("Soikat"))
print("inside project.py and __name__ = ", __name__)
```

> Running **`python my_module.py`**,  we get following output

`output:`

```
I'm inside a module my_module.py and __name__ =  __main__
```
> Running **`python project.py`** 

`output:`

```
I'm inside a module my_module.py and __name__ =  my_module
Hello, Soikat
inside project.py and __name__ =  __main__
```

As seen above, when `my_module.py` is run **directly**, the interpreter sets the `__name__` variable as `__main__` 

and when it is run through `project.py` by **importing**, the `__name__` variable is set as the name of the python script, i.e. `my_module.py`. 

Thus, it can be said that if `__name__ == __main__` is the part of the program that runs when the script is run from the command line using a command like `python my_module.py`.

This can be use full to hide confidential code:


> `my_module.py`


```python
def greeting(name):
    return "Hello, "+name
print("I'm inside a module my_module.py and __name__ = ", __name__)

if __name__ == '__main__':
    print("I'm very confidential code...")

```

Now if we run through `project.py` the if block won't run:

`python project.py`

```
I'm inside a module my_module.py and __name__ =  my_module
Hello, Soikat
inside project.py and __name__ =  __main__
```

Only running `python my_module.py` will execute if blocks:

```
I'm inside a module my_module.py and __name__ =  __main__
I'm very confidential code..
```
