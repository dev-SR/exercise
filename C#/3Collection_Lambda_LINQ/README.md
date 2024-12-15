# Note

- [Note](#note)
  - [Lambda Expressions, Func\<..., T\>, Action, and Action\<...\>](#lambda-expressions-func-t-action-and-action)
    - [Introducing Lambda Functions](#introducing-lambda-functions)
    - [Lambda Expression Syntax](#lambda-expression-syntax)
      - [`Func<...>` vs `Action<...>`](#func-vs-action)
    - [Understanding closures](#understanding-closures)
  - [Callbacks and delegates](#callbacks-and-delegates)
    - [Callbacks](#callbacks)
    - [delegates](#delegates)
  - [Collections Overview](#collections-overview)
    - [**List**](#list)
      - [Common Methods for List](#common-methods-for-list)
    - [`IEnumerable<T>` as Our First Generic Collection Type](#ienumerablet-as-our-first-generic-collection-type)
      - [Lazy evaluation](#lazy-evaluation)
    - [**Dictionary\<TKey, TValue\>**](#dictionarytkey-tvalue)
      - [Setting Values](#setting-values)
      - [Getting Values](#getting-values)
      - [Useful Methods](#useful-methods)
    - [**HashSet**](#hashset)
    - [**ImmutableArray**](#immutablearray)
    - [**Queue and Stack**](#queue-and-stack)
      - [Queue](#queue)
      - [Stack](#stack)
  - [**`LINQ`** (Language INtegrated Query)](#linq-language-integrated-query)
    - [Example: Employee Data Query](#example-employee-data-query)
      - [Solution Using For Loops and Sorting](#solution-using-for-loops-and-sorting)
      - [Solution Using LINQ](#solution-using-linq)
    - [How Lazy Evaluation Works with IEnumerable and LINQ](#how-lazy-evaluation-works-with-ienumerable-and-linq)
    - [`ToList()` and `ToArray()`](#tolist-and-toarray)
    - [Query Syntax vs Lambda Syntax](#query-syntax-vs-lambda-syntax)
      - [Query Syntax](#query-syntax)
      - [Lambda Syntax](#lambda-syntax)
    - [**Select** ~ .map()](#select--map)
      - [Projection and Anonymous Types](#projection-and-anonymous-types)
        - [When to Use Anonymous Types:](#when-to-use-anonymous-types)
        - [Things to Avoid](#things-to-avoid)
    - [**Where** ~ .filter()](#where--filter)
      - [Chaining Where and Select](#chaining-where-and-select)
      - [Example Multiple Filters with Where](#example-multiple-filters-with-where)
    - [Selecting Single Values](#selecting-single-values)
      - [**First/FirstOrDefault**:](#firstfirstordefault)
      - [**Single/SingleOrDefault**](#singlesingleordefault)
      - [First vs Single](#first-vs-single)
    - [Ordering](#ordering)
      - [**OrderBy** and **OrderByDecending**](#orderby-and-orderbydecending)
      - [**ThenBy** for Secondary Sorting](#thenby-for-secondary-sorting)
    - [Aggregate Methods](#aggregate-methods)
      - [**Sum/Average/Max/Min/Count**](#sumaveragemaxmincount)
      - [Exceptions with Empty Seats](#exceptions-with-empty-seats)
      - [Using `DefaultIfEmpty`](#using-defaultifempty)
    - [**Take/Skip**](#takeskip)
    - [**All/Any**](#allany)
    - [**Distinct**](#distinct)
    - [**GroupBy**](#groupby)
    - [Flatten with **SelectMany**](#flatten-with-selectmany)
      - [Filtering with Nested Collections](#filtering-with-nested-collections)
      - [Cartesian Product](#cartesian-product)
    - [**Join**](#join)


## Lambda Expressions, Func<..., T>, Action, and Action<...>

### Introducing Lambda Functions

Lambda expressions are a concise way to represent anonymous methods (methods without a name) in C#. They are commonly used in scenarios involving delegates or expressions, where a quick and simple function is needed.

Many programming languages offer a concept similar to lambda expressions. They may have names like:

- **Anonymous functions** (JavaScript)
- **Arrow functions** (JavaScript, TypeScript, Kotlin, etc.)
- **Lambdas** (Python, Ruby, etc.)
  
Lambda expressions in C# are functionally similar, allowing for concise inline function definitions.

### Lambda Expression Syntax

The basic syntax of a lambda expression in C# uses the `=>` operator, which is pronounced as "goes into." Here's a breakdown:

- The left side contains the input parameters (in parentheses).
- The right side contains the expression or the body of the function.


```ts
(x, y) => x + y
```

This is functionally equivalent to a "regular function" that looks like this:

```csharp
int Add(int x, int y)
{
    return x + y;
}
```

**Refresher: Action Methods vs Methods That Return a Value**

- **Action or void-returning methods** perform an action but do not return a value (i.e., they have a void return type).
- **Value-returning methods** return a value of a specific type.

#### `Func<...>` vs `Action<...>`

`Func<T1, T2, ..., TResult>` represents a method that takes input parameters and returns a value of type `TResult`.

Each of the types in the `Func<...>` delegate represents the type of each parameter, and the last type represents the type of the return value.

For example, a `Func<int, int, int>` delegate represents a method that **takes two int parameters and returns an int**, like this "normal function":


```csharp
Func<int, int, int> Sum = (a, b) =>
{
    return a + b;
};
int res = Sum(1, 2);
```


`Action<T1, T2, ...>` represents a method that takes input parameters and returns void (i.e., does not return a value).

These delegates are frequently used with lambda expressions to create anonymous methods inline.

```csharp
Action<string> writeStringToConsole = x => Console.WriteLine(x);
```

An Action delegate encapsulates a method that returns void. This Action delegate represents a method that takes an object parameter and prints it to the console. The lambda expression defines this action concisely.

### Understanding closures

Closures occur when a lambda expression captures variables from its enclosing scope. In other words, the lambda expression "remembers" the variables that were in scope when the lambda was created, even after the scope ends. This can be particularly useful in scenarios where you need to keep track of values outside the function's direct scope.

For example:


```csharp
int counter = 0;
Func<int, int> incrementCounter = num => {
    counter = num + counter;
    return counter;
};
Console.WriteLine(incrementCounter(5)); // Output: 5
Console.WriteLine(incrementCounter(7)); // Output: 12
Console.WriteLine(incrementCounter(8)); // Output: 20
```

In this example, the lambda expression { counter = num + counter; return counter; } captures the variable counter from its surrounding scope. Each time incrementCounter is invoked, it increments by the specified amount and returns the current value of counter, even though counter is outside the direct scope of the lambda.

How Closures Work
Closures work because C# handles the captured variables as references, not as values. Even though the function is anonymous and can be executed outside its initial context, the captured variable still exists in memory, and changes to it persist.

## Callbacks and delegates

### Callbacks 

```csharp

Func<int, int, int> Sum = (a, b) =>
{
    return a + b;
};
Func<int, int, int> Subtract = (a, b) =>
{
    return a - b;
};


void PrintCalculation(Func<int, int, int> callback)
{
    Console.WriteLine("Enter 1st integer:");
    int a = int.Parse(Console.ReadLine());
    Console.WriteLine("Enter 2nd integer:");
    int b = int.Parse(Console.ReadLine());

    int res = callback(a, b);
    Console.WriteLine($"The result is: {res}");
}

Console.WriteLine("Addition Example: ");
PrintCalculation(Sum);
Console.WriteLine("Subtract Example: ");
PrintCalculation(Subtract);
```

### delegates

— `Action` is simple
— `Func` is convenient but doesn't help readability
But what if we want our own? Can we get more readability? ans: `delegates`

Defining a Custom Delegate:

```csharp
// Declare a custom delegate
delegate int Calculation(int a, int b);
```

 Example: Using Delegates in a Class  

```csharp
// Declare a custom delegate
delegate int Calculation(int a, int b);

class Calculator
{
    public static int Add(int a, int b)
    {
        return a + b;
    }

    public static int Subtract(int a, int b)
    {
        return a - b;
    }

    public void PerformCalculation(Calculation calculation)
    {
        Console.WriteLine("Enter 1st integer:");
        int a = int.Parse(Console.ReadLine());
        Console.WriteLine("Enter 2nd integer:");
        int b = int.Parse(Console.ReadLine());

        int result = calculation(a, b);
        Console.WriteLine($"The result is: {result}");
    }
}

class Program
{
    static void Main()
    {
        Calculator calculator = new Calculator();

        Console.WriteLine("Addition Example:");
        calculator.PerformCalculation(Calculator.Add);

        Console.WriteLine("Subtraction Example:");
        calculator.PerformCalculation(Calculator.Subtract);
    }
}
```

## Collections Overview

- **`ImmutableArray<T>`:** Use when you need a collection that won’t change. Great for immutable objects.  
- **`List<T>`:** Use when you need a resizable collection that allows fast access by index.  
- **`Dictionary<TKey, TValue>`:** Use when you need to map keys to values and need fast lookups.  
- **`HashSet<T>`:** Use when you need a collection of unique values with fast lookups.  
- **`Queue<T>`:** Use when you need a first-in, first-out (**FIFO**) collection.  
- **`Stack<T>`:** Use when you need a last-in, first-out (**LIFO**) collection.  

🌶️ **Top Picks:** **`ImmutableArray<T>`**, **`Dictionary<TKey, TValue>`**, and **`List<T>`** for their versatility and performance.

### **List<T>**  

The `List<T>` is a generic collection in .NET that addresses many of the limitations of arrays. It is flexible, resizable, and provides various methods for adding, removing, and modifying elements.  

```csharp
List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };
List<string> list = new() { "a", "b", "c" };
```

You can even declare it with collection initializer syntax in newer versions of C#:  

```csharp
List<int> numbers = [1, 2, 3, 4, 5];
```


#### Common Methods for List<T>

- `Add / AddRange` 
- **Add:** Adds a single element to the list.  
  ```csharp
  numbers.Add(item);
  ```
- **AddRange:** Adds multiple elements to the list at once.  
  ```csharp
  numbers.AddRange(new int[] { 7, 8, 9 });
  ```

- `Remove / RemoveAt`  
- **Remove:** Removes the first occurrence of a specific element.  
  ```csharp
  numbers.Remove(item);
  ```
- **RemoveAt:** Removes an element at the specified index.  
  ```csharp
  numbers.RemoveAt(index);
  ```

- `Insert`  
Adds an element at the specified index.  
```csharp
numbers.Insert(index, item);
```

- `IndexOf`  
Returns the index of the first occurrence of an element.  
```csharp
int index = numbers.IndexOf(item);
```

- `Count`  
Returns the number of elements in the list.  
```csharp
int count = numbers.Count;
```

- `Sort` : Sorts the elements in the list in ascending order.  
  
```csharp
numbers.Sort();
```

- `Reverse` : Reverses the order of elements in the list.  
  
```csharp
numbers.Reverse();
```

- `ForEach` Method  

```csharp
// Avoid using List<T>.ForEach like this
numbers.ForEach(number => Console.WriteLine(number));

// standard foreach loop
foreach (var number in numbers) 
{
    Console.WriteLine(number);
}
```

### `IEnumerable<T>` as Our First Generic Collection Type

It provides a way to iterate over a collection of items of type `T`. All interfaces and classes that are generic collections implement `IEnumerable<T>`.

You will almost never implement `IEnumerable<T>` directly, but it's important to understand that all generic collections implement it and the implications of its existence. More on this later!

Example: Basic Use of `IEnumerable<T>`

```csharp
IEnumerable<int> numbers = new List<int> { 1, 2, 3, 4, 5 };

foreach (var number in numbers)
{
    Console.WriteLine(number);
}
```

Why Use IEnumerable<T>
- **Abstraction & Flexibility**: It abstracts the underlying collection type, allowing you to switch between different implementations (e.g., List<T> to HashSet<T>) without changing the consuming code.
- **Performance**: Lazy Deferred execution helps handle large datasets efficiently by processing items as needed, rather than all at once.

#### Lazy evaluation

Not just `IEnumerable<T>` makes it more versatile and reusable, for example, you can pass arrays (`int[]`), `HashSet<int>`, or any other collection that supports enumeration and integrates seamlessly with LINQ, allowing further query chaining, But also importantly **allow Lazy deferred execution**, improving performance.

**Lazy evaluation** is an important concept in .NET collections, especially when working with `IEnumerable<T>`. It means that for certain types of operations, values or sequences of values are not generated or fetched until they are actually needed, which can significantly improve performance and reduce memory usage, especially when working with large data sets or expensive computations.


```csharp
public IEnumerable<int> GetNumbers()
{
    yield return 1;
    yield return 2;
}
```

the `yield` keyword is used to return an element one at a time from a method. It is commonly used in `LINQ` queries to return a sequence of elements.

```csharp
public class Demo
{
    public static void M()
    {
        List<int> numbers = new List<int> { 1, 2, 3, 4, 5, 6, 8, 10 };
        var evenNumbers = GetEvenNumbers(numbers).Take(3);//LINQ integration

        foreach (var number in evenNumbers)
        {
            Console.WriteLine(number);
        }

        evenNumbers = GetEvenNumbersList(numbers).Take(3);//

        foreach (var number in evenNumbers)
        {
            Console.WriteLine(number);
        }
    }
    static IEnumerable<int> GetEvenNumbers(IEnumerable<int> numbers)
    {
        foreach (var number in numbers)
        {
            if (number % 2 == 0)
                yield return number; // Deferred execution
        }
    }


    // vs List implementation | watchout the differences
    static List<int> GetEvenNumbersList(IEnumerable<int> numbers)
    {
        List<int> _result = new();
        foreach (var number in numbers)
        {
            if (number % 2 == 0)
            {
                _result.Add(number);
            }
        }
        return _result;
    }
}
```

### **Dictionary<TKey, TValue>**

A `Dictionary<TKey, TValue>` is a collection that maps **keys** to **values**, where both keys and values have specific types. It uses a **hash code** internally for fast lookups.

#### Setting Values
```csharp
Dictionary<string, int> dictionary = new Dictionary<string, int>();

// Set the values
dictionary["one"] = 1;
dictionary[2] = "two"; // This doesn't compile because the key must be a string!
```

#### Getting Values

```csharp
Dictionary<string, int> dictionary = new Dictionary<string, int>();

// Set the values
dictionary["one"] = 1;
dictionary["two"] = 2;

// Get the values
int thisValue = dictionary["one"];
int thatValue = dictionary["two"];

// Will throw KeyNotFoundException if the key doesn't exist
int doesNotExistValue = dictionary["three"];
```

#### Useful Methods
1. **`Add`**  
   Adds a key-value pair to the dictionary.  
   ```csharp
   dictionary.Add("three", 3); // Throws an exception if the key already exists
   ```

2. **`Remove`**  
   Removes a key-value pair from the dictionary.  
   ```csharp
   dictionary.Remove("one");
   ```

3. **`ContainsKey`**  
   Checks if the dictionary contains a key.  
   ```csharp
   bool exists = dictionary.ContainsKey("two");
   ```

4. **`ContainsValue`**  
   Checks if the dictionary contains a value.  
   ```csharp
   bool hasValue = dictionary.ContainsValue(3);
   ```

5. **`TryGetValue`**  
   Tries to get the value for a key without throwing an exception.  
   ```csharp
   if (dictionary.TryGetValue("three", out int value)) 
   {
       Console.WriteLine(value);
   }
   ```

6. **`Clear`**  
   Removes all key-value pairs from the dictionary.  
   ```csharp
   dictionary.Clear();
   ```

7. **`Count`**  
   Gets the number of key-value pairs in the dictionary.  
   ```csharp
   int count = dictionary.Count;
   ```

8. **`Keys` and `Values`**  
   Retrieves all keys or all values as collections.  
   ```csharp
   IEnumerable<string> keys = dictionary.Keys;
   IEnumerable<int> values = dictionary.Values;
   ```

---

### **HashSet<T>**
A `HashSet<T>` is a collection that stores a **set of unique values**. It also uses a hash code for fast lookups.

```csharp
HashSet<int> hashSet = new HashSet<int>();
hashSet.Add(1);
hashSet.Add(2);
hashSet.Add(2); // This will not be added because it is a duplicate
```

### **ImmutableArray<T>**
An `ImmutableArray<T>` stores a fixed-size array of values that cannot be changed after creation.

```csharp
ImmutableArray<int> immutableArray = ImmutableArray.Create(1, 2, 3, 4, 5);

// Adding to the array returns a new ImmutableArray<T> with the added value
ImmutableArray<int> newImmutableArray = immutableArray.Add(6);
```

### **Queue<T> and Stack<T>**

#### Queue<T> 
A first-in, first-out (**FIFO**) collection.  
```csharp
Queue<int> queue = new Queue<int>();
queue.Enqueue(1);
queue.Enqueue(2);
queue.Enqueue(3);

int first = queue.Dequeue(); // 1
int second = queue.Dequeue(); // 2
```

#### Stack<T>  
A last-in, first-out (**LIFO**) collection.  
```csharp
Stack<int> stack = new Stack<int>();
stack.Push(1);
stack.Push(2);
stack.Push(3);

int top = stack.Pop(); // 3
int second = stack.Pop(); // 2
```

## **`LINQ`** (Language INtegrated Query)

`LINQ` stands for **Language INtegrated Query**. It is one of the best features of .NET, enabling developers to write concise, readable queries directly in C# (or other .NET languages) to work with **collections, databases, XML**, and other data sources.

While other languages have their versions of LINQ, it is a **key feature in .NET** that enhances productivity and code clarity.

---

### Example: Employee Data Query

Imagine you have an `Employee` object, and you need to:
1. Get the names of all employees earning over $100,000.
2. Display these names on the page, sorted in order.

---

#### Solution Using For Loops and Sorting
Before LINQ, you would write:

```csharp
public class Employee{
    public int Id { get; set; }
    public string Name { get; set; }
    public int Age { get; set; }
    public double Salary { get; set; }
    public string Department { get; set; }
}

public class LINQDemo{
    private static List<Employee> employees = GetEmployees();
    public static List<Employee> GetEmployees()
    {
        return new List<Employee>
                {
                    new Employee { Id = 1, Name = "Alice", Age = 25, Department = "HR", Salary = 120000 },
                    new Employee { Id = 2, Name = "Bob", Age = 30, Department = "IT", Salary = 95000 },
                    new Employee { Id = 3, Name = "Charlie", Age = 28, Department = "Finance", Salary = 105000  },
                    new Employee { Id = 4, Name = "Diana", Age = 35, Department = "IT", Salary = 75000  },
                    new Employee { Id = 5, Name = "Eve", Age = 22, Department = "HR", Salary = 130000 }
                };
    }

    public static void WithOutLinq()    {
        List<Employee> highEarners = new List<Employee>();
        foreach (var employee in employees){
            if (employee.Salary > 100000){
                highEarners.Add(employee);
            }
        }

        highEarners.Sort((emp1, emp2) => emp1.Name.CompareTo(emp2.Name));
        
        foreach (var highEarner in highEarners){
            Console.WriteLine(highEarner.Name);
        }
    }


}
```

#### Solution Using LINQ

**Lambda Syntax:**
```csharp
    public static void WithLINQ()
    {
        var highEarners = employees
                            .Where(e => e.Salary > 100000)
                            .OrderBy(e => e.Name)
                            .Select(e => e.Name);
        foreach (var name in highEarners)
        {
            Console.WriteLine(name);
        }
    }
```

**Query Syntax:**
```csharp
public static void QuerySyntax()
{
    var highEarners = from e in employees
                        where e.Salary > 100000
                        orderby e.Name
                        select e.Name;

    foreach (var name in highEarners)
    {
        Console.WriteLine(name);
    }
}
```

Technologies That Make LINQ Possible:

1. **Generics**  
   Allows LINQ to work with collections of any type.  
2. **IEnumerable<T>**  
   LINQ queries operate on any collection that implements this interface.  
3. **Extension Methods**  
   LINQ uses extension methods like `Where()`, `OrderBy()`, and `Select()` to add query capabilities to collections.  
4. **Lambda Expressions**  
   Provide the logic for filtering, sorting, and transforming data in LINQ queries.

---

### How Lazy Evaluation Works with IEnumerable<T> and LINQ

In the context of `IEnumerable<T>`, methods like `Select`, `Where`, and `Take` do not execute immediately. They set up a **query pipeline**, and the actual execution happens only when the results are accessed—for example, in a `foreach` loop or by calling a terminal operation like `ToList()`.

```csharp
public class Example
{
    public static void Main()
    {
        var numbers = new[] { 1, 2, 3, 4, 5 };
        
        var query = numbers.Where(n => n % 2 == 0);

        Console.WriteLine("Query is defined, but not executed yet.");

        foreach (var number in query)
        {
            Console.WriteLine(number);  // Query executes here
        }
    }
}
```

**Key Points:**
- `numbers.Where(n => n % 2 == 0)` defines the query but doesn’t execute it immediately.
- The query executes only when the `foreach` loop iterates over the sequence.  
This is called **deferred execution**.

---

### `ToList()` and `ToArray()`

`ToList` and `ToArray` are methods that make an `IEnumerable<T>` into a `List<T>` or `Array` of that type. It forces an otherwise "lazy" sequence into materialization.


```csharp
public class Example
{
    public static void Main()
    {
        var numbers = new[] { 1, 2, 3, 4, 5 };
        
        var query = numbers.Where(n => n % 2 == 0);

        Console.WriteLine("Query is defined, but not executed yet.");

        var asList = query.ToList();  // Forces execution and materializes the results in memory
    }
}
```

---

### Query Syntax vs Lambda Syntax

#### Query Syntax
This syntax is closer to SQL and is easier to read for those familiar with traditional databases.

```csharp
var result = from item in collection
             where item.Condition == true
             select item;
```

#### Lambda Syntax
This is more concise, allows chaining multiple operations, and is commonly used in modern C# development.

```csharp
var result = collection
    .Where(item => item.Condition == true);  // Select is implied
```

Both syntaxes compile to the same code, so the choice between them is a matter of **personal preference** and **readability**.

use **lambda syntax**, and the vast majority of the code you would encounter in the wild also uses it.


### **Select** ~ .map()

Select is used to transform one type into another, essentially making something out of something else.

```csharp
var employeeNames = employees.Select(e => e.Name).ToList();
// Output: Alice, Bob, Charlie, Diana, Eve
```

#### Projection and Anonymous Types

If you want to project their `Name` and `Salary` properties into a new type. Here’s an example:

```csharp
var employeeData = employees.Select(e => new { 
  e.Name, 
  e.Salary
});
```

Wait, what the heck is that thing? We're using new without a type? They're known as `anonymous` types, and they're supremely useful.

Why is this useful? Why not just use the original type as is?

If you have a complex type with lots of nested data, you can project a new type to "flatten" the data, like so:


```csharp
var employeeData = employees.Select(e => new { 
  ManagerName = e.Manager.Name,
  e.Salary,
  DepartmentName = e.Department.Name
});
```


You might need a completely different object from your first type:

```csharp
var employeeData = employees.Select(e => new EmployeeInfo(e));
```

Spoiler alert, in the next course we'll be using LINQ to query databases, and we can improve performance by projecting a new type that has fewer columns.

##### When to Use Anonymous Types:

- Use them when you need a quick data projection without creating new classes.
- Typically used in temporary situations like LINQ queries where the projected result is not intended to last beyond its immediate use.

##### Things to Avoid

Avoid using Select as a kind of foreach loop: Although it may seem tempting, Select is not a substitute for foreach. Select should be used for projection (i.e., transforming data), not for performing actions or side effects.

```csharp
//Incorrect Usage
employees.Select(e => Console.WriteLine(e.Name));  //🤢
```

This misuses Select as if it were foreach. If you need to iterate over a collection to perform an action, use foreach instead.

Another common mistake is using Select to modify the objects that are being iterated over. Select should be used to transform and project new objects, not mutate existing ones.

```csharp
//Incorrect Usage
employees.Select(e => e.Salary += 5000);  //🤢
```

This example tries to modify each employee’s salary, which is not the intended purpose of Select. If you need to mutate objects, handle that logic elsewhere.

### **Where** ~ .filter()

Filters the collection based on a condition.

Where takes a **predicate**, which is a function that returns `true` or `false` based on whether the object should be included in the result set.

```csharp
var itEmployees = employees.Where(e => e.Department == "IT").ToList();
// Output: Bob, Diana
```

#### Chaining Where and Select

In LINQ, you can chain methods together to perform multiple operations in sequence. This is particularly useful when combining `Where` and `Select` to both filter and transform data.

```csharp
var highEarnerNames = employees
    .Where(e => e.Salary > 100000)
    .Select(e => e.Name);
```

    
Here’s what happens:
- `Where` filters the collection based on salary.
- `Select` then projects the result into a new collection that only contains the employees' names.

#### Example Multiple Filters with Where

```csharp
var seniorHighEarners = employees
    .Where(e => e.Salary > 100000)
    .Where(e => e.YearsOfExperience > 10);
```

### Selecting Single Values

#### **First/FirstOrDefault**:

- `First` returns the first element of a sequence. It throws an exception if the sequence is empty.
- `FirstOrDefault` returns the first element of a sequence, or the default value (e.g., null for reference types) if the sequence is empty.



```csharp
var firstEmployee = employees.First();
// Output: Alice

var firstItEmployee = employees.FirstOrDefault(e => e.Department == "IT");
// Output: Bob

int emptyFirst = new List<Employee>().First(); // throws an exception
Employee emptyFirstOrDefault = new List<Employee>().FirstOrDefault();
Console.WriteLine(emptyFirstOrDefault is null);//true
```

#### **Single/SingleOrDefault**

- `Single` returns the single element of a sequence. It throws an exception if the sequence is empty or if there is more than one matching element.
- `SingleOrDefault` returns the single element of a sequence, or the default value (e.g., `null` for reference types) if the sequence is empty. It throws an exception if more than one element exists.


```csharp
var singleEmployee = employees.Single(e => e.Id == 3);
// Output: Charlie

// Throws exception if there are no employees with Id 10
var singleEmployeeNotFound = employees.Single(e => e.Id == 10);
// Throws InvalidOperationException
var singleEmployeeOrDefault = employees.SingleOrDefault(e => e.Id == 3);
// Output: Charlie

var singleEmployeeNotFoundOrDefault = employees.SingleOrDefault(e => e.Id == 10);
// Output: null (no element found)

var singleEmployeeDuplicateOrDefault = employees.SingleOrDefault(e => e.Department == "HR");
// Throws InvalidOperationException (because there are multiple employees in the HR department)
```


#### First vs Single

While `First` and `FirstOrDefault` can be useful, they come with a caveat: they return the first matching element in a sequence, **even if multiple elements match the condition**. That sounds reasonable since it's called First after all, but it's a code smell. This can introduce subtle bugs if you assume the collection only contains one matching element but it actually contains more.

🌶️🌶️🌶️ In most scenarios, be prefers to use `Single` or `SingleOrDefault`. These methods are explicit in their expectations: they demand that the sequence contains only one matching element, which can help avoid subtle bugs and improve code clarity. By using Single, you can ensure that your logic enforces uniqueness, avoiding cases where multiple elements are incorrectly returned.

Example

```csharp
var employees = new List<Employee>
{
    new Employee { Id = 1, Name = "John" },
    new Employee { Id = 1, Name = "Jane" }
};

// Using First
Employee firstEmployee = employees.First(e => e.Id == 1); // returns "John"

// Potentially dangerous assumption:
Employee singleEmployee = employees.FirstOrDefault(e => e.Id == 1); // returns "John", but there are two employees with Id == 1
```


In this case, `First` would return the first employee it finds ("John"), but it ignores that there is another employee with the same ID ("Jane"). If your logic assumes there should only be one match, using `Single` would be a safer option, as it would throw an exception if multiple matches are found.

🌶️🌶️🌶️ Some developers go too far to avoid exceptions in their code, to the point of writing software that is technically incorrect. Exceptions are not bad - it's better to have an exception thrown than to introduce a subtle bug that puts a production system in an incorrect state.


### Ordering

#### **OrderBy** and **OrderByDecending**


```csharp
var sortedByAge = employees.OrderBy(e => e.Age).ToList();
// Output: Eve (22), Alice (25), Charlie (28), Bob (30), Diana (35)

var sortedByAgeDesc = employees.OrderByDescending(e => e.Age).ToList();
// Output: Diana (35), Bob (30), Charlie (28), Alice (25), Eve (22)
```


How it works: `OrderBy/OrderByDecending` requires a **key selector**—a function that extracts the **key** by which the elements are sorted.


#### **ThenBy** for Secondary Sorting

After applying `OrderBy` or `OrderByDescending`, you can use the `ThenBy` method to specify a secondary sort key. This is useful when you need to sort by more than one property.

```csharp
var sortedEmployees = employees
    .OrderBy(e => e.Salary)
    .ThenBy(e => e.Name);

var sortedEmployees = employees
    .OrderBy(e => e.Salary)
    .ThenByDescending(e => e.Name);
```

How it works
- The collection is first sorted by Salary in ascending order. 
- For employees with the same Salary, the ThenBy method sorts them by Name in ascending/descending order.


### Aggregate Methods
Aggregate methods in LINQ provide an easy way to perform calculations over a sequence of elements. These methods allow you to compute sums, averages, and find maximum or minimum values from a collection. In this lesson, we will cover the commonly used aggregate methods in LINQ, how they work, and the caveats to watch out for, such as handling empty sets.

#### **Sum/Average/Max/Min/Count**


```csharp
var totalAge = employees.Sum(e => e.Age);
// Output: 140

var averageAge = employees.Average(e => e.Age);
// Output: 28

var maxAge = employees.Max(e => e.Age);
// Output: 35

var minAge = employees.Min(e => e.Age);
// Output: 22

var totalEmployees = employees.Count();
// Output: 5

var hrCount = employees.Count(e => e.Department == "HR");
// Output: 2

```

#### Exceptions with Empty Seats
When dealing with empty collections, aggregate methods such as Sum, Max, Min, and Average will throw an exception.

```csharp
var emptyList = new List<int>();
int sumOfEmpty = emptyList.Sum(); // throws InvalidOperationException
```

#### Using `DefaultIfEmpty`
The `DefaultIfEmpty` method allows you to handle empty sequences gracefully by providing a default value. This is particularly useful with aggregate methods to avoid exceptions when dealing with empty collections.

```csharp
var emptyList = new List<int>();
int safeSum = emptyList.DefaultIfEmpty(0).Sum(); // returns 0
int safeMax = emptyList.DefaultIfEmpty(0).Max(); // returns 0

//these would throw an exception:
int exceptional = emptyList.Sum();
```


### **Take/Skip**

Takes or skips a specified number of elements.

csharp
Copy code

```csharp
var firstThree = employees.Take(3).ToList();
// Output: Alice, Bob, Charlie

var skipTwo = employees.Skip(2).ToList();
// Output: Charlie, Diana, Eve
```

### **All/Any**

`Any`: Determines if any elements satisfy a condition.

```csharp
var hasYoungEmployees = employees.Any(e => e.Age < 23);
// Output: True
```

`All`:Determines if all elements satisfy a condition.

```csharp
var allAbove20 = employees.All(e => e.Age > 20);
// Output: True
```

### **Distinct**
Distinct is a LINQ method used to remove duplicate elements from a sequence, returning only unique values. It is particularly useful when you want to ensure that the resulting collection contains no repeated items.


```csharp
var uniqueDepartments = employees.Select(e => e.Department).Distinct().ToList();
// Output: HR, IT, Finance
```


This also works with anonymous types and records naturally:


```csharp
var employees = new[]
{
    new { Name = "John", Department = "HR" },
    new { Name = "Mike", Department = "IT" },
    new { Name = "John", Department = "HR" }, // Duplicate
    new { Name = "Sara", Department = "HR" }
};

var distinctEmployees = employees.Distinct();

foreach (var employee in distinctEmployees)
{
    Console.WriteLine($"{employee.Name} from {employee.Department}");
}

//output:
//John from HR
//Mike from IT
//Sara from HR
```


Using `Distinct` with a Custom Class (`Employee`) and `IEqualityComparer<T>`

When working with a custom class (like Employee), you need to define how two instances of that class should be compared. This is where `IEqualityComparer<T>` comes into play.

```csharp
public class EmployeeEqualityComparer : IEqualityComparer<Employee>
{
    public bool Equals(Employee x, Employee y)
    {
        if (x == null || y == null)
            return false;

        // Compare based on Name and Department
        return x.Name == y.Name && x.Department == y.Department;
    }

    public int GetHashCode(Employee obj)
    {
        if (obj == null)
            return 0;

        // Combine Name and Department into a unique hash code
        return (obj.Name + obj.Department).GetHashCode();
    }
}
```

Now we'll pass it to `Distinct` so it can use it:

```csharp
public class Employee
{
    public string Name { get; set; }
    public string Department { get; set; }
}

var employees = new[]
{
    new Employee { Name = "John", Department = "HR" },
    new Employee { Name = "Jane", Department = "Finance" },
    new Employee { Name = "Mike", Department = "IT" },
    new Employee { Name = "John", Department = "HR" }, // Duplicate
    new Employee { Name = "Sara", Department = "HR" }
};

// Use Distinct with a custom comparer for Employee objects
var distinctEmployees = employees.Distinct(new EmployeeEqualityComparer());

foreach (var employee in distinctEmployees)
{
    Console.WriteLine($"{employee.Name} from {employee.Department}");
}

//output:
//John from HR
//Jane from Finance
//Mike from IT
//Sara from HR
```



Last note: there is a `DistinctBy` method that came out in the last few years that allows you to specify a property to use for the distinct comparison:


```csharp
var employees = new[]
{
    new Employee { Name = "John", Department = "HR" },
    new Employee { Name = "Jane", Department = "Finance" },
    new Employee { Name = "Mike", Department = "IT" },
    new Employee { Name = "John", Department = "HR" }, // Duplicate
    new Employee { Name = "Sara", Department = "HR" }
};
var distinctEmployees = employees.DistinctBy(e => e.Name);
```



### **GroupBy**

The `GroupBy` method is very valuable when you need to group similar objects together. It allows you to categorize elements into groups.

Example

```csharp
var groupedByDept = employees.GroupBy(e => e.Department);
foreach (var group in groupedByDept)
{
    Console.WriteLine($"{group.Key}: {string.Join(", ", group.Select(e => e.Name))}");
}
// Output:
// HR: Alice, Eve
// IT: Bob, Diana
// Finance: Charlie
```


### Flatten with **SelectMany**

The SelectMany method is used to **flatten** a collection of collections into a single sequence. This is particularly useful when you have objects that contain other collections, and you want to “unzip” them.

Example

```csharp
public class Employee
{
    public string Name { get; set; }
    public List<string> Skills { get; set; }
}

var employees = new List<Employee>
{
    new Employee { Name = "Alice", Skills = new List<string> { "C#", "SQL" } },
    new Employee { Name = "Bob", Skills = new List<string> { "Java", "Python" } },
    new Employee { Name = "Charlie", Skills = new List<string> { "C++", "Go" } }
};

//Without SelectMany (Nested Collections):
var employeeSkills = employees.Select(e => e.Skills).ToList();
// Output: List of skill lists:
// [ ["C#", "SQL"], ["Java", "Python"], ["C++", "Go"] ]

// Using SelectMany (Flattened Collection):
var allSkills = employees.SelectMany(e => e.Skills).ToList();
// Output: ["C#", "SQL", "Java", "Python", "C++", "Go"]

```


#### Filtering with Nested Collections

Ex: Find all unique skills starting with "C":


```csharp
var skillsStartingWithC = employees
    .SelectMany(e => e.Skills)
    .Where(skill => skill.StartsWith("C"))
    .Distinct()
    .ToList();
// Output: ["C#", "C++"]
```

#### Cartesian Product

```csharp
var numbers = new List<int> { 1, 2, 3 };
var letters = new List<string> { "A", "B" };
var cartesianProduct = numbers.SelectMany(
    n => letters,
    (number, letter) => $"{number}{letter}"
).ToList();
// Output: ["1A", "1B", "2A", "2B", "3A", "3B"]
```

### **Join**

The Join method is used to combine data from two sequences based on a common key.

ex1:

```csharp
var departments = new List<string> { "HR", "IT" };
var matchingEmployees = employees.Join(departments,
    e => e.Department,
    d => d,
    (e, d) => e.Name).ToList();
// Output: Alice, Bob, Diana, Eve
```

ex2:

```csharp
var employees = new[]
{
    new { EmployeeId = 1, Name = "John", DepartmentId = 1 },
    new { EmployeeId = 2, Name = "Jane", DepartmentId = 2 },
    new { EmployeeId = 3, Name = "Mike", DepartmentId = 3 }
};

var departments = new[]
{
    new { EmployeeId = 1, Department = "HR" },
    new { EmployeeId = 2, Department = "Finance" },
    new { EmployeeId = 3, Department = "IT" }
};

//query syntax
var result = from e in employees
             join d in departments on e.DepartmentId equals d.DepartmentId
             select new { e.Name, d.Department };

foreach (var item in result)
{
    Console.WriteLine($"{item.Name} works in {item.Department}");
}

//lambda syntax
var result = employees.Join(departments,
                            e => e.DepartmentId,
                            d => d.DepartmentId,
                            (e, d) => new { e.Name, d.Department });

foreach (var item in result)
{
    Console.WriteLine($"{item.Name} works in {item.Department}");
}
```
