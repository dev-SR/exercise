# Functional Interface In Java

- [Functional Interface In Java](#functional-interface-in-java)
  - [TypeScript Function Types](#typescript-function-types)
    - [UseCase - Callback Function](#usecase---callback-function)
  - [Java Implementation](#java-implementation)
    - [Single Abstract Method Interfaces (SAM Interfaces)](#single-abstract-method-interfaces-sam-interfaces)
    - [UseCase - Callback Function in Java](#usecase---callback-function-in-java)
  - [Ex: android sim](#ex-android-sim)
  - [ex: Communication Between ClassA & ClassB](#ex-communication-between-classa--classb)


## TypeScript Function Types

A function type has two parts: parameters and return type. When declaring a function type, you need to specify both parts with the following syntax:

```bash
(parameter: type, parameter:type,...) => type
```

The following example shows how to declare a variable which has a function type that accepts two numbers and returns a number:

```typescript
let add: (x: number, y: number) => number;

add = function (x: number, y: number) {
    return x + y;
};
```

### UseCase - Callback Function

```typescript
function isEven(num: number) {
 return num % 2 == 0;
}
function MyFilter(ar: number[]): number[] {
 let newArr: number[] = [];
 for (let i = 0; i < ar.length; i++) {
  const currentEl = ar[i];
  if (isEven(currentEl)) {
   newArr.push(currentEl);
  }
 }
 return newArr;
}

console.log(MyFilter([1, 2, 3, 4, 5]));

// Built-in
console.log( [1, 2, 3, 4, 5].filter( isEven ) );
// function is like variable
const isOdd = function (num) {
 return num % 2 != 0;
};
console.log([1, 2, 3, 4, 5].filter(isOdd));
// Arrow Function
console.log([1, 2, 3, 4, 5].filter((n) => n % 2 == 0));



// Function Type
function MyFilter(ar: number[], fn: (n: number) => boolean): number[] {
 let newArr: number[] = [];
 for (let i = 0; i < ar.length; i++) {
  const currentEl = ar[i];
  if (fn(currentEl)) {
   newArr.push(currentEl);
  }
 }
 return newArr;
}
console.log(MyFilter([1, 2, 3, 4, 5], isEven));
console.log( MyFilter( [1, 2, 3, 4, 5], isOdd ) );


// using interface
interface FunctionType {
 fn(n: number): boolean;
}
function MyFilter(ar: number[], { fn }: FunctionType): number[] {
 let newArr: number[] = [];
 for (let i = 0; i < ar.length; i++) {
  const currentEl = ar[i];
  if (fn(currentEl)) {
   newArr.push(currentEl);
  }
 }
 return newArr;
}
console.log(MyFilter([1, 2, 3, 4, 5], { fn: isEven }));
console.log(MyFilter([1, 2, 3, 4, 5], { fn: isOdd }));

// Arrow Function
// function isEven(num: number) {
//  return num % 2 == 0;
// }
// console.log( [1, 2, 3, 4, 5].filter(isEven));
console.log([1, 2, 3, 4, 5].filter(isEven));

```

## Java Implementation

### Single Abstract Method Interfaces (SAM Interfaces)

A functional interface is an interface that contains only one abstract method. They can have only one functionality to exhibit. From Java 8 onwards, `lambda` expressions can be used to represent the instance of a functional interface. We can also call Lambda expressions as the instance of functional interface. `Runnable`, `ActionListener`, `Comparable` are some of the examples of functional interfaces.

Functional Interface is additionally recognized as `Single Abstract Method Interfaces`. In short, they are also known as `SAM` interfaces.

Functional interfaces are included in Java SE 8 with Lambda expressions and Method references in order to make code more readable, clean, and straightforward.Functional interfaces are used and executed by representing the interface with an annotation called `@FunctionalInterface`.


Before Java 8, we had to create **anonymous inner class objects** or **implement these interfaces**.

```java
// @FunctionalInterface
// public interface Runnable {
//     public abstract void run();
// }

class Test {
 public static void main(String args[])
 {
  // create anonymous inner class object
  new Thread(new Runnable() {
   @Override public void run()
   {
    System.out.println("New thread created");
   }
  }).start();
 }
}
```

Java 8 onwards, we can assign lambda expression to its functional interface object like this:

```java
// Java program to demonstrate Implementation of
// functional interface using lambda expressions
class Test {
 public static void main(String args[])
 {
  // lambda expression to create the object
  new Thread(() -> {
   System.out.println("New thread created");
  }).start();
 }
}
```

### UseCase - Callback Function in Java

```java
import java.util.ArrayList;

interface FunctionType {
    boolean fn(int n);
}

public class Array {
    static String filter(int arr[], FunctionType callbackFunction) {
        ArrayList<Integer> list = new ArrayList();
        for (int j : arr) {
            if (callbackFunction.fn(j)) {
                list.add(j);
            }
        }
        return list.toString();
    }
}
```



```java
class ArrayTest {

    @Test
    @DisplayName("Callback using Arrow Function")
    void t1() {
        //JS/TS..................
        //console.log(MyFilter([1, 2, 3, 4, 5], (n) => n % 2 == 0));
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, (n) -> n % 2 == 0));
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, (n) -> n % 2 != 0));
    }

    @Test
    @DisplayName("Callback using Anonymous Interface implementation")
    void t2() {
        /*
         * JS/TS..................
         *
         * const isOdd = function (num) {
         *  return num % 2 != 0;
         * };
         * console.log(MyFilter([1, 2, 3, 4, 5], isOdd));
         * */

        FunctionType isEven = new FunctionType() {
            @Override
            public boolean fn(int n) {
                return n % 2 == 0;
            }
        };
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, isEven));

        //Using Lambda Function
        FunctionType isEven2 = n -> n % 2 == 0;
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, isEven2));
    }

    @Test
    @DisplayName("Callback using Class Interface implementation")
    void t3() {

        class isODD implements FunctionType {
            @Override
            public boolean fn(int n) {
                return n % 2 != 0;
            }
        }
        FunctionType isOdd = new isODD();
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, isOdd));
    }
}
```

## Ex: android sim

```typescript
// Part of Android SDK
class View {
 id: string;
 constructor(id: string) {
  this.id = id;
 }
 getId() {
  return this.id;
 }
}
function findViewById(s: string) {
 return new Button(s);
}

interface OnClickListener {
 (v: View): void;
}

class Button {
 v: View;
 callback: OnClickListener;
 constructor(view_id) {
  this.v = new View(view_id);
 }
 setOnClickListener(cb: OnClickListener) {
  this.callback = cb;
 }

 //called by the framework
 runtime() {
  console.log('App is running');
  setTimeout(() => {
   this.callback(this.v);
  }, 2000);
 }
}

// User Implementation
const b: Button = findViewById('button');
function myClickHandlerCallBack(v: View) {
 if (v.getId() == 'button') {
  console.log('Button clicked');
 }
}
b.setOnClickListener(myClickHandlerCallBack);

// While the App is running, the button will be clicked by the user,
// and the callback will be called By the Android runtime.
b.runtime();
```

## ex: Communication Between ClassA & ClassB

In Android, We communicate between the `Activity`and  `Fragment` using `Interface` method.

For Example:

- Calling Method of `Activity` from `Fragment`

Let's say `ClassA` class have a method called `methodOfClassA` of type `ClassAMethodType` .

```java
interface ClassAMethodType {
        void methodOfClassA();
}
```

 Now, we want to call this method from `ClassB` class using `callMethodOfClassA`.

```java

public class ClassB {
    ClassAMethodType cb;

    public ClassB() {
        System.out.println("ClassB");
    }

    public void callMethodOfClassA() {
        cb.methodOfClassA();
    }
}
```

During the runtime, the `ClassB` will call the method of `ClassA`.

```java
public class ClassA {
    public ClassA() {
        System.out.println("ClassA constructor");
    }
}
```

```java
class RunTime {
    void onRunTime() {
        ClassA a = new ClassA();
        ClassB b = new ClassB();
        b.callMethodOfClassA();
    }
}

new RunTime().onRunTime();
```

But When calling `callMethodOfClassA()` of ClassB, we get the following error:

`java.lang.NullPointerException: Cannot invoke "ClassAMethodType.methodOfClassA()" because "this.cb" is null`

Because, we can't say that `ClassA` has a method called `methodOfClassA()`

Therefore we have to make sure `ClassA` has a method called `methodOfClassA()`. We can do this by validating that  `ClassA` has implemented `ClassAMethodType` interface.

```java
public class ClassB {

    ClassAMethodType cb;

    public ClassB() {
        System.out.println("ClassB");
    }

    public ClassB CheckParentHasMethod(ClassA parent) {
        try {
            cb = (ClassAMethodType) parent; // ClassA has implemented ClassAMethodType
        } catch (ClassCastException e) {
            throw new RuntimeException("ClassA does not have method");
        }
        return this;
    }

    public void callMethodOfClassA() {
        if (cb != null) {
            cb.methodOfClassA();
        }
    }
}
```

```java
class RunTime {
    void onRunTime() {
        ClassA a = new ClassA();
        ClassB v = new ClassB().checkClassAHasMethod(a);
        b.callMehtodOfClassA();
    }
}

new RunTime().onRunTime();
```

Now we get a customized error if `ClassA` don't implement `ClassAMethodType` interface

`java.lang.RuntimeException: ClassA does not have method`

So,  if we implement `ClassAMethodType` in `ClassA` everything will work accordingly:

```java
public class ClassA implements ClassAMethodType {
    public ClassA() {
        System.out.println("ClassA constructor");
    }

    @Override
    public void methodOfClassA() {
        System.out.println("This is a parent method");
    }
}
```

```java
class RunTime {
    void onRunTime() {
        ClassA a = new ClassA();
        ClassB b = new ClassB().checkClassAHasMethod(parent);
        b.callMehtodOfClassA();//This is a parent method
    }
}

new RunTime().onRunTime();
```