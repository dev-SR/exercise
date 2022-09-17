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

// Spread operator

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

let { firstName, lastName, middleName = '', currentAge: renamedAge = 18 } = person2;

console.log(middleName); // ''
console.log(renamedAge);

function getValues(): {
	// [key: string]: string | number | boolean | undefined;
	a: number;
	b: number;
} | null {
	return null;
}
let { a, b } = getValues() || {};

console.log(a, b); // undefined undefined

let employee = {
	id: 1001,
	name: {
		fName: 'John',
		lName: 'Doe'
	}
};

let {
	name: { fName, lName }
} = employee;

console.log(fName); // John
console.log(lName); // Doe

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

const regularPerson = {
	firstname: 'Bill',
	lastname: 'Wilson',
	spouse: {
		firstname: 'Phil',
		lastname: 'Wilson'
	}
};

const { firstname: x, lastname: y, ...spouseDetails } = regularPerson;

console.log(x); // Bill
console.log(y); // Wilson
console.log(spouseDetails); // { spouse: { firstname: 'Phil', lastname: 'Wilson' } }
