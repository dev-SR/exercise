- [Python Generators](#python-generators)
  - [Return vs. Yield](#return-vs-yield)
  - [Generator with a loop](#generator-with-a-loop)
- [Generator Expressions](#generator-expressions)
      - [Advantage](#advantage)

# Python Generators

<img src="https://media.giphy.com/media/l0MYwrucQ9amOkFHO/giphy.gif" width = 400>

- Python generator is kind of a function only. It generates a `sequence of values` that we can `iterate` on.
- Unlike functions, generators **doesn't terminate** after returning a value.
- `yield` _(give back value and pause execution)_ keyword is used in Generators.
- Like a list or a tuple, Generator is also an iterable.


```python
def my_generator():
    n = 1

    print("First time")
    yield n # return `n`
    # and pause until next() is called

    n+=1

    print("Second time")
    yield n

    n+=1

    print("Third time")
    yield n
```


```python
my_gen = my_generator()
```


```python
type(my_gen)
```




    generator




```python
next(my_gen)
```

    First time





    1




```python
next(my_gen)
```

    Second time





    2




```python
next(my_gen)
```

    Third time





    3




```python
next(my_gen)
```


    ---------------------------------------------------------------------------

    StopIteration                             Traceback (most recent call last)

    <ipython-input-9-78dc05d55b31> in <module>
    ----> 1 next(my_gen)


    StopIteration:


## Return vs. Yield
- `yield` **returns a value and pauses the execution** while maintaining the internal states.
- `return` statement **returns a value and terminates the execution of the function**.
- When a generator is called, it **returns an object (iterator)** but does not start execution immediately. Starts when calling with `next()` function call.
- Local variables and their states are remembered between successive calls.

<img src="https://media.giphy.com/media/EmMWgjxt6HqXC/giphy.gif" width = 400>


```python
def counter_func(n):
    i = 1
    while (i <= n):
        return i
        i += 1  # inaccessible
```


```python
counter_func(4)
```




    1




```python
def counter_gen(n):
    i = 1
    while (i <= n):
        yield i
        i+=1
```


```python
gen = counter_gen(3)
```


```python
next(gen)
```




    1




```python
next(gen)
```




    2




```python
next(gen)
```




    3




```python
next(gen)
```


    ---------------------------------------------------------------------------

    StopIteration                             Traceback (most recent call last)

    <ipython-input-24-6e72e47198db> in <module>
    ----> 1 next(gen)


    StopIteration:


## Generator with a loop

- We can use the for loop to traverse the elements over the generator.
- The next() function is called implicitly and the StopIteration is also automatically taken care of.


```python
for ele in counter_gen(3):
    print(ele)
```

    1
    2
    3



```python
def reverse_string(string):
    for i in range(len(string)-1, -1, -1):
        yield string[i]
```


```python
for ele in reverse_string("abc"):
    print(ele)
```

    c
    b
    a


# Generator Expressions

- Python also provides a generator expression, which is a shorter way of defining simple generator functions. The generator expression is an anonymous generator function.


- The major difference between a list comprehension and a generator expression is that a list comprehension produces the entire list while the generator expression produces one item at a time.


- They have lazy execution ( producing items only when asked for ). For this reason, a generator expression is much more memory efficient than an equivalent list comprehension.


#### Advantage
- Memory efficient
- Represent Infinite Stream


```python
squares_list = [i**2 for i in range(1000000) if i%2==0]
```


```python
squares_gen = (i**2 for i in range(1000000) if i%2==0)
```


```python
idx = 0
for i in squares_gen:
    if idx == 10:
        break
    print(i)
    idx +=1
```

    0
    4
    16
    36
    64
    100
    144
    196
    256
    324



```python
idx = 0
for i in squares_list:
    if idx == 10:
        break
    print(i)
    idx +=1
```

    0
    4
    16
    36
    64
    100
    144
    196
    256
    324

