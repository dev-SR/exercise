// Function Declaration
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


// Function Parameters
// Function with Default Parameter
function sayHello2(name = "Guest") {
	console.log(`Hello, ${name}!`);
}
sayHello2(); // Hello, Guest!
sayHello2("Clifford"); // Hello, Clifford!

// Function with Rest Parameters
function sumNumbers(...numbers: number[]) {
	let sum = 0;
	for(let num of numbers) {
		sum += num;
	}
	console.log(sum);
}

sumNumbers(1,2,3,4); // 10

// Arrow function
// TYPE 1 Curly Braces and Parens
const fn1 = (arg1: number,arg2: number) => {
	const res = arg1 + arg2;
	return `Sum is ${res}`;
};
// TYPE 2: No curly braces - auto return
const fn2 = (arg1: number,arg2: number) => `Sum is ${arg1 + arg2}`;

// Type 3: no parens - only valid with exactly 1 argument
const fn3 = (arg1: any) => `Only 1 arg here ${arg1}`;

// console.log( fn1( 1, 2 ) )



// Example: Higher-Order Function
type Operation = (x: number,y: number) => number;

function applyOperation(a: number,b: number,operation: Operation): number {
	return operation(a,b);
}

let result = applyOperation(5,2,(a,b) => a * b);
console.log(result); // Output: 10
result = applyOperation(5,2,(a,b) => a + b);
console.log(result); // Output: 7

