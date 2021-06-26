# String

Strings in Java are Objects that are backed internally by a `char` array. Since arrays are `immutable`(cannot grow), **Strings are immutable** as well. Whenever a change to a String is made, an entirely new String is created. 

Since, Java String is `immutable` and `final`, so a new String is created whenever we do String manipulation. As String manipulations are resource consuming, Java provides two utility classes: `StringBuffer` and `StringBuilder`.
Let us understand the difference between these two utility classes:

- `StringBuffer` and `StringBuilder` are **mutable** classes.
- `StringBuffer` operations are **thread-safe and synchronized** whereas `StringBuilder` operations are **not thread-safe**.
- `StringBuffer` is to be used when **multiple threads** are working on same String and `StringBuilder` in the **single threade**d environment.
- `StringBuilder` performance is **faster** when compared to `StringBuffer` because of no overhead of synchronized.