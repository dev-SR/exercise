# Dispose,IO,Stream,File APi

- [Dispose,IO,Stream,File APi](#disposeiostreamfile-api)
  - [Dispose Pattern](#dispose-pattern)
    - [IDisposable Interface](#idisposable-interface)
    - [`Using` Statement](#using-statement)
    - [Async Dispose](#async-dispose)
  - [Streams: “An Abstraction of a Sequence of Bytes”](#streams-an-abstraction-of-a-sequence-of-bytes)
    - [Common Streams](#common-streams)
    - [Basic Operations with Streams](#basic-operations-with-streams)
      - [Reading from Files](#reading-from-files)
      - [Writing to Files](#writing-to-files)
  - [File APIs](#file-apis)
    - [File Class](#file-class)
      - [File.Exists](#fileexists)
      - [File.ReadAllText vs File.ReadAllLines vs File.ReadAllBytes](#filereadalltext-vs-filereadalllines-vs-filereadallbytes)
      - [File.WriteAllText vs File.AppendAllText vs File.WriteAllLines](#filewritealltext-vs-fileappendalltext-vs-filewritealllines)
      - [File.Copy](#filecopy)
      - [File.Move](#filemove)
      - [File.Delete](#filedelete)
    - [FileInfo Class](#fileinfo-class)
      - [new FileInfo](#new-fileinfo)
      - [Common Properties](#common-properties)
      - [Common Methods](#common-methods)
    - [DirectoryInfo and Directory](#directoryinfo-and-directory)
      - [Directory.CreateDirectory](#directorycreatedirectory)
    - [Path Class](#path-class)
      - [Path.Combine](#pathcombine)
      - [Path.GetDirectoryName](#pathgetdirectoryname)
      - [Path.GetExtension](#pathgetextension)
      - [Path.GetRandomFileName](#pathgetrandomfilename)
      - [Path.GetTempFileName](#pathgettempfilename)


## Dispose Pattern

The `Dispose` method is used to release unmanaged resources that an object holds. Unmanaged resources include things like file handles, network connections, database connections, and memory from other systems (such as native OS calls). Properly releasing these resources is crucial for avoiding resource leaks and ensuring that your application runs efficiently.

Unmanaged Resources:
- **File Handles**: Resources used to read from or write to files.  
- **Network Connections**: Connections to network services or remote servers.  
- **Database Connections**: Connections to databases that need to be explicitly closed.  
- **Memory from Other Systems**: Memory allocated through native code or APIs that needs manual management.  

Many .NET objects (e.g., `Stream`, `FileStream`, `SqlConnection`) rely on unmanaged resources and implement the `IDisposable` interface to ensure they are properly cleaned up.

---

### IDisposable Interface

The `IDisposable` interface is designed for types that need to release unmanaged resources. It contains a single method, `Dispose`, which should be implemented to free these resources.

Most of the time, you'll be implementing `Dispose` to clean up unmanaged resources used by that class (if they are not already being cleaned up elsewhere).

**Example of IDisposable Interface**

The resource below uses a `SqlConnection` which relies on unmanaged resources. It's **EXTREMELY** important to call `Dispose` on the connection when you're done with it. For this example, since the `MyResource` class creates and manages the `SqlConnection`, it should also be responsible for disposing of it.

```csharp
public class MyResource : IDisposable
{
    private bool _disposed = false; // To detect redundant calls
    private SqlConnection _connection;

    // Implement IDisposable
    public void Dispose()
    {
        if (!_disposed)
        {
            _connection.Dispose();

            // Free your own state (unmanaged objects).
            _disposed = true;
        }
    }
}
```

---

### `Using` Statement

The `using` statement provides a convenient syntax that ensures the `Dispose` method is **called automatically**at the end of the block, even if an exception occurs.

For our example above, you would then use the `MyResource` class like this:

```csharp
using (var myResource = new MyResource())
{
    myResource.UseResource();
}
```

You can also use the `using` statement at the beginning of a variable declaration to ensure it's disposed of when the scope ends:

```csharp
using var myResource = new MyResource();
myResource.UseResource();

// Automatically disposed of when myResource goes out of scope
```

🌶️🌶️🌶️ The inline `using` statement looks great, but I vastly prefer to use my `using` statements within code blocks so that it's explicitly clear when the resource is expected to be disposed of.

---

### Async Dispose

With asynchronous programming, you can use `await using` to asynchronously dispose of objects that implement `IAsyncDisposable`. This is useful for I/O-bound resources that benefit from asynchronous disposal.

Example

```csharp
await using (var stream = new FileStream("file.txt", FileMode.Open))
{
    // Use the stream
}
```

🌶️🌶️🌶️ **Rule of thumb**: If your method is `async` and your resource is disposable, you should use `await using` - otherwise, using `using` is fine.


## Streams: “An Abstraction of a Sequence of Bytes”

According to Microsoft docs, a stream is an abstraction that represents a sequence of bytes. Streams are a fundamental concept in .NET for handling input and output operations. They allow you to read from and write to various data sources in a consistent manner.

We're not going to dive too deeply into streams right now - we're just going to go over the basic use cases.

### Common Streams

There are several common types of streams provided by .NET, each serving different purposes:

- **FileStream**: Used for reading and writing to files on disk.
- **MemoryStream**: Provides a stream for storing data in memory.
- **NetworkStream**: Allows reading and writing over network connections.

### Basic Operations with Streams

#### Reading from Files

Streams are commonly used to read from files. You can perform both synchronous and asynchronous read operations.

```csharp
using (var fileStream = new FileStream("file.txt", FileMode.Open))
{
    using (var reader = new StreamReader(fileStream))
    {
        string content = reader.ReadToEnd();
        Console.WriteLine(content);
    }
}
```

#### Writing to Files

```csharp
using (var fileStream = new FileStream("file.txt", FileMode.Create))
{
    using (var writer = new StreamWriter(fileStream))
    {
        writer.Write("Hello, World!");
    }
}
```

## File APIs

Streams are important and very useful to understand, but sometimes you just want to read a text file into memory, do some stuff, and then move on with your life. The File API provides common file methods for .NET developers.

### File Class

The **File** class provides static methods for working with files.

#### File.Exists

Checks if a file exists at the specified path.

#### File.ReadAllText vs File.ReadAllLines vs File.ReadAllBytes

- **ReadAllText**: Reads the contents of a file as a single string.
- **ReadAllLines**: Reads the contents of a file and returns an array of strings, each representing a line in the file.
- **ReadAllBytes**: Reads the contents of a file as a byte array.

```csharp
string content = File.ReadAllText("file.txt");
string[] lines = File.ReadAllLines("file.txt");
byte[] bytes = File.ReadAllBytes("file.txt");
```

#### File.WriteAllText vs File.AppendAllText vs File.WriteAllLines

- **WriteAllText**: Writes text to a file, overwriting the file if it already exists.
- **AppendAllText**: Appends text to a file, creating the file if it doesn't exist.
- **WriteAllLines**: Writes an array of strings to a file, each string being a line in the file.

```csharp
File.WriteAllText("file.txt", "Hello, World!");
File.AppendAllText("file.txt", "\nGoodbye, World!");
File.WriteAllLines("file.txt", new[] { "Hello", "World" });
```

#### File.Copy

Copies an existing file to a new file, optionally overwriting the destination file.

```csharp
File.Copy("source.txt", "destination.txt");
```

#### File.Move

Moves a file to a new location, optionally overwriting the destination file.

```csharp
File.Move("source.txt", "destination.txt");
```

#### File.Delete

Deletes a specified file.

```csharp
File.Delete("file.txt");
```

### FileInfo Class

The **FileInfo** class provides instance methods and properties for working with files.

#### new FileInfo

Creates a new **FileInfo** instance for a specified file path.

```csharp
var fileInfo = new FileInfo("file.txt");
```

#### Common Properties

- **Length**: Gets the size of the file in bytes.
- **CreationTime**: Gets or sets the creation date and time of the file.
- **LastAccessTime**: Gets or sets the date and time the file was last accessed.

```csharp
var fileInfo = new FileInfo("file.txt");
Console.WriteLine(fileInfo.Length);
Console.WriteLine(fileInfo.CreationTime);
Console.WriteLine(fileInfo.LastAccessTime);
```

#### Common Methods

- **Delete**: Deletes the file represented by the **FileInfo** instance.

```csharp
fileInfo.Delete();
```

### DirectoryInfo and Directory

The **DirectoryInfo** and **Directory** classes provide methods for working with directories.

#### Directory.CreateDirectory

Creates a directory and any subdirectories specified in the path. If the directory already exists, no action is taken, so it's safe to call this method multiple times.

```csharp
Directory.CreateDirectory("newDirectory");
```

### Path Class

The **Path** class provides static methods for manipulating path strings.

#### Path.Combine

Combines two or more strings into a path.

```csharp
string path = Path.Combine("directory", "file.txt");
// output: "directory\file.txt"
```

#### Path.GetDirectoryName

Gets the directory information for the specified path string.

```csharp
string directory = Path.GetDirectoryName("file.txt");
```

#### Path.GetExtension

Gets the extension of the specified path string.

```csharp
string extension = Path.GetExtension("file.txt");
```

#### Path.GetRandomFileName

Gets a random file name.

```csharp
string randomFileName = Path.GetRandomFileName();
```

#### Path.GetTempFileName

Gets the full path to a temporary file. This file is actually created inside of the user's temp directory. Useful for creating a temporary file and then deleting it after the program is done using it.

```csharp
string tempFileName = Path.GetTempFileName();
```