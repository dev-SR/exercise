# Higher order functions

- Everything in Python is `object`, including `functions`.
- functions that take other functions as arguments are also called `higher order functions`.


```python
def add(ele): return ele + 1

def sub(ele): return ele - 1
```


```python
def calculator(cb, number):
    result = cb(number)
    return result
```


```python
calculator(add, 5)
```




    6




```python
calculator(sub, 9)
```




    8



# Python Decorators

- A decorator takes a function as arguments, adds some functionality to the exisiting code and returns a function.


<img src="https://media.giphy.com/media/73Y6EEJqbyGovenlLE/giphy.gif" wdith=300>


```python
def basic():
    print("I am a very basic function.")
```


```python
basic()
```

    I am a very basic function.
    


```python
def add_features(cb):
    def wrapper():
        print("="*30)
        print("A new feature is added")
        print("="*30)
        cb()
    return wrapper
```


```python
new_func = add_features(basic)
```


```python
new_func()
```

    ==============================
    A new feature is added
    ==============================
    I am a very basic function.
    

We can see that the decorator function added some new functionality to the original function. This is similar to packing a gift. The decorator acts as a wrapper.

# The Decorative call...
- We can use the @ symbol along with the name of the decorator function and place it above the definition of the function to be decorated. 


```python
@add_features
def new_basic():
    print("I am also a simple function")
```


```python
new_basic()
```

    ==============================
    A new feature is added
    ==============================
    I am also a simple function
    

# Decorating Function with parameters


```python
DB = {
    'admin': 'admin@123',
    'super_user': 'super_user@123'
}
```


```python
def login(func):
    def wrapper(username, password, *args, **kwargs):
        if username in DB and DB[username] == password:
            # successful
            func(*args, **kwargs)
        else:
            print("Authentication failed")
            
    return wrapper
```


```python
@login
def add(a,b):
    print(a+b)
```


```python
add("admin", "admin@123", 5,10)
```

    15
    


```python
add(5, 6)
```

    Authentication failed
    

## Chaining Decorators in Python
- Multiple decorators can be chained in Python.
- A function can be decorated multiple times with different decorators.


```python
# decorator function
def star(cb):
    def wrapper(*args, **kwargs):
        print("*"*30)
        cb(*args, **kwargs)
        print("*"*30)
    return wrapper

```


```python
# decorator function
def dollar(cb):
    def wrapper(*args, **kwargs):
        print("$"*30)
        cb(*args, **kwargs)
        print("$"*30)
    return wrapper

```


```python
@dollar
@star
def main(message):
    print(message)
```


```python
main("Hello world")
```

    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    ******************************
    Hello world
    ******************************
    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    

<img src="https://media.giphy.com/media/3oEjHQOeg3YhQ8REZ2/giphy.gif" width=300>
