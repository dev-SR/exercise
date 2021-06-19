# Basic OOP in python

**Definig the constructor of a Class**

- A constructor is a special member function of a class that is executed whenever we create new objects of the class.

```python
def __init__(self):
    ...
    ...
```

**Definig the methods of a instance**

```
def intro(self):
    ...
    ...
```

**Class Variable**

- Class Variables are common to all instances
- They are associated with the class
- Accessed by `class_name.variable`

**Magic Functions**

- they are called automatically when some particular event occur

- e.g. `__repr__`(toString) , `__init__`,, `__str__` 


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
    
    # Magic Function -> overriding __repr__ (toString equivalent)

    def __repr__(self):
        """
            represents the object...prints object
        """
        return "[{}, {}, {}, {}]".format(self.id,self.name,self.age,self.is_alive)



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
# before overriding __repr__ magic function
print(Human.database)
print(Human.database[0])
print(Human.database[1].name)
```

    2
    2
    [<__main__.Human object at 0x000002294D374A00>, <__main__.Human object at 0x000002294D374E20>]
    <__main__.Human object at 0x000002294D374A00>
    Jhon
    


```python
# after overriding __repr__ magic function
print(h1)
print(Human.database)
print(Human.database[0])
print(Human.database[1].name)
print(dir(Human))
```

    [0, soikat, 22, True]
    [[0, soikat, 22, True], [1, Jhon, 69, True]]
    [0, soikat, 22, True]
    Jhon
    ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', 'database', 'die', 'id_seq', 'intro', 'population']
    


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




```python
print(dir(Human))
```

    ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', 'database', 'die', 'id_seq', 'intro', 'population']
    

## Inheritance 

-  a process where one class acquire all the methods and properties of another class

**Parent Class** is the class being inherited, also called base class.
**Child Class** is the class that inherits another class, also called derived class.

Syntax :

```python
class ChildClassName(ParentClassName)
```

## Polymorphism

- One function Name can have different functionality.

**Function overriding** - If derived class defines same function in it's base class, it known as function overriding. This is used to achieve Polymorphism.




```python
# Child class
class Hitman(Human):
    # constructor

    def __init__(self,name,age):
        super().__init__(name,age)

        # addtional hitman properties
        self.kills  = 0
        self.kills_list = []
    
    def kill(self,person):
        """
        person will be an object of Human
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
    


```python

```
