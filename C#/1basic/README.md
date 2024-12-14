# Basics of Csharp

- [Basics of Csharp](#basics-of-csharp)
  - [Variables in C#](#variables-in-c)
    - [Declaring Variables](#declaring-variables)
    - [Initializing Variables](#initializing-variables)
    - [Constants](#constants)
    - [Value Types vs Reference Types](#value-types-vs-reference-types)
  - [Built-in Types in C#](#built-in-types-in-c)
    - [1. Object](#1-object)
    - [2. String/Char](#2-stringchar)
    - [3. Boolean](#3-boolean)
    - [4. Byte/Sbyte](#4-bytesbyte)
    - [5. Int/Short/Long](#5-intshortlong)
    - [6. Unsigned Int/Short/Long](#6-unsigned-intshortlong)
    - [7. Float/Double/Decimal](#7-floatdoubledecimal)
    - [8. DateTime](#8-datetime)
    - [9. Arrays](#9-arrays)
      - [**Array Initialization**](#array-initialization)
      - [**Array Properties:**](#array-properties)
    - [10. Enums](#10-enums)
    - [11. Tuples](#11-tuples)
      - [**Creating Tuples**](#creating-tuples)
      - [**Named Tuples**](#named-tuples)
      - [**Deconstructing Tuples**](#deconstructing-tuples)
      - [**Use Cases**](#use-cases)
    - [12. Special Mention: `Null` and `Void`](#12-special-mention-null-and-void)
  - [Control Flow in C#](#control-flow-in-c)
    - [If Statements](#if-statements)
    - [Switch Statements](#switch-statements)
  - [Loops](#loops)
    - [For Loop](#for-loop)
    - [Foreach Loop](#foreach-loop)
  - [More on **String**](#more-on-string)
    - [A Few Different Types of Strings](#a-few-different-types-of-strings)
      - [Plain ol string](#plain-ol-string)
      - [Verbatim string](#verbatim-string)
      - [Raw string](#raw-string)
    - [String Interpolation](#string-interpolation)
    - [Empty Strings - Declaring Them and Checking for Them](#empty-strings---declaring-them-and-checking-for-them)
      - [Common methods:](#common-methods)
    - [Common Methods/Properties](#common-methodsproperties)
    - [Quick Mention of StringBuilder](#quick-mention-of-stringbuilder)
    - [Checking for Equality](#checking-for-equality)
      - [Basic Equality Checks](#basic-equality-checks)
      - [Case-Insensitive Comparisons](#case-insensitive-comparisons)
      - [Best Practices](#best-practices)
  - [Pattern Matching](#pattern-matching)
    - [`Constant` Patterns](#constant-patterns)
    - [`Relational` Patterns](#relational-patterns)
    - [`Null` Patterns](#null-patterns)
    - [`Type` Patterns](#type-patterns)
    - [`Logical` Patterns](#logical-patterns)
    - [`Property` Patterns](#property-patterns)
    - [`Positional` Patterns](#positional-patterns)
  - [Conversion in C#](#conversion-in-c)
    - [Implicit Conversion](#implicit-conversion)
    - [Explicit Conversion](#explicit-conversion)
    - [Conversion Methods](#conversion-methods)
      - [**Parse**](#parse)
      - [**TryParse**](#tryparse)
      - [**Convert**](#convert)
  - [Exception Handling in C#](#exception-handling-in-c)
    - [Try/Catch](#trycatch)
    - [Catching Multiple Types of Exceptions](#catching-multiple-types-of-exceptions)
    - [Throwing Your Own Exceptions](#throwing-your-own-exceptions)
    - [Creating Custom Exception Types](#creating-custom-exception-types)
    - [Exception Filtering](#exception-filtering)


## Variables in C#

### Declaring Variables

In C#, variables must be declared before they can be used. The basic syntax for declaring a variable is:

```csharp
dataType variableName;
```

Here are some examples of variable declarations:

```csharp
int age;
string name;
double salary;
bool isEmployed;
```

You can also declare multiple variables of the same type in a single line:

```csharp
int x, y, z;
```

### Initializing Variables

You can initialize a variable at the time of declaration:

```csharp
int age = 25;
string name = "John Doe";
double salary = 50000.50;
bool isEmployed = true;
```

C# also supports type inference using the `var` keyword. The compiler will infer the type based on the assigned value:

```csharp
var count = 10; // int
var message = "Hello, World!"; // string
var pi = 3.14159; // double
```

### Constants

Constants are variables whose values cannot be changed once they are assigned. They are declared using the `const` keyword:

```csharp
const int MaxScore = 100;
const string CompanyName = "Acme Corp";
```

### Value Types vs Reference Types

C# variables can be categorized into two main types:

- **Value types**: These include simple types like `int`, `float`, `bool`, and `struct`. They are always initialized with a default value — e.g., `int` will be initialized with 0, `bool` as `false`, etc.
- **Reference types**: These include `class`, `interface`, `delegate`, and arrays. These are typically nullable by default.

The main difference is how they are stored in memory and how they are passed to methods.

We'll dive deeper into different data types and how to work with them in C# in the types section.


Here's your content with proper markdown formatting, including the added details on array initialization:


## Built-in Types in C#

These types are built into C# as most of them have usefulness across a wide array of applications.

### 1. Object

The base type for all data types.  
Can hold any data type, including user-defined types.  
ALL types inherit from `object`. More on this later.

### 2. String/Char
- **String**: A sequence of characters.

```csharp
string myString = "Hello, World!";
```

- **Char**: A single character literal.

```csharp
char myChar = 'A';
```

### 3. Boolean

Represents `true` or `false` values.

```csharp
bool myBool = true;
```

### 4. Byte/Sbyte

- **Byte**: 8-bit unsigned integer.
- **Sbyte**: 8-bit signed integer.

```csharp
byte myByte = 255;
sbyte mySbyte = -128;
```

### 5. Int/Short/Long

- **Int**: 32-bit signed integer. Min value is `int.MinValue` and max value is `int.MaxValue`, which are `-2147483648` and `2147483647`, respectively.

```csharp
int myInt = 2147483647;
```

- **Short**: 16-bit signed integer. Min value is `short.MinValue` and max value is `short.MaxValue`, which are `-32768` and `32767`, respectively.

```csharp
short myShort = 32767;
```

- **Long**: 64-bit signed integer. Min value is `long.MinValue` and max value is `long.MaxValue`, which are `-9223372036854775808` and `9223372036854775807`, respectively.

```csharp
long myLong = 9223372036854775807;
```

### 6. Unsigned Int/Short/Long

- **Unsigned Int**: 32-bit unsigned integer. Min value is `uint.MinValue` and max value is `uint.MaxValue`, which are `0` and `4294967295`, respectively.
- **Unsigned Short**: 16-bit unsigned integer. Min value is `ushort.MinValue` and max value is `ushort.MaxValue`, which are `0` and `65535`, respectively.
- **Unsigned Long**: 64-bit unsigned integer. Min value is `ulong.MinValue` and max value is `ulong.MaxValue`, which are `0` and `18446744073709551615`, respectively.

```csharp
uint myUint = 4294967295;
ushort myUshort = 65535;
ulong myUlong = 18446744073709551615;
```

### 7. Float/Double/Decimal

- **Float**: 32-bit floating point number.
- **Double**: 64-bit floating point number.
- **Decimal**: 128-bit precise decimal value.

```csharp
float myFloat = 3.14f;
double myDouble = 3.141592653589793;
decimal myDecimal = 3.14159265358979323846264338327950288419716939937510582097494459m;
```

I tend to use `decimal` for most decimal representations for consistency.

### 8. DateTime

Used for representing dates and times. These are immutable values.

```csharp
DateTime myDateTime = DateTime.UtcNow;
```

`DateTime` has a bunch of important methods and properties:

- `DateTime.Now`: Gets the current date and time on the local machine.
- `DateTime.UtcNow`: Gets the current date and time in UTC.
- `DateTime.Day`: Gets the day of the month.
- `DateTime.Month`: Gets the month of the year.
- `DateTime.Year`: Gets the year.
- `DateTime.Hour`: Gets the hour of the day.
- `DateTime.Minute`: Gets the minute of the hour.
- `DateTime.Second`: Gets the second of the minute.
- `DateTime.Millisecond`: Gets the millisecond of the second.
- `DateTime.DayOfWeek`: Gets the day of the week.
- `DateTime.DayOfYear`: Gets the day of the year.
- `DateTime.TimeOfDay`: Gets the time of day.

- ``DateTime.AddDays()``: Adds specified days.
- ``DateTime.AddHours()``: Adds specified hours.
- ``DateTime.AddMinutes()``: Adds specified minutes.
- ``DateTime.AddSeconds()``: Adds specified seconds.
- ``DateTime.AddMilliseconds()``: Adds specified milliseconds.
- ``DateTime.Parse()``: Parses a date/time string to ``DateTime``.
- ``DateTime.TryParse()``: Attempts to parse a date/time string.
- ``DateTime.TryParseExact()``: Attempts to parse using a specific format.

### 9. Arrays

An array is a collection of items of the same type, stored in contiguous memory. Here’s how to declare and initialize arrays:

#### **Array Initialization**

```csharp
// Declare and initialize an array with size
int[] myIntArray = new int[3];
myIntArray[0] = 1;
myIntArray[1] = 2;
myIntArray[2] = 3;

// Declare and initialize an array with values
int[] myIntArray2 = { 1, 2, 3 };
int[] myIntArray3 = [1,2,3];

// Multi-dimensional array
int[,] myMultiDimArray = new int[2, 2] { {1, 2}, {3, 4} };

// Jagged array (array of arrays)
int[][] jaggedArray = new int[2][];
jaggedArray[0] = new int[] {1, 2};
jaggedArray[1] = new int[] {3, 4};
```

The `[]` syntax is called the "indexer" – it's a way to access elements in the array.

#### **Array Properties:**

- `myIntArray.Length`: Gets the number of elements in the array.
- `myIntArray.Rank`: Gets the number of dimensions in the array.


### 10. Enums

An enum is a set of named constants.

```csharp
enum EmployeeType
{
    Manager,
    Supervisor,
    Worker
}
```

Enums have an "underlying" type — the default is `int`. Each of these enum values has values automatically assigned to them, starting with 0. You can also manually define values:

```csharp
enum EmployeeType
{
    Manager = 1,
    Supervisor = 2,
    Worker = 10
}
```

### 11. Tuples

Tuples in C# are versatile, lightweight data structures that can group multiple values together, even if they are of different types. They are particularly useful when you want to return more than one value from a method or quickly bundle values without creating a custom class or struct.

#### **Creating Tuples**

```csharp
var myTuple = (42, "Hello", true);
Console.WriteLine(myTuple.Item1); // Output: 42
Console.WriteLine(myTuple.Item2); // Output: Hello
Console.WriteLine(myTuple.Item3); // Output: true
```

#### **Named Tuples**

You can assign meaningful names to the tuple elements, making your code more readable:

```csharp
var personInfo = (Age: 30, Name: "Alice", IsEmployed: true);
Console.WriteLine(personInfo.Age); // Output: 30
Console.WriteLine(personInfo.Name); // Output: Alice
Console.WriteLine(personInfo.IsEmployed); // Output: true
```

#### **Deconstructing Tuples**

You can deconstruct tuples into individual variables using the deconstruction syntax:

```csharp
var (age, name, isEmployed) = personInfo;
Console.WriteLine(age); // Output: 30
Console.WriteLine(name); // Output: Alice
Console.WriteLine(isEmployed); // Output: true
```

#### **Use Cases**

- Returning multiple values from a method:

```csharp
public (int, string) GetPerson()
{
    return (25, "Bob");
}

var (age, name) = GetPerson();
```

- Ad-hoc grouping of values: Tuples can be used to group temporary, related data without the need to define a separate class or struct.

### 12. Special Mention: `Null` and `Void`

- **Null**: A special marker for "no value." Doesn't have a type per se.

```csharp
string? s = null; 
```

`?` should be used for possible nullable types.


- **Void**: Represents no return value from a method.

```csharp
void MyMethod()
{
    Console.WriteLine("Hello, World!");
}
```

Fun fact: `void` is actually an alias for `System.Void` and is an actual type in C#, but not one you can use directly.

Here's the combined document covering control flow and pattern matching in C#:

---

## Control Flow in C#

Control flow statements allow you to control the execution of your code based on certain conditions or repeat a block of code multiple times. Below are the most common control flow statements and loops in C#.

### If Statements

```csharp
int age = 20;
if (age >= 18)
{
    Console.WriteLine("You are an adult.");
}
else if (age >= 13)
{
    Console.WriteLine("You are a teenager.");
}
else
{
    Console.WriteLine("You are a minor.");
}
```

### Switch Statements

The `switch` statement is used to execute different blocks of code based on the value of a variable.

```csharp
int day = 3;
switch (day)
{
    case 1:
        Console.WriteLine("Monday");
        break;
    case 2:
        Console.WriteLine("Tuesday");
        break;
    case 3:
        Console.WriteLine("Wednesday");
        break;
    case 4:
        Console.WriteLine("Thursday");
        break;
    case 5:
        Console.WriteLine("Friday");
        break;
    case 6:
        Console.WriteLine("Saturday");
        break; 
    case 7:
        Console.WriteLine("Sunday");
        break;
    default:
        Console.WriteLine("Invalid day.");
        break;
}
```

Switch Expressions : `switch` expressions provide a more concise way to write switch statements.

```csharp
int day = 3;
string dayName = day switch
{
    1 => "Monday",
    2 => "Tuesday",
    3 => "Wednesday",
    4 => "Thursday",
    5 => "Friday",
    6 => "Saturday",
    7 => "Sunday",
    _ => "Invalid day"
};
Console.WriteLine(dayName);
```

---

## Loops

### For Loop

The `for` loop is used to execute a block of code repeatedly for a specific number of times.

```csharp
for (int i = 0; i < 5; i++)
{
    Console.WriteLine(i);
}
```

The first part of the `for` is for variable declarations, the second part is the "check" to see if the loop should be executed, and the last statement is typically used to increment the variable declared in the first statement.


### Foreach Loop

The `foreach` loop is used to iterate over each element in a collection.

```csharp
foreach (var item in collection)
{
    // code block to be executed
}
```

## More on **String**

Strings are a sequence of characters, like so:

```csharp
string myString = "Hello, World!";
```

Strings have a few important properties:
- They are Unicode.
- They are immutable.
- They are reference types, but are treated like value types in use (e.g. when passed to a method, a copy is made).

---

### A Few Different Types of Strings

#### Plain ol string
```csharp
string myString = "Hello, World!";
```
This type of string is the most common. Some things you should know:

- Adding a double quote within a string requires the use of the escape character `\"`: 
  ```csharp
  string myString = "He said \"Hello\" to me.";
  ```
- Adding a backslash within a string requires the use of the escape character `\\`: 
  ```csharp
  string myString = "The path is C:\\Program Files\\MyApp";
  ```
- Adding a newline within a string requires the use of the escape character `\n`: 
  ```csharp
  string myString = "Hello\nWorld!";
  ```
- Adding a tab within a string requires the use of the escape character `\t`: 
  ```csharp
  string myString = "Hello\tWorld!";
  ```

#### Verbatim string
```csharp
string myString = @"Hello, World!";
```
This type of string is useful when you need to include special characters in a string without having to use the escape character.

- Adding two double quotes within a string will result in a single double quote within the string:
  ```csharp
  string myString = @"He said ""Hello"" to me.";
  ```
- Backslashes are not treated as escape characters, so you can use them freely within the string:
  ```csharp
  string myString = @"The path is C:\Program Files\MyApp";
  ```

#### Raw string
```csharp
string myString = """Hello, World!""";
```
This type of string is useful when you need to include special characters in a string without having to use the escape character. In newer versions of C# and probably my favorite type of string.

---

### String Interpolation
```csharp
string name = "Alice";
string greeting = $"Hello, {name}!";
```
This type of string is useful when you need to include variables within a string. My other favorite type of string!

You can combine string interpolation with verbatim strings:

```csharp
string name = "Alice";
string greeting = $@"Hello, I say to ""{name}!""";
```

---

### Empty Strings - Declaring Them and Checking for Them

#### Common methods:
- `String.Empty`: Represents an empty string. You can also declare an empty string like this `""` but Spencer recommends using `String.Empty` for consistency (also, he thinks double quotes everywhere looks ugly).
- `String.IsNullOrEmpty()`: Checks if a string is null or empty.
- `String.IsNullOrWhiteSpace()`: Checks if a string is null, empty, or consists only of white-space characters (like space or tab). (🌶️🌶️🌶️ This is Spencer's preferred method for checking if a string is empty.)

---

### Common Methods/Properties

- **Length**: Get the number of characters in a string.
  ```csharp
  string myString = "Hello";
  int length = myString.Length; // 5
  ```

- **String.Join()**: Concatenate elements of an array into a single string.
  ```csharp
  string[] words = { "Hello", "World" };
  string result = String.Join(" ", words); // "Hello World"
  ```

- **ToLower() / ToUpper()**: Convert strings to lowercase or uppercase.
  ```csharp
  string myString = "Hello";
  string lower = myString.ToLower(); // "hello"
  string upper = myString.ToUpper(); // "HELLO"
  ```

- **Contains()**: Check if a string contains a specified substring.
  ```csharp
  string myString = "Hello, World!";
  bool contains = myString.Contains("World"); // true
  ```

- **StartsWith() / EndsWith()**: Determine if a string starts or ends with a specific substring.
  ```csharp
  string myString = "Hello, World!";
  bool starts = myString.StartsWith("Hello"); // true
  bool ends = myString.EndsWith("World!"); // true
  ```

- **Trim() / TrimStart() / TrimEnd()**: Remove whitespace from the start, end, or both ends of a string.
  ```csharp
  string myString = "  Hello, World!  ";
  string trimmed = myString.Trim(); // "Hello, World!"
  string startTrim = myString.TrimStart(); // "Hello, World!  "
  string endTrim = myString.TrimEnd(); // "  Hello, World!"
  ```

- **Substring()**: Extract a substring from a string.
  ```csharp
  string myString = "Hello, World!";
  string substring = myString.Substring(7, 5); // "World"
  ```

- **IndexOf() / LastIndexOf()**: Find the position of a substring within a string.
  ```csharp
  string myString = "Hello, World!";
  int index = myString.IndexOf("World"); // 7
  int lastIndex = myString.LastIndexOf("o"); // 8
  ```

- **Replace()**: Replace occurrences of a substring with another substring.
  ```csharp
  string myString = "Hello, World!";
  string replaced = myString.Replace("World", "C#"); // "Hello, C#!"
  ```

- **Split()**: Split a string into an array of substrings based on a delimiter.
  ```csharp
  string myString = "Hello,World,From,C#";
  string[] split = myString.Split(','); // ["Hello", "World", "From", "C#"]
  ```
  
- **String.Join()**: Concatenate elements of an array into a single string with a separator.
  ```csharp
  string[] words = { "Hello", "World", "from", "C#" };
  string result = String.Join(" ", words); // "Hello World from C#"
  int[] numbers = { 1, 2, 3, 4, 5 };
  string result = String.Join("-", numbers); // "1-2-3-4-5"
  ```

### Quick Mention of StringBuilder
`StringBuilder` is a mutable string type that is meant to be used when you need to build a long string in a loop. It is more efficient than using the `+` operator to concatenate strings.

```csharp
StringBuilder sb = new StringBuilder();

for (int i = 0; i < 1000; i++)
{
    sb.Append(i);
}

Console.WriteLine(sb.ToString());
```
I use this class surprisingly often.

---

### Checking for Equality

Strings can be compared in various ways, depending on your specific needs:

#### Basic Equality Checks
- `==`: Checks if two strings are the same.
- `!=`: Checks if two strings are different.
- `Equals()`: Checks if two strings are the same.

#### Case-Insensitive Comparisons
To compare strings without considering case differences:

```csharp
string str1 = "Hello";
string str2 = "hello";
bool areEqual = string.Equals(str1, str2, StringComparison.OrdinalIgnoreCase);
```

#### Best Practices
- Use `StringComparison.Ordinal` or `StringComparison.OrdinalIgnoreCase` for most programmatic string comparisons.
- Avoid using `==` and `!=` for string comparisons, as it doesn't allow specifying the comparison method.

## Pattern Matching

Pattern matching is a feature in C# that allows you to check a value against a pattern and execute different code based on the result. It is a more flexible and powerful alternative to the `switch` statement.


### `Constant` Patterns

Constant patterns allow you to check if a value is equal to a specific constant.

```csharp
int number = 42;
if (number is 42)
{
    Console.WriteLine("The number is 42.");
}
else
{
    Console.WriteLine("The number is not 42.");
}
```

### `Relational` Patterns

Relational patterns allow you to check if a value is within a specific range.

```csharp
int number = 42;
if (number is >= 0 and <= 100)
{
    Console.WriteLine("The number is between 0 and 100.");
}
```


### `Null` Patterns
The null pattern is used to check whether a value is null.

```csharp
string? a = null;
if (a is null)
    Console.WriteLine("The value is null."); //✔
else
    Console.WriteLine("The value is not null.");

string b = "";
if (b is null)
    Console.WriteLine("The value is null.");//❌
else
{
    Console.WriteLine("The value is not null.");//✔
    if (b == string.Empty)
    {
        Console.WriteLine("is not null but Empty");//✔
    }
    if (string.IsNullOrEmpty(b))
    {
        Console.WriteLine("Null or Empty");//✔
    }
    if (string.IsNullOrWhiteSpace(b))
    {
        Console.WriteLine("Null, Empty or Whitespace Char");//✔
    }
}

string[] arr = [];
if (arr is null)
{
    Console.WriteLine("1.Array is empty"); //❌
}
else if (arr.Length == 0)
{
    Console.WriteLine("2.Array is empty");//✔
}
```

### `Type` Patterns

Type patterns allow you to check if a value is of a specific type.

```csharp
object value = "Hello, World!";
if (value is string str)
{
    Console.WriteLine($"The value is a string: {str}");
}
else
{
    Console.WriteLine("The value is not a string.");
}
```

### `Logical` Patterns

Logical patterns allow you to combine multiple patterns using logical operators.

```csharp
object value = "Hello, World!";
if (value is string str && str.Length > 5)
{
    Console.WriteLine("The string is longer than 5 characters.");
}
else
{
    Console.WriteLine("The string is not longer than 5 characters.");
}
```

### `Property` Patterns

Property patterns allow you to check if a value has a specific property.

```csharp
class Person
{
    public string Name { get; set; }
    public int Age { get; set; }
}

Person person = new Person { Name = "John", Age = 30 };
if (person is { Name: "John", Age: 30 })
{
    Console.WriteLine("The person is John and 30 years old.");
}
else
{
    Console.WriteLine("The person is not John and 30 years old.");
}
```

### `Positional` Patterns

Positional patterns allow you to check if a value matches a specific pattern based on its position in a tuple or array.

```csharp
(int, string, bool) tuple = (1, "Hello", true);
if (tuple is (1, string str, true))
{
    Console.WriteLine("The tuple matches the pattern.");
}
else
{
    Console.WriteLine("The tuple does not match the pattern.");
}
```

## Conversion in C#

### Implicit Conversion
Implicit conversions are automatically performed by the compiler when it is safe to do so.

```csharp
int a = 5;
double b = a; // Implicit conversion from int to double
```

**Note:** Implicit conversion is not supported for all types.

```csharp
int a = 5;
string b = a; // Compilation error
```

---

### Explicit Conversion

Explicit conversions, also known as casting, are performed by the programmer when required.

```csharp
int a = 5;
double b = (double)a; // Explicit conversion from int to double
```

---

### Conversion Methods

#### **Parse**
The `Parse` method converts a string to a specific type.  
It throws an exception if the string cannot be converted.

```csharp
int a = int.Parse("5"); // Converts "5" to 5
```

---

#### **TryParse**
The `TryParse` method attempts to convert a string to a specific type. It returns a boolean indicating whether the conversion was successful.

```csharp
int a;
bool success = int.TryParse("5", out a); // Converts "5" to 5 and returns true
```

**Shorter Syntax:**
```csharp
int.TryParse("5", out int a); // Converts "5" to 5 and returns true
```

---

#### **Convert**
The `Convert` class provides various methods for type conversion.  
It throws an exception if the conversion fails.

```csharp
int a = Convert.ToInt32("5"); // Converts "5" to 5
```

## Exception Handling in C#

Exception handling is a fundamental concept in C#, allowing developers to gracefully manage errors and maintain robust applications.

**Golden Rule of Exception Handling**: **Expect exceptions!**  
Understand how they influence control flow and affect application behavior. Most .NET methods document the exceptions they may throw.

---

### Try/Catch

- **Try Block**: Encapsulates code that may throw an exception.  
- **Catch Block**: Handles the exception.

```csharp
try
{
    // Code that may throw an exception
}
catch (Exception ex)
{
    // Code to handle the exception
    Console.WriteLine(ex.Message);
}
```

- **Finally Block**: Executes code after `try` and `catch`, regardless of whether an exception was thrown or not.

```csharp
try
{
    // Code that may throw an exception
}
catch (Exception ex)
{
    // Code to handle the exception
}
finally
{
    // Code that always executes
}
```

---

### Catching Multiple Types of Exceptions
You can handle different exception types in separate `catch` blocks.

```csharp
try
{
    // Code that may throw an exception
}
catch (IOException ex)
{
    // Handle IO exceptions
}
catch (ArgumentException ex)
{
    // Handle argument exceptions
}
```

### Throwing Your Own Exceptions
Raise custom exceptions using the `throw` keyword.

```csharp
public void DoSomething(string? input)
{
    if (string.IsNullOrWhiteSpace(input))
    {
        throw new ArgumentException("Input cannot be null or empty", nameof(input));
    }
}
```

---

### Creating Custom Exception Types
Define custom exceptions by inheriting from the `Exception` class.

```csharp
public class MyCustomException : Exception
{
    public MyCustomException(string message) : base(message)
    {
    }
}
```

### Exception Filtering
Filter exceptions based on specific conditions using the `when` keyword.

```csharp
try
{
    // Code that may throw an exception
}
catch (Exception ex) when (ex.Message.Contains("specific condition"))
{
    // Handle exceptions meeting the condition
}
```

example:


```csharp
public class CustomException : Exception{
    public int ErrorCode { get; set; }
    public CustomException(string message, int errorCode) : base(message){
        ErrorCode = errorCode;
    }
}


public class HandleException{
    public static void CustomErrorWithFiltering(){
        try        {
            // Simulate an error
            throw new CustomException("This is a critical error", 500);
        }
        catch (CustomException ex) when (ex.ErrorCode == 500){
            Console.WriteLine($"Critical error: `{ex.Message}`, code {ex.ErrorCode}");//✔
        }
        catch (CustomException ex)
        {
            Console.WriteLine($"Other error: {ex.Message}");//X
        }
    }
}
```

> **Best Practice:** Use custom exceptions sparingly. Most cases can be handled with built-in types like `InvalidOperationException` or `ArgumentException`. Reserve custom exceptions for specialized cases, such as in company-specific frameworks.