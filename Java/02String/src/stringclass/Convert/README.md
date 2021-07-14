# String Conversion

## String Primitive Conversions

### Conversion between String , int or Integer

#### String to int or Integer

- `Integer.valueOf()` -> returns `Integer` class
- `Integer.parseInt()` -> returns primitive `int`
- `Integer.decode()` -> only for decimal, hexadecimal and octal numbers.

```java
Integer.parseInt(String s)
Integer.parseInt(String s, int radix)

Integer.valueOf(String s)
Integer.valueOf(String s, int radix)
```

```java
  String s = "100";
  int n = Integer.parseInt(s);
  // int n1 = Integer.valueOf(s);//Redundant boxing inside 'Integer.valueOf(s)'
  Integer n1 = Integer.valueOf(s);
```

#### int or Integer to String

- `String.valueOf()`
- `Integer.toString()`

```java
 int v  = 1001;
 String s1 = String.valueOf(v);
 String s2= Integer.toString(v);

 Integer in = new Integer(2018);//'Integer(int)' is deprecated and marked for removal
 String s3 = String.valueOf(in);
 String s4 = in.toString();
```

### Converting String to CharArray

#### String to char[]

```java
String str = new String("Hello World");
char[] array = str.toCharArray();
```

#### char[] to String

```java
char[] ch = {'g', 'o', 'o', 'd', ' ', 'm', 'o', 'r', 'n', 'i', 'n', 'g'};
String s = new String(ch);
String s2 = String.valueOf(ch);
```

### Converting String to ByteArray

#### String to byte[]

```java
String s = "Hello";
byte[] bytes = s.getBytes();//"US-ASCII"/UTF-8
for (byte b : bytes) System.out.println("char: " + (char) b + ", byte: " + b);
// char: H, byte: 72
// char: e, byte: 101
// char: l, byte: 108
// char: l, byte: 108
// char: o, byte: 111

//https://docs.oracle.com/javase/8/docs/technotes/guides/intl/encoding.doc.html
try {
 byte[] bytes = s.getBytes("UTF-16");
 for (byte b : bytes) System.out.println("char: " + (char) b + ", byte: " + b);

} catch (UnsupportedEncodingException e) {
 e.printStackTrace();
}

// char: ￾, byte: -2
// char: ￿, byte: -1
// char:  , byte: 0
// char: H, byte: 72
// char:  , byte: 0
// char: e, byte: 101
// char:  , byte: 0
// ..........
```

### Converting String to Date or LocalDateTime
