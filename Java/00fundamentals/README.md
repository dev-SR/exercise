# Fundamentals of Java 

- [Fundamentals of Java](#fundamentals-of-java)
  - [Primitive / Reference Types and Objects](#primitive--reference-types-and-objects)
  - [Pass by Value \& Pass by Reference](#pass-by-value--pass-by-reference)
    - [Pass by Value](#pass-by-value)
    - [Pass by Reference (Objects)](#pass-by-reference-objects)
    - [Is Java Pass by Value or Pass by Reference?](#is-java-pass-by-value-or-pass-by-reference)
  - [Strings](#strings)
    - [Working with Strings](#working-with-strings)
    - [String Pool](#string-pool)
    - [Immutability](#immutability)
    - [String Equality](#string-equality)
  - [Arrays](#arrays)
    - [Creating Arrays](#creating-arrays)
    - [Iterating Arrays](#iterating-arrays)
    - [Taking Array Input](#taking-array-input)

## Primitive / Reference Types and Objects

In Java, there are two types of data:

- **Primitive types**
- **Reference types**

Primitive data types are simple and are not associated with objects. Reference types are more complex and are used to refer to objects. Objects are instances of classes, which define the state and behavior of an object. Class objects and interface objects are also reference types.

When a reference type is created, it is assigned a default value of `null`, meaning it does not point to any object. Once an object is instantiated, the reference can point to that object. When the object is no longer needed, the reference can be set to `null`, indicating it no longer refers to any object.

A Java reference type can be dereferenced in four ways:

- by setting it to `null`
- by assigning it a new value
- by passing it as a parameter to a method
- by returning it from a method

When a reference is dereferenced, the memory used by the object may be reclaimed by the Java garbage collector.

A reference type can be declared `final`. This means once it is initialized, it cannot be reassigned to another object. A final variable can be initialized only once, either at declaration or through an assignment. If not explicitly assigned, it has a default value of `null`.

Java provides several built-in reference types:

- **Class** – `java.lang.Class`
- **Interface**
- **Array** – `java.[type]`
- **String / StringBuffer** – `java.lang.String`, `java.lang.StringBuffer`
- **Primitive wrapper classes** – `java.lang.[type]` (e.g. `Integer`)
- **Enum** – `java.lang.Enum`

## Pass by Value & Pass by Reference

In Java, arguments are passed to methods in a specific way that is often described as *pass by value* and *pass by reference*.

When you pass an argument **by value**, the method makes a copy of the argument and uses that copy as the actual parameter. This means that any changes made to the parameter within the method **will not be reflected** in the original argument.

On the other hand, when you pass an argument **by reference**, the method accesses the original argument directly. This means that any changes made to the parameter within the method **will be reflected** in the original argument.

### Pass by Value

When an argument is passed by value, a **copy** of the variable is passed to the method. Any **changes** made inside the method **do not affect** the original variable.

Primitive types (such as `int`, `double`, `boolean`) are passed by value.

```java
int num = 5;
increment(num);
```

Here, `num` remains `5` after the method call. A copy of `num` is passed, incremented inside the method, and then discarded. The original variable is unchanged.

---

### Pass by Reference (Objects)

When objects are passed to a method, Java passes a **copy of the reference** to the object, not the object itself.

```java
class MyClass {
  int myInt;
}

void increment(MyClass obj) {
  obj.myInt++;
}

MyClass myObj = new MyClass();
increment(myObj);
```

In this case, `myObj.myInt` becomes `1`.  So, when we call increment with `myObj`, java doesn't make a copy of `myObj` - it just passes a reference to it. And since java passes objects by reference, any changes made to `obj` within our increment method will be reflected in our original `myObj` object.

---

### Is Java Pass by Value or Pass by Reference?

Java is **always pass by value**.

* For primitives: the value itself is copied.
* For objects: the **reference is copied**, not the object.

This allows methods to modify the object’s internal state but not to change which object the original reference points to.

As a result, Java behaves like pass by reference for objects, but technically it is still pass by value.

**Objects**

```java
class Person { String name; }

static void changeName(Person p) {
    p.name = "Alice";
}

Person person = new Person();
person.name = "Bob";
changeName(person);
System.out.println(person.name); // Alice
```

The method gets a **copy of the reference**. Both references point to the same object, so its internal state can change.

---

**Reassigning the reference**

```java
static void reassign(Person p) {
    p = new Person();
    p.name = "Charlie";
}

reassign(person);
System.out.println(person.name); // Bob
```

Reassigning only changes the **local copy** of the reference.

---

**Key point**

Java is **pass by value**:

* Primitives → value copied
* Objects → reference value copied
  Object state can change, but the original reference cannot.


## Strings

A string in Java is an **immutable** object that represents a sequence of characters. The `String` class provides methods for tasks such as checking length, concatenation, and searching characters

Because strings are **immutable**, they can be safely shared across different parts of a program, including multiple threads, without the risk of modification. This makes them suitable for storing shared data like *configuration settings*.

---

### Working with Strings

```java
String brand = new String("Amigoscode");
String sentence = new String("Here we have a whole sentence created");
```

Strings can also be assigned using string literals:

```java
String brand = "Amigoscode";
String sentence = "Here we have a whole sentence created";
```

---

### String Pool

Strings are a special reference type in Java. The JVM maintains a special memory area called the **String Pool**.

When a string literal is created, the JVM checks if it already exists in the pool:

* If it exists, a reference to the existing string is returned.
* If it does not exist, a new string is added to the pool.

This ensures only one copy of each literal string exists, improving performance and memory usage.

```java
String brand = "FOO";
```

The value `"FOO"` is stored in the String Constant Pool.

```java
String brand = "FOO";
String courseName = new String("FOO");
```

Even though `new` creates a new object in heap memory, the value `"FOO"` already exists in the pool. In summary, all strings are immutable, whether created as literals or objects.

---

### Immutability

If multiple variables point to the same string in the pool, changing the value of one would affect all others. To prevent this costly and unsafe behavior, strings are immutable in Java.

Reassigning a string variable creates a new string instead of modifying the existing one.

---

### String Equality

* `==` returns true only if both variables refer to the same object.
* `.equals()` returns true if the values are the same.

```java
String brand = "FOO";
String courseName = "FOO";

System.out.println(brand == courseName); 
// True

System.out.println(brand.equals(courseName)); 
// True
```

If strings are created as separate objects in the heap, `==` returns false, while `.equals()` still returns true if the values match.

## Arrays

### Creating Arrays

```java
int[] a = new int[5];                 // size 5, default values (0)
int[] b = new int[]{1, 2, 3, 4, 5};   // explicit initialization
int[] c = {1, 2, 3, 4, 5};            // shorthand initialization

String[] s1 = {"Hello", "World"};
String[] s2 = {"Hello", "World", null}; // nulls allowed
```

> Arrays have a fixed length once created.

---

### Iterating Arrays

**Enhanced for-loop (read-only for elements):**

```java
for (int el : arr) {
    System.out.print(el);
}
```

**Index-based loop (full control):**

```java
for (int i = 0; i < arr.length; i++) {
    System.out.print(arr[i]);
}
```

**Utility output:**

```java
System.out.println(Arrays.toString(arr));
```

---

### Taking Array Input

```java
int[] arr = takeInput();

public static int[] takeInput() {
    System.out.print("Size? ");
    int n = scn.nextInt();

    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
        System.out.print("Value at index " + i + "? ");
        arr[i] = scn.nextInt();
    }
    return arr;
}
```

