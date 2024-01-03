function formatCommandLine(input: string | string[]) {
	let line = '';
	if (typeof input === 'string') {
		line = input.trim();
	} else {
		line = input.map((x) => x.trim()).join(' ');
	}
	return line;
}
console.log(formatCommandLine('hello ')); //hello
console.log(formatCommandLine(['hello', ' world'])); //hello world
// console.log(formatCommandLine(1337));
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
// padLeft('hello world', false);//Error

type CardinalDirection = 'North' | 'East' | 'South' | 'West';
let direction: CardinalDirection;
direction = 'North';
// direction = 'n0r7h'; //error
direction = 'South';
function move(distanceMeters: number, direction: CardinalDirection) {
	console.log(`Moving ${distanceMeters} meters towards ${direction}`);
}

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

type Points = {
	x: number;
	y: number;
};
let point: Points;
function init(): Points {
	return { x: 1, y: 2 };
}
point = init();
console.log(point.x, point.y); //Ok now

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
	sendEmail(person.email);
}

// Express Base

const personJSON = {
	name: 'jhon',
	email: 'jhon@gmail.com'
};
type PersonResponse = typeof personJSON;
function processRes(person: PersonResponse) {
	console.log(`Name: ${person.name}, Email: ${person.email}`);
}

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

type PaymentReq = LongTypeDef['payment'];
type PreviousAliases = LongTypeDef['personal']['previousAliases'][0];

type Personal = {
	name: string;
	age: number;
	location: string;
};
const person: Personal = {
	name: 'Jhon',
	age: 35,
	location: 'Dhaka,BD'
};

function logGet(obj: Personal, key: keyof Personal) {
	const val = obj[key];
	console.log(`Getting: ${key} ${val}`);
	return val;
}

const age = logGet(person, 'age');
logGet(person, 'email'); //ER: type '"email"' is not assignable to parameter of type 'keyof Personal

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
