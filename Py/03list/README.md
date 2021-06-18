# LIST

### Indexing/Slicing of List works same as String



```python
l = [1,2,3,4,5,6]

print(l[0])
print(l[-1])
print(l[1:-1])

# because of mutable property
my_list[0] = 5
print(my_list)
```

    1
    6
    [2, 3, 4, 5]
    [5, 2, 3, 4, 5, 6]
    

## Some methods for list 


```python
# add the given element at the end of the list
l.append(33)
print(l)

```

    [1, 2, 3, 4, 5, 6, 33]
    


```python
# insert 10 at index 1
l.insert(1,10)
print(l)
```

    [1, 10, 2, 3, 4, 5, 6, 33]
    


```python
# pop():
# delete the last element
# can also delete from specified index
l.pop()
print(l)
l.pop(1)
print(l)

# remove(idx)
l.remove(1)
print(l)
```

    [1, 10, 2, 3, 4, 5, 6]
    [1, 2, 3, 4, 5, 6]
    [2, 3, 4, 5, 6]
    


```python
# reverse
l.reverse()
print(l)
```

    [6, 5, 4, 3, 2]
    


```python

```


```python
programming_lan= ["Java","C","C++","Kotlin","TypeScript"]

v = "C" in programming_lan
print(v)

# looping
for lan in programming_lan:
    print(lan)

# accessing List
print()
print(f"at 3: {programming_lan[2]}") 
print(f"first 2 item: {programming_lan[0:2]}") 
print(f"last: {programming_lan[-1]}") 

#common methods:
print()
l=[2,4,6,8]
print(min(l))
print(max(l))
print(len(l))


```

    True
    Java
    C
    C++
    Kotlin
    TypeScript
    
    at 3: C++
    first 2 item: ['Java', 'C']
    last: TypeScript
    
    2
    8
    4
    

## List Comprehension


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
    


```python
# e.g of heterogenous list

l2 = [4,True,98.4,[6,9,1],"Py"]
print(l2)
```

    [4, True, 98.4, [6, 9, 1], 'Py']
    

### 2D list 


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
    

## Built-in Function:

### enumerate():
##### returns each item with its index postion.


```python
programming_lan= ["Java","C","C++","Kotlin","TypeScript"]

# looping
for lan in enumerate(programming_lan):
    print(lan)

print()

for i,v in enumerate(programming_lan):
    print(f"{i+1}: {v}")

str
```

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
    

### any(iterable)
##### returns True if any element of the iterable is true. 


```python
print(any([1,0]))
print(any([False,0,"",]))
print(any([]))
```

    True
    False
    False
    

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
    

## Generating List


```python
lists =[]
for i in range(1,10):
    lists.append(str(i))
print(lists)

print()

lists = [str(i) for i in range(10,15)]
print(lists)
```

    ['1', '2', '3', '4', '5', '6', '7', '8', '9']
    
    ['10', '11', '12', '13', '14']
    

## Creating List


```python
l1 = [1,2,3]
l2= [4,5,6]
l=l1+l2
print(l)
print()

l3=sorted(l,reverse=True)
print(l3)

# digits = list('22')
# print(digits)

print()
copy = l[:]
print(copy)
copy =l.copy()
print(copy)
# copy() is more efficient 
```

    [1, 2, 3, 4, 5, 6]
    
    [6, 5, 4, 3, 2, 1]
    
    [1, 2, 3, 4, 5, 6]
    [1, 2, 3, 4, 5, 6]
    

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
    
