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
    - [List](#list)
    - [Common Methods for List](#common-methods-for-list)


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


### List<T>  

The `List<T>` is a generic collection in .NET that addresses many of the limitations of arrays. It is flexible, resizable, and provides various methods for adding, removing, and modifying elements.  

```csharp
List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };
List<string> list = new() { "a", "b", "c" };
```

You can even declare it with collection initializer syntax in newer versions of C#:  

```csharp
List<int> numbers = [1, 2, 3, 4, 5];
```

---

### Common Methods for List<T>

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
