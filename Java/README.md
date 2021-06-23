# Overview

- [Overview](#overview)
- [Compiling and Running Java Code](#compiling-and-running-java-code)
  - [Manual](#manual)
  - [IntelliJ IDEA](#intellij-idea)
  - [Vs Code's Project Manager for Java (microsoft)](#vs-codes-project-manager-for-java-microsoft)

# Compiling and Running Java Code

## Manual

**dir setup:**

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

## IntelliJ IDEA

**Basic dir setup:**

![intellij init](../img/java_vscode_6.jpg)

Run Configuration:

![run config](../img/java_vscode_7.jpg)

## Vs Code's Project Manager for Java (microsoft)

![Vs code](../img/java_vscode.jpg)

![Vs code pro name](../img/java_vscode_2.jpg)

generated files:

![vs code java pro](../img/java_vscode_3.jpg)

But not compatible with IntelliJ IDEA!!

![intellij problem](../img/java_vscode_4.jpg)

Making this setup compatible with IntelliJ IDEA by making a sub dir/package

![intellij solve](../img/java_vscode_5.jpg)
