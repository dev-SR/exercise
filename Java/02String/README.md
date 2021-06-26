# Working with String in Java

**Strings** in Java are Objects that are backed internally by a `char` array. Since arrays are `immutable`(cannot grow), **Strings are immutable** as well. Whenever a change to a String is made, an entirely new String is created

Since, Java **String** is `immutable` and `final`, so a new String is created whenever we do String manipulation. As String manipulations are resource consuming, Java provides two utility classes: `StringBuffer` and `StringBuilder`.
Let us understand the difference between these two utility classes:

**StringBuffer:**

`StringBuffer` is a peer class of String that provides much of the functionality of strings. The string represents fixed-length, immutable character sequences while StringBuffer represents growable and writable character sequences.

**StringBuilder:**

The `StringBuilder` in Java represents a mutable sequence of characters. Since the String Class in Java creates an immutable sequence of characters, the StringBuilder class provides an alternate to String Class, as it creates a mutable sequence of characters.

## String vs StringBuilder vs StringBuffer in Java

```java
public class Main {

    // Concatenates to String
    public static void concat1(String s1) {
        s1 = s1 + "World";
    }

    // Concatenates to StringBuilder
    public static void concat2(StringBuilder s2) {
        s2.append("World");
    }

    // Concatenates to StringBuffer
    public static void concat3(StringBuffer s3) {
        s3.append("World");
    }

    public static void main(String[] args) {
        String s1 = "Hello";
        // s1 is not changed
        concat1(s1);
        System.out.println("String: " + s1);//Hello

        StringBuilder s2 = new StringBuilder("Hello");
        // s2 is changed
        concat2(s2);
        System.out.println("StringBuilder: " + s2);//HelloWorld

        StringBuffer s3 = new StringBuffer("Hello");
        // s3 is changed
        concat3(s3);
        System.out.println("StringBuffer: " + s3);//HelloWorld
    }
}
```

> Explanation:

1. **Concat1:** In this method, we pass a string "Hello" and perform “s1 = s1 + "World". The string passed from main() is not changed, this is due to the fact that String is `immutable`. Altering the value of string creates another object and s1 in `concat1()` stores reference of the new string. _References s1 in `main()` and `cocat1()` refer to different strings_.

2. **Concat2:** In this method, we pass a string "Hello" and perform “s2.append("World")” which changes the actual value of the string (in main) to "HelloWorld". This is due to the simple fact that `StringBuilder` is `mutable` and hence changes its value.

3. **Concat3:** StringBuffer is similar to `StringBuilder` except for one difference that `StringBuffer` is `thread-safe`, i.e., multiple threads can use it without any issue. The thread-safety brings a penalty of performance

So, String vs StringBuilder vs StringBuffer:

- `StringBuffer` and `StringBuilder` are **mutable** classes.
- `StringBuffer` operations are **thread-safe and synchronized** whereas `StringBuilder` operations are **not thread-safe**.
- `StringBuffer` is to be used when **multiple threads** are working on same String and `StringBuilder` in the **single threade**d environment.
- `StringBuilder` performance is **faster** when compared to `StringBuffer` because of no overhead of synchronized.
  
## When to use which one

- If a string is going to remain `constant` throughout the program, then use the **`String`** class object because a **String** object is `immutable`.
- If a string can `change` _(for example: lots of logic and operations in the construction of the string)_ and will only be accessed from a `single thread`, using a **`StringBuilder`** is good enough.
- If a string can `change` and will be accessed from `multiple threads`, use a **`StringBuffer`** because **StringBuffer** is synchronous, so you have thread-safety.
- If you don’t want thread-safety than you can also go with `StringBuilder` class as it is not synchronized.

> Conclusion

- Objects of **String** are `immutable`, and objects of **StringBuffer and StringBuilder** are `mutable`.
- StringBuffer and StringBuilder are similar, but **StringBuilder is faster** *and preferred over StringBuffer* for the single-threaded program. **If thread safety is needed, then StringBuffer is used.**

## Conversion between types of strings in Java

> 1.From String to StringBuffer and StringBuilder:

```java
String str = "Hello";
// conversion from String object to StringBuffer
StringBuffer sbr = new StringBuffer(str);
// conversion from String object to StringBuilder
StringBuilder sbl = new StringBuilder(str);
```

> 2.From StringBuffer and StringBuilder to String:

This conversion can be performed using `toString()` method which is overridden in both StringBuffer and StringBuilder classes.

Note that while we use toString() method, a new String object(in Heap area) is allocated and initialized to the character sequence currently represented by the StringBuffer object, which means the subsequent changes to the StringBuffer object do not affect the contents of the String object.

```java
StringBuffer sbr = new StringBuffer("Hello");
StringBuilder sbdr = new StringBuilder("Hello");
 
// conversion from StringBuffer object to String
String str = sbr.toString();

// conversion from StringBuilder object to String
String str1 = sbdr.toString();
```

> 3.From StringBuffer to StringBuilder or vice-versa:

This conversion is tricky. There is no direct way to convert the same. In this case, We can use a String class object. We first convert the StringBuffer/StringBuilder object to String using toString() method and then from String to StringBuilder/StringBuffer using constructors.

```java
StringBuffer sbr = new StringBuffer("Hello");
 // conversion from StringBuffer
// object to StringBuilder
String str = sbr.toString();
StringBuilder sbl = new StringBuilder(str);
```
