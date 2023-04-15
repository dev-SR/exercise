# Itertools

- [Itertools](#itertools)
  - [product](#product)
  - [permutation](#permutation)
  - [combination](#combination)
  - [accumulate](#accumulate)
  - [groupby](#groupby)

```python
"""
cd .\Py\11advanced_python\Itertools
jupyter nbconvert --to markdown itertools.ipynb --output README.md
"""
```

## product


```python
from itertools import product
a = [1,2]
b = [3,4]

prod = product(a,b)
print(list(prod))
```

    [(1, 3), (1, 4), (2, 3), (2, 4)]



```python
print(list(product(a,b,repeat=2)))
```

    [(1, 3, 1, 3), (1, 3, 1, 4), (1, 3, 2, 3), (1, 3, 2, 4), (1, 4, 1, 3), (1, 4, 1, 4), (1, 4, 2, 3), (1, 4, 2, 4), (2, 3, 1, 3), (2, 3, 1, 4), (2, 3, 2, 3), (2, 3, 2, 4), (2, 4, 1, 3), (2, 4, 1, 4), (2, 4, 2, 3), (2, 4, 2, 4)]


## permutation


```python
from itertools import permutations
a = [1,2,3]
perm = permutations(a)
print(list(perm))
```

    [(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)]



```python
perm = permutations(a,2)
print(list(perm))
```

    [(1, 2), (1, 3), (2, 1), (2, 3), (3, 1), (3, 2)]


## combination


```python
from itertools import combinations
a = [1,2,3,4]
comb = combinations(a,2)
print(list(comb))
```

    [(1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4)]


## accumulate


```python
from itertools import accumulate
a = [1,2,5,3,4]
print(a)
print(list(accumulate(a)))
print(list(accumulate(a,func=max)))
```

    [1, 2, 5, 3, 4]
    [1, 3, 8, 11, 15]
    [1, 2, 5, 5, 5]


## groupby


```python
from itertools import groupby
a = [1,2,5,3,4]
print(a)

def smaller_than_3(x):
    return x<3

group_obj = groupby(a,key=smaller_than_3)
for k,v in group_obj:
    print(k,list(v))
```

    [1, 2, 5, 3, 4]
    True [1, 2]
    False [5, 3, 4]



```python
persons = [ {'name':'Tim','age':25},{'name':'Dan','age':25},
        {'name':'Tim','age':27},{'name':'Dan','age':28}]

group_obj = groupby(persons,key=lambda x:x['age'])
for k,v in group_obj:
    print(k,list(v))
```

    25 [{'name': 'Tim', 'age': 25}, {'name': 'Dan', 'age': 25}]
    27 [{'name': 'Tim', 'age': 27}]
    28 [{'name': 'Dan', 'age': 28}]

