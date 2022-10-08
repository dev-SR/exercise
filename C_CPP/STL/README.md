# STL: Standard Template Library

- [STL: Standard Template Library](#stl-standard-template-library)
  - [Intro](#intro)
    - [Containers in STL](#containers-in-stl)

## Intro

STL is an acronym for standard template library. It is a set of C++ template classes that provide generic classes and function that can be used to implement data structures and algorithms .STL is mainly composed of :

- `Algorithms`
- `Containers`
- `Iterators`

### Containers in STL

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
