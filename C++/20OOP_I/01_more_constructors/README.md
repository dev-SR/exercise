# Overview

-  **Constructor**
   -  that is responsible for creating an object
   -  get called automatically and only once
   -  same as class name
   -  Parametrized Constructor
   -  Constructor Overloading
-  **Copy Constructor**

   -  make a copy of the given object
   -  exists by default
   -  shallow copy
   -  When you need to define your own copy constructor?

      -  You have to make your own copy constructor if a deep copy is needed.

-  **Copy Assignment Operator**

   -  Copies when you do Assignment

   ```cpp

   Car d=c; //Copy Constructor

   Car d;
   d=c; //Copy Assignment operator.

   ```

   -  you can write your own copy assignment operator to make a deep copy.

# Copy Constructor

Copy Constructors is a type of constructor which is used to create a copy of an
already existing object of a class type.

> Syntax of Copy Constructor

```cpp
Classname(const classname &objectname)
{
    . . . .
}
```

> ex:

```cpp
class Point
{
private:
    int x, y;
public:
    Point(int x1, int y1) { x = x1; y = y1; }
    // Copy constructor
    Point(const Point &p1) {x = p1.x; y = p1.y; }

};

int main()
{
    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here

    return 0;
}

```

## When is copy constructor called?

---

In C++, a Copy Constructor may be called in the following cases:

-  When an object is returned by value.
-  When an object is passed (to a function) by value as an argument.
-  When an object is constructed based on another object of the same class.
-  When the compiler generates a temporary object.

It is, however, not guaranteed that a copy constructor will be called in all
these cases, because the C++ Standard allows the compiler to optimize the copy
away in certain cases

# Shallow Copy vs Deep Copy

## Shallow copy

---

A shallow copy of an object copies all of the member field values. This works
well if the fields are values, but may not be what you want for fields that
point to dynamically allocated memory. The pointer will be copied. but the
memory it points to will not be copied – the field in both the original object
and the copy will then point to the same dynamically allocated memory, which is
not usually what you want.\
**The default copy constructor and assignment operator make shallow copies**.

> Shallow Copy

![shallow](img/shallow-1.png)

Shallow copy constructor is used when class is not dealing with any dynamically
allocated memory.

## Deep Copy

---

The compiler created copy constructor works fine in general. We need to define
our own copy constructor only if an object has pointers or any runtime
allocation of the resource like filehandle, a network connection..etc.

A deep copy copies all fields, and makes copies of dynamically allocated memory
pointed to by the fields. To make a deep copy, you must write a copy constructor
and overload the assignment operator, otherwise the copy will point to the
original, with disasterous consequences.

Deep copy allocates separate memory for copied information. So the source and
copy are different. Any changes made in one memory location will not affect copy
in the other location. When we allocate dynamic memory using pointers we need
user defined copy constructor. Both objects will point to different memory
locations.

> Deep Copy

![deep](img/deep-1.png)

**Deep copy is possible only with user defined copy constructor.** In user
defined copy constructor, we make sure that pointers (or references) of copied
object point to new memory locations.

General requirements for deep copy:

-  A normal constructor.
-  A destructor to delete the dynamically allocated memory.
-  A copy constructor to make a copy of the dynamically allocated memory. An
   overloaded assignment operator.

# Destructors

Destructor is a member function which destructs or deletes an object.
Destructors have same name as the class preceded by a tilde (~) Destructors
don’t take any argument and don’t return anything A destructor function is
called automatically when the object goes out of scope:

-  the function ends
-  the program ends
-  a block containing local variables ends
-  a delete operator is called

If we do not write our own destructor in class, compiler creates a default
destructor for us. The default destructor works fine unless we have dynamically
allocated memory or pointer in class. When a class contains a pointer to memory
allocated in class, we should write a destructor to release memory before the
class instance is destroyed. This must be done to avoid memory leak.

# Const Data Members

-  Const keyword is used to make any element of a program constant.
-  If we declare a variable as const, we cannot change its value. A const
   variable must be assigned a value at the time of its declaration.
-  Once initialized, if we try to change its value, then we will get compilation
   error.

# Const member functions in C++

-  A function becomes const when const keyword is used in function’s
   declaration. The idea of const functions is not allow them to modify the
   object on which they are called.

-  When a function is declared as const, it can be called on any type of object.
   Non-const functions can only be called by non-const objects.

# Initializer List

The **initializer list** is used to directly initialize data members of a class.
An initializer list starts after the constructor name and its parameters. The
list begins with a colon ( : ) and is followed by the list of variables that are
to be initialized – all of​ the variables are separated by a comma with their
values in curly brackets.

```cpp
Constructorname(datatype value1, datatype value2):datamember(value1),datamember(value2)
{
    ...
}
```

> When do we use Initializer List in C++?

1. Initializing a reference type data member
2. Initializing const data member
3. Initializing member objects which do not have a default constructor

[link-1](https://www.educative.io/edpresso/what-are-initializer-lists-in-cpp)\
[link-2](https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/)
