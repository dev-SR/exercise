- [Python Iterators](#python-iterators)
  - [Iterating Through an Iterator](#iterating-through-an-iterator)
  - [Loops for Iterators](#loops-for-iterators)
- [Building Custom Iterators](#building-custom-iterators)

# Python Iterators

- Iterators are objects that can be iterated upon.
- Terminology : iterator, iterable, iteration.



<img src="https://media.giphy.com/media/l44QeXqzp5JoYSNe8/giphy.gif" width=200>


**Iterator**
- Any object that you can traverse upon is an **iterator**. An object which will return data, one element at a time.
- Python iterator object must implement two special methods, `__iter__()` and `__next__()` , known as iterator protocol.


**Iterable**
- An object is called **iterable** if we can get an iterator from it. Examples - list, tuple, string etc. are iterables.

**Iteration**
- repetiton of the process.


## Iterating Through an Iterator



```python
# iterable
my_list = [1,2]
# get an iterator.
my_iter = iter(my_list)
my_iter
```




    <list_iterator at 0x286667a8a60>




```python
# next element
next(my_iter)
```




    1




```python
# next element
next(my_iter)
```




    2




```python
# next element
next(my_iter)
```


    ---------------------------------------------------------------------------

    StopIteration                             Traceback (most recent call last)

    <ipython-input-12-56a19a8bf4b2> in <module>
          1 # next element
    ----> 2 next(my_iter)


    StopIteration:


## Loops for Iterators

- A more elegant way of automatically iterating is by using the for loop.
- We can iterate over any object that can return an iterator, for example list, string, file etc.


```python
for ele in my_list:
    print(ele)
```

    1
    2



```python
my_iter = iter(my_list)

# infinte while loop
while True:
    try:
        # getting the next element
        ele = next(my_iter)
        print(ele)
    except StopIteration:
        # all the elements are exhausated.
        break
```

    1
    2


# Building Custom Iterators
- Every custom iterator must implement the `__iter__()` and the `__next__()` methods.
- The `__iter__()` method returns the iterator object itself.
- The `__next__()` method must return the next item in the sequence. On reaching the last element, it must raise StopIteration.


```python
class CubeNumber:
    def __init__(self, number = 0):
        self.number = number

    def __iter__(self):
        self.ele = 0
        return self

    def __next__(self):
        if self.ele <= self.number:
            result = self.ele**3 # 0^3,....
            self.ele += 1  # move pointer to next number 0^3 -> 1^3 -> 2^3...
            return result
        else:
            raise StopIteration
```


```python
cn = CubeNumber(5)
```


```python
my_iter = cn.__iter__()
```


```python
my_iter.__next__()
```




    0




```python
my_iter.__next__()
```




    1




```python
my_iter.__next__()
```




    8




```python
my_iter.__next__()
```




    27




```python
my_iter.__next__()
```




    64




```python
my_iter.__next__()
```




    125




```python
my_iter.__next__()
```


    ---------------------------------------------------------------------------

    StopIteration                             Traceback (most recent call last)

    <ipython-input-30-56d779eb7d74> in <module>
    ----> 1 my_iter.__next__()


    <ipython-input-21-5f3b4bdd8d50> in __next__(self)
         13             return result
         14         else:
    ---> 15             raise StopIteration


    StopIteration:



```python
for ele in cn:
    print(ele)
```

    0
    1
    8
    27
    64
    125

