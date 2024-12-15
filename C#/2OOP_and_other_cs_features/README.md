# Types Classes Structures

<!--  -->
- [Types Classes Structures](#types-classes-structures)
  - [Classes Overview](#classes-overview)
    - [Example](#example)
    - [Fields](#fields)
    - [Properties](#properties)
    - [Constructors](#constructors)
      - [Multiple Constructors](#multiple-constructors)
      - [Primary Constructor](#primary-constructor)
      - [Thrown Exceptions in Constructors](#thrown-exceptions-in-constructors)
    - [Object Initializers](#object-initializers)
      - [Legacy Way](#legacy-way)
      - [Modern Syntax](#modern-syntax)
    - [Equality of Classes](#equality-of-classes)
  - [Overview of Types](#overview-of-types)
    - [Value Types](#value-types)
    - [Reference Types](#reference-types)
    - [Stack vs. Heap](#stack-vs-heap)
      - [Value Types:](#value-types-1)
      - [Reference Types:](#reference-types-1)
    - [Null and Nullability](#null-and-nullability)
      - [Nullable value types:](#nullable-value-types)
    - [Modern Nullability](#modern-nullability)
  - [Inheritance](#inheritance)
    - [How to Do It](#how-to-do-it)
      - [Why to Do It](#why-to-do-it)
    - [Sealed vs. Virtual](#sealed-vs-virtual)
      - [**Sealed**](#sealed)
      - [**Virtual**](#virtual)
  - [Abstract Classes](#abstract-classes)
    - [U-Turn Back to Access Modifiers](#u-turn-back-to-access-modifiers)
    - [DRY vs. MOIST](#dry-vs-moist)
  - [Interfaces in C#](#interfaces-in-c)
    - [Inheritance is Great (kind of), But Why Use Interfaces?](#inheritance-is-great-kind-of-but-why-use-interfaces)
    - [Why Are Interfaces Important?](#why-are-interfaces-important)
    - [Declaring an Interface](#declaring-an-interface)
    - [Advanced Stuff](#advanced-stuff)
    - [Use Cases](#use-cases)
  - [Structs and Records](#structs-and-records)
    - [Structs](#structs)
      - [Value Types](#value-types-2)
      - [Syntax](#syntax)
      - [Equality](#equality)
      - [Mutability](#mutability)
    - [Records](#records)
      - [Syntax](#syntax-1)
      - [With Expressions](#with-expressions)
      - [Structural Equality](#structural-equality)
    - [Records vs. Classes vs. Structs](#records-vs-classes-vs-structs)
      - [Problem with Inheritance](#problem-with-inheritance)
      - [Using Composition](#using-composition)
    - [How Composition Solves Problems](#how-composition-solves-problems)
  - [Extension Methods in C#](#extension-methods-in-c)
    - [Extension Methods](#extension-methods)
    - [Nuanced example](#nuanced-example)
  - [Reflection in C#](#reflection-in-c)
  - [Generics](#generics)
    - [Very Basics of Generic Types](#very-basics-of-generic-types)
    - [Creating Generic Classes](#creating-generic-classes)
    - [Demonstrating Using Generically-Typed Methods](#demonstrating-using-generically-typed-methods)
    - [Multiple Type Generics](#multiple-type-generics)
    - [Demonstrating Type Constraints](#demonstrating-type-constraints)
    - [Demonstrating the Repo Patterns with Generics](#demonstrating-the-repo-patterns-with-generics)



## Classes Overview

Classes are fundamental building blocks in object-oriented programming that define the structure and behavior of objects. They encapsulate data for the object and methods to manipulate and use that data.

**Syntax**: A class is defined using the `class` keyword, followed by the class name and its body enclosed in curly braces `{}`.

### Example

```csharp
public class Person
{
    // Fields, properties, and methods go here
}
```

### Fields

Fields are variables that are declared directly in a class. They store the data for the object.

```csharp
public class Person
{
    public string Name;
}
```

You can interact with fields using dot notation:

```csharp
var person = new Person();
person.Name = "John Doe";

// or

var person = new Person() { Name = "Jhon Doe" };
Console.WriteLine(person.Name);
```

### Properties

Properties mainly provide controlled access to fields with getter and setter methods

```csharp
public class Person
{
    private string _name = ""; //Fields

    public string MutableName //Properties
    {
        get { return _name; }
        set { _name = value; }
    }
}

```

In this example, `value` is a special keyword that represents the value being assigned to the property:

```csharp
Person person = new Person();
Console.WriteLine(person.MutableName);//""
person.MutableName = "NewName";
Console.WriteLine(person.MutableName);//NewName
```

This is considered the "legacy" way of defining properties. Let's look at more concise ways of declaring properties:

```csharp
public class Person
{
    private string _name = "init"; //Fields
    public string ImmutableName1 => _name;//The `=>` syntax denotes that this property is a read-only computed property. ex: public string FullName => $"{FirstName} {LastName}";

    // Creates a private backing field under the hood
    public string ImmutableName2 { get; } = "immutable";// Immutable property, typically set in constructor
    public string? MutableName { get; set; }    // Creates a private backing field under the hood

}

Person person = new Person();
Console.WriteLine(person.ImmutableName1);//init
Console.WriteLine(person.ImmutableName2);//immutable
person.MutableName = "muting...";
Console.WriteLine(person.MutableName);//muting...
```

### Constructors

Special methods called when an object is instantiated. They initialize the object. The `new` keyword is used to create an instance of a class. Method syntax is used to pass parameters to the constructor.

```csharp
public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }
}

Person person = new Person("Jhon",25);
// or
Person person = new("Jhon", 25);
```

---

#### Multiple Constructors

Classes can contain multiple constructors:

```csharp
public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

    public Person(string name)
    {
        Name = name;
        Age = 0;
    }
}

Person person = new Person("John Doe", 30);
Person person2 = new Person("John Doe");
```

You can use the `this` keyword to call the current class's constructor from another constructor:

```csharp
public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

    public Person(string name) : this(name, 0){}
}
```

---

#### Primary Constructor

Simplified syntax for constructors that allows initializing properties directly in the class definition.

```csharp
public class Person(string Name, int Age)
{
    // Properties automatically created
}
```


#### Thrown Exceptions in Constructors

If you throw an exception in a constructor, the object is not instantiated.

```csharp
public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Person(string name, int age)
    {
        if (string.IsNullOrWhiteSpace(name))
        {
            throw new ArgumentException("Name cannot be null or empty", nameof(name));
        }
        Name = name;
        Age = age;
    }
}

Person person = new Person("John Doe", 30);
Person person2 = new Person(string.Empty, 30); // This will throw an exception
```


### Object Initializers

Object initializers provide a way to initialize objects with some default properties.

#### Legacy Way

```csharp
public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }
}

Person person = new Person();
person.Name = "John Doe";
person.Age = 30;        // 😕
```

#### Modern Syntax

```csharp
Person person = new Person { 
    Name = "John Doe",
    Age = 30            // ❤️
};
// or 
Person person = new() { Name = "Jhon", Age = 25 };
```

Properties can be made immutable but settable using the object initializer syntax by using the init keyword:

```csharp
public class Person
{
    public string Name { get; init; }
    public int Age { get; init; }
}

Person person = new Person { 
    Name = "John Doe", 
    Age = 30
};
```

You can also force the developer to set the property using object initializer syntax by using the required keyword:

```csharp
public class Person
{
    public required string Name { get; init; }
    public required int Age { get; init; }
}
```

🌶️🌶️🌶️ I love object initializers, full stop. That said, I don't use init and required super often, except in newer codebases.

### Equality of Classes

Classes are reference types, which means that they are compared by reference, not value.

```csharp
Person person1 = new Person { Name = "John Doe", Age = 30 };
Person person2 = new Person { Name = "John Doe", Age = 30 };

Console.WriteLine(person1 == person2); // False
person1.Equals(person2); // False
```

You can override `Equals` and `GetHashCode` to customize how classes are compared:

```csharp
public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public override bool Equals(object obj)
    {
        if (obj == null || GetType() != obj.GetType()) return false; //here, GetType() == this.GetType()
        Person other = (Person)obj;
        return Name == other.Name && Age == other.Age;
    }
    public override int GetHashCode()
    {
        return HashCode.Combine(Name, Age);
    }
}

Console.WriteLine(person1 == person2);//false
Console.WriteLine(person1.Equals(person2));//True
```

`IEquatable<T>`: Interface for providing a strongly-typed method to check equality.


```csharp
public class Person : IEquatable<Person>
{
    public string Name { get; set; }
    public int Age { get; set; }

    public bool Equals(Person? other)
    {
        if (other == null) return false;
        return Name == other.Name && Age == other.Age;
    }
}
```


## Overview of Types

This section explores the differences between reference types and value types in programming, including practical examples using method calls.

### Value Types
Value types store the actual data. When you pass a value type to a method, the method receives a copy of the data.

```csharp
class Person
{
    public string Name { get; set; }
    public int Age { get; set; }
}

void ChangeAge(int age)//pass by value
{
    age = 10;
}

Person person = new Person { Name = "Old Name", Age = 20 };
ChangeAge(person.Age);
// person.Age is still 20
```

### Reference Types
Reference types store references to the actual data in memory. When you pass a reference type to a method, the method receives a reference to the same object.

```csharp
class Person
{
    public string Name { get; set; }
}

void ChangeName(Person person)//pass by reference
{
    person.Name = "New Name";
}

Person person = new Person { Name = "Old Name" };
ChangeName(person);
// person.Name is now "New Name"
```

Special note: Strings are a special type of reference type in C# that are treated a bit more like value types when passed to methods in that their value is copied.

### Stack vs. Heap
You don't need to know the difference between the stack and heap deeply for this course, but you should be aware that value types are stored on the stack and reference types are stored on the heap. What are the most important implications of this?

#### Value Types:
- Stored on the stack.  
- Faster access - direct memory allocation.  
- Automatic memory management - collected by the runtime when out of scope.  

#### Reference Types:
- Stored on the heap.  
- Slower access - indirect memory allocation. Reference-typed variables, technically speaking, are pointers to the object's location in memory.  
- Cleaned up via garbage collection, which is managed by the .NET runtime. Not automatically removed from memory when out of scope.  

### Null and Nullability
Represents the absence of a value. Commonly used in reference types.

```csharp
string str = null; // Valid for reference types
int number = null; // This will cause a compilation error - value types cannot be null
```

#### Nullable value types:
Allows value types to be assigned null. Add a `?` to the type to make it nullable!

```csharp
string str = null; // Valid for reference types
int? nullableInt = null; // Valid for nullable value types
```

Word to the Wise: `NullReferenceException`

This is perhaps the most common exception in C#. It's thrown when you try to access a member of a null object.

```csharp
Person person = null;
Console.WriteLine(person.Name); // NullReferenceException
```

_"Object reference not set to an instance of an object."_ These are famous (and famously frustrating) words in C#.

> Most important thing to remember: **Check for null before accessing members of a reference type!**

### Modern Nullability
Modern .NET versions have added explicit nullability for reference types to the language. This feature helps you to be more explicit about what is nullable and what isn't.

```csharp
public class Address
{
    public string Street { get; set; }
    public string City { get; set; }
    public string State { get; set; }
    public string ZipCode { get; set; }
}

public class Person
{
    public string Name { get; set; }        // Non-nullable reference type
    public string? MiddleName { get; set; } // Nullable reference type
    public Address? Address { get; set; }   // Nullable reference type
}
```

🌶️🌶️🌶️ C# devs tend to not fully embrace the benefits of nullable reference types. In brownfield (e.g., existing) projects, it's almost impossible to reverse-add nullability in a meaningful way. In greenfield (e.g., new) projects, I'd recommend turning on nullability + treating warnings as errors - this gives you the strictest null handling rules and will result in fewer bugs.


## Inheritance

Inheritance is core to understanding object hierarchy.

First Things First: ALL objects in C# inherit from the `object` class.

A class that inherits from another class is called a **derived class**.

### How to Do It

In C#, you can inherit from a class using the `:` syntax. This allows the derived class to use the members of the base class.

```csharp
namespace src.Inheritance.ex;

public class Vehicle
{
    public int DoorCount { get; init; }

    public void OpenDoors()
    {
        Console.WriteLine($"{GetType()} opening {DoorCount} doors");
    }
}

public class AutoMobile : Vehicle { }
public class Car : AutoMobile { }
public class Truck : AutoMobile { }
public class Van : AutoMobile { }

public class Bike : Vehicle { }
public class Plane : Vehicle { }


Car sedan = new() { DoorCount = 4 };
Car coupe = new() { DoorCount = 2 };
Truck pickupTruck = new() { DoorCount = 2 };
Bike bike = new();

sedan.OpenDoors();//src.Inheritance.ex.Car opening 4 doors
coupe.OpenDoors();//src.Inheritance.ex.Car opening 2 doors
pickupTruck.OpenDoors();//src.Inheritance.ex.Truck opening 2 doors
bike.OpenDoors();//src.Inheritance.ex.Bike opening 0 doors

// polymorph
Vehicle car = new Car();
Vehicle Bike = new Bike();
Vehicle plane = new Plane();
```

#### Why to Do It
- **Code Reusability**: Reduces redundancy by reusing code from base classes.  
- **Organizing Code**: Structures code hierarchically, improving readability and maintainability.  
- **Polymorphism**: Enables treating derived classes as instances of the base class, allowing flexible designs.  

---

### Sealed vs. Virtual

#### **Sealed**
A `sealed` class cannot be inherited. Use it to prevent further derivation.

```csharp
public sealed class FinalEmployee
{
    // Implementation
}
```

Fun fact: The most common `sealed` class in C# is `string`. You can't inherit from `string` (and thank goodness for that).  

You can also seal methods and properties:

```csharp
public class BaseEmployee
{
    public sealed override string ToString()
    {
        return "Base employee details";
    }
}
```

#### **Virtual**
A `virtual` method or property in the base class can be overridden in derived classes to provide specific implementations.

```csharp
public class BaseEmployee
{
    public virtual string GetEmployeeDetails()
    {
        return "Base employee details";
    }
}

public class DerivedEmployee : BaseEmployee
{
    public override string GetEmployeeDetails()
    {
        return "Derived employee details";
    }
}
```

---

## Abstract Classes

**Abstract classes** serve as a base class for other classes. They:
- May contain abstract methods that derived classes **must implement**.  
- Can provide shared behaviors and properties.  
- **Cannot** be instantiated directly.

```csharp
public abstract class Employee
{
    public string FirstName { get; set; }
    public string LastName { get; set; }

    public abstract decimal CalculatePay(); // Abstract method

    public virtual string GetEmployeeDetails() // Virtual method
    {
        return $"{FirstName} {LastName}";
    }

    public sealed override string ToString() // Sealed method
    {
        return GetEmployeeDetails();
    }
}
```

Examples of Derived Classes

```csharp
public class HourlyEmployee : Employee
{
    public decimal HourlyRate { get; set; }
    public int HoursWorked { get; set; }

    public override decimal CalculatePay()
    {
        return HourlyRate * HoursWorked;
    }
}

public class SalariedEmployee : Employee
{
    public decimal Salary { get; set; }

    public override decimal CalculatePay()
    {
        return Salary / 52; // Weekly pay calculation
    }
}
```

Demonstrate Methods:
- **Abstract Method**: `CalculatePay()` must be implemented in derived classes.  
- **Virtual Method**: `GetEmployeeDetails()` can be overridden in derived classes.  
- **Sealed Method**: `ToString()` cannot be overridden in derived classes.  


### U-Turn Back to Access Modifiers

**Encapsulation** is an essential object-oriented principle: expose only what's necessary for external consumers while keeping internal details hidden.

```csharp
public abstract class Employee
{
    protected Guid Id { get; set; }  // Accessible to derived classes only!
    public string FirstName { get; set; }  // Accessible to anyone who has access to this object
    public string LastName { get; set; }

    public abstract decimal CalculatePay();

    private void GenerateEmployeeId()  // Not accessible to derived classes
    {
        Id = Guid.NewGuid();
    }
}
```

Common Access Modifiers:
- **public**: Accessible from anywhere.  
- **private**: Accessible only within the class.  
- **protected**: Accessible within the class and derived classes.  
- **internal**: Accessible only within the same assembly.  

Opinions About Inheritance 🌶️:

- **Inheritance is often overused.** New developers frequently misuse it, leading to overly complex designs.  
- **Limit inheritance to one level.** Spencer rarely goes beyond this, preferring simpler designs.  
- **Modeling Alternative**: Use properties as discriminators instead of inheritance.  


```csharp
public enum EmployeePaymentType
{
    Hourly,
    Salary
}

public class Employee
{
    public EmployeePaymentType PaymentType { get; set; }
}
```

```csharp
public class EmployeePayCalculator
{
    public decimal CalculatePay(Employee employee)
    {
        if (employee.PaymentType == EmployeePaymentType.Hourly)
        {
            // Calculate hourly pay
        }
        // Additional logic for other payment types
    }
}
```

### DRY vs. MOIST

- **DRY**: Don't Repeat Yourself - minimize code duplication.  
- **MOIST**: Moderate Overlap Is Sometimes Tolerable - accept some duplication to avoid unnecessary complexity.  

Spencer's rule of thumb:  
- Copy/paste similar code up to **two times**.  
- After that, start refactoring to reduce duplication.  
- Total elimination of duplication? **Not worth it.**


## Interfaces in C#

Interfaces allow us to define a contract for a class to implement. Think of it like a lightweight abstract class.

A common example is a database connection. There are dozens of kinds of databases, and they all have slightly different behaviors and capabilities. However, the way you interact with them is often the same. You have to be able to open/close connections:


```csharp
public interface IDatabase
{
    void Connect();
    void Disconnect();
}
```

And the actual way you would do that between, say, Postgres and SQL Server is different, but the code behavior is (roughly) the same. (This is a good example of abstraction, one of the four object-oriented programming principles.)

### Inheritance is Great (kind of), But Why Use Interfaces?

**Multiple Inheritance is Not a Thing**

C# does not support multiple inheritance for classes, meaning a class cannot inherit from more than one base class. However, C# allows a class to implement multiple interfaces. This helps achieve similar functionality as multiple inheritance without the complexities and issues it can introduce.

**Interfaces Emphasize Composability**

Interfaces are a way to achieve composability in C#. They allow different classes to share common behavior without being tied to a single inheritance hierarchy. This promotes flexible and modular design, making it easier to manage and extend code.

Understanding interfaces is core to understanding how C# code is written in the real world.

### Why Are Interfaces Important?

**They Provide No Behaviors by Default**

Interfaces in C# define a contract but do not provide any implementation. It is up to the implementing classes to define how the contract is fulfilled. This means interfaces are purely about defining what methods and properties a class should have, not how they should work.

In other words:

- Classes define the thing's behaviors and properties
- Interfaces define the thing's shape without opinions about the behavior

### Declaring an Interface

An interface is declared using the interface keyword. It can contain method signatures, properties, events, and indexers but no implementation.


```csharp
public interface IDatabase
{
    void Connect();
    void Disconnect();
    bool IsConnected { get; }
}
```


Classes implement interfaces by providing the required method and property implementations.


```csharp
public class SqlDatabase : IDatabase
{
    public bool IsConnected { get; private set; }

    public void Connect()
    {
        // Implementation code
        IsConnected = true;
    }

    public void Disconnect()
    {
        // Implementation code
        IsConnected = false;
    }
}
```

When a class inherits from an abstract class, it's said that the class is *inheriting* from the abstract class.

When a class implements an interface, it's said that the class is *implementing* the interface.

### Advanced Stuff

**Default Implementations**

C# 8.0 introduced default implementations in interfaces, allowing you to provide a default implementation for methods in an interface.

```csharp
public interface ILogger
{
    void Log(string message);

    void LogError(string error) // Default implementation
    {
        Console.WriteLine($"Error: {error}");
    }
}
```


🌶️🌶️ hot take: I don't use default implementations in interfaces pretty much ever. Not that they can't be useful, but I typically just use interfaces as they were intended. Default implementations are useful in a very *narrow set of circumstances.

### Use Cases

**Service-Based Architecture**

Interfaces are commonly used in .NET for defining service contracts. For example, interfaces are used to define services that perform operations or provide functionalities, such as data access services or logging services.

The database example above is pretty good.

**Marker Interfaces**

Interfaces can also be used as markers to provide metadata about a class. For instance, IAuditable can be used to mark classes that should be audited.

```csharp
public interface IAuditable { }
```

Doesn't look useful, until you have other code that audits objects based on their type! I'll show an example of this when we get to the next course on ASP.NET.

**Avoiding Inheritance**

Interfaces are often used to avoid deep inheritance hierarchies. Instead of extending classes, you can use interfaces to define shared behaviors and compose functionalities from multiple sources.

That doesn't mean that you should declare one class that implements 10 interfaces. I like code to be broken up as necessary, and often will have a single-use interface for a single class.


## Structs and Records

Structs and records are types in C# that provide different ways of modeling data. **Structs are value types, while records are reference types** with built-in structural equality. Understanding their use cases can help in choosing the right type for a given scenario.

### Structs

#### Value Types
Structs are value types, meaning they are stored on the stack and copied by value. They are typically used for small, immutable data structures and have better performance for such scenarios compared to classes.

#### Syntax
Structs are defined using the struct keyword, followed by the struct name and its body enclosed in curly braces {}.

Example

```csharp
public struct Point
{
    public int X { get; set; }
    public int Y { get; set; }
}
```

#### Equality
Structs support value equality by default. This means two structs are considered equal if all their fields are equal.

```csharp
Point point1 = new Point { X = 5, Y = 10 };
Point point2 = new Point { X = 5, Y = 10 };

Console.WriteLine(point1 == point2); // True
point1.Equals(point2); // True
```


#### Mutability

Structs can be mutable, but it is recommended to use immutable structs to prevent unintended side effects. An immutable struct has readonly fields or properties and does not change after initialization.

```csharp
public struct Point
{
    public int X { get; }   //look ma, no setter!
    public int Y { get; }

    public Point(int x, int y)
    {
        X = x;
        Y = y;
    }
}
```

### Records

**Reference Types with Structural Equality**
Records are reference types that provide value-based equality semantics. They are ideal for data models that do not require behavior (e.g. methods) and are mainly used to encapsulate immutable data.

#### Syntax
Records are defined using the `record` keyword, followed by the record name and its body enclosed in curly braces `{}`.

```csharp
public record Person(string Name, int Age);
```

#### With Expressions

The `with` expression allows you to create a new record based on an existing record, with modifications to some properties.

```csharp
var person1 = new Person("John Doe", 30);
var person2 = person1 with { Age = 31 };

Console.WriteLine(person1); // Person { Name = John Doe, Age = 30 }
Console.WriteLine(person2); // Person { Name = John Doe, Age = 31 }
```

#### Structural Equality

Records provide built-in value equality, which means two records are considered equal if all their properties are equal.

```csharp
var person1 = new Person("John Doe", 30);
var person2 = new Person("John Doe", 30);

Console.WriteLine(person1 == person2); // True
person1.Equals(person2); // True
```

### Records vs. Classes vs. Structs

**Structs**
- **Performance**: Best suited for small, immutable data types due to value semantics.
- **Use Cases**: High-performance scenarios, geometric points, complex numbers.

**Records**
- **Data-Centric**: Best for immutable data models that do not require behavior.
- **Use Cases**: DTOs (data transfer objects), configuration objects, immutable data transfers.

**Classes**
- **Flexibility**: Ideal for complex objects with behavior and mutable state.
- **Use Cases**: Domain models, services, business logic.

```markdown

## Composition in C#

### What is Composition?

Composition is a design principle where an object is composed of other objects, rather than inheriting behavior from a base class. It promotes code reuse by embedding one object inside another to provide desired functionality.

In simpler terms, instead of inheriting from a class, you include instances of other classes as part of your own class.

**Advantages of Composition**
- **Flexibility**: Unlike inheritance, composition allows you to dynamically change the behavior of your object by composing it with different components.
- **Encapsulation**: Components are private to the class and do not expose internal details.
- **Avoids Overuse of Inheritance**: Helps maintain simpler and flatter class hierarchies, reducing coupling.


### Scenario: Notification System
Imagine you are building a notification system with different types of notifications: **Email** and **SMS**. At first glance, inheritance might seem like the ideal solution.


#### Using Inheritance

We create a `Notification` base class and derive `EmailNotification` and `SMSNotification` classes from it.

```csharp
public class Notification
{
    public string Message { get; set; }

    public virtual void Send()
    {
        Console.WriteLine("Sending notification...");
    }
}

public class EmailNotification : Notification
{
    public string EmailAddress { get; set; }

    public override void Send()
    {
        Console.WriteLine($"Sending Email to {EmailAddress}: {Message}");
    }
}

public class SMSNotification : Notification
{
    public string PhoneNumber { get; set; }

    public override void Send()
    {
        Console.WriteLine($"Sending SMS to {PhoneNumber}: {Message}");
    }
}
```

#### Problem with Inheritance

1. **Limited Flexibility**: If you later want to add functionality for **push notifications**, you need to modify the hierarchy or create another derived class.
2. **Code Duplication**: Common functionality (e.g., logging or formatting the message) often needs to be duplicated or moved up the hierarchy.
3. **Rigid Hierarchy**: What if a notification needs to send both **Email** and **SMS**? Inheritance doesn't handle such scenarios well.

---

#### Using Composition

Instead of inheritance, we use composition by creating separate classes for different responsibilities and combining them.

```csharp
public interface INotificationSender
{
    void Send(string message);
}

public class EmailSender : INotificationSender
{
    public string EmailAddress { get; set; }

    public void Send(string message)
    {
        Console.WriteLine($"Sending Email to {EmailAddress}: {message}");
    }
}

public class SMSSender : INotificationSender
{
    public string PhoneNumber { get; set; }

    public void Send(string message)
    {
        Console.WriteLine($"Sending SMS to {PhoneNumber}: {message}");
    }
}

public class Notification
{
    private readonly INotificationSender _sender;

    public Notification(INotificationSender sender)
    {
        _sender = sender;
    }

    public void Send(string message)
    {
        _sender.Send(message);
    }
}
```

```csharp
var emailNotification = new Notification(new EmailSender { EmailAddress = "test@example.com" });
emailNotification.Send("Hello via Email!");

var smsNotification = new Notification(new SMSSender { PhoneNumber = "1234567890" });
smsNotification.Send("Hello via SMS!");
```

```
Sending Email to test@example.com: Hello via Email!
Sending SMS to 1234567890: Hello via SMS!
```


### How Composition Solves Problems

1. **Flexibility**: Adding new notification types (e.g., **Push Notification**) only requires creating a new class that implements `INotificationSender`. No changes to existing classes.
   
2. **No Code Duplication**: Shared functionality, such as formatting messages, can be encapsulated in reusable components.

3. **Dynamic Behavior**: You can mix and match behaviors at runtime. For example, sending both Email and SMS for a single notification:

```csharp
public class MultiSender : INotificationSender
{
    private readonly List<INotificationSender> _senders;

    public MultiSender(params INotificationSender[] senders)
    {
        _senders = senders.ToList();
    }

    public void Send(string message)
    {
        foreach (var sender in _senders)
        {
            sender.Send(message);
        }
    }
}

// Usage
var multiNotification = new Notification(
    new MultiSender(
        new EmailSender { EmailAddress = "test@example.com" },
        new SMSSender { PhoneNumber = "1234567890" }
    )
);
multiNotification.Send("Hello via Multiple Channels!");
```

Output
```
Sending Email to test@example.com: Hello via Multiple Channels!
Sending SMS to 1234567890: Hello via Multiple Channels!
```

Conclusion:
While inheritance is useful in some cases, composition provides:
- Greater flexibility for changes and extensions.
- A more modular and reusable design.
- The ability to handle complex scenarios without deep hierarchies.

Always prefer composition over inheritance unless the relationship is strictly "is-a."


## Extension Methods in C#

**"Adding behaviors to non-modifiable classes since 2007"**

Sometimes, you encounter situations where you cannot modify a class or a piece of functionality. This could be due to:

- **Class in Another Library**: The class might belong to a third-party library or a framework, and you do not have access to its source code.
- **Method Doesn’t Quite Fit**: The existing methods in a class may not meet your specific needs, and you want to extend the class with additional functionality.

Example Scenario:

Imagine you are working with `string` - it's fundamental to the language but almost completely non-extensible. You may find that the existing methods of the `string` class do not fully cover your requirements, and you want a way for developers to interact with the string in a way that feels natural. For instance, you might want to add formatting methods but do so in a way where you access those methods from the `string` class directly.

### Extension Methods

**What Are Extension Methods?**Extension methods allow you to "add" new methods to an existing class without modifying its source code. This is achieved by creating a static class with static methods that act as if they are part of the class you are extending.

Syntax
To create an extension method:

- **Define a Static Class**: The extension methods must be in a static class.
- **Create a Static Method**: The method you want to add must be static.
- **Use the `this` Keyword on the first parameter**: The first parameter of the method specifies the type that the method operates on, using the this keyword.
  
Example: Extending the string Class

Let’s add a method to the string class to check if a string is a palindrome.


```csharp
public static class StringExtensions
{
    public static bool IsPalindrome(this string str)
    {
        if (string.IsNullOrEmpty(str))
            return false;

        string reversed = new string(str.Reverse().ToArray());
        return str.Equals(reversed, StringComparison.OrdinalIgnoreCase);
    }
}
```

### Nuanced example

Oftentimes, you will define interfaces in such a way that you want to narrowly define what the interface is, but still have convenient methods for developers to use. Those convenient methods are best added via extension methods.

Example
Let's say you have an interface such as:


```csharp
public interface ILogger
{
    void Log(LogLevel level, string message);
}
```

With a logger level that might look like this:

```csharp
public enum LogLevel
{
    Information,
    Warning,
    Error
}
```


Instead of defining an extension method for every logging level, you can define an extension method for the ILogger interface:


```csharp
public static class LoggerExtensions
{
    public static void LogInformation(this ILogger logger, string message)
    {
        logger.Log(LogLevel.Information, message);
    }

    public static void LogWarning(this ILogger logger, string message)
    {
        logger.Log(LogLevel.Warning, message);
    }

    public static void LogError(this ILogger logger, string message)
    {
        logger.Log(LogLevel.Error, message);
    }
}
```


This keeps your API surface area small for the ILogger interface, while adding convenient methods for developers to use. Convenience makes developers happy!

## Reflection in C#

Reflection is a feature in C# that allows you to inspect, analyze, and manipulate the metadata of types, objects, and assemblies at runtime. It enables a program to dynamically access the structure of classes, methods, properties, fields, and more, without having prior knowledge at compile-time.

Libraries like **Entity Framework** and **Dapper** use reflection to map database columns to class properties and vice versa. Libraries like xUnit, NUnit, or MSTest use reflection to find test methods and execute them dynamically.

```csharp
using System.Reflection;

namespace src.Reflection.ex;

public class Product
{
    public Guid Id { get; set; }
    public string Name { get; set; }
    public double Price { get; set; }

    public string GetProductDetails()
    {
        return $"{Name}: {Price:C}";
    }
}

public class ReflectionDemo
{
    public static void example()
    {
        // Create an instance of Product
        var product = new Product
        {
            Id = Guid.NewGuid(),
            Name = "Laptop",
            Price = 1200.50
        };

        // Get the Type of the object
        Type type = product.GetType();
        Console.WriteLine($"Type: {type.Name}\n");

        // Get all properties of the Product class
        Console.WriteLine("Properties:");
        foreach (var property in type.GetProperties())
        {
            Console.WriteLine($"- {property.Name} ({property.PropertyType.Name})");
        }

        // Get and display the value of a specific property
        var nameProperty = type.GetProperty("Name");
        if (nameProperty != null)
        {
            var nameValue = nameProperty.GetValue(product);
            Console.WriteLine($"\nValue of 'Name': {nameValue}");
        }

        // Get all methods of the Product class
        Console.WriteLine("\nMethods:");
        foreach (var method in type.GetMethods(BindingFlags.Public | BindingFlags.Instance))
        {
            Console.WriteLine($"- {method.Name}");
        }

        // Invoke a specific method
        var getDetailsMethod = type.GetMethod("GetProductDetails");
        if (getDetailsMethod != null)
        {
            var details = getDetailsMethod.Invoke(product, null);
            Console.WriteLine($"\nInvoked 'GetProductDetails': {details}");
        }
    }
}
```

```
Type: Product

Properties:
- Id (Guid)
- Name (String)
- Price (Double)

Value of 'Name': Laptop

Methods:
- get_Id
- set_Id
- get_Name
- set_Name
- get_Price
- set_Price
- GetProductDetails
- GetType
- ToString
- Equals
- GetHashCode

Invoked 'GetProductDetails': Laptop: $1,200.50
```

## Generics

Generics were introduced in .NET 3.5 and C# 2 (e.g. a Long Time Ago). They are a powerful feature that allows you to define classes, methods, and interfaces with a placeholder for the data type.

This feature is fundamental in many modern programming languages and is one of the pieces of magic that makes LINQ (Language Integrated Query) possible. What is LINQ, you ask? Wait young grasshopper, you'll learn soon enough.

(Generics are a great example of polymorphism, another object-oriented pillar!)

### Very Basics of Generic Types
Generics provide a way to define classes, methods, and interfaces with a placeholder for the type of data they operate on. This allows for more flexible and reusable code, as you can define a generic class or method once and use it with any data type.

Example

```csharp
public class Box<T>
{
    private T _item;

    public void SetItem(T item)
    {
        _item = item;
    }

    public T GetItem()
    {
        return _item;
    }
}

Box<int> intBox = new Box<int>();
intBox.SetItem(10);
Console.WriteLine(intBox.GetItem()); // 10

Box<string> stringBox = new Box<string>();
stringBox.SetItem("Hello");
Console.WriteLine(stringBox.GetItem()); // Hello

stringBox.SetItem(123); // Compile-time error, yay!
```


### Creating Generic Classes
Example

```csharp
public class Storage<T>
{
    public T Item { get; set; }
}
```

In this example, Item is a property of type T, where T can be any type specified when the Storage<T> class is instantiated.

### Demonstrating Using Generically-Typed Methods


```csharp
public class Utilities
{
    public T GetDefaultValue<T>()
    {
        return default(T);
    }
}
```


In this example, `GetDefaultValue` is a method that returns the default value for the specified type T.


### Multiple Type Generics
Generics can have multiple type parameters (I think the language limit is 16, but I have never gone higher than 2 in practice).


```csharp
public class KeyValuePairs
{
    public Dictionary<int, string> CreateDictionary()
    {
        return new Dictionary<int, string>
        {
            { 1, "One" },
            { 2, "Two" }
        };
    }
}
```

One of the most common uses of multiple generic types is with collections like `Dictionary<TKey, TValue>`. In this example, `Dictionary<int, string>` holds key-value pairs, where the key is an int and the value is a string.


### Demonstrating Type Constraints

If we want to **restrict a generic class to accept only the particular type of placeholder**, then we need to use **Constraints**. *Using Constraints, we can specify what type of placeholder the generic class can accept, and the compiler will throw a compile-time error*. If we try to instantiate a generic class with the placeholder type, that is not allowed by a constraint.


In c#, constraints are specified by using the `where` keyword. The following table lists a different type of constraints available in c#.

- **`where T : struct`**:  The type argument must be a value type.
- **`where T : unmanaged`** :The type argument must not be a reference type.
- **`where T : class`** :The type argument must be a reference type.
- **`where T : new()`** :The type argument must have a public parameterless constructor.
- **`where T : <base class name>`** : The type argument must be or derive from the specified base class.
- **`where T : <interface name>`** : The type argument must be or implement the specified interface.
- **`where T : U`** : The type argument supplied for `T` must be or derive from the argument supplied for `U`.
  
  
1. **Constraint by Value Type**
Use the `struct` keyword to restrict the generic type to value types. Nullable value types are not allowed.

```csharp
class ConstrainByValueType<T> where T : struct { }

var obj = new ConstrainByValueType<int>(); // Valid
// var obj = new ConstrainByValueType<MyClass>(); // Invalid The type 'MyClass' must be a non-nullable value type in order to use it as parameter 'T' in the generic type or method 'ConstrainByValueType<T>'
```

2. **Constraint by Reference Type**
Use the `class` keyword to restrict the generic type to reference types.

```csharp
class ConstrainByReferenceType<T> where T : class { }

var obj = new ConstrainByReferenceType<MyClass>(); // Valid
// var obj = new ConstrainByReferenceType<int>(); // Invalid
```

3. **Interface Type Constraint**
Constrain the generic type to an interface, allowing only classes that implement that interface.

```csharp
interface IMammal { }
class Lion : IMammal { }

class ConstrainByInterface<T> where T : IMammal { }

var obj = new ConstrainByInterface<Lion>(); // Valid
// var obj = new ConstrainByInterface<int>(); // Invalid
```

4. **Constraint by Specific Class**
Restrict the generic type to a specific class or its derived classes.

```csharp
class Lion { }
class CuteLion : Lion { }
class Cat{}

class ConstrainByClass<T> where T : Lion { }

var obj = new ConstrainByClass<CuteLion>(); // Valid
// var obj = new ConstrainByClass<Cat>(); // Invalid
```

5. **Constraint by Parameterless Constructor**
Ensure the generic type has a public parameterless constructor using `new()`.

```csharp
class ConstrainByCtor<T> where T : new() { }
class Example {
    public Example() { }
}

var obj = new ConstrainByCtor<Example>(); // Valid
// var obj = new ConstrainByCtor<string>(); // Invalid
```

6. **Constraint by Enum**
Starting with C# 7.3, you can constrain a generic type to enums using `System.Enum`.

```csharp
class ConstrainByEnum<T> where T : System.Enum {
    public void PrintValues() {
        foreach (var value in Enum.GetValues(typeof(T)))
            Console.WriteLine(value);
    }
}
enum Rainbow { Red, Orange, Yellow, Green }
var obj = new ConstrainByEnum<Rainbow>();
obj.PrintValues();
```

7. **Combining Constraints**
You can apply multiple constraints simultaneously.

```csharp
interface IMammal { }
class RainbowLion : IMammal {
    public RainbowLion() { }
}

class ConstrainByCombination<T> where T : class, IMammal{ }

var obj = new ConstrainByCombination<RainbowLion>(); // Valid
```

In this example, the `where T : class` constraint specifies that `T` must be **a reference type** AND **must implement `IMammal`**. Constraining the type is extremely useful as it allows you to define how an interface is used. It also means that you can use members specific to that type or interface:

### Demonstrating the Repo Patterns with Generics
While I don't love talking about "software patterns", there are a few common and important ones. We'll explore this one, the Repository pattern, in more detail in the next course on APIs.

That said, imagine that you wanted to define and store the types you use in your application (spoiler alert, this is an extremely common thing to do!) Things like `Customer`, `Order`, `Product`, etc. When building that system, you might start with something like this:


```csharp
public interface IRepository<T> where T : class
{
    IEnumerable<T> GetAll();
    T GetById(int id);
    void Add(T entity);
    void Update(T entity);
    void Delete(T entity);
}

public class Repository<T> : IRepository<T> where T : class
{
    private readonly List<T> _entities = new();

    public IEnumerable<T> GetAll()
    {
        return _entities;
    }

     public T? GetById(Guid id)
    {
        if (typeof(T).GetProperty("Id")?.GetValue(null) is Guid)
        {
            return _entities.FirstOrDefault(e => (Guid)typeof(T).GetProperty("Id")!.GetValue(e)! == id);
        }
        throw new InvalidOperationException("The entity does not have an Id property.");
    }

    public void Add(T entity)
    {
        _entities.Add(entity);
    }

    public void Update(T entity)
    {
        var existing = GetById((Guid)typeof(T).GetProperty("Id")!.GetValue(entity)!);
        if (existing != null)
        {
            Delete(existing);
            Add(entity);
        }
    }
    public void Delete(T entity)
    {
        _entities.Remove(entity);
    }
}

var customerRepository = new Repository<Customer>();
var productRepository = new Repository<Product>();

customerRepository.Add(new Customer { Id = Guid.NewGuid(), Name = "John Doe" });
productRepository.Add(new Product { Id = Guid.NewGuid(), Name = "Product A" });
```


In this example, `Repository<T>` is a generic class that implements the `IRepository<T> `interface. This allows for the reuse of the repository logic across different types of entities, such as Customer, Product, etc.

