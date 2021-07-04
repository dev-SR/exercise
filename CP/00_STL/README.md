# STL: Standard Template Library

STL is an acronym for standard template library. It is a set of C++ template classes that provide generic classes and function that can be used to implement data structures and algorithms .STL is mainly composed of :

- Algorithms
- Containers
- Iterators

## Containers in STL

**Sequence Containers:** implement data structures which can be accessed in a sequential manner.

- `vector`
- `list`
- `dequeue`
- `arrays`
- `forward list`

**Container Adaptors :** provide a different interface for sequential containers.

- `queue`
- `priority_queue`
- `stack`

**Associative Containers :** implement sorted data structures that can be quickly searched ( O(log(n)) complexity)

- `set`
- `multiset`
- `map`
- `multimap`

**Unordered Associative Containers**: implement unordered data structures that can be quickly
searched

- `unordered set`
- `unordered multiset`
- `unordered map`
- `unordered multimap`

## Iterators

Iterators as an entity that helps us to access the data within a container with certain
restrictions.

**Input Iterators:**

A entity through which you can read data from container and move ahead.
For example - A Keyboard

**Output Iterators:**

A entity through which you can write into the container and move ahead.

**Forward Iterators:**

Iterator with functionalities of input and output iterator in single direction.
For Example - Singly Linked List

**Bidirectional Iterators:**

Forward Iterator that can move in both directions.

**Random Access Iterators:**
Random Access Iterator is an iterator that can read/write in both directions and also can take
jumps.