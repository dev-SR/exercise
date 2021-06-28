# Overview

- [Overview](#overview)
- [Compiling and Running Java Code](#compiling-and-running-java-code)
  - [Manual](#manual)
  - [Vs Code's Project Manager for Java (microsoft)](#vs-codes-project-manager-for-java-microsoft)
  - [IntelliJ IDEA](#intellij-idea)
    - [Basic dir setup with template checked:](#basic-dir-setup-with-template-checked)
    - [Basic dir setup with template un-checked:](#basic-dir-setup-with-template-un-checked)

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

## Vs Code's Project Manager for Java (microsoft)

![Vs code](../img/java_vscode.jpg)

![Vs code pro name](../img/java_vscode_2.jpg)

generated files:

![vs code java pro](../img/java_vscode_3.jpg)

But not compatible with IntelliJ IDEA!!

![intellij problem](../img/java_vscode_4.jpg)

Making this setup compatible with IntelliJ IDEA by making a sub dir/package

![intellij solve](../img/java_vscode_5.jpg)

## IntelliJ IDEA

### Basic dir setup with template checked:

init:

![temp checked](../img/template-Checked.jpg)


![intellij init](../img/java_vscode_6.jpg)

Run Configuration:

![run config](../img/java_vscode_7.jpg)

### Basic dir setup with template un-checked:

init:

![temp un-checked](../img/template-unChecked.jpg)


![intellij init un](../img/java-pro-2.jpg)

Run Configuration:

![run config-2](../img/java-pro-2-1.jpg)
