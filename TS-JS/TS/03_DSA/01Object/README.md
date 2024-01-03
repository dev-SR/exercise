# Object in TS/Js

- [Object in TS/Js](#object-in-tsjs)
	- [Object basic](#object-basic)
	- [Iterating over objects](#iterating-over-objects)
	- [Spread operator](#spread-operator)
		- [Cloning an object with spread operator](#cloning-an-object-with-spread-operator)
		- [Merging objects with spread operator](#merging-objects-with-spread-operator)
	- [Destructuring Objects](#destructuring-objects)
		- [Setting default values](#setting-default-values)
		- [Destructuring a null object](#destructuring-a-null-object)
		- [Nested object destructuring](#nested-object-destructuring)
		- [Destructuring function parameters](#destructuring-function-parameters)
		- [Destructuring with rest operator](#destructuring-with-rest-operator)
		- [Check if object is empty using destructor](#check-if-object-is-empty-using-destructor)

## Object basic


```typescript
// object initialization

type GenericObject = {
	[key: string]: string | number | boolean | undefined;
};

let personObject: GenericObject = {
	name: 'John',
	age: 30
};

console.log(personObject); //{ name: 'John', age: 30 }

// accessing object properties
// 1. dot notation
console.log(personObject.name);
console.log(personObject.age);
// 2. bracket notation
console.log(personObject['name']);
console.log(personObject['age']);

// changing object properties
personObject.name = 'Jane';
personObject.age = 25;
console.log(personObject); // { name: 'Jane', age: 25 }

// adding new properties

personObject.address = 'USA';
console.log(personObject); // { name: 'Jane', age: 25, addres: 'USA' }

// deleting properties
delete personObject.address;
console.log(personObject); // { name: 'Jane', age: 25 }

// Check if a property exists
console.log('name' in personObject); // true

// methods

type GreetPerson = {
	name: string;
	age: number;
	greet: (phrase: string) => void;
};

let person1: GreetPerson = {
	name: 'John',
	age: 30,
	greet(phrase: string) {
		console.log(phrase + ' ' + this.name);
	}
};

person1.greet('Hi there - I am'); // Hi there - I am John
```

## Iterating over objects

```typescript
// iterating over object keys

for (let key in personObject) {
	console.log(key); // name, age
}

// iterating over object keys and values

for (let key in personObject) {
	console.log(personObject[key]); // John 25
}

// list of object keys
console.log(Object.keys(personObject)); // [ 'name', 'age' ]

// list of object values
console.log(Object.values(personObject)); // [ 'Jane', 25 ]

// list of object keys and values
console.log(Object.entries(personObject)); // [ [ 'name', 'Jane' ], [ 'age', 25 ] ]
```

Example:


```typescript
type Obj = {
	[key: string]: {
		capital: string;
		population: number;
		languages: string[];
	};
};

let obj1: Obj = {
	bangladesh: {
		capital: 'dhaka',
		population: 160000000,
		languages: ['bengali', 'english']
	},
	india: {
		capital: 'delhi',
		population: 1300000000,
		languages: ['hindi', 'english']
	},
	pakistan: {
		capital: 'islamabad',
		population: 200000000,
		languages: ['urdu', 'english']
	}
};

Object.keys(obj1).map((key) => {
	console.log(`country: ${key}`);
	console.log(`capital: ${obj1[key].capital}`);
	console.log(`population: ${obj1[key].population}`);
	obj1[key].languages.map((lang) => {
		console.log(`language: ${lang}`);
	});
});
```


## Spread operator

In ES6, you use the `spread operator (...) `to unpack elements of an array. The spread operator can be very useful to clone an array. For example:


```js
let colors = ["red", "green", "blue"];
let rgb = [...colors];
console.log(rgb); //Output: ["red", "green", "blue"];
```

In this example, the spread operator (...) unpacks elements of the colors array and places them in a new array rgb.

The spread operator (...) can be used to merge two or more arrays into one as shown in the following example:

```typescript
let rgb = ["red", "green", "blue"];
let cmyk = ["cyan", "magenta", "yellow", "black"];
let merge = [...rgb, ...cmyk];
console.log(merge);
//["red", "green", "blue", "cyan", "magenta", "yellow", "black"];
```

ES2018 expands the spread operator (...) to make it works with own enumerable properties of an object.

### Cloning an object with spread operator



```typescript
const circle = {
   radius: 10,
   style: {
      color: "blue",
   },
};

const clonedCircle = {
   ...circle,
};

clonedCircle.style = "red";

console.log(clonedCircle); //{ radius: 10, style: 'red' }
```

### Merging objects with spread operator

```typescript
const circle = {
    radius: 10
};
const style = {
    backgroundColor: 'red'
};
const solidCircle = {
    ...circle,
    ...style
};

console.log(solidCircle);//{ radius: 10, backgroundColor: 'red' }
```

## Destructuring Objects


```js
let person = {
   firstName: "John",
   lastName: "Doe",
};
let { firstName, lastName } = person;

console.log(firstName); // 'John'
console.log(lastName); // 'Doe'
```

### Setting default values

```ts
let person2: {
	firstName: string;
	lastName: string;
	currentAge: number;
	middleName?: string;
} = {
	firstName: 'John',
	lastName: 'Doe',
	currentAge: 28
};

let { firstName, lastName,
		middleName = '',
		currentAge: renamedAge = 18 } = person2;

console.log(middleName); // ''
console.log(renamedAge);
```

### Destructuring a null object


```typescript
function getValues(): {
	// [key: string]: string | number | boolean | undefined;
	a: number;
	b: number;
} | null {
	return null;
}
let { a, b } = getValues() || {};

console.log(a, b);// undefined undefined
```

### Nested object destructuring


```typescript
let employee = {
   id: 1001,
   name: {
      firstName: "John",
      lastName: "Doe",
   },
};


let {
   name: { firstName, lastName },
} = employee;

console.log(firstName); // John
console.log(lastName); // Doe

// It’s possible to do multiple assignment of a property to multiple variables:
let {
   name: { firstName, lastName },
   name,
} = employee;

console.log(firstName); // John
console.log(lastName); // Doe
console.log(name); // { firstName: 'John', lastName: 'Doe' }

```

### Destructuring function parameters


```typescript
type dParam = {
	[key: string]: string | number | boolean | undefined;
};

let display = (person: dParam) => console.log(`${person.firstName} ${person.lastName}`);

let P = {
	firstName: 'John',
	lastName: 'Doe'
};

display(P);

// destructuring
let display2 = ({ firstName, lastName }: dParam) => console.log(`${firstName} ${lastName}`);

display(P);
```

with nested objects

```typescript
const regularPerson = {
	firstname: 'Bill',
	lastname: 'Wilson',
	spouse: {
		firstname: 'Phil',
		lastname: 'Wilson'
	}
};
const lordify = ({ spouse: { firstname } }) => {
   console.log(`${firstname} of Canterbury`);
};
lordify(regularPerson); // Phil of Canterbur
```

### Destructuring with rest operator

```typescript
const regularPerson = {
	firstname: 'Bill',
	lastname: 'Wilson',
	spouse: {
		firstname: 'Phil',
		lastname: 'Wilson'
	}
};

const { firstname:x,lastname:y,...spouseDetails } = regularPerson;

console.log( x ); // Bill
console.log( y ); // Wilson
console.log( spouseDetails ); // { spouse: { firstname: 'Phil', lastname: 'Wilson' } }
```

```typescript
const user = {
   username: 'dceddia',
   firstname: 'Dave',
   lastname: 'Ceddia'
};
const extendedPerson = {
   ...user,
   username: 'Assigning new Name', //overriding username
   newprops: 'New' //adding new properties
};
console.log(extendedPerson);
//   username: 'Assigning new Name',
//   firstname: 'Dave',
//   lastname: 'Ceddia',
//   newprops: 'New'
```

```typescript
const items = [
   {
      name: 'User 1',
      Role: 'admin',
      selected: false
   },
   {
      name: 'User 2',
      Role: 'user',
      selected: false
   }
];

items.map(({ Role, ...item }) => {
   console.log(item); // { name: 'User 1', selected: false }......
   console.log(Role); // admin.......
   console.log(`User: ${item.name}, selected? ${item.selected} `);
   //User: User 1, selected? false
});
```

### Check if object is empty using destructor

