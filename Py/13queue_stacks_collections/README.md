# Other DSA libs in Python

- [Other DSA libs in Python](#other-dsa-libs-in-python)
  - [Queue](#queue)
    - [Implementation using `list`](#implementation-using-list)
    - [👉Implementation using `collections.deque`](#implementation-using-collectionsdeque)
    - [Implementation using `queue.Queue`](#implementation-using-queuequeue)
    - [`collections.deque` vs `queue.Queue`](#collectionsdeque-vs-queuequeue)

```python
"""
cd .\Py\13queue_stacks_collections\
jupyter nbconvert --to markdown qsc.ipynb --output README.md
"""

```

## Queue

 - [https://www.geeksforgeeks.org/queue-in-python/](https://www.geeksforgeeks.org/queue-in-python/)

There are various ways to implement a queue in Python.


- `list`
- `collections.deque`
- `queue.Queue`

### Implementation using `list`


```python
# Initializing a queue
queue = ['a']

print("Initial queue")
print(queue)
# Adding elements to the queue
queue.append('b')
queue.append('c')
print("\nQueue after adding elements")
print(queue)

# Removing elements from the queue
print("\nElements dequeued from queue")
print(queue.pop(0))
print(queue.pop(0))
print(queue.pop(0))


print("\nQueue after removing elements")
print(queue)

# Uncommenting print(queue.pop(0))
# will raise and IndexError
# as the queue is now empty

```

    Initial queue
    ['a']

    Queue after adding elements
    ['a', 'b', 'c']

    Elements dequeued from queue
    a
    b
    c

    Queue after removing elements
    []



```python
# empty list
if len(queue) == 0:
	print("\nQueue is empty")
# or
if not queue:
	print("\nQueue is empty")


```


    Queue is empty

    Queue is empty


### 👉Implementation using `collections.deque`


Queue in Python can be implemented using deque class from the collections module. **Deque is preferred over list in the cases where we need quicker append and pop operations from both the ends of container**, as deque provides an O(1) time complexity for append and pop operations as compared to list which provides O(n) time complexity. Instead of enqueue and deque, append() and popleft() functions are used.


```python
from collections import deque

# Initializing a queue
# q = deque('a')
# Initializing a queue from list
q = deque(['a'])

print("Initial queue")
print(q)
# Adding elements to a queue
q.append('b')
q.append('c')
print("\nQueue after adding elements")
print(q)


# Removing elements from a queue
print("\nElements dequeued from the queue")
print(q.popleft())
print(q.popleft())
print(q.popleft())

print("\nQueue after removing elements")
print(q)

```

    Initial queue
    deque(['a'])

    Queue after adding elements
    deque(['a', 'b', 'c'])

    Elements dequeued from the queue
    a
    b
    c

    Queue after removing elements
    deque([])



```python
# queue is  empty
if not q:
	print("Queue is empty")
```

    Queue is empty



```python
print(q.popleft())
```


    ---------------------------------------------------------------------------

    IndexError                                Traceback (most recent call last)

    ~\AppData\Local\Temp/ipykernel_20016/1747577676.py in <module>
    ----> 1 print(q.popleft())


    IndexError: pop from an empty deque


### Implementation using `queue.Queue`

Queue is built-in module of Python which is used to implement a queue. `queue.Queue(maxsize)` initializes a variable to a maximum size of `maxsize`. A `maxsize` of zero `‘0’` means a infinite queue. This Queue follows FIFO rule.

- `maxsize` – Number of items allowed in the queue.
- `empty()` – Return True if the queue is empty, False otherwise.
- `full()` – Return True if there are maxsize items in the queue. If the queue was initialized with maxsize=0 (the default), then full() never returns True.
- `get()` – Remove and return an item from the queue. If queue is empty, wait until an item is available.
- `get_nowait()` – Return an item if one is immediately available, else raise QueueEmpty.
- `put(item)` – Put an item into the queue. If the queue is full, wait until a free slot is available before adding the item.
- `put_nowait(item)` – Put an item into the queue without blocking. If no free slot is immediately available, raise QueueFull.
- `qsize()` – Return the number of items in the queue.


```python
from queue import Queue

# Initializing a queue
q = Queue(maxsize = 3)

# qsize() give the maxsize
# of the Queue
print(q.qsize())

# Adding of element to queue
q.put('a')
q.put('b')
q.put('c')

# Return Boolean for Full
# Queue
print("\nFull: ", q.full())

# Removing element from queue
print("\nElements dequeued from the queue")
print(q.get())
print(q.get())
print(q.get())

# Return Boolean for Empty
# Queue
print("\nEmpty: ", q.empty())

q.put(1)
print("\nEmpty: ", q.empty())
print("Full: ", q.full())

# This would result into Infinite
# Loop as the Queue is empty.
# print(q.get())

```

    0

    Full:  True

    Elements dequeued from the queue
    a
    b
    c

    Empty:  True

    Empty:  False
    Full:  False


### `collections.deque` vs `queue.Queue`

`Queue.Queue` and `collections.deque` serve different purposes. `Queue.Queue` is intended for **allowing different threads to communicate using queued messages/data**, whereas `collections.deque` is simply intended as a **datastructure**. That's why Queue.Queue has methods like `put_nowait()`, `get_nowait()`, and `join()`, whereas `collections.deque` doesn't. `Queue.Queue` isn't intended to be used as a collection, which is why it lacks the likes of the in operator.

 - [https://stackoverflow.com/questions/717148/queue-queue-vs-collections-deque](https://stackoverflow.com/questions/717148/queue-queue-vs-collections-deque)
 - [https://www.geeksforgeeks.org/difference-between-queue-queue-vs-collections-deque-in-python/](https://www.geeksforgeeks.org/difference-between-queue-queue-vs-collections-deque-in-python/)
