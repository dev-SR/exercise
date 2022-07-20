# Fundamentals of TypeScript

- [Fundamentals of TypeScript](#fundamentals-of-typescript)
  - [Types](#types)
    - [Primitive Types](#primitive-types)
    - [Instance Types](#instance-types)
    - [Arrays and Tuples](#arrays-and-tuples)
    - [Objects Types and Type Aliases](#objects-types-and-type-aliases)
    - [Functions Types](#functions-types)
    - [Structural Typing](#structural-typing)
    - [🚀Special Types:  `any` and `unknown`](#special-types--any-and-unknown)
    - [🚀Js to TS](#js-to-ts)
    - [🚀Type Assertions](#type-assertions)
    - [Type Declarations](#type-declarations)
  - [Classes In TypeScript](#classes-in-typescript)
    - [private and protected](#private-and-protected)
  - [Generics](#generics)

## Types

### Primitive Types

- **JavaScript**
  - `number`
  - `string`
  - `boolean`
  - `null`
  - `undefined`
  - `object`
- **TypeScript**
  - `any`
  - `unknown`
  - `never`
  - `enum`
  - `tuple`

```typescript
let isBool: boolean = false;
let magic: number = 66.6;
let hello: string = 'world';

let notDefined: undefined = undefined;
let notPresent: null = null;

let biggy: bigint = 24n; //ES2020
```

### Instance Types

```typescript
let regexp: RegExp = new RegExp('ab+c');
let array: Array<number> = [1, 2, 3, 3];
let set: Set<number> = new Set(array);

class Queue<T> {
 private data: Array<T> = [];
 push(item: T) {this.data.push(item);}
 pop(): T | undefined {  return this.data.shift(); }
}

let q: Queue<number> = new Queue();
```

### Arrays and Tuples

```typescript
//Array
let arr: number[] = [1, 2, 3];
// usage
arr = [1];
arr = [1, 2, 3];
arr = ['hello']; //error

// Tuple
let tuple: [number, number] = [0, 0];
tuple = [1, 2];
tuple = [1]; //error: must be 2 items
tuple = [1, 2, 3]; //error: must be 2 items
tuple = ['hello', 1]; //error:must be number
```

### Objects Types and Type Aliases

```typescript
type Point = { x: number; y: number };
let center: Point = {
 x: 0,
 y: 0
};
let unit: Point = {
 x: 1,
 y: 1
};
```

### Functions Types

```typescript
function add(a: number, b: number): number {
 return a + b;
}
function log(msg: string): void {
 console.log(`LOG:${msg}`);
}
function sum(...vals: number[]) {
 return vals.reduce((pre, curr) => pre + curr);
}
sum(1, 2); //3
sum(1, 2, 3); //6

type Add = (a: number, b: number) => number;
let adder: Add;
// let adder: (a: number, b: number) => number;
adder = function (a: number, b: number): number {
 return a + b;
};
adder = (a, b) => a + b;
```

### Structural Typing

```typescript
type Point2D = { x: number; y: number };
type Point3D = { x: number; y: number; z: number };
let point2D: Point2D = { x: 0, y: 10 };
let point3D: Point3D = { x: 0, y: 10, z: 20 };

/** Extra info ok */
point2D = point3D;
function takesPoint2D(point: Point2D) {
 /***/
}
takesPoint2D(point3D);

/** Error: missing info */
point3D = point2D; //Error
function takesPoint3D(point: Point3D) {
 /***/
}
takesPoint3D(point2D); //Error
```

### 🚀Special Types:  `any` and `unknown`

```typescript
let exampleAny: any;
let exampleUnknown: unknown;
// any
exampleAny = 123;
exampleAny = 'Hello';
// unknown
exampleUnknown = 123;
exampleUnknown = 'World';

// any
exampleAny.allows.anything.you.can.imagine();//Ok
let anySetBool: boolean = exampleAny;//Ok
// unknown
exampleUnknown.trim();//Error
let unknownSetBool: boolean = exampleUnknown;//Error

//resolving 'unknown'
if (typeof exampleUnknown == 'string') {
 exampleUnknown.trim();
}
if (typeof exampleUnknown == 'boolean') {
 let unknownSetBool: boolean = exampleUnknown;
}
```

### 🚀Js to TS

1. Assigning a value to a variable of type `any`

```typescript

let someLegacyVariable: any;
someLegacyVariable = loadString();
console.log(someLegacyVariable.trim());//ok
someLegacyVariable = loadNumber();
console.log(someLegacyVariable.toFixed(2));//ok
```

2. Assigning a value to a variable of type `unknown`

```typescript
let someLegacyVariable: unknown;
someLegacyVariable = loadString();
console.log(someLegacyVariable.trim());//Error
someLegacyVariable = loadNumber();
console.log(someLegacyVariable.toFixed(2));//Error
```

with `unknown` you can assign any type to a variable, but you can't access the properties of the variable.

To resolve this, you can use type check.

```typescript
if (typeof someLegacyVariable == 'string') {
 console.log(someLegacyVariable.trim());
}

if (typeof someLegacyVariable == 'number') {
 console.log(someLegacyVariable.toFixed(2));
}
```

### 🚀Type Assertions

```typescript
let ret = load();
const trimmed = ret.trim(); //Error
// when return type is not known
if (typeof ret === 'string') {
 const trimmed = ret.trim();
}

// when return type is known, we can use type assertion
const trimmed = (ret as string).trim();
const trimmed = (<string>ret).trim();```
```

### Type Declarations

```typescript
console.log('Logged in user:', process.env.USER);//Error

declare const process: any;
```

Or install type declarations package if available

```bash
npm install @types/<package> @types/node --save-dev
```

## Classes In TypeScript

```typescript
class Animal {
 name: string;
 constructor(name: string) {
  this.name = name;
 }
 public move(distanceInMeters: number): void {
  console.log(`${this.name} moved ${distanceInMeters}m.`);
 }
}
let cat = new Animal('Cat');
cat.move(10);
cat.name = 'Dog';
```

### private and protected

```typescript
class Animal {
 private name: string;
 constructor(name: string) {
  this.name = name;
 }
 public move(distanceInMeters: number): void {
  console.log(`${this.name} moved ${distanceInMeters}m.`);
 }
}
class Bird extends Animal {
 fly(distanceInMeters: number) {
  console.log(`${this.name} flew ${distanceInMeters}m.`);
  //Error: Property 'name' is private and only accessible within class 'Animal'
 }
}
let cat = new Animal('Cat');
cat.move(10);
cat.name = 'Dog'; //Error: Property 'name' is private and only accessible within class 'Animal'
```

```typescript
class Animal {
 protected name: string;
 constructor(name: string) {
  this.name = name;
 }
 public move(distanceInMeters: number): void {
  console.log(`${this.name} moved ${distanceInMeters}m.`);
 }
}
class Bird extends Animal {
 fly(distanceInMeters: number) {
  console.log(`${this.name} flew ${distanceInMeters}m.`); ////OK Now
 }
}
let cat = new Animal('Cat');
cat.move(10);
cat.name = 'Dog'; //Property 'name' is private and only accessible within class 'Animal'
```

## Generics

```typescript
/** A FIFO (First In First Out) collection */
class Queue<T> {
 data = [];
 push(item: T) {
  this.data.push(item);
 }
 pop(): T {
  return this.data.shift();
 }
}
const queue = new Queue<number>();
queue.push(123);
queue.push(456);
console.log(queue.pop().toPrecision(1));
console.log(queue.pop().toPrecision(1));
```
