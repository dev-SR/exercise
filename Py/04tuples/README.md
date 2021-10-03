# Tuples

- similar to lists (read-only)
- ordered, collections of items
- indexable
- immutable
- faster then lists

- [Tuples](#tuples)
  - [creating empty tuple](#creating-empty-tuple)
  - [Access elements in tuples](#access-elements-in-tuples)
  - [Changing a Tuple](#changing-a-tuple)

## creating empty tuple


```python
t = ()

t = tuple()

type(t)
```




    tuple




```python
# Heterogenous elements

tup = (1,2,"Hello",33)

print(tup)

type(tup)
```

    (1, 2, 'Hello', 33)





    tuple




```python
# for one element : only paranthesis is not enough

t = ('mohit')

print(type(t))

# for one element : comma is mandatory

t = ('mohit',)

print(type(t))




```

    <class 'str'>
    <class 'tuple'>


## Access elements in tuples


```python
print(tup[0])

print(tup[-1])

print(tup[:-1])

print(tup[:])


```

    1
    33
    (1, 2, 'Hello')
    (1, 2, 'Hello', 33)


## Changing a Tuple


```python
# But this is not possible because of immutability

tup[0] = 1
```


    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    <ipython-input-5-28d48dc86fdf> in <module>
          1 # But this is not posible because of immutability
    ----> 2 tup[0] = 1


    TypeError: 'tuple' object does not support item assignment



```python
l=['A','B','C']

tup=(1,2,l,(1,2,3),100)

tup[2][2]='X'

print(tup)
```

    (1, 2, ['A', 'B', 'X'], (1, 2, 3), 100)

