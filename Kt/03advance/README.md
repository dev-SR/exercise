# Advance Kotlin

- [Advance Kotlin](#advance-kotlin)
	- [Standard Library - Scope functions](#standard-library---scope-functions)
		- [Kotlin `let`](#kotlin-let)
			- [Chaining `let` functions](#chaining-let-functions)
			- [Nesting let](#nesting-let)
			- [let for null checks](#let-for-null-checks)
		- [Kotlin `run`](#kotlin-run)

## Standard Library - Scope functions

The Kotlin standard library contains several functions whose sole purpose is to execute a block of code within the context of an object. When you call such a function on an object with a lambda expression provided, it forms a temporary scope. In this scope, you can access the object without its name. Such functions are called scope functions. There are five of them: `let`, `run`, `with`, `apply`, and `also`.

Here is a short guide for choosing scope functions depending on the intended purpose:

- Executing a lambda on an objects (non-null): `let`
- Introducing an expression as a variable in local scope: `let`
- Object configuration: `apply`
- Object configuration and computing the result: `run`
- Running statements where an expression is required: non-extension `run`
- Additional effects: `also`
- Grouping function calls on an object: `with`

### Kotlin `let`

`let` scope function is used to apply operations on an object and finally return the lambda expression from that scope function. The return type can also be void.

This clarifies a few things:

- The return type of the let function is nothing but the last expression we returned from our passed lambda parameter.
- Since its an extension function to the Template class, it can be called on any object.

An example demonstrating kotlin let function is given below.

```kotlin
	var str = "Hello World"
    str.let { println("$it!!") }//Hello World!!
```

```kotlin
class Employee {
    var firstName: String? = null
    var age: Int = 0
}

    val employee: Employee? = Employee()
    employee?.firstName = "Suneet"
    employee?.age = 27

    employee?.let {
        println(it.age)
    }
```

So basically, let function will be:

- called only during the owner function will be called.
- called ONLY ONCE.
- called on the calling object.
- and will return the expression returned by the lambda passed to the let function.

Please note that we can point to the calling object by using `it`.

we can even use a local parameter for the calling object to avoid conflicts in the nested let or lambda function.

```kotlin
employee?.let { person ->
    person.firstName?.let { name ->
        println(name)
    }
}
```

Here the `person` and `name` are the named variable within the let function scope.

If the let lambda contains only a single expression, we can even use method reference (`::`) instead of lambda

```kotlin
employee?.firstName?.let(::println)
```

**The last value from the let is returned as an argument as shown below.**

```kotlin
	var strLength = str.let {
        println("$it!!")//Hello World!!
        "$it function".length
    }
    println("strLength is $strLength") //prints strLength is 25
```

Things to keep in mind about let,
- `let` uses the context as it or we can use a named parameter.
- `let` return the last expression of the lambda passed which can also be void.

#### Chaining `let` functions

```kotlin
	var a = 1
    var b = 2

    a = a.let { it + 2 }.let {
        val i = it + b
        i//returns
    }
    println(a) //5
```

As you can see we’ve declared a local variable `“i”` inside the second let function. Setting the last statement of the let function to `i` returns the property to the outer property `a`.

Also, the `let` function can be used to invoke one or more functions on the result of the chain.

```kotlin
	var list = mutableListOf(6, 1, 5, 2, 4, 3)
    list.filter { it % 2 == 0 }.sortedBy { it }.let {
        println("Sorted even numbers are : $it")
    }
```

#### Nesting let

We can set a let expression inside another let expression as shown below.

```kotlin
	var x = "X"
    x.let { outer ->
        outer.let { inner ->
            print("Inner is $inner and outer is $outer")
            //Inner is X and outer is X
        }
    }
```

For nested let, we can’t use `it` keyword. We need to assign explicit names to `it` in both the let functions.
Only the**outermost let returns the value** as shown below.

```kotlin
var y = "Y"
    y = y.let { outer ->
        outer.let { inner ->
            println("Inner is $inner and outer is $outer")//Inner is Y and outer is Y
            "Kotlin Tutorials Inner let"
        }
        "Kotlin Tutorials Outer let"
    }
    println(y) //prints Kotlin Tutorials Outer let
```

#### let for null checks

Additionally, let is useful for checking Nullable properties as shown below.

```kotlin
	var name : String? = "Kotlin let null check"
    name?.let { println(it) } //prints Kotlin let null check
    name = null
    name?.let { println(it) }
```

### Kotlin `run`


