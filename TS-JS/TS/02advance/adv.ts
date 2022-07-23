let dice!: number;
function rollDice() {
	dice = Math.floor(Math.random() * 6) + 1;
}
rollDice();
console.log(`Current Dice Value: ${dice}`); //r

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
type Persons = {
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

// type Adds = (a: number, b: number) => number;
// type Adds = {
// 	(a: number, b: number): number;
// };
// // interface Add{
// // 	(a: number, b: number): number;
// // };
// const add: Adds = (a: number, b: number) => a + b;

type Adds = {
	(a: number, b: number): number;
	(a: number, b: number, c: number): number;
	debugName?: string;
};

const add: Adds = (a: number, b: number, c?: number) => a + b + (c != null ? c : 0);
add.debugName = 'Addition Func';

// type PointCreator = new (x: number, y: number) => { x: number; y: number };
type PointCreator = {
	new (x: number, y: number): { x: number; y: number };
	new (x: number, y: number, z: number): { x: number; y: number; z: number };
	(x: number, y: number): { x: number; y: number };
	(x: number, y: number, z: number): { x: number; y: number; z: number };
	debugName: string;
};
const p: PointCreator = class {
	constructor(public x: number, public y: number) {}
};

type NameFields = { firstName: string; lastName: string };
function addFullName<T extends NameFields>(obj: T): T & { fullName: string } {
	return {
		...obj,
		fullName: `${obj.firstName} ${obj.lastName}` //ER:Property 'lastName/' does not exist on type 'T'
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

type IsNumber<T> = T extends number ? 'number' : 'other';

type WithNumber = IsNumber<number>;
type WithOther = IsNumber<string>;

const isNumber = (v: unknown) => (typeof v === 'number' ? 'number' : 'other');

const withNumber = isNumber(10);
const withOther = isNumber('abc');
