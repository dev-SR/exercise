## Asynchronous Programming

- [Asynchronous Programming](#asynchronous-programming)
  - [Task Object](#task-object)
  - [Chaining multiple task](#chaining-multiple-task)
- [**async/await**](#asyncawait)


Asynchronous programming is crucial for maintaining the responsiveness and efficiency of applications, especially in environments where tasks may be time-consuming or involve waiting for external resources. By allowing your application to perform other work while waiting for long-running operations to complete, you can improve both user experience and system performance.

Imagine if you went to google.com in your browser and the whole app locked up while you downloaded the data and rendered it. I don't think you'd be using that browser for very long.

Async programming allows us to free up resources (threads, usually) while we wait for typically I/O bound operations (like reading byte streams or waiting for a database to return with data) to complete.

Benefits
- **Improved User Experience**: Asynchronous programming helps keep your application responsive by performing tasks in the background and avoiding freezing or blocking the user interface.
- **Efficient Resource Utilization**: It allows better utilization of system resources by not blocking threads while waiting for operations to complete. In web frameworks like ASP.NET, this can free up a thread to handle another request while the current one is waiting for a response and is a critical component for its ability to scale.


### Task Object

Tasks in C# allow us to perform asynchronous operations. Using Task objects, we can get more control over how we'd like our asynchronous operations to be executed.

```csharp

Console.WriteLine($"Main Thread ID: {Thread.CurrentThread.ManagedThreadId}");
Task task1 = Task.Run(() =>
{
    Console.WriteLine($"Task 1 Thread Id: {Thread.CurrentThread.ManagedThreadId}");
});
Task task2 = Task.Run(() =>
{
    Console.WriteLine($"Task 2 Thread Id: {Thread.CurrentThread.ManagedThreadId}");
});
Task task3 = Task.Run(() =>
{
    for (int i = 0; i < 5; i++)
    {
        Console.WriteLine($"Task 3 Thread Id: {Thread.CurrentThread.ManagedThreadId} ({i})");
        Thread.Sleep(100);
    }
});

Task.WaitAll(task1, task2, task3);
Console.WriteLine("Task 1, 2, and 3 have completed.");

/* 
Output:
Main Thread ID: 1
Task 1 Thread Id: 7
Task 2 Thread Id: 8
Task 3 Thread Id: 9 (0)
Task 3 Thread Id: 9 (1)
Task 3 Thread Id: 9 (2)
Task 3 Thread Id: 9 (3)
Task 3 Thread Id: 9 (4)
Task 1, 2, and 3 have completed.

 */
```

### Chaining multiple task

```csharp
Task task5 = Task.Run(() =>
{
    Console.WriteLine($"Task 1 Thread Id: {Thread.CurrentThread.ManagedThreadId}");
}).ContinueWith((preTask) =>
{
    Console.WriteLine($"Task 2 Continuation Thread Id: {Thread.CurrentThread.ManagedThreadId}");
});

task5.Wait();

/* 
Output:
Task 1 Thread Id: 6
Task 2 Continuation Thread Id: 9 
*/
```

## **async/await**

The `async` and `await` keywords in C# provide a simple way to write asynchronous code. They allow you to perform asynchronous operations without explicitly managing threads or using callbacks.

```csharp
async Task FirstAsyncMethod()
{
    Console.WriteLine("Before awaiting....");
    await Task.Delay(TimeSpan.FromSeconds(1));
    Console.WriteLine("After awaiting....");
}
async Task<int> SecondAsyncMethod()
{
    Console.WriteLine("Before awaiting....");
    await Task.Delay(TimeSpan.FromSeconds(1));
    Console.WriteLine("After awaiting....");
    return 1;
}

Console.WriteLine("awaiting FirstAsyncMethod...");
await FirstAsyncMethod();
Console.WriteLine("alternatively, awaitin'g FirstAsyncMethod...");
// alternatively...
Task firstAsyncMethodTask = FirstAsyncMethod();
await firstAsyncMethodTask;

async Task<string> ThirdAsyncMethod(TimeSpan timeWait, string message)
{
    await Task.Delay(timeWait);
    Console.WriteLine(message);
    return message;
}

Task<string> task1 = ThirdAsyncMethod(TimeSpan.FromSeconds(1), "Task 1 completed");
Task<string> task2 = ThirdAsyncMethod(TimeSpan.FromSeconds(2), "Task 2 completed");
Task<string> task3 = ThirdAsyncMethod(TimeSpan.FromSeconds(3), "Task 3 completed");

Console.WriteLine("waiting for 3 async methods....");
await Task.WhenAll(task1, task2, task3);
Console.WriteLine("All 3 async methods have completed.");
// Notice that overall it took 3 sec.  not 1+2+3 sec.
```

`Task` and `Task<T>`:
- `Task`: Represents an ongoing operation that does not return a value. It is used for methods that perform asynchronous operations but do not need to return a result.
- `Task<T>`: Represents an ongoing operation that returns a value of type `T`. It is used for methods that perform asynchronous operations and return a result.

More:
- [https://schneidenbach.github.io/intro-to-csharp-and-dotnet-from-beginner-to-professional/lessons/common-libraries-and-advanced-topics/asynchronous-programming](https://schneidenbach.github.io/intro-to-csharp-and-dotnet-from-beginner-to-professional/lessons/common-libraries-and-advanced-topics/asynchronous-programming)