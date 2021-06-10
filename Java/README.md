```
├──com
│  ├──company
│     ├──Main.java
│
├──test
│  ├──A.java
```

`Main.java`

```java
package com.company;
import test.A;
public class Main {
    public static void main(String[] args) {
	// write your code here
        A a =new A();
        a.run();
    }
}

```

`A.java`

```java
package test;
public class A {
    public void  run(){
        System.out.println("Hello World");
    }
}
```

compile:

```bash
javac -d . .\com\company\Main.java
```

run:

```bash
java .\com\company\Main.java
```
