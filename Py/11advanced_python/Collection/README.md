# Collection

- [Collection](#collection)
  - [Counter](#counter)
  - [Named Tuple](#named-tuple)
  - [🔥 Default Dict](#-default-dict)
  - [Deque](#deque)


```python
"""
cd .\Py\11advanced_python\Collection
jupyter nbconvert --to markdown Collection.ipynb --output README.md
"""
```

    hello world


## Counter


```python
from collections import Counter

a = "aaaabbbbbccc"

counter = Counter(a)

print(counter)
print(counter.values())
print(counter.items())
```

    Counter({'b': 5, 'a': 4, 'c': 3})
    dict_values([4, 5, 3])
    dict_items([('a', 4), ('b', 5), ('c', 3)])



```python
print(counter.most_common(1))
```

    [('b', 5)]


## Named Tuple


```python
from collections import namedtuple

Point  = namedtuple("Point",['x','y'])

pt = Point(1,-1)
print(pt.x, pt.y) #x y
```

    1 -1


## 🔥 Default Dict


```python
from collections import defaultdict
d = defaultdict(int)

d['a'] = 1
d['b'] = 2

print(d['c']) #

# vs
d = {}
try:
    print(d['c'])
except Exception:
    print('error')

```

    0
    error



```python
print(defaultdict(list)['x'])
print(defaultdict(set)['x'])
print(defaultdict(dict)['x'])
```

    []
    set()
    {}


## Deque


```python
from collections import deque

d = deque()
d.append(1)
d.append(2)
print(d)

d.appendleft(3)
print(d)

d.extendleft([4,5,6])
print(d)

print("popping...")
d.pop()
print(d)
d.popleft()
print(d)
```

    deque([1, 2])
    deque([3, 1, 2])
    deque([6, 5, 4, 3, 1, 2])
    popping...
    deque([6, 5, 4, 3, 1])
    deque([5, 4, 3, 1])

