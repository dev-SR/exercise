# Coroutines

- [Coroutines](#coroutines)
	- [Create Project with Kotlin Coroutines](#create-project-with-kotlin-coroutines)
	- [Threads](#threads)
	- [Coroutines intro](#coroutines-intro)

## Create Project with Kotlin Coroutines

<div align="center">
<img src="img/ckp.jpg" alt="kcp.jpg" width="600px">
</div>

[dependencies](https://github.com/Kotlin/kotlinx.coroutines)

```gradle
implementation "org.jetbrains.kotlinx:kotlinx-coroutines-core:1.6.0"
```

## Threads

In `Java` — and accordingly in Kotlin on the JVM — you can **parallelize** your program
using threads. Each `java.lang.Thread`object represents one execution flow, which
sequentially performs the commands within the single thread. You can operate on
threads in various ways — create them, start, pause, join, etc. By creating several
threads, you can perform multiple tasks simultaneously.

Take a look at the example below:

```kotlin
fun main() {
    thread(start = true, name = "another thread") {
        (0..3).forEach {
            println("Message #$it from the ${Thread.currentThread().name}")
        }
    }
    (0..3).forEach {
        println("Message #$it from the ${Thread.currentThread().name}")
    }
}
```

In the above, you first create a thread named `"another thread"` using the function
`thread()` from the `kotlin.concurrent` package. You pass true for the start parameter,
so the thread will start executing commands immediately. A message with the thread
name and a number will be printed 11 times.

```
Message #0 from the another thread
Message #0 from the main
Message #1 from the another thread
Message #2 from the another thread
Message #1 from the main
Message #2 from the main
Message #3 from the another thread
Message #3 from the main
```

The exact ordering of the parallel println() results from the two threads is
indeterminate, and it depends on whatever is going on in your CPU at the time you run.
You can see that your main thread, along with "another thread," are executing at the
same time without waiting for each other to complete, which is expected and is the
desired behavior.

Everything seems fine with threads until you need to manipulate a large number of
them or pass data back and forth between them. Also, it's important to note that Java
threads are based on OS-level threads and, therefore, consume a significant amount of
system resources. You can't create thousands of threads as you'll likely end up with an
OutOfMemoryError thrown by the JVM

without thread:

<div align="center">
<img src="img/thread.jpg" alt="thread.jpg" width="600px">
</div>

with thread:

<div align="center">
<img src="img/thread-1.jpg" alt="thread-1.jpg" width="600px">
</div>

⚠️⚠️

<div align="center">
<img src="img/thread-2.jpg" alt="thread-2.jpg" width="600px">
</div>


## Coroutines intro

