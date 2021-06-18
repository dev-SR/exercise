# Tuples

- similar to lists (read-only)
- ordered, collections of items
- indexable
- immutable
- faster then lists


```python
tup = (1,2,"Hello",33)
print(tup)
type(tup)
```

    (1, 2, 'Hello', 33)
    




    tuple




```python
print(tup[0])
print(tup[:-1])
```

    1
    (1, 2, 'Hello')
    


```python
# But this is not posible because of immutability
tup[0] = 1
```


    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    <ipython-input-5-28d48dc86fdf> in <module>
          1 # But this is not posible because of immutability
    ----> 2 tup[0] = 1
    

    TypeError: 'tuple' object does not support item assignment



```python

```
