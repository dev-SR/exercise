# String CLass

## String Literal Vs String Object

Q) What is the difference between the following two
Statements?

```java
String str = "abc";
Srting str = new String("abc");
```

							
### 1. Direct Initialization

```java
String str = "abc";
```

- String object will be created in `String Constant
Pool Area` with the data `abc`.
  
- First JVM will check whether any String object is
existed or not in **String Constant Pool Area** with the
data `abc`.
  
- If any String Object is existed with the data `abc`
in String Constant Pool Area, JVM will return that
existed String Object reference with out creating new
String Object. It is called as `String Intern`.
  
- If no String object is existed already with the data
abc' in String Constant Pool Area, then JVM will create
new String Object with the data 'abc'.
  
_Note: In Initial Versions of JAVA, String Constant Pool
area is a block of memory in `Method Area`, if any Object
is created in String Constant Pool area then that Object
is not eligible for Garbage Collection. When Program
Execution is completed or When JVM is in Shutdown then
only String Constant Pool Area data will be removed. In
later Versions of Java String Constant Pool Area is
hoved to `Heap Memory`._

**String pool** in Java is a pool of String literals and interned Strings in JVM for efficient use of String object. Since String is
Immutable Class In Java , it makes sense to cache and shares them in JVM. Java creators introduced this String pool construct as an optimization on the way String objects are allocated and stored. It is a simple implementation of the Flyweight pattern, which in essence, says this: when a lot of data is common among several objects, it is better to just share the same instance of that data than creating several different “copies” of it.


### 1. Direct Initialization

```java
Srting str = new String("abc");
```

- As per 'new' keyword, JVM will create new String
object in Heap Memory irrespective of the String object
existed with the same data.
  
- If String objects are created in Heap Memory then
that String objects are eligible for Garbage Collection.
  
- In the above context, str is able to refer heap
memory String object only.


![literral vs object string](../img/string-1.jpg)




