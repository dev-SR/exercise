const animals = ['🐑','🐈','🐄','🐪','🐅'];

const genArray1 = new Array(5).fill(0); // [0, 0, 0, 0, 0]
const genArray2 = [...Array(5).keys()]; // [0, 1, 2, 3, 4]
const genArray3 = Array.from({length: 5},(_,i) => i); //[0,1,2,3,4]
const genArray4 = Array.from({length: 5},(_,i) => i + 1); //[1,2,3,4,5]

console.log(genArray1,genArray2,genArray3);


// LOOPING
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


// Spread Operator
// I have seen a lot of developers use[].concat() to join two arrays together and array.slice() to clone an array.But this can be done easily with the Javascript ES6 spread operator.

const birds = ['parrot','swan','eagle','duck'];

// Longhand
// joining arrays
const animals2 = ['zebra','giraffe','llama','raccoon'].concat(birds);

// cloning arrays
const newBirds1 = birds.slice();

// Shorthand
// joining arrays
const animals3 = ['zebra','giraffe','llama','raccoon',...birds];

//cloning arrays
const newBirds2 = [...birds];



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


// RUDUCE
function sum(numbers) {
    let accumulationSoFar = 0;

    for(const number of numbers) {
        accumulationSoFar += number;
    }
    return accumulationSoFar;
}

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
},{})//{ Chicken: 7, Bat: 3, Owl: 3, Unicorn: 7, Wolf: 4 }
console.log(res);


// Extraction & Subsetting
