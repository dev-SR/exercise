
// Console.WriteLine($"Main Thread ID: {Thread.CurrentThread.ManagedThreadId}");
// Task task1 = Task.Run(() =>
// {
//     Console.WriteLine($"Task 1 Thread Id: {Thread.CurrentThread.ManagedThreadId}");
// });
// Task task2 = Task.Run(() =>
// {
//     Console.WriteLine($"Task 2 Thread Id: {Thread.CurrentThread.ManagedThreadId}");
// });
// Task task3 = Task.Run(() =>
// {
//     for (int i = 0; i < 10; i++)
//     {
//         Console.WriteLine($"Task 3 Thread Id: {Thread.CurrentThread.ManagedThreadId} ({i})");
//         Thread.Sleep(100);
//     }
// });

// Task.WaitAll(task1, task2, task3);
// Console.WriteLine("Task 1, 2, and 3 have completed.");

// Task task5 = Task.Run(() =>
// {
//     Console.WriteLine($"Task 1 Thread Id: {Thread.CurrentThread.ManagedThreadId}");
// }).ContinueWith((preTask) =>
// {
//     Console.WriteLine($"Task 2 Continuation Thread Id: {Thread.CurrentThread.ManagedThreadId}");
// });

// task5.Wait();

// Task as void the return type 
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