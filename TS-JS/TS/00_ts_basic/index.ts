let isBool: boolean = false;
let magic: number = 66.6;
let hello: string = 'world';

let notDefined: undefined = undefined;
let notPresent: null = null;

let biggy: bigint = 24n; //ES2020

let regexp: RegExp = new RegExp('ab+c');
let array: Array<number> = [1, 2, 3, 3];
let set: Set<number> = new Set(array);

class Queue<T> {
	private data: Array<T> = [];
	push(item: T) {
		this.data.push(item);
	}
	pop(): T | undefined {
		return this.data.shift();
	}
}

let q: Queue<number> = new Queue();

//Array
let arr: number[] = [1, 2, 3];
// usage
arr = [1];
arr = [1, 2, 3];
// arr = ['hello']; //error

// Tuple
let tuple: [number, number] = [0, 0];
tuple = [1, 2];
// tuple = [1]; //error: must be 2 items
// tuple = [1, 2, 3]; //error: must be 2 items
// tuple = ['hello', 1]; //error:must be number

type Point = { x: number; y: number };
const center: Point = {
	x: 0,
	y: 0
};

// center = {
// 	x: 1,
// 	y: 1
// }; // Error

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

//

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
// point3D = point2D; //Error
function takesPoint3D(point: Point3D) {
	/***/
}
// takesPoint3D(point2D); //Error

let exampleAny: any;
let exampleUnknown: unknown;
// any
exampleAny = 123;
exampleAny = 'Hello';
// unknown
exampleUnknown = 123;
exampleUnknown = 'World';
// any
exampleAny.allows.anything.you.can.imagine();
let anySetBool: boolean = exampleAny;

// unknown
// exampleUnknown.trim();//Error
// let unknownSetBool: boolean = exampleUnknown;//Error
//resolve
if (typeof exampleUnknown == 'string') {
	exampleUnknown.trim();
}
if (typeof exampleUnknown == 'boolean') {
	let unknownSetBool: boolean = exampleUnknown;
}

function loadString() {}
function loadNumber() {}
// let someLegacyVariable: any;
// someLegacyVariable = loadString();
// console.log(someLegacyVariable.trim());
// someLegacyVariable = loadNumber();
// console.log(someLegacyVariable.toFixed(2));

let someLegacyVariable: unknown;
someLegacyVariable = loadString();
// console.log(someLegacyVariable.trim());//Error
someLegacyVariable = loadNumber();
// console.log(someLegacyVariable.toFixed(2));//Error

if (typeof someLegacyVariable == 'string') {
	console.log(someLegacyVariable.trim());
}

if (typeof someLegacyVariable == 'number') {
	console.log(someLegacyVariable.toFixed(2));
}

function load(): any {}

let ret = load();
// const trimmed = ret.trim(); //
// when return type is not known
if (typeof ret === 'string') {
	// const trimmed = ret.trim(); //
}
// const trimmed = ( ret as string ).trim();
// const trimmed = ( <string>ret).trim();

console.log('Logged in user:', processed.env.USER);

declare const processed: any;

class Animal {
	protected name: string;
	constructor(name: string) {
		this.name = name;
	}
	public move(distanceInMeters: number): void {
		console.log(`${this.name} moved ${distanceInMeters}m.`);
	}
}
let cat = new Animal('Cat');
cat.move(10);
// cat.name = 'Dog'; //Property 'name' is private and only accessible within class 'Animal'
class Bird extends Animal {
	fly(distanceInMeters: number) {
		console.log(`${this.name} flew ${distanceInMeters}m.`); ///ok
	}
}

// type Dictionary = {
// 	[key: string]: boolean;
// };

type P = {
	email: string;
	displayName: string;
};
type PersonDictionary = {
	[username: string]: P | undefined;
};

const prs: PersonDictionary = {
	jhonwick: {
		displayName: 'Jhon Wick',
		email: 'jhonw@gmail.com'
	}
};
prs['jhon'] = {
	displayName: 'Jhon Wick',
	em: 'jhonw@gmail.com' //ERROR
};
