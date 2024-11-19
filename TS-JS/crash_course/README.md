# Javascript/TypeScript

- [Javascript/TypeScript](#javascripttypescript)
  - [Function](#function)
    - [Function Declaration](#function-declaration)
    - [Function Parameters](#function-parameters)
      - [Function with Default Parameter](#function-with-default-parameter)
      - [Function with Rest Parameters](#function-with-rest-parameters)
    - [Arrow Function](#arrow-function)
    - [Higher-Order Function](#higher-order-function)
  - [Array and Object](#array-and-object)
    - [Object Basic](#object-basic)
      - [Creating Objects](#creating-objects)
        - [Object Literal](#object-literal)
      - [Accessing Object Properties](#accessing-object-properties)
      - [Iterating](#iterating)
    - [Array Basic](#array-basic)
      - [Array Creation](#array-creation)
      - [Array iteration](#array-iteration)
      - [Stack and Queue](#stack-and-queue)
        - [LIFO (Stack):](#lifo-stack)
        - [FIFO (Queue)](#fifo-queue)
    - [Object Methods - `values`, `keys`, `entries` and `fromEntries`](#object-methods---values-keys-entries-and-fromentries)
    - [Array Methods](#array-methods)
      - [Search](#search)
        - [`find()`](#find)
        - [`filter()`](#filter)
        - [`includes()`](#includes)
        - [`indexOf()`](#indexof)
        - [`lastIndexOf()`](#lastindexof)
        - [`findIndex()`](#findindex)
        - [`some()`](#some)
        - [`every()`](#every)
      - [Iterating and transforming - map,reduce](#iterating-and-transforming---mapreduce)
        - [`map()`](#map)
        - [`reduce()`](#reduce)
      - [Extraction \& SubSetting with `slice` and `splice`](#extraction--subsetting-with-slice-and-splice)
    - [Array and Object Destructuring](#array-and-object-destructuring)
    - [Rest / Spread for Objects](#rest--spread-for-objects)

## Function

### Function Declaration

```typescript
// Basic Function Declaration
function functionDeclaration() {
	console.log("function declaration !");
}
//  Function Expression
const SaySomething = function() {
	console.log("Something");
};

// Arrow Function 
const sayHello = () => {
	console.log("Hello!");
};

functionDeclaration(); // function declaration !
SaySomething(); // Something
sayHello(); // Hello!
```

### Function Parameters

#### Function with Default Parameter


```typescript
function sayHello2(name = "Guest") {
	console.log(`Hello, ${name}!`);
}
sayHello2(); // Hello, Guest!
sayHello2("Clifford"); // Hello, Clifford!
```

#### Function with Rest Parameters

```typescript
function sumNumbers(...numbers: number[]) {
	let sum = 0;
	for(let num of numbers) {
		sum += num;
	}
	console.log(sum);
}

sumNumbers(1,2,3,4); // 10
```


### Arrow Function

```typescript
// TYPE 1 Curly Braces and Parens
const fn1 = ( arg1: number, arg2: number ) => {
    const res = arg1 + arg2;
    return `Sum is ${res}`;
}
// TYPE 2: No curly braces - auto return
const fn2 = ( arg1: number, arg2: number ) => `Sum is ${arg1 + arg2}`

// Type 3: no parens - only valid with exactly 1 argument
const fn3 = ( arg1: any ) => `Only 1 arg here ${arg1}`
```

### Higher-Order Function

A **higher-order function** is a function that can **take another function as an argument** or **return a function as a result**, enabling abstraction and code reuse.

```typescript
type Operation = (x: number, y: number) => number;

function applyOperation(a: number, b: number, operation: Operation): number {
  return operation(a, b);
}

let result = applyOperation(5, 2, (a, b) => a * b);
console.log(result); // Output: 10

result = applyOperation(5, 2, (a, b) => a + b);
console.log(result); // Output: 7
```

In this example, `applyOperation` takes a function (`operation`) as an argument to perform a custom operation (e.g., multiplication or addition) on `a` and `b`. It demonstrates how higher-order functions enhance flexibility and reduce redundancy.

## Array and Object

### Object Basic

#### Creating Objects

##### Object Literal

```typescript
const vehicles = {
    car: "🚗",
    taxi: "🚕",
    bus: "🚌",
    minibus: "🚐"
};

// Object Property
const quantity = 324,price = 45.50;
// Longhand
const product = {
    quantity: quantity,
    price: price
}
// Shorthand
const product = {quantity,price}
```

#### Accessing Object Properties

```typescript
// 1. Accessing object properties using the dot notation
console.log(vehicles.car)
// 2. Accessing object properties using the bracket notation
console.log(vehicles['car'])
```

#### Iterating

```typescript
// Looping Through an Object
for(let key in vehicles) {
    console.log(`${key}:${vehicles[key]}`)
}

/* 
car:🚗
taxi:🚕
bus:🚌
minibus:🚐
*/
```

### Array Basic

#### Array Creation

```typescript
const animals = ['🐑','🐈','🐄','🐪','🐅'];
const genArray1 = new Array(5).fill(0); // [0, 0, 0, 0, 0]
const genArray2 = [...Array(5).keys()]; // [0, 1, 2, 3, 4]
const genArray3 = Array.from({length: 5},(_,i) => i); //[0,1,2,3,4]
const genArray4 = Array.from({length: 5},(_,i) => i + 1); //[1,2,3,4,5]
```


#### Array iteration

```typescript
// Longhand
for(let i = 0; i < animals.length; i++) {
    console.log(animals[i]);
}
// Shorthand
for(let animal of animals) {
    console.log(animal);
}
// Getting the index
for(let index in animals) {
    console.log(`${index}:${animals[index]}`);
}
animals.forEach((value,index) => {
    console.log(`${index}:${value}`);
})
```

#### Stack and Queue

Arrays can be used as stacks and queues: Arrays can be used as both stacks (last-in, first-out) and queues (first-in, first-out) by using the `push()`,` pop()`, `shift()`, and `unshift()` methods.

| Method      | Description                             |
| ----------- | --------------------------------------- |
| `push()`    | Adds to the end, returns new length.    |
| `unshift()` | Adds to the start, returns new length.  |
| `pop()`     | Removes last, returns removed element.  |
| `shift()`   | Removes first, returns removed element. |


##### LIFO (Stack):

```typescript
// LIFO (Stack) example

// Create a new stack (empty array)
const  stack = [];

// Add elements to the top of the stack using push()
stack.push("apple");
stack.push("banana");
stack.push("cherry");

// Remove the top element of the stack using pop()
let lastItem = stack.pop();
console.log(lastItem); // output : "cherry"
console.log(stack); // output: ["apple", "banana"]
```

In this example, the `push()` method is used to add elements to the top of the stack, and the `pop()` method is used to remove the top element of the stack (i.e., the last item that was added).

##### FIFO (Queue)

```typescript
// FIFO (Queue) example

// Create a new queue (empty array)
const queue = [];

// Add elements to the end of the queue using push()
queue.push("apple");
queue.push("banana");
queue.push("cherry");

// Remove the first element of the queue using shift()
let firstItem = queue.shift();
console.log(firstItem); // output: "apple"
console.log(queue); // output: ["banana", "cherry"]
```

In this example, the `push()` method is used to add elements to the end of the queue, and the `shift()` method is used to **remove the first element of the queue** (i.e., the item that was added first).

### Object Methods - `values`, `keys`, `entries` and `fromEntries`

```typescript
const vehicles = {
    car: "🚗",
    taxi: "🚕",
    bus: "🚌",
    minibus: "🚐"
};

Object.keys(vehicles)//[ "car", "taxi", "bus", "minibus" ]
Object.values(vehicles)//[ "🚗", "🚕", "🚌", "🚐" ]
Object.entries(vehicles)
/* 
[
  [ "car", "🚗" ],
  [ "taxi", "🚕" ],
  [ "bus", "🚌" ],
  [ "minibus", "🚐" ]
]
*/
Object.fromEntries([
    ["car","🚗"],
    ["taxi","🚕"],
    ["bus","🚌"],
    ["minibus","🚐"]
])
/* 
{
    car: "🚗",
    taxi: "🚕",
    bus: "🚌",
    minibus: "🚐"
}
*/
```

### Array Methods

#### Search 

Here are some **search-related array methods** in JavaScript/TypeScript with examples:

##### `find()`
Returns the first element that matches a condition or `undefined` if none matches.

```typescript
const arr = [1, 2, 3, 4];
const found = arr.find((x) => x > 2);
console.log(found); // Output: 3
```

##### `filter()`
Returns a new array with elements that match a condition.

```typescript
const arr = [1, 2, 3, 4];
const filtered = arr.filter((x) => x > 2);
console.log(filtered); // Output: [3, 4]
```

##### `includes()`
Checks if an element exists in the array, returning `true` or `false`.

```typescript
const arr = [1, 2, 3, 4];
console.log(arr.includes(3)); // Output: true
console.log(arr.includes(5)); // Output: false
```

#####  `indexOf()` 
Finds the first occurrence of an element and returns its index, or `-1` if not found.

```typescript
const arr = [1, 2, 3, 4, 2];
console.log(arr.indexOf(2)); // Output: 1
console.log(arr.indexOf(5)); // Output: -1
```

##### `lastIndexOf()`
Finds the last occurrence of an element and returns its index, or `-1` if not found.

```typescript
const arr = [1, 2, 3, 4, 2];
console.log(arr.lastIndexOf(2)); // Output: 4
console.log(arr.lastIndexOf(5)); // Output: -1
```

##### `findIndex()`
Returns the index of the first element that matches a condition, or `-1` if none matches.

```typescript
const arr = [1, 2, 3, 4];
const index = arr.findIndex((x) => x > 2);
console.log(index); // Output: 2
```

##### `some()`
Checks if at least one element matches a condition, returning `true` or `false`.

```typescript
const arr = [1, 2, 3, 4];
console.log(arr.some((x) => x > 3)); // Output: true
console.log(arr.some((x) => x > 5)); // Output: false
```

##### `every()`
Checks if all elements match a condition, returning `true` or `false`.

```typescript
const arr = [1, 2, 3, 4];
console.log(arr.every((x) => x > 0)); // Output: true
console.log(arr.every((x) => x > 2)); // Output: false
```



These methods allow flexible searching and processing of arrays based on specific conditions.

#### Iterating and transforming - map,reduce

<p align="center">
<img src="img/arr_methods.png" alt="arr_methods.png" width="600px"/>
</p>

##### `map()`

```typescript
// INPUT:
let animalObj = [
    {id: 1,emoji: '🐔',name: 'Chicken'},
    {id: 2,emoji: '🦇',name: 'Bat'},
    {id: 3,emoji: '🦉',name: 'Owl'},
    {id: 4,emoji: '🦄',name: 'Unicorn'},
    {id: 5,emoji: '🐺',name: 'Wolf'}
];
let emojis = animalObj.map(animal => animal.emoji);
console.log(emojis) //OUTPUT: [ "🐔", "🦇", "🦉", "🦄", "🐺" ]
```

##### `reduce()`

<p align="center">
<img src="img/reduce.png" alt="reduce.png" width="600px"/>
</p>

- `reduce` loops over an array and let's you "collect" the elements into something else (by running a function)
- That "something else" is specified by you as the second argument
- This way, you can "collapse" (reduce) the array into a new array, an object, number, etc.

- During each loop of reduce, you can get **result of the last loop - Accumulator**, and **the Current element & Current index**
- Change the result, then return it for the next loop iteration
- When you're done, you have the completed collection


When reduce calls your reducer function, it passes the following four parameters in:

- **Accumulator** - result of the last loop
- **Current element** 
- **Current index**
- **Source array**

Case study: the `sum` function
We're all familiar with the sum function. Let's take a look at a simple implementation:

```typescript
function sum(numbers) {
    let accumulationSoFar = 0;

    for(const number of numbers) {
        accumulationSoFar += number;
    }
    return accumulationSoFar;
}
```

The body of the `for` loop is describing how to **combine the current element (number) with the current accumulator to produce the next accumulator for the next iteration**. This should sound familiar! With reduce, this is the job of the reducer function:


```typescript
function sumReduced(numbers,reducerCallback,initial = 0) {
    let accumulator = initial;

    for(const number of numbers) {
        accumulator = reducerCallback(accumulator,number);
                    //reducer gets current el and current accumulator and returns next accumulator
    }

    return accumulator;
}

function reducer1(accumulator,currentElement) {
    return accumulator + currentElement;
}
function reducer2(accumulator,currentElement) {
    return accumulator * currentElement;
}
console.log(sumReduced([1,2,3],reducer1))//6
console.log(sumReduced([1,2,3],reducer2,1))//6
```

Last but not least, with native reduce we don't need to pass in the array because we're calling reduce on the array. For illustrative purposes it looks something like the following:

```typescript
Array.prototype.reduce = function(reducer, initialValue) {
  let accumulator = initialValue;

  for (let i = 0; i < this.length; ++i) {
    accumulator = reducer(accumulator, this[i], i, this);
  }

  return accumulator;
}
```

Applications of reduce?

```typescript
let data = [
    {id: 1,emoji: '🐔',name: 'Chicken',number: 5},
    {id: 2,emoji: '🦇',name: 'Bat',number: 6},
    {id: 3,emoji: '🦉',name: 'Owl',number: 9},
    {id: 4,emoji: '🦄',name: 'Unicorn',number: 2},
    {id: 5,emoji: '🐺',name: 'Wolf',number: 10}
];

let countAnimalReducer = (accumulator,currentValue) => accumulator + currentValue.number;

const totalAnimals = data.reduce(countAnimalReducer,0)

console.log(totalAnimals) // 32


const res = data.reduce((accumulator,currentItem) => {
    accumulator[currentItem.name] = currentItem.name.length;
    return accumulator
},{})

console.log(res); //{ Chicken: 7, Bat: 3, Owl: 3, Unicorn: 7, Wolf: 4 }

```

#### Extraction & SubSetting with `slice` and `splice`

`arr.slice(start, [end])` method is used to copy a given part of the array. It returns the copied array as a new array without changing the original array.

Rules

1. A new array is returned and the original array is unmodified.
2. If `end` is omitted, end becomes the end (last element) of array.
3. If `start` is `-ve`, the elements are counted from the end.


`arr.splice(start, [deleteCount, itemToInsert1, itemToInsert2, ...])` method changes the original array, by adding or removing elements from it and return the removed items in a new array. **The first argument is the starting point for removing elements**. Elements that have a smaller index number from the given index won’t be removed.

Rules:

1. Operation is in place.
2. An array is returned with the deleted items.
3. If `start` is -ve, the elements are counted from the end.
4. If `deleteCountis` omitted,the elements until the end of array are removed.
   1. If items to insert such as itemToInsert1 are omitted, elements are only removed.



```typescript
const myArray  = [1,2,3,4,5,6,7] 

console.log(myArray.slice(0))       // [ 1, 2, 3, 4, 5, 6, 7 ]
console.log(myArray.slice(0, 1))    // [ 1 ]
console.log(myArray.slice(1))       // [ 2, 3, 4, 5, 6, 7 ]
console.log(myArray.slice(5))       // [ 6, 7 ]
console.log(myArray.slice(-1))      // [ 7 ]
console.log(myArray)                // [ 1, 2, 3, 4, 5, 6, 7 ]



const secondArray = [10, 20, 30, 40, 50]

console.log(secondArray.splice(0, 1))   // [ 10 ] : deletes 1 element starting at index 0
console.log(secondArray.splice(-2, 1))  // [ 40 ] : deletes 1 element starting at index end-2 
console.log(secondArray)                // [ 20, 30, 50 ]
console.log(secondArray.splice(0))      // [ 20, 30, 50 ] : deletes all elements starting at index 0
console.log(secondArray)                // []
console.log(secondArray.splice(2, 0, 60, 70)) // [] : deletes 0 elements starting at index 2 (doesn't exist so defaults to 0) and then inserts 60, 70
console.log(secondArray)                // [60, 70]
```


### Array and Object Destructuring

### Rest / Spread for Objects
This feature builds off of updates from ES6 so we can use rest/spread syntax for objects. The spread operator enables us to create a clone of an Object so we can modify the original more easily. This feature should not be used at the end, or it will result in an error. Take a look at the code below to see how it works.

```typescript
let myObj = {
  a:1,
  b:3,
  c:5,
  d:8,
}

// we use the rest operator to grab everything else left in the object.
let { a, b, ...z } = myObj;
console.log(a);     // 1
console.log(b);     // 3
console.log(z);     // {c: 5, d: 8}

// using the spread syntax we cloned our Object
let clone = { ...myObj };
console.log(clone);
// {a: 1, b: 3, c: 5, d: 8}
myObj.e = 15;
console.log(clone)
// {a: 1, b: 3, c: 5, d: 8}
console.log(myObj)
// {a: 1, b: 3, c: 5, d: 8, e: 15}
``
