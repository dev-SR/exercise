# NumPy

- [NumPy](#numpy)
  - [Why Numpy?](#why-numpy)
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
    - [Array slicing](#array-slicing)
      - [Negative slicing of NumPy arrays](#negative-slicing-of-numpy-arrays)
    - [Masking](#masking)
    - [Selecting values from your array that fulfill certain conditions](#selecting-values-from-your-array-that-fulfill-certain-conditions)
      - [`np.where()` to select elements or indices from an array](#npwhere-to-select-elements-or-indices-from-an-array)
  - [3D Arrays](#3d-arrays)
    - [Converting to 1D array with `flatten()` method](#converting-to-1d-array-with-flatten-method)

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

## Array Creation

`array`: Fundamental element in numpy is homogenous array. Numpy Arrays can be 1D, 2D, 3D ...nD

Different ways to create np array:

### 1) Converting Python sequences to NumPy Arrays

- `np.array()`

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

![svg](README_files/README_27_0.svg)

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

    array([[ 1,  9, 12, 13],
           [15, 17,  3, 15],
           [ 8,  9,  4,  3],
           [18,  4,  1,  5],
           [ 0,  8,  4, 11]])

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

### Array slicing

`arr[start_row_idx : end_row_idx + 1, start_col_idx : end_col_idx + 1]`

```python
a = np.array([[1 , 2, 3, 4], 
              [5, 6, 7, 8], 
              [9, 10, 11, 12],
              [13 , 14, 15, 16]])
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

<div align="center"><img src="img/index_slice.jpg" alt="Itrtype" ></div>

```python
print(a[:,1]) #all rows of column 2
print("vs")
print(a[:,1:2]) #all rows of column 2
```

    [ 2  6 10 14]
    vs
    [[ 2]
     [ 6]
     [10]
     [14]]

```python
print(a[1,:]) #all columns of row 2
print("vs")
print(a[1:2,:]) #all columns of row 2
```

    [5 6 7 8]
    vs
    [[5 6 7 8]]

```python
print(a[:,2:]) #all rows of last two rows
```

    [[ 3  4]
     [ 7  8]
     [11 12]
     [15 16]]

#### Negative slicing of NumPy arrays

```python
# last column only
print(a[:,-1]) # all rows, last column
print()
print(a[:,3])
```

    [ 4  8 12 16]
    
    [ 4  8 12 16]

```python
#  last two  column only
ans = a[:,-2:]
print(ans) 
print()
print(ans[1,0])
```

    [[ 3  4]
     [ 7  8]
     [11 12]
     [15 16]]
    
    7

If, however, we wanted to extract from the end, we would have to explicitly provide a negative step-size otherwise the result would be an empty list.

```python
print(a[:,-1:-3:-1])
```

    [[ 4  3]
     [ 8  7]
     [12 11]
     [16 15]]

```python
print('Reversed array :','\n',a[::-1,::-1])
```

    Reversed array : 
     [[16 15 14 13]
     [12 11 10  9]
     [ 8  7  6  5]
     [ 4  3  2  1]]

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

#### `np.where()` to select elements or indices from an array

```python
# print the indices of elements that are, for example, less than 5:
a = np.array([[1 , 5, 6, 4], 
              [5, 1, 7, 8], 
              [9, 10, 11, 1]])
b = np.where(a<5)
print(b)
```

```python
In this example, a tuple of arrays was returned: one for each dimension.
The first array represents the row indices where these values are found, and
the second array represents the column indices where the values are found. 
```

## 3D Arrays

 <div align="center"><img src="img/array_creation.jpg" alt="Itrtype" ></div>

```python
a = np.array([[[1,2],[3,4],[5,6]],# first axis array
[[7,8],[9,10],[11,12]],# second axis array
[[13,14],[15,16],[17,18]]])# third axis array

a.shape # 3 sets , 3 rows, 2 columns
```

    (3, 3, 2)

```python
# value
print(a[0],'\n')
print(a[0,0],'\n')
# First array, first row, first column value
print(a[0,0,0],'\n')
# First array last column 
print(a[0,:,1],'\n')
```

    [[1 2]
     [3 4]
     [5 6]] 
    
    [1 2] 
    
    1 
    
    [2 4 6] 

```python
print(a[1])
print()
print(a[2])
print()
print("first row from each arrays:",'\n')
print(a[:,0,:2])
```

    [[ 7  8]
     [ 9 10]
     [11 12]]
    
    [[13 14]
     [15 16]
     [17 18]]
    
    first row from each arrays: 
    
    [[ 1  2]
     [ 7  8]
     [13 14]]

```python
# First one rows for second and third arrays:
print(a[1:,:1,:2])
print('\n',"watch out!!",'\n')
# First one rows for second and third arrays:
print(a[1:,0,:2],'\n')
```

    [[[ 7  8]]
    
     [[13 14]]]
    
     watch out!! 
    
    [[ 7  8]
     [13 14]] 

```python

```

### Converting to 1D array with `flatten()` method

```python
print('Printing as a single array :','\n',a[1:,0:2,0:2].flatten())
```

    Printing as a single array : 
     [ 7  8  9 10 13 14 15 16]

```python

```

    [[[ 5  6]
      [ 3  4]]
    
     [[11 12]
      [ 9 10]]
    
     [[17 18]
      [15 16]]]
