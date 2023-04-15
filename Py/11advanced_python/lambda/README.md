# Lambda

- [Lambda](#lambda)
  - [Intro](#intro)
  - [Sorted](#sorted)
  - [With map and filter](#with-map-and-filter)
    - [map(func,seq)](#mapfuncseq)
    - [filter(func,seq)](#filterfuncseq)


```python
"""
cd .\Py\11advanced_python\lambda
jupyter nbconvert --to markdown lambda.ipynb --output README.md
"""
```

## Intro


```python
add10 = lambda x: x+10
print(add10(5))
```

    15



```python
mult = lambda x,y: x*y

print(mult(2,7))
```

    14


## Sorted


```python
points2D = [(1,2),(15,1),(5,-1),(10,4)]

points2D_sorted = sorted(points2D,key=lambda x:x[1])

print(points2D)
print(points2D_sorted)
```

    [(1, 2), (15, 1), (5, -1), (10, 4)]
    [(5, -1), (15, 1), (1, 2), (10, 4)]


## With map and filter

### map(func,seq)


```python
a = [1,2,3,4,5,6]
b = map(lambda x: x*2,a)

print(list(b))
```

    [2, 4, 6, 8, 10, 12]



```python
[x*2 for x in a]
```




    [2, 4, 6, 8, 10, 12]



### filter(func,seq)


```python
a = [1,2,3,4,5,6]
b = filter(lambda x: x%2==0,a)

print(list(b))
```

    [2, 4, 6]



```python
[x for x in a if x%2==0]
```




    [2, 4, 6]


