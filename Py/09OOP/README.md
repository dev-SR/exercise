- [OOP](#oop)
  - [OOP concept](#oop-concept)
  - [OOP in Python](#oop-in-python)
    - [Instance Attribute and Class Attributes](#instance-attribute-and-class-attributes)
      - [Class Attributes](#class-attributes)
      - [Instance Variables](#instance-variables)
    - [EX- 1](#ex--1)
    - [Private members](#private-members)
      - [Name Mangling to access private members](#name-mangling-to-access-private-members)
    - [Magic Methods](#magic-methods)
    - [Comparing Objects](#comparing-objects)
    - [Custom containers](#custom-containers)
    - [Class method and Static method](#class-method-and-static-method)
      - [Static Method](#static-method)
      - [Class Method](#class-method)
        - [When do you use the class method?](#when-do-you-use-the-class-method)
          - [1. Factory methods](#1-factory-methods)
          - [2. Correct instance creation in inheritance](#2-correct-instance-creation-in-inheritance)
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

### Instance Attribute and Class Attributes

#### Class Attributes

- defined within the _class construction_
- shared by all instances of the class
- They are associated with the class
- Accessed by `class_name.variable`

They therefore will generally have the same value for every instance unless you are using the class variable to initialize a variable.

#### Instance Variables

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
		# local variable - only availabe to method
		local_var = 0

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
t1.local_var
```


    ---------------------------------------------------------------------------

    AttributeError                            Traceback (most recent call last)

    <ipython-input-28-bac5ddb7ca08> in <module>
    ----> 1 t1.local_var


    AttributeError: 'Test' object has no attribute 'local_var'



```python
print(t1.__dict__)
print(t2.__dict__)
```

    {'instance_var': 10}
    {'instance_var': 20}



```python
print(hasattr(t1,'instance_var'))
print(hasattr(t1, 'class_var'))
print(hasattr(t1, '__init__'))

print(getattr(t1,'instance_var'))
print(getattr(t1, 'class_var'))
```

    True
    True
    True
    10
    0


### EX- 1


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

The `private` members of a class are only accessible within the class. In Python, a private member can be defined by using a prefix `__` (double underscore).



```python
class FrqCounter():
    def __init__(self):
        # private member
        self.__d = {}

    def add(self,v):
        # private members are accessible from a class
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


#### Name Mangling to access private members

Python performs name mangling on private attributes. Every member with a double underscore will be changed to `object._class__variable`.


```python
print(fcnt._FrqCounter__d)
```

    {'python': 2, 'c++': 1}



```python
 print(fcnt.__dict__)
```

    {'_FrqCounter__d': {'python': 2, 'c++': 1}}


### Magic Methods

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


### Class method and Static method

#### Static Method

A static method does not receive an implicit first argument (`self`).

Syntax:

```python
class C(object):
    @staticmethod
    def fun(arg1, arg2, ...):
        ...
returns: a static method for function fun.
```

- A static method is also a method that is bound to the class and not the object of the class.
- A static method can’t access or modify the class state.
- It is present in a class because it makes sense for the method to be present in class.


```python
class Student():
	def __init__(self,name,age):
		self.name = name
		self.age = age

	def __str__(self):
		return f"Student [{self.name}, {self.age}]"

	@staticmethod
	def welcomeToSchool(): # self is not required
		print("Welcome to School!!")

	@staticmethod
	def isTeen(self,age): # explicitly mentioning self
		return age>=13 and age<=19

s1 = Student("soikat",22)
s1.welcomeToSchool()

```

    Welcome to School!!



```python
Student.welcomeToSchool()
```

    Welcome to School!!



```python
Student.isTeen(s1,22)
```




    False



#### Class Method

Class methods are methods that are called on the class itself, not on a specific object instance. Therefore, it belongs to a class level, and all class instances share a class method.

- **A class method is bound to the class and not the object of the class**. It can access only class variables.
- It can modify the class state by changing the value of a class variable that would apply across all the class objects.

The difference between a static method and a class method is:

- Static method knows nothing about the class and just deals with the parameters
- Class method works with the class since its parameter is always the class itself.

The class method can be called both by the class and its object.

```python
class C(object):
    @classmethod
    def fun(cls, arg1, arg2, ...):
       ....
# fun: function that needs to be converted into a class method
# returns: a class method for function.
```


##### When do you use the class method?

###### 1. Factory methods

Class methods are used when we are dealing with factory methods. **Factory methods are those methods that return a class object for different use cases**. Thus, factory methods create concrete implementations of a common interface.

It is similar to function overloading in C++. Since, Python doesn't have anything as such, class methods and static methods are used.



```python
from datetime import date


class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    @classmethod
    def calculate_age(cls, name, birth_year):
        # calculate age an set it as a age
        # return new object
        return cls(name, date.today().year - birth_year)

    def show(self):
        print(self.name + "'s age is: " + str(self.age))


jessa = Student('Jessa', 20)
jessa.show()

# create new object using the factory method
joy = Student.calculate_age("Joy", 1995)
joy.show()

```

    Jessa's age is: 20
    Joy's age is: 26


The constructor takes normal parameters `name` and `age`. While, `fromBirthYear` takes `class`, `name` and `birthYear`, calculates the current age by subtracting it with the current year and returns the class instance.

The `fromBirthYear` method takes `Person` class (not `Person` object) as the first parameter `cls` and **returns** the constructor by calling `cls(name, date.today().year - birthYear)`, which is equivalent to `Person(name, date.today().year - birthYear)`

###### 2. Correct instance creation in inheritance

Whenever you derive a class from implementing a factory method as a class method, it ensures correct instance creation of the derived class.

You can create a static method for the above example but the object it creates, will always be hard coded as Base class.

But, when you use a class method, it creates the correct instance of the derived class.


```python
from datetime import date

# random Person
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    @staticmethod
    def fromFathersAge(name, fatherAge, fatherPersonAgeDiff):
        return Person(name, date.today().year - fatherAge + fatherPersonAgeDiff)

    @classmethod
    def fromBirthYear(cls, name, birthYear):
        return cls(name, date.today().year - birthYear)

    def display(self):
        print(self.name + "'s age is: " + str(self.age))

# Inheritance
class Man(Person):
    sex = 'Male'


man = Man.fromBirthYear('John', 1985) # using classmethod
print(isinstance(man, Man))

man1 = Man.fromFathersAge('John', 1965, 20) # using staticmethod
print(isinstance(man1, Man))

```

    True
    False


Here, using a `static` method to create a class instance wants us to hardcode the instance type during creation.

This clearly causes a problem when inheriting `Person` to `Man`.

`fromFathersAge` method **doesn't return** a `Man` object but its base class `Person`'s object.

This violates the OOP paradigm. Using a class method as `fromBirthYear` can ensure the OOP-ness of the code since it takes the first parameter as the class itself and calls its factory method.

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

