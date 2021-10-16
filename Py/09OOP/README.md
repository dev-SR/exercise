- [OOP](#oop)
  - [OOP concept](#oop-concept)
  - [OOP in Python](#oop-in-python)
    - [Private members](#private-members)
      - [force accessing private methods using `__dict__`](#force-accessing-private-methods-using-__dict__)
  - [Magic Methods](#magic-methods)
    - [Comparing Objects](#comparing-objects)
    - [Custom containers](#custom-containers)
  - [Inheritance](#inheritance)
    - [Method Overriding with super()](#method-overriding-with-super)
    - [Multiple Inheritance](#multiple-inheritance)
  - [Abstract Base Classes](#abstract-base-classes)
  - [Polymorphism](#polymorphism)

# OOP

## OOP concept

**Abstraction**

- Data Abstraction is the property through which only essential details are displayed to the user
- Hiding the implementation
- e.g. the working of a car

**Encapsulation**

- wrapping up of data into one unit
- All the properties and methods are combined together

**Inheritance**

- It is the mechanism by which one class is allowed to inherit the feature (properties and methods) of another class
- This offers a lot of reusability of code

**Polymorphism**

- The word polymorphism means having many forms
- We can define polymorphism as the ability of a message to be displayed in more than one form

## OOP in Python

**Defining the constructor of a Class**

- A constructor is a special member function of a class that is executed whenever we create new objects of the class.

```python
def __init__(self):
    ...
    ...
```

**Defining the methods of a instance**

```
def intro(self):
    ...
    ...
```

In object-oriented programming, variables at the class level are referred to as class variables, whereas variables at the object level are called instance variables.

**Class Variable**

- defined within the _class construction_
- shared by all instances of the class
- They are associated with the class
- Accessed by `class_name.variable`

They therefore will generally have the same value for every instance unless you are using the class variable to initialize a variable.

**Instance Variables**

Instance variables are owned by instances of the class. This means that for each object or instance of a class, the instance variables are different.

Unlike class variables, instance variables are defined within methods.

Instance variables, owned by objects of the class, allow for each object or instance to have different values assigned to those variables.


```python
class Test:
    # class variable - common to all
	class_var= 0

	def __init__(self,v):
	 # instance variables - only availabe to instance
		self.instance_var = v

t1= Test(10)
t2= Test(20)

print(t1.class_var)
print(t1.instance_var)
print()
print(t2.class_var)
print(t2.instance_var)

```

    0
    10

    0
    20



```python
class Human:

    # class variable - common to all
    database = []
    population = 0
    id_seq = 0

    def __init__(self,name,age,is_alive = True):
        # instance variables - only availabe to instance
        self.name = name
        self.age = age
        self.is_alive = is_alive
        #
        self.id = Human.id_seq
        Human.id_seq += 1
        Human.population += 1
        Human.database.append(self)

    # instance methods
    def intro(self):
        print("Hi, My name is",self.name,"My age is",self.age)

    def die(self):
        if self.is_alive:
            print(self.name, "is dying")
            self.is_alive = False
            Human.population -= 1
        else:
            print("{} is already dead".format(self.name))
```


```python
h1 = Human("soikat",22)
h2 = Human("Jhon",69)
```


```python
h1.intro()
h2.intro()
```

    Hi, My name is soikat My age is 22
    Hi, My name is Jhon My age is 69



```python
# class variables:
print(Human.population)
print(Human.id_seq)

# class variable is common for all
print(h1.population)
print(h2.population)
# instance variable is not
print(h1.name)
print(h2.name)
```

    2
    2
    2
    2
    soikat
    Jhon



```python
h1.is_alive
```




    True




```python
h1.die()
```

    soikat is dying



```python
h1.is_alive
```




    False




```python
h1.die()
```

    soikat is already dead



```python
Human.population
```




    1



### Private members


```python
class FrqCounter():
    def __init__(self):
        self.d = {}

    def add(self,v):
        self.d[v.lower()] = self.d.get(v.lower(),0) + 1

    def __str__(self):
        return f"FC ({self.d})"
```


```python
fcnt = FrqCounter()
fcnt.add("python")
fcnt.add("Python")
fcnt.add("C++")
fcnt.d["python"] = 10 # but direct access should not be allowed
print(fcnt)

```

    FC ({'python': 10, 'c++': 1})


> making 'd' private


```python
class FrqCounter():
    def __init__(self):
        self.__d = {}

    def add(self,v):
        self.__d[v.lower()] = self.__d.get(v.lower(),0) + 1

    def __str__(self):
        return f"FC ({self.d})"
```


```python
fcnt = FrqCounter()
fcnt.add("python")
fcnt.add("Python")
fcnt.add("C++")
fcnt.d["python"] = 10 # AttributeError
print(fcnt.d) # AttributeError
print(fcnt.__d) # AttributeError
```


    ---------------------------------------------------------------------------

    AttributeError                            Traceback (most recent call last)

    <ipython-input-47-1eebd60a5344> in <module>
          3 fcnt.add("Python")
          4 fcnt.add("C++")
    ----> 5 fcnt.d["python"] = 10 # AttributeError
          6 print(fcnt.d) # AttributeError
          7 print(fcnt.__d) # AttributeError


    AttributeError: 'FrqCounter' object has no attribute 'd'


#### force accessing private methods using `__dict__`


```python
 print(fcnt.__dict__)
```

    {'_FrqCounter__d': {'python': 2, 'c++': 1}}



```python
print(fcnt._FrqCounter__d)
```

    {'python': 2, 'c++': 1}


## Magic Methods

- they are called automatically when some particular event occur

- e.g. `__repr__`(toString) , `__init__`,, `__str__`


```python
# before overriding __repr__ magic function
print(h1)
print(Human.database)
print(Human.database[0])
print(Human.database[1].name)
```

    <__main__.Human object at 0x0000020FF9D60790>
    [<__main__.Human object at 0x0000020FF9D60790>, <__main__.Human object at 0x0000020FF9D60430>]
    <__main__.Human object at 0x0000020FF9D60790>
    Jhon



```python
class Human():

    # class variable
    database = []
    population = 0
    id_seq = 0

    # constructor
    def __init__(self,name,age,is_alive = True):
        # instance variables
        self.name = name
        self.age = age
        self.is_alive = is_alive
        #
        self.id = Human.id_seq
        Human.id_seq += 1
        Human.population += 1
        Human.database.append(self)

    # instance methods
    def intro(self):
        print("Hi, My name is",self.name,"My age is",self.age)

    def die(self):
        if self.is_alive:
            print(self.name, "is dying")
            self.is_alive = False
            Human.population -= 1
        else:
            print("{} is already dead".format(self.name))

    # __repr__ is a special method used to represent a class’s objects as a string
    def __repr__(self):
        return "%s(%r)" % (self.__class__, self.__dict__)
    # The __str__ method in Python represents the class objects as a string. The __str__ method is
    # called when the following functions are invoked on the object and return a string: print(), str()
    def __str__(self):
        return f"Human [{self.id}, {self.name}, {self.age}, {self.is_alive}]"
    #  `__repr__` vs `__str__`: __repr__ is for developers, __str__ is for customers.
    # If we have not defined the __str__, then it will call the __repr__ method.
```


```python
# after overriding __repr__ magic function
h1 = Human("soikat",22)
h2 = Human("Jhon",69)
# __repr__
print(Human.database)
print()
# __str__
print(h1)
print(str(h1))
print(Human.database[0])


print("other magic methods: \n"+str(dir(Human)))
```

    [<class '__main__.Human'>({'name': 'soikat', 'age': 22, 'is_alive': True, 'id': 0}), <class '__main__.Human'>({'name': 'Jhon', 'age': 69, 'is_alive': True, 'id': 1})]

    Human [0, soikat, 22, True]
    Human [0, soikat, 22, True]
    Human [0, soikat, 22, True]
    other magic methods:
    ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', 'database', 'die', 'id_seq', 'intro', 'population']


### Comparing Objects


```python
class Point():
    def __init__(self,x,y):
        self.x=x
        self.y=y

    def __eq__(self,other):
        return self.x==other.x and self.y==other.y

    def __gt__(self,other):
        return self.x > other.x and self.y>other.y

    def __add__(self,o):
        return Point(self.x+o.x,self.y+o.y)

    def __str__(self):
        return f"Point({self.x} , {self.y})"
```


```python
p1= Point(1,2)
p2= Point(1,2)
p3= Point(10,3)

print(p1==p2)
print(p3>p1)
print(p1+p2)
```

    True
    True
    Point(2 , 4)


### Custom containers


```python
class FreqCount():

    def __init__(self):
        self.d={}

    def add(self,v):
        self.d[v.lower()] = self.d.get(v.lower(),0) + 1

    def __getitem__(self,v):
        return self.d.get(v.lower(),0)

    def __setitem__(self,v,count):
        self.d[v.lower()] = count

    def __len__(self):
        return len(self.d)

    def __iter__(self):
        return iter(self.d)

    def __str__(self):
        return f"FC ({self.d})"

```


```python

fc = FreqCount()
fc.add("python")
fc.add("Python")
fc.add("python")
# print(fc.d) instead use __getitem__
print(fc["python"])
# using __setitem__ instead of fc.d["c++"]
fc["c++"] = 10
# __len__
print(len(fc))
# __str__
print(fc)
print()
# __iter__
for i in fc:
    print(i,"->",fc[i])

```

    3
    2
    FC ({'python': 3, 'c++': 10})

    python -> 3
    c++ -> 10


## Inheritance

-  a process where one class acquire all the methods and properties of another class

**Parent Class** is the class being inherited, also called base class.
**Child Class** is the class that inherits another class, also called derived class.

Syntax :

```python
class ChildClassName(ParentClassName)
```


```python
# Child class
class Hitman(Human):
    # re-initialize constructor
    def __init__(self,name,age):
        super().__init__(name,age)
        # additional hitman properties
        self.kills  = 0
        self.kills_list = []

    def kill(self,person):
        """
        `person` will be an object of Human
        """
        if person.is_alive:
            print("{} is killing {}".format(self.name,person.name))
            person.die()
            self.kills+=1
            self.kills_list.append(person)
        else:
            print("{} is already dead.".format(person.name))

    # function overriding - Achieving Polymorphism:
    def intro(self):
        print("Hi, my nam is {}, I've killed {} people".format(self.name,self.kills))

```


```python
h3 =  Human("Bob",10)
print(Human.population)
print(Human.database)
```

    3
    [[0, soikat, 22, True], [1, Jhon, 69, True], [2, Bob, 10, True]]



```python
bond = Hitman("James",40)
print(bond)
print(Human.population)
print(Human.database)
```

    [3, James, 40, True]
    4
    [[0, soikat, 22, True], [1, Jhon, 69, True], [2, Bob, 10, True], [3, James, 40, True]]



```python
print(Human.population)
print(Human.database)
bond.kill(h3)
print(bond.kills)
print(bond.kills_list)
```

    4
    [[0, soikat, 22, True], [1, Jhon, 69, True], [2, Bob, 10, True], [3, James, 40, True]]
    James is killing Bob
    Bob is dying
    1
    [[2, Bob, 10, False]]



```python
bond.kill(h3)
```

    Bob is already dead.



```python
# Polymorphism
h2.intro()
bond.intro()
```

    Hi, My name is Jhon My age is 69
    Hi, my nam is James, I've killed 1 people


### Method Overriding with super()

The `super()` builtin returns a proxy object (temporary object of the superclass) that allows us to access methods of the base class.

In Python, `super()` has two major use cases:

- Allows us to avoid using the base class name explicitly
- Working with Multiple Inheritance


```python
class Animal():
    def __init__(self):
        print("Animal constructor")
        self.age = 1


class Mammal(Animal):
    def __init__(self):
        print("Mammal constructor")
        self.weight = 2
        super().__init__()

m = Mammal()
print(m.age)
print(m.weight)
```

    Mammal constructor
    Animal constructor
    1
    2


### Multiple Inheritance


```python
class Employee:
    def greet(self):
        print("Employee greeting...")

class Person:
    def greet(self):
        print("Person greeting...")


class Manager(Employee,Person):
    pass

m = Manager()
m.greet()
```

    Employee greeting...



```python
class Manager(Person, Employee):
    pass

m = Manager()
m.greet()
```

    Person greeting...


## Abstract Base Classes

> lets build a class:


```python

```


```python
class InvalidOperationError(Exception):
    pass

class Stream:
    def __init__(self):
        self.opened = False

    def open(self):
        if self.opened:
            raise InvalidOperationError("Stream is Already opened")
        self.opened = True

    def close(self):
        if self.opened:
            raise InvalidOperationError("Stream is Already opened")
        self.opened = True

class FileStream(Stream):
    def read(self):
        print("Reading data from a file")


class NetworkStream(Stream):
    def read(self):
        print("Reading data from a network")

```

**Whats wrong with below code:::**

```py
stream = Stream()
print(stream.opened)
stream.open()
print(stream.opened)
```

We should not allow `Stream()` class to be instantiated as above beacuse `Stream()` is abstruct idea... we don't know what type of stream we are talking about?? is it  `FileStream` or `NetworkStream`



```python
from abc import ABC,abstractmethod
```


```python

class InvalidOperationError(Exception):
    pass

class Stream(ABC):
    def __init__(self):
        self.opened = False

    def open(self):
        if self.opened:
            raise InvalidOperationError("Stream is Already opened")
        self.opened = True

    def close(self):
        if self.opened:
            raise InvalidOperationError("Stream is Already opened")
        self.opened = True

    @abstractmethod
    def read(self):
        pass

class FileStream(Stream):
    def read(self):
        print("Reading data from a file")


class NetworkStream(Stream):
    def read(self):
        print("Reading data from a network")

```

> abstruct class can't be instantiated


```python
stream = Stream()
stream.open()
```


    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    <ipython-input-24-1456ce223969> in <module>
    ----> 1 stream = Stream()
          2 stream.open()


    TypeError: Can't instantiate abstract class Stream with abstract methods read


> Also we now  must implement `read()` method


```python
class MemoryStream(Stream):
    pass

mem = MemoryStream()
```


    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    <ipython-input-25-e4845ed35a73> in <module>
          2     pass
          3
    ----> 4 mem = MemoryStream()


    TypeError: Can't instantiate abstract class MemoryStream with abstract methods read



```python
class MemoryStream(Stream):
    def read():
        print("Memory Stream")

mem = MemoryStream()
mem.open()
print(mem.opened)
```

    True


## Polymorphism

- One function Name can have different functionality.

**Function overriding** - If derived class defines same function in it's base class, it known as function overriding. This is used to achieve Polymorphism.


```python
from abc import ABC,abstractmethod

class UIControl(ABC):
    @abstractmethod
    def draw(self):
        pass

class TextBox(UIControl):
    def draw(self):
        print("TextBox...")

class DropDownList(UIControl):
    def draw(self):
        print("DropDownList....")


def draw(controls):
    for c in controls:
        c.draw()
```


```python

ddl = DropDownList()
txtbx = TextBox()

draw([ddl,txtbx])
```

    DropDownList....
    TextBox...

