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
      - [**Queue**](#queue)
      - [**Stack**](#stack)


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

#### **Queue<T>**  
A first-in, first-out (**FIFO**) collection.  
```csharp
Queue<int> queue = new Queue<int>();
queue.Enqueue(1);
queue.Enqueue(2);
queue.Enqueue(3);

int first = queue.Dequeue(); // 1
int second = queue.Dequeue(); // 2
```

#### **Stack<T>**  
A last-in, first-out (**LIFO**) collection.  
```csharp
Stack<int> stack = new Stack<int>();
stack.Push(1);
stack.Push(2);
stack.Push(3);

int top = stack.Pop(); // 3
int second = stack.Pop(); // 2
```

