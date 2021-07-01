# LIST

### Indexing/Slicing of List works same as String



```python

l = [1,2,3,4,5,6]

print(l[0])
print(l[-1])
print(l[1:-1])

# because of mutable property
l[0] = 5
print(l)
```

    1
    6
    [2, 3, 4, 5]
    [5, 2, 3, 4, 5, 6]
    


```python
numbers = list(range(20))
print(numbers[::2])
```

    [0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
    

### Unpacking Operator


```python
# rest equivalent
n = list(range(5))
first,second,*other =n

print(first)
print(second)
print(other)

print()
first,*other,last =n

print(first)
print(last)
print(other)

print()
n = [*range(5),*"Hello"]
print(n)
```

    0
    1
    [2, 3, 4]
    
    0
    4
    [1, 2, 3]
    
    [0, 1, 2, 3, 4, 'H', 'e', 'l', 'l', 'o']
    

### iteration


```python
programming_lan= ["Java","C","C++","Kotlin","TypeScript"]

v = "C" in programming_lan
print(v)

# looping
for lan in programming_lan:
    print(lan)

print()

# looping with enumerate()
for lan in enumerate(programming_lan):
    print(lan)

print()
# also returns each item with its index postion.
for i,v in enumerate(programming_lan):
    print(f"{i+1}: {v}")

```

    True
    Java
    C
    C++
    Kotlin
    TypeScript
    
    (0, 'Java')
    (1, 'C')
    (2, 'C++')
    (3, 'Kotlin')
    (4, 'TypeScript')
    
    1: Java
    2: C
    3: C++
    4: Kotlin
    5: TypeScript
    

## Some methods for list 

### add


```python
# add the given element at the end of the list
l.append(33)
print(l)
# insert 10 at index 1
l.insert(1,10)
print(l)

```

    [5, 2, 3, 4, 5, 6, 33]
    [5, 10, 2, 3, 4, 5, 6, 33]
    

### remove


```python
# pop():
# delete the last element
# can also delete from specified index
l.pop()
print(l)
l.pop(1)
print(l)

# remove()
l.remove(5)
print(l)

del l[0:3]
print(l)

l.clear()
print(l)
```

    [5, 10, 2, 3, 4, 5, 6]
    [5, 2, 3, 4, 5, 6]
    [2, 3, 4, 5, 6]
    [5, 6]
    []
    


```python
# reverse
l.reverse()
print(l)
```

    [6, 5, 4, 3, 2]
    

### Finding Items


```python
letters = ["a","b","c"]
print(letters.count("d"))

if "b" in letters:
    print(letters.index("b"))
```

    0
    1
    

## 2D list 


```python
list_2d = [[1,2,3],[4,5,6,],[7,8,9]]
print(list_2d)

# accessing element in 2D list
print(list_2d[1])
print(list_2d[1][0])

```

    [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    [4, 5, 6]
    4
    

## Sorting


```python
l=[1,2,3,4,5]

l.sort(reverse=True)
print(l)
l.sort()
print(l)

# sorted() returns new list
sorted_list =sorted(l,reverse=True)
print(sorted_list)

# Case-Insensitive Sorting
l=['a','B','e','D','c']
l.sort()
print(l)
l.sort(key=str.casefold)
print(l)

```

    [5, 4, 3, 2, 1]
    [1, 2, 3, 4, 5]
    [5, 4, 3, 2, 1]
    ['B', 'D', 'a', 'c', 'e']
    ['a', 'B', 'c', 'D', 'e']
    


```python
items = [
    ("product 1",10),
    ("product 2",5),
    ("product 4",45),
    ("product 5",23),
]

def sorted_item(i):
    return i[1] #return price

items.sort(key=sorted_item)
print(items)
```

    [('product 2', 5), ('product 1', 10), ('product 5', 23), ('product 4', 45)]
    

#### Using lembda:

syntax:

`lembda parameters:expression` 


```python
items = [
    ("product 1",10),
    ("product 2",5),
    ("product 4",45),
    ("product 5",23),
]
# def sorted_item(i):
#     return i[1]
items.sort(key=lambda i:i[1])
print(items)
```

    [('product 2', 5), ('product 1', 10), ('product 5', 23), ('product 4', 45)]
    

## Map Function


```python
items = [
    ("product 1",10),
    ("product 2",5),
    ("product 4",45),
    ("proeduct 5",23),
]
# extracting price from list of tuples
prices = []
for item in items:
    prices.append(item[1])

print(prices)
print()
# using map
prices_mapped = map(lambda item:item[1],items)
print(type(prices_mapped))
prices = list(prices_mapped)
print(prices)
```

    [10, 5, 45, 23]
    
    <class 'map'>
    [10, 5, 45, 23]
    

## Filter Function


```python
filtered = list(filter(lambda item:item[1]>=10,items ))
print(filtered)
```

    [('product 1', 10), ('product 4', 45), ('proeduct 5', 23)]
    

## List Comprehension

`[expression for item in list]`

```python
letters = list(map(lambda x: x, 'human'))
print(letters) # ['h','u','m','a','n']

```


```python
l = [1,2,3,4,5,6]
# creating a new list of squares of each element
new_l = []
for el in l:
    new_l.append(el**2)

print(new_l)

# With List Comprehension:

new_l = [el**2 for el in new_l] # [(What to Store ) for each element of list]
print(new_l)

```

    [1, 4, 9, 16, 25, 36]
    [1, 16, 81, 256, 625, 1296]
    

### Replacing Map and Filter function with list comprehension


```python
items = [
    ("product 1",10),
    ("product 2",5),
    ("product 4",45),
    ("proeduct 5",23),
]

# prices = list(map(lambda item:item[1],items))
prices = [item[1] for item in items]
# filtered = list(filter(lambda item:item[1]>=10,items ))
filtered = [item for item in items if item[1] >= 10]


print(prices)
print(filtered)
```

    [10, 5, 45, 23]
    [('product 1', 10), ('product 4', 45), ('proeduct 5', 23)]
    

### Difference between Generator Expressions and List Comprehensions

**What are Generator Expressions?**

Generator Expressions are somewhat similar to list comprehensions, but the former doesn’t construct list object. Instead of creating a list and keeping the whole sequence in the memory, the generator generates the next element in demand.
When a normal function with a return statement is called, it **terminates** whenever it gets a return statement. But a function with a yield statement **saves the state of the function and can be picked up from the same state, next time the function is called.**

The Generator Expression allows us to create a generator _without the yield keyword._without



```python
# List Comprehension
list_comprehension = [i for i in range(11) if i % 2 == 0]
  
print(list_comprehension)

# Generator Expression
generator_expression = (i for i in range(11) if i % 2 == 0)
print(generator_expression)
for i in generator_expression:
    print(i, end=" ")
```

    [0, 2, 4, 6, 8, 10]
    <generator object <genexpr> at 0x00000242AFC14C80>
    0 2 4 6 8 10 

**So what’s the difference between Generator Expressions and List Comprehensions?**

The generator yields one item at a time and generates item only when in demand. Whereas, in a list comprehension, Python reserves memory for the whole list. Thus we can say that the generator expressions are memory efficient than the lists. Generator expressions are also faster than list comprehension and hence time efficient.


```python
# import getsizeof from sys module
from sys import getsizeof
  
comp = [i for i in range(10000)]
gen = (i for i in range(10000))
  
#gives size for list comprehension
x = getsizeof(comp) 
print("x = ", x)
  
#gives size for generator expression
y = getsizeof(gen) 
print("y = ", y)
```

    x =  87616
    y =  112
    

## Zip Function


```python
l1 = [1,2,3]
l2= [10,20,30]

print(list(zip(l1,l2)))
print(list(zip("abc",l1,l2)))
```

    [(1, 10), (2, 20), (3, 30)]
    [('a', 1, 10), ('b', 2, 20), ('c', 3, 30)]
    

# Examples


```python
op ="xx"
lan = []

while op !='0':
    if op in "12345":
        print(f"Adding {op}")
        if op == '1':
            lan.append("Java")
        elif op =='2':
            lan.append("C")
        elif op =='3':
            lan.append("C++")
        elif op =='4':
            lan.append("Kotlin")
        elif op =='5':
            lan.append("TypeScript")
    else:
        print("Please add options from the list below:")
        print("1:Java")
        print("2:C")
        print("3:C++")
        print("4:Kotlin")
        print("5:TypeScript")
        print()
    
    op = input()

print(f"Selected Language: {lan}")
      
```

    Please add options from the list below:
    1:Java
    2:C
    3:C++
    4:Kotlin
    5:TypeScript
    
    Adding 1
    Adding 1
    Adding 2
    Adding 3
    Selected Language: ['Java', 'Java', 'C', 'C++']
    
