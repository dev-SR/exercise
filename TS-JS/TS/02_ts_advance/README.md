# Advance TS

- [Advance TS](#advance-ts)
	- [More with Types](#more-with-types)
		- [`typeof` type operator](#typeof-type-operator)
		- [Lookup Types](#lookup-types)
		- [`keyof` type operator](#keyof-type-operator)
		- [Conditional Types](#conditional-types)
	- [Definite Assignment Assertion](#definite-assignment-assertion)
	- [User Defined Type Guards](#user-defined-type-guards)
	- [Assertion Functions](#assertion-functions)
	- [Function Overloading](#function-overloading)
	- [Call Signatures](#call-signatures)
	- [Generics](#generics)
		- [Generics Constraints](#generics-constraints)

## More with Types

### `typeof` type operator

```typescript
const personJSON = {
 'name': 'jhon',
 'email': 'jhon@gmail.com'
};
type PersonResponse = typeof personJSON;
function processRes(person: PersonResponse) {
 console.log(`Name: ${person.name}, Email: ${person.email}`);
}
```

### Lookup Types

```typescript
type LongTypeDef = {
 transactionId: string;
 personal: {
  email: string;
  phone: string;
  previousAliases: {
   name: string;
   email: string;
  }[];
  gender: string;
 };
 payment: {
  creditCardToken: string;
 };
};


type PaymentReq = LongTypeDef['payment']
type PreviousAliases = LongTypeDef['personal']['previousAliases'][0]
```

### `keyof` type operator

```typescript
type Personal = {
 name: string,
 age: number,
 location:string
}
const person: Personal = {
 name: 'Jhon',
 age: 35,
 location:"Dhaka,BD"
}

function logGet(obj: Personal, key: keyof Personal) {
 const val = obj[key];
 console.log(`Getting: ${key} ${val}`);
 return val;
}

const age = logGet( person, 'age' );
logGet( person, 'email' );//ER: type '"email"' is not assignable to parameter of type 'keyof Personal
```

More Generic:

```typescript
function logGet<Obj, Key extends keyof Obj>(obj: Obj, key: Key) {
 const value = obj[key];
 console.log('Getting:', key, value);
 return value;
}

const age = logGet(john, 'age'); // 35
function logSet<Obj, Key extends keyof Obj>(obj: Obj, key: Key, value: Obj[Key]) {
 console.log('Setting:', key, value);
 obj[key] = value;
}
logSet(john, 'age', 36);
```

### Conditional Types


```typescript
type IsNumber<T> = T extends number ? 'number' : 'other';

type WithNumber = IsNumber<number>;
type WithOther = IsNumber<string>;

const isNumber = (v: unknown) => (typeof v === 'number' ? 'number' : 'other');

const withNumber = isNumber(10);
const withOther = isNumber('abc');
```


## Definite Assignment Assertion

```typescript
let dice: number;
function rollDice() {
 dice = Math.floor(Math.random() * 6) + 1;
}
rollDice();
console.log(`Current Dice Value: ${dice}`); //Variable 'dice' is used before being assigned.ts(2454)
```

with definite assignment assertion `!`:

```typescript
let dice!: number;
function rollDice() {
 dice = Math.floor(Math.random() * 6) + 1;
}
rollDice();
console.log(`Current Dice Value: ${dice}`); //r

```

## User Defined Type Guards

```typescript
type Sqr = {
 size: number;
};

type Rect = {
 width: number;
 height: number;
};
type Shapes = Sqr | Rect;

function isSquare(shape: Shapes): shape is Sqr {
 return 'size' in shape;
}
function isRectangle(shape: Shapes): shape is Sqr {
 return 'size' in shape;
}

function area(shape: Shapes) {
 if (isSquare(shape)) {
  return shape.size * shape.size;
 }
 if (isRectangle(shape)) {
  return shape.width * shape.height;
 }
}
```

## Assertion Functions

assertion functions are used to check if a value is of a certain type.if not, it throws an error. this is useful for `debugging/testing` not in `production` where we should use `user defined type guards`.

```typescript
type Person = {
 name: string;
 dateOfBirth: Date;
};
function assertPerson(condition: unknown, message: string): asserts condition {
 if (!condition) throw new Error(message);
}
function assertDate(value: unknown): asserts value is Date {
 if (value instanceof Date) return;
 else throw new TypeError('value is not a Date');
}

const maybePerson = load();

assertPerson(maybePerson != null, 'Could not load');
console.log('Name:', maybePerson.name);
assertDate(maybePerson.dateOfBirth);
console.log('Birth:', maybePerson.dateOfBirth.toISOString());

```

## Function Overloading

```typescript
function reverse(string: string): string;
function reverse(stringArray: string[]): string[];
function reverse(stringOrStringArray: string | string[]) {
 if (typeof stringOrStringArray == 'string') {
  return stringOrStringArray.split('').reverse().join('');
 } else {
  return stringOrStringArray.slice().reverse();
 }
}

const hello = reverse('hello');
const h_e_l_l_o = reverse(['h', 'e', 'l', 'l', 'o']);
```

## Call Signatures

```typescript
type Adds = (a: number, b: number) => number;
type Adds = {
 (a: number, b: number): number;
};
// interface Add{
//  (a: number, b: number): number;
// };
const add: Adds = (a: number, b: number) => a + b;

// func overloading, function properties
type Adds = {
 (a: number, b: number): number;
 (a: number, b: number, c: number): number;
 debugName?: string;
};

const add: Adds = (a: number, b: number, c?: number) => a + b + (c != null ? c : 0);
add.debugName = 'Addition Func';
```

```typescript
// type PointCreator = new (x: number, y: number) => { x: number; y: number };
type PointCreator = {
 new (x: number, y: number): { x: number; y: number };
};
const p: PointCreator = class {
 constructor(public x: number, public y: number) {}
};


// more
type PointCreator = {
 new (x: number, y: number): { x: number; y: number };
 new (x: number, y: number, z: number): { x: number; y: number; z: number };
 (x: number, y: number): { x: number; y: number };
 (x: number, y: number, z: number): { x: number; y: number; z: number };
 debugName: string;
};
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

### Generics Constraints

```typescript
function addFullName<T>(obj: T): T & { fullName: string } {
 return {
  ...obj,
  fullName: `${obj.firstName} ${obj.lastName}` //ER:Property 'lastName/' does not exist on type 'T'
 };
}
```

```typescript
type NameFields = { firstName: string; lastName: string };
function addFullName<T extends NameFields>(obj: T): T & { fullName: string } {
 return {
  ...obj,
  fullName: `${obj.firstName} ${obj.lastName}` //Ok
 };
}

addFullName({
	email: 'a@gmail.com',
	firstName: 'a',
	lastName: 'b'
});
addFullName({
	firstName: 'a' //ER:Property 'lastName' is missing in type '{ firstName: string; }' but required in type 'NameFields'
});

```
