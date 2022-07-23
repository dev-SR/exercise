# TypeScript Intermediate

- [TypeScript Intermediate](#typescript-intermediate)
  - [More On Types](#more-on-types)
    - [Union Types](#union-types)
    - [Literal Types](#literal-types)
    - [Type Narrowing](#type-narrowing)
    - [Discriminated Unions](#discriminated-unions)
    - [Intersection Types](#intersection-types)
  - [Optional modifier](#optional-modifier)
    - [`null` and `undefined` with optional modifiers](#null-and-undefined-with-optional-modifiers)
  - [Null Assertion](#null-assertion)
  - [Interface](#interface)
    - [Interface Declaration Merging](#interface-declaration-merging)
    - [type vs interface](#type-vs-interface)

## More On Types

### Union Types

```typescript
function formatCommandLine(input: string | string[]) {
 let line = '';
 if (typeof input === 'string') {
  line = input.trim();
 } else {
  line = input.map((x) => x.trim()).join(' ');
 }
 return line;
}
console.log(formatCommandLine('hello '));//hello
console.log(formatCommandLine(['hello', ' world']));//hello world
console.log(formatCommandLine(1337));//ERROR

```

```typescript
type Padding = number | string;
function padLeft(value: string, padding: Padding) {
 if (typeof padding === 'number') {
  return Array(padding + 1).join(' ') + value;
 }
 if (typeof padding == 'string') {
  return padding + value;
 }
 throw new Error(`Expected number or string, got '${padding}'.`);
}

console.log(padLeft('hello world', 4)); //'    hello world'
console.log(padLeft('hello world', ' ')); //' hello world'
console.log(padLeft('hello world', '__')); //'__hello world
padLeft('hello world', false);//Error

```

### Literal Types

```typescript
type CardinalDirection = 'North' | 'East' | 'South' | 'West';
let direction: CardinalDirection;

direction = 'North';
// direction = 'n0r7h'; //error
direction = 'South';

function move(distanceMeters: number, direction: CardinalDirection) {
 console.log(`Moving ${distanceMeters} meters towards ${direction}`);
}
```

### Type Narrowing

```typescript
type Square = {
 size: number;
};
type Rectangle = {
 width: number;
 height: number;
};

type Shape = Square | Rectangle;
function area(shape: Shape) {
 if ('size' in shape) {
  return shape.size * shape.size;
 }

 if ('width' in shape) {
  return shape.width * shape.height;
 }
}
area({ size: 2 }); // 4
area({ width: 2, height: 3 }); // 6
```

### Discriminated Unions

```typescript
type Square = {
 kind: 'square';
 size: number;
};
type Rectangle = {
 kind: 'rectangle';
 width: number;
 height: number;
};

type Shape = Square | Rectangle;
function area(shape: Shape) {
 if (shape.kind === 'square') {
  return shape.size * shape.size;
 }

 if (shape.kind === 'rectangle') {
  return shape.width * shape.height;
 }
}
```

### Intersection Types

```typescript
type Point2D = {
 x: number;
 y: number;
};
type Point3D = Point2D & {
 z: number;
};
```

```typescript
type Person = { name: string };
type Email = { email: string };
type Phone = { phone: string };

type ContactDetails = Person & Email & Phone;

function contact(details: ContactDetails) {
 console.log(`Dear ${details.name}.
 I hope you received out email at ${details.email}.
 We will call you at ${details.phone} shortly`);
}
```

## Optional modifier

```typescript
type Person = {
 name: string;
 email: string;
 phone?: string;
};

const bruce: Person = {
 name: 'Bruce',
 email: 'br@gmail.com',
 phone: '911'
};

const jhon: Person = {
 name: 'Jhon',
 email: 'jhn@gmail.com',
 phone: undefined
};
```

### `null` and `undefined` with optional modifiers

```typescript
class Point {
 x?: number;
 y?: number;
}

const point = new Point();
console.log(point.x); //undefined

point.x = 0;//ok
point.x = undefined;//ok
point.x = null; //Error in 'strict' mode;Type 'null' is not assignable to type 'number | undefined'.
```

```typescript
class Point {
 x?: number | null;
 y?: number;
}

const point = new Point();
point.x = null; //ok
```

## Null Assertion

```typescript
type Point = {
 x: number,
 y: number
};
let point: Point;
function init() {
 point = {x:1,y:2}
}
init();
console.log(point.x, point.y);//ER:Variable 'point' is used before being assigned
console.log(point!.x, point!.y);//Fix
```

or

```typescript
let point: Point;
function init(): Point {
 return { x: 1, y: 2 };
}
point = init();
console.log(point.x, point.y); //Ok now
```

```typescript
type Person = {
 name: string;
 email?: string | null | undefined;
};

function sendEmail(email: string) {
 console.log('Sent email to', email);
}
function contact(person: Person) {
 if (person.email == null) throw new Error(`Person ${person.name} is not contactable`);
 // now we are sure email is not null
 sendEmail( person.email );
}
```

## Interface

```typescript
type Point2D = {
 x: number;
 y: number;
};
type Point3D = Point2D & {
 z: number;
};
```

`==`

```typescript
interface Point2D {
 x: number;
 y: number;
};
interface Point3D extends Point2D & {
 z: number;
};
```

### Interface Declaration Merging

```typescript
export interface Request {
 body: any;
}
// Express JSON
export interface Request {
 json: any;
}

// out app
function handleReq(req: Request) {
 req.body;
 req.json;
}
```

### type vs interface

- `type`
  - Unions
  - Intersections (&)
  - Primitives
  - Shorthand Functions
  - Advanced Type Functions
- `interface`
  - Declaration Merging
  - Familiarity (extends)

```typescript
export interface InputProps {
 type:'text' | 'number' | 'password',
 value: string,
 onChange: (value: string) => void
}

//
type InputOnChange = (value: string) => void;
type InputValue = string;
type InputType = 'text' | 'number' | 'password';
export type InputProps = {
 type: InputType,
 value: InputValue,
 onChange: InputOnChange,
};
```

``
