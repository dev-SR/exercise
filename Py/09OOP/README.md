# OOP

- [OOP](#oop)
  - [OOP concept](#oop-concept)
  - [Basics](#basics)
  - [Instance Attribute and Class Attributes](#instance-attribute-and-class-attributes)
      - [EX- 1](#ex--1)
  - [Encapsulation : Private members](#encapsulation--private-members)
    - [Getters and Setters](#getters-and-setters)
      - [Using normal function](#using-normal-function)
      - [Using `@property` decorators as 'getter'](#using-property-decorators-as-getter)
  - [Class method and Static method](#class-method-and-static-method)
  - [Magic Methods](#magic-methods)
    - [`__repr__`  vs `__str__`](#__repr__--vs-__str__)
    - [`__hash__`](#__hash__)
    - [Comparing Objects](#comparing-objects)
  - [Inheritance](#inheritance)
    - [Intro](#intro)
    - [super()](#super)
    - [Multiple Inheritance](#multiple-inheritance)
  - [Abstract Class in python](#abstract-class-in-python)
  - [Polymorphism](#polymorphism)


```python
"""
cd .\Py\09OOP\
jupyter nbconvert py_oop.ipynb --to markdown  --output README.md
"""

```

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

## Basics

**Defining the constructor of a Class**

- A constructor is a special member function of a class that is executed whenever we create new objects of the class.

```python
def __init__(self):
    ...
    ...
```

The `__init__` method is a special method in Python classes that is *automatically called when an object is created from the class.* It is used to initialize the object's attributes and perform setup tasks


**Defining the methods of a instance**

```
def intro(self):
    ...
    ...
```

In object-oriented programming, variables at the class level are referred to as class variables, whereas variables at the object level are called instance variables.



## Instance Attribute and Class Attributes

**Class Attributes**

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
	 # instance variables - only available to instance
		self.instance_var = v
		# local variable - only available to current method
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


#### EX- 1


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
        # accessing class variable
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



## Encapsulation : Private members

Encapsulation is the process of bundling data and methods together within a class. It allows for data hiding and controlling access to the object's attributes using getter and setter methods.



```python
class Test:
	def __init__(self):
		self.__private = 0
		self._not_so_private = 0


t = Test()

print(t._not_so_private)  # 0
print(t.__private)  # AttributeError: 'Test' object has no attribute '__private'

```

    0



    ---------------------------------------------------------------------------

    AttributeError                            Traceback (most recent call last)

    <ipython-input-1-747979b56390> in <module>
          8
          9 print(t._not_so_private)  # 0
    ---> 10 print(t.__private)  # AttributeError: 'Test' object has no attribute '__private'


    AttributeError: 'Test' object has no attribute '__private'


Why do we need private members?


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
print(fcnt)
fcnt.add("C++")
fcnt.d["python"] = 10 # but direct access should not be allowed
print(fcnt)

```

    FC ({'python': 2})
    FC ({'python': 10, 'c++': 1})


> making 'd' private

The `private` members of a class are only accessible within the class. In Python, a private member can be defined by using a prefix `__` (double underscore).



```python
class FrqCounter():
    def __init__(self):
        # private member using `__` prefix ; !!not `_`
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
# fcnt.d["python"] = 10 # AttributeError: 'FrqCounter' object has no attribute 'd'
# print(fcnt.d) # AttributeError: 'FrqCounter' object has no attribute 'd'
# print(fcnt.__d) # AttributeError: 'FrqCounter' object has no attribute '__d'
```

### Getters and Setters

Private variables in python are not actually hidden fields like in other object oriented languages. Getters and Setters in python are often used when:

- We use getters & setters to add validation logic around getting and setting a value.
- To avoid direct access of a class field i.e. private variables cannot be accessed directly or modified by external user.

#### Using normal function


```python
class Test:
	def __init__(self):
		self.__private = 0

	# getter method
	def get_private(self):
		return self.__private

	# setter method
	def set_private(self, x):
		self.__private = x


t = Test()

# setting the age using setter
t.set_private(21)

# retrieving age using getter
print(t.get_private())

# print(t.__private)  # AttributeError: 'Test' object has no attribute '__private'

```

    21


#### Using `@property` decorators as 'getter'


The `@property` decorator in Python is used to define a method as a `"getter"` for a class attribute. It allows you to access the method like an attribute rather than calling it as a method. The main purpose of the @property decorator is to provide a controlled way to access and compute values for an object's attributes.



```python
class Test:
	def __init__(self):
		pass

	@property
	def read_only(self):
		return "Jhon"

t = Test()
print(t.read_only) # Jhon
t.read_only  = "Sara" # AttributeError: can't set attribute
```

    Jhon



    ---------------------------------------------------------------------------

    AttributeError                            Traceback (most recent call last)

    <ipython-input-4-461a102b3cac> in <module>
          9 t = Test()
         10 print(t.read_only)
    ---> 11 t.read_only  = "Sara" # AttributeError: can't set attribute


    AttributeError: can't set attribute



```python
class Item:
	def __init__(self,name):
		self.__name = name

	# getter method
	@property
	def name(self):
		return self.__name

	# setter method
	@name.setter
	def name(self, value):
		if len(value) > 10:
			raise Exception("Name is too long")
		else:
			self.__name = value


i = Item("Phone")
print(i.name)
i.name = "Tablet"
print(i.name)

# i.name = "Tablet is too long" # Exception: Name is too long

```

    Phone
    Tablet


## Class method and Static method



`@classmethod` and `@staticmethod` are both used to define methods that are associated with a class rather than an instance of the class. However, they serve different purposes:

1. **@classmethod**:
   - It takes the class (`cls`) as its first argument, allowing you to access and modify class-level attributes and methods.
   - Typically used for factory methods or methods that create instances of the class.
   - Can be overridden by subclasses.

2. **@staticmethod**:
   - It does not take the class or instance as its first argument. It behaves like a regular function defined within a class.
   - Often used for utility functions related to the class, which do not depend on class-specific attributes or methods.
   - Cannot be overridden by subclasses.

Here are examples to illustrate the difference:

**@classmethod Example (Factory Method):**


```python
class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    @classmethod
    def create_square(cls, side_length):
        return cls(side_length, side_length)

square = Rectangle.create_square(5)
print(square.width, square.height)  # Output: 5 5
```



In this example, `create_square` is a class method used as a factory to create square instances of the `Rectangle` class. It takes the class (`cls`) as its first argument and returns an instance of the class.

**@staticmethod Example (Utility Function):**





```python
class MathUtils:
    @staticmethod
    def add(x, y):
        return x + y

result = MathUtils.add(3, 4)
print(result)  # Output: 7
```

In this example, `add` is a static method within the `MathUtils` class. It does not depend on class-specific attributes or methods and can be called directly on the class without creating an instance.

To summarize, `@classmethod` is typically used for methods that operate on the class itself or create instances of the class, while `@staticmethod` is used for utility functions that are related to the class but do not depend on its state.


| `@classmethod`                                                                    | `@staticmethod`                                                               |
| --------------------------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| It can access **class attributes**, but not the **instance attributes**.          | It cannot access either **class attributes** or **instance attributes**.      |
| It can be called using the `ClassName.MethodName()` or object.MethodName()        | It can be called using the `ClassName.MethodName()` or `object.MethodName().` |
| It can be used to **declare a factory method that returns objects of the class**. | It cannot return an object of the class.                                      |


## Magic Methods


- they are called automatically when some particular event occur
- e.g. `__repr__` , `__init__`,, `__str__`

### `__repr__`  vs `__str__`


```python
import datetime

# Create a datetime object representing the current date and time
today = datetime.datetime.now()
today

```




    datetime.datetime(2023, 9, 12, 15, 4, 14, 905963)




```python
# Similarly
print(repr(today))
```

    datetime.datetime(2023, 9, 12, 15, 4, 14, 905963)


but 👉


```python
print(today)
```

    2023-09-12 15:04:14.905963


In this example, `today` is a datetime object representing the current date and time. When we evaluate it in the `REPL`, the `.__repr__()` method is called, providing a detailed and unambiguous representation. When we use the `print()` function, the `.__str__()` method is called, presenting a more user-friendly and human-readable representation.


Often, the official string representation is a valid Python expression that you can use to create a new object with the same value. You can confirm this with the datetime.datetime object by copying the official string representation and assigning it to a new name. You can also attempt to use the informal string representation, but this won’t work:


```python
new_date = datetime.datetime(2023, 9, 12, 15, 4, 14, 905963)
new_date == today
```




    True




```python
new_date = 2023-02-18 18:40:02.160890
```


      File "<ipython-input-13-82edebb4853b>", line 1
        new_date = 2023-02-18 18:40:02.160890
                         ^
    SyntaxError: leading zeros in decimal integer literals are not permitted; use an 0o prefix for octal integers



The output you got from `.__repr__()` when you evaluated today in the REPL created a new object equal to the original one.

However, the string representation from `.__str__()`, which you got when you used `print()`, isn’t a valid Python expression, so it raises a SyntaxError.

In short:

- `.__repr__()` provides the official string representation of an object, aimed at the **programmer**.
- `.__str__()` provides the informal string representation of an object, aimed at the **user**.


```python
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __str__(self):
        return f"{self.name} ({self.age} years old)"

person = Person("Alice", 30)
print(str(person))  # Output: Alice (30 years old)

```

    Alice (30 years old)



```python
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return f"Point({self.x}, {self.y})"

point = Point(3, 4)
print(repr(point))  # Output: Point(3, 4)

```

    Point(3, 4)


### `__hash__`


```python
class Node:
    def __init__(self, name):
        self.name = name

    def __hash__(self):
        return hash(self.name)

    def __repr__(self):
        return f"Node({self.name})"

class Graph:
    def __init__(self):
        self.adjacency_list = {}

    def add_node(self, node):
        self.adjacency_list[node] = []

    def add_edge(self, node1, node2):
        self.adjacency_list[node1].append(node2)
        self.adjacency_list[node2].append(node1)

    def __repr__(self):
        return f"Graph({self.adjacency_list})"

# Create nodes
node_A = Node("A")
node_B = Node("B")
node_C = Node("C")

# Create a graph and add nodes
graph = Graph()
graph.add_node(node_A)
graph.add_node(node_B)
graph.add_node(node_C)

# Add edges
graph.add_edge(node_A, node_B)
graph.add_edge(node_B, node_C)

# Display node and graph representations
print(node_A)    # Output: Node(A)
print(graph)      # Output: Graph({Node(A): [Node(B)], Node(B): [Node(A), Node(C)], Node(C): [Node(B)]})

```

    Node(A)
    Graph({Node(A): [Node(B)], Node(B): [Node(A), Node(C)], Node(C): [Node(B)]})


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


## Inheritance


### Intro

Inheritance in Python allows you to create a new class (called a subclass or derived class) that inherits attributes and methods from an existing class (called a superclass or base class). This enables you to create new classes that reuse and extend the behavior of existing classes. Here's a concise overview of inheritance in Python:


- **Superclass**: The existing class that you want to inherit from.
- **Subclass**: The new class that you are creating, which inherits from the superclass.

Syntax :

```python
class Superclass:
    # Superclass attributes and methods

class Subclass(Superclass):
    # Subclass attributes and methods
```

Key Concepts:

- **Inheritance**: Inheritance establishes an "is-a" relationship between the superclass and subclass. The subclass is a specialized version of the superclass.

- **Accessing Superclass Members**: The subclass can access attributes and methods of the superclass using the `super()` function.


```python
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        pass

class Dog(Animal):
    def speak(self):
        return f"{self.name} says Woof!"

class Cat(Animal):
    def speak(self):
        return f"{self.name} says Meow!"

# Create instances of subclasses
dog = Dog("Buddy")
cat = Cat("Whiskers")

# Call methods of the subclasses
print(dog.speak())  # Output: Buddy says Woof!
print(cat.speak())  # Output: Whiskers says Meow!

```

    Buddy says Woof!
    Whiskers says Meow!


### super()

In Python, the `super()` function is used to access and call **methods or attributes** from a parent (or superclass) class within a subclass. **It allows you to extend or override the behavior of the parent class's methods while still using them in the subclass**. Here's a concise example:




```python
class Parent:
    def __init__(self, name):
        self.name = name

    def speak(self):
        return f"{self.name} says something"

class Child(Parent):
    def __init__(self, name, toy):
        super().__init__(name)  # Call the parent class's constructor
        self.toy = toy

    def speak(self):
        parent_speech = super().speak()  # Call the parent class's method
        return f"{self.name} says something and plays with {self.toy}"

# Create instances
parent = Parent("Alice")
child = Child("Bob", "blocks")

# Access parent class's method from the child
parent_message = parent.speak()
child_message = child.speak()

print(parent_message)  # Output: Alice says something
print(child_message)   # Output: Bob says something and plays with blocks

```

    Alice says something
    Bob says something and plays with blocks


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


## Abstract Class in python

In Python, an abstract class is a class that cannot be instantiated and is meant to serve as a blueprint for other classes. It is often used when you want to define a common interface or set of methods that derived classes must implement. Python provides a module called `abc` (Abstract Base Classes) for working with abstract classes.


```python
from abc import ABC, abstractmethod

class MyAbstractClass(ABC):
    @abstractmethod
    def my_abstract_method(self):
        pass

    @abstractmethod
    def another_abstract_method(self):
        pass
```


```python
# This will raise a TypeError
obj = MyAbstractClass()
```


    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    <ipython-input-3-350a722c5d4e> in <module>
          1 # This will raise a TypeError
    ----> 2 obj = MyAbstractClass()


    TypeError: Can't instantiate abstract class MyAbstractClass with abstract methods another_abstract_method, my_abstract_method


Here's an example of a concrete class that inherits from the abstract class and provides implementations for the abstract methods:


```python
class MyConcreteClass(MyAbstractClass):
    def my_abstract_method(self):
        return "Implemented my_abstract_method"

    def another_abstract_method(self):
        return "Implemented another_abstract_method"
```

## Polymorphism

- One function Name can have different functionality.

**Function overriding** - If derived class defines same function in it's base class, it known as function overriding. This is used to achieve Polymorphism.


```python
class Animal:
    def speak(self):
        pass

class Dog(Animal):
    def speak(self):
        return "Woof!"

class Cat(Animal):
    def speak(self):
        return "Meow!"

# Polymorphic behavior
def animal_sound(animal):
    return animal.speak()

dog = Dog()
cat = Cat()

print(animal_sound(dog))  # Output: "Woof!"
print(animal_sound(cat))  # Output: "Meow!"

```

    Woof!
    Meow!

