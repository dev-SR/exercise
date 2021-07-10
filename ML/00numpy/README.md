# NumPy

- [NumPy](#numpy)
  - [Why Numpy?](#why-numpy)
    - [Less Memory](#less-memory)
    - [Fast](#fast)
  - [Array Creation](#array-creation)
    - [1) Converting Python sequences to NumPy Arrays](#1-converting-python-sequences-to-numpy-arrays)
    - [2) Intrinsic NumPy array creation functions](#2-intrinsic-numpy-array-creation-functions)
      - [1 - 1D array creation functions](#1---1d-array-creation-functions)
      - [`numpy.arange(start,[end,[step]])`](#numpyarangestartendstep)
      - [`numpy.linspace(s,en,equally spaced between)`](#numpylinspacesenequally-spaced-between)
      - [2, 3 - general ndarray creation functions](#2-3---general-ndarray-creation-functions)
  - [Generating an array of random numbers in NumPy](#generating-an-array-of-random-numbers-in-numpy)
    - [NumPy Random Seed](#numpy-random-seed)
  - [Indexing and Masking](#indexing-and-masking)
    - [Selecting values from your array that fulfill certain conditions](#selecting-values-from-your-array-that-fulfill-certain-conditions)
    - [Array slicing](#array-slicing)
    - [Masking](#masking)


```python
import numpy as np
```

## Why Numpy?

- performs fast operations (because of Vectorization)
- numpy arrays can be treated as vectors and matrices from linear algebra


```python
l = [1,2,3,4,5,6,7,8,9,10]
```


```python
%timeit [i**2 for i in l]
```

    3.83 µs ± 575 ns per loop (mean ± std. dev. of 7 runs, 100000 loops each)
    


```python
arr = np.array(l)
arr
```




    array([ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10])




```python
%timeit arr**2
```

    1.17 µs ± 40.9 ns per loop (mean ± std. dev. of 7 runs, 1000000 loops each)
    


```python
# adding 1 to each element of this vector
l + 1
```


    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    <ipython-input-13-9fd71c034c35> in <module>
          1 # adding 1 to each element of this vector
    ----> 2 l + 1
    

    TypeError: can only concatenate list (not "int") to list



```python
# but it's possible in numpy
arr + 1
```




    array([ 2,  3,  4,  5,  6,  7,  8,  9, 10, 11])



### Less Memory


```python
import time
import sys
S= range(1000)
print(sys.getsizeof(5)*len(S))
 
D= np.arange(1000)
print(D.size*D.itemsize)
```

    28000
    4000
    

### Fast


```python
import time
import sys
 
SIZE = 1000000
 
L1= range(SIZE)
L2= range(SIZE)
A1= np.arange(SIZE)
A2=np.arange(SIZE)
 
start= time.time()
result=[(x,y) for x,y in zip(L1,L2)]
print((time.time()-start)*1000)
 
start=time.time()
result= A1+A2
print((time.time()-start)*1000)
```

    221.99392318725586
    59.9970817565918
    

## Array Creation

`array`: Fundamental element in numpy is homogenous array. Numpy Arrays can be 1D, 2D, 3D ...nD

Different ways to create np array:

### 1) Converting Python sequences to NumPy Arrays

- `np.array()`

<div align="center"><img src="img/array_creation.jpg" alt="Itrtype" ></div> 


```python
a1D = np.array([1, 2, 3, 4])
print(a1D)
# da
print(type(a1D))
print(a1D.ndim)
print(a1D.dtype)
print("shape: ",a1D.shape)  

print()

# 2D
a2D = np.array([[1, 2], [3, 4]])
print(a2D) 
print("total item: ",a2D.size)  
print("shape: ",a2D.shape)  
```

    [1 2 3 4]
    <class 'numpy.ndarray'>
    1
    int32
    shape:  (4,)
    
    [[1 2]
     [3 4]]
    total item:  4
    shape:  (2, 2)
    


```python
a3D = np.array([ [[1,2,3], [4,5,6], [7,8,9]],
                  [[10,11,12], [13,14,15], [16,17,18]]
               ])
print(a3D)
print("shape: ",a3D.shape)  
```

    [[[ 1  2  3]
      [ 4  5  6]
      [ 7  8  9]]
    
     [[10 11 12]
      [13 14 15]
      [16 17 18]]]
    shape:  (2, 3, 3)
    


```python

```

### 2) Intrinsic NumPy array creation functions

NumPy has over 40 built-in functions for creating arrays as laid out in the Array creation routines. These functions can be split into roughly three categories, based on the dimension of the array they create:

1. 1D arrays
2. 2D arrays
3. ndarrays


#### 1 - 1D array creation functions

The 1D array creation functions e.g. `numpy.linspace` and `numpy.arange` generally need at least two inputs,`start` and `stop`.

#### `numpy.arange(start,[end,[step]])`

`numpy.arange` creates arrays with regularly incrementing values.






```python
print(np.arange(10))

print()

print(np.arange(1,10))

print()

print(np.arange(1,10,2))
```

    [0 1 2 3 4 5 6 7 8 9]
    
    [1 2 3 4 5 6 7 8 9]
    
    [1 3 5 7 9]
    

#### `numpy.linspace(s,en,equally spaced between)` 

`numpy.linspace`  will create arrays with a specified number of elements, and spaced equally between the specified beginning and end values.


```python
print(np.linspace(1,10,5)) # from 
```

    [ 1.    3.25  5.5   7.75 10.  ]
    

#### 2, 3 - general ndarray creation functions

- `zeros()`
- `ones()`
- `diag()`
- `indentity()` , `eye()`



```python
print(np.zeros(10))
print("2d..............")
print(np.zeros((3,3)))
print("3d.............")
print(np.zeros((2,3,3)))
```

    [0. 0. 0. 0. 0. 0. 0. 0. 0. 0.]
    2d..............
    [[0. 0. 0.]
     [0. 0. 0.]
     [0. 0. 0.]]
    3d.............
    [[[0. 0. 0.]
      [0. 0. 0.]
      [0. 0. 0.]]
    
     [[0. 0. 0.]
      [0. 0. 0.]
      [0. 0. 0.]]]
    


```python
print(np.ones(10))
print()
print(np.ones((3,3)) * 5) 
```

    [1. 1. 1. 1. 1. 1. 1. 1. 1. 1.]
    
    [[5. 5. 5.]
     [5. 5. 5.]
     [5. 5. 5.]]
    


```python
np.diag([1,2,3,4])
```




    array([[1, 0, 0, 0],
           [0, 2, 0, 0],
           [0, 0, 3, 0],
           [0, 0, 0, 4]])




```python
np.identity(4)
```




    array([[1., 0., 0., 0.],
           [0., 1., 0., 0.],
           [0., 0., 1., 0.],
           [0., 0., 0., 1.]])




```python
np.eye(4)
```




    array([[1., 0., 0., 0.],
           [0., 1., 0., 0.],
           [0., 0., 1., 0.],
           [0., 0., 0., 1.]])



## Generating an array of random numbers in NumPy

We can generate an array of random numbers using `rand()`, `randn()` or `randint()` functions.

- Using `random.rand()`, we can generate an array of random numbers of the shape we pass to it from uniform distribution over 0 to 1.



```python
# For example, say we want a one-dimensional array of 4 objects that are uniformly 
# distributed from 0 to 1, we can do this:

r = np.random.rand(4)
print(r)

# And if we want a two-dimensional array of 3rows and 2columns:
print()
r = np.random.rand(3, 2)
print(r)
```

    [0.9448474  0.93929097 0.4827775  0.65302109]
    
    [[0.26754535 0.03942572]
     [0.31236268 0.85961221]
     [0.99364858 0.35495844]]
    

- Using `randn()`, we can generate random samples from **Standard, normal or Gaussian distributioncentered around 0** . For example, let’s generate 7 random numbers:


```python
r = np.random.randn(7)
r
```




    array([ 0.85628608,  1.06652993, -0.24465544,  0.74419801, -0.35160372,
           -0.14436767, -0.06093946])



When you plot the result will give us a normal distribution curve.


```python
import matplotlib.pyplot as plt
```


```python
r = np.random.randn(700)
plt.hist(r)
plt.show()
```


    
![svg](README_files/README_34_0.svg)
    


- Lastly, we can use the `randint()` function to generate an array of integers. 
- The `randint()` function can take up to 3 arguments; 
    - the low(inclusive), 
    - high(exclusive) 
    - size of the array.


```python
print(np.random.randint(20)) #generates a random integer exclusive of 20
print()
print(np.random.randint(2, 20))#generates a random integer including 2 but excluding 20
print()
print(np.random.randint(2, 20, 7))#generates 7 random integers including 2 but excluding 20
print()
print(np.random.randint(2, 20, (2,3)))#generates 2D array of shape 2,3
```

    17
    
    12
    
    [10  8 18 18  5 16 15]
    
    [[13  8 13]
     [ 5  8  9]]
    

### NumPy Random Seed

If we set the np.random.seed(a_fixed_number) every time you call the numpy's other random function, the result will be the same:


```python
r= np.random.randint(10,size=(2,3))
print(r)
# changes each time
```

    [[2 3 8]
     [1 3 3]]
    


```python

```


```python
np.random.seed(43)
r= np.random.randint(10,size=(2,3))
print(r) # fixed
```

    [[4 0 1]
     [5 0 3]]
    

## Indexing and Masking


```python
a = np.random.randint(0,20,(5,4)) 
a
```




    array([[ 2, 14, 10, 18],
           [ 3,  6, 19,  6],
           [12,  4, 14, 19],
           [19,  8, 19, 10],
           [17,  6, 16, 16]])




```python
# first row
print(a[0])
# sencond last row
print(a[-2])
# first element
print(a[0,0])
# last element
print(a[4,3])
```

    [ 2 14 10 18]
    [19  8 19 10]
    2
    16
    

### Selecting values from your array that fulfill certain conditions


```python
# print all of the values in the array that are less than 5.
print(ar[ar<5]) 

# numbers that are equal to or greater than 5
print()
five_up = (ar >= 5)
print(ar[five_up])

# elements that are divisible by 2:
print()
divisible_by_2 = a[a%2==0]
print(divisible_by_2)

# elements that satisfy two conditions using the & and | operators:
print()
c = a[(a > 2) & (a < 11)]
print(c)
```

    [2 4 0 3 2 3]
    
    [16  9 16  9  7 15  8  9 11 16  8 10  7 19]
    
    [ 2 14 10 18  6  6 12  4 14  8 10  6 16 16]
    
    [10  3  6  6  4  8 10  6]
    

You can also use `np.where()` to select elements or indices from an array.


```python
# print the indices of elements that are, for example, less than 5:
a = np.array([[1 , 5, 6, 4], 
              [5, 1, 7, 8], 
              [9, 10, 11, 1]])
b = np.where(a<5)
print(b)
```

    (array([0, 0, 1, 2], dtype=int64), array([0, 3, 1, 3], dtype=int64))
    

In this example, a tuple of arrays was returned: one for each dimension.
The first array represents the row indices where these values are found, and
the second array represents the column indices where the values are found. 

### Array slicing

`arr[start_row_idx : end_row_idx + 1, start_col_idx : end_col_idx + 1]`


```python
a = np.array([[1 , 2, 3, 4], 
              [5, 6, 7, 8], 
              [9, 10, 11, 12],
              [1 , 2, 3, 4]])
```


```python
print(a[0:2,0:2])
print()
print(a[:2,:2])
```

    [[1 2]
     [5 6]]
    
    [[1 2]
     [5 6]]
    


```python
# last column only
print(a[:,-1]) # all rows, last column
print()
print(a[:,3])
```

    [ 4  8 12  4]
    
    [ 4  8 12  4]
    


```python
# 2nd last  column only
ans = a[:,-2:-1]
print(ans) 
print()
print(ans[1,0])
```

    [[ 3]
     [ 7]
     [11]
     [ 3]]
    
    7
    

### Masking


```python
a = np.array([[1 , 2, 3, 4], 
              [5, 6, 7, 8], 
              [9, 10, 11, 12],
              [1 , 2, 3, 4]])

a[1:3,1:3] = 0
print(a)
```

    [[ 1  2  3  4]
     [ 5  0  0  8]
     [ 9  0  0 12]
     [ 1  2  3  4]]
    


```python
mask = a>5
print(mask)
```

    [[False False False False]
     [False False False  True]
     [ True False False  True]
     [False False False False]]
    


```python
# get all values greater then 5
a[mask]
```




    array([ 8,  9, 12])


