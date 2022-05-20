# Set

- [Set](#set)
  - [Introduction](#introduction)
  - [Remove duplicates for list](#remove-duplicates-for-list)
  - [Membership Operator](#membership-operator)
  - [Set Operations](#set-operations)
    - [symmetric difference](#symmetric-difference)


```python
"""
cd .\Py\05sets\
jupyter nbconvert --to markdown py_list.ipynb --output README.md
"""
```

## Introduction

- contains only unique elements
- mutable
- unordered
- unindexable


```python
s = set([1]) # ~not set(1)
s.add(2)
s.add(3)
s.add(1)
print(s)
```

    {1, 2, 3}



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


## Membership Operator


```python
7 in {1,2,3,4,5,6,7}
```




    True



## Set Operations

- set `union`
- set `intersection`
- set `difference`
- set `symmetric difference`


```python
s1= {1,3,4,5,8}
s2= {4,5,6,7,1,9}
```


```python
s1.union(s2)
```




    {1, 3, 4, 5, 6, 7, 8, 9}




```python
s1 | s2
```




    {1, 3, 4, 5, 6, 7, 8, 9}




```python
s1.intersection(s2)
```




    {1, 4, 5}




```python
s1 & s2
```




    {1, 4, 5}




```python
s1.difference(s2)
```




    {3, 8}




```python
s2.difference(s1)
```




    {6, 7, 9}




```python
s1 - s2
```




    {3, 8}



### symmetric difference


```python
s1.symmetric_difference(s2)
```




    {3, 6, 7, 8, 9}




```python
(s1 | s2) - (s1 & s2)
```




    {3, 6, 7, 8, 9}


