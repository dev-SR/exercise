# Set
- contains only unique elements
- mutable 
- unordered
- unindexable


```python
s = {5,3,7,8,4,6,6,6}
# No duplicate elements
print(s)
type(s)
```

    {3, 4, 5, 6, 7, 8}
    




    set




```python
s.add(99)
print(s)
s.remove(8) # remove(item) ✖ remove(idx)
print(s)
```

    {3, 4, 5, 6, 7, 8, 99}
    {3, 4, 5, 6, 7, 99}
    

## Remove duplicates for list


```python
l = [1,1,1,2,3,4,4,4,6,6,5]
_set = set(l)
_l = list(_set)
print(_l)
```

    [1, 2, 3, 4, 5, 6]
    
