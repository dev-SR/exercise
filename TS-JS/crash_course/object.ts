
const vehicles = {
    car: "🚗",
    taxi: "🚕",
    bus: "🚌",
    minibus: "🚐"
};
// Accessing Object Properties in JavaScript
// 1. Accessing object properties using the dot notation
console.log(vehicles.car)
// 2. Accessing object properties using the bracket notation
console.log(vehicles['car'])

// Looping Through an Object
for(let key in vehicles) {
    console.log(`${key}:${vehicles[key]}`)
}

console.log(Object.keys(vehicles));//[ "car", "taxi", "bus", "minibus" ]
console.log(Object.values(vehicles))//[ "🚗", "🚕", "🚌", "🚐" ]
console.log(Object.entries(vehicles))
/* returns 2d array of [[key,value]]
[
  [ "car", "🚗" ],
  [ "taxi", "🚕" ],
  [ "bus", "🚌" ],
  [ "minibus", "🚐" ]
]
*/
console.log(Object.fromEntries([ //takes 2d array of [[key,value]]
    ["car","🚗"],
    ["taxi","🚕"],
    ["bus","🚌"],
    ["minibus","🚐"]
]))
/* returns object
{
    car: "🚗",
    taxi: "🚕",
    bus: "🚌",
    minibus: "🚐"
}
*/

// Destructuring Assignment
// Longhand
let car = vehicles.car
let taxi = vehicles.taxi
let bus = vehicles.bus
let minibus = vehicles.minibus

// Shorthand
// const {car,taxi,bus,minibus} = vehicles


// Object Property
// In ES6 we can easily assign properties to objects.You can take advantage of the shorthand notation if the variable name is the same as the object key.

const {unicorn = "🦆",eagle = "🦅",chicken = "🐔"} = {unicorn: "🦄"}

console.log(unicorn)// 🦄
console.log(chicken)// 🐔


let data = {
    id: 23,
    location: "Madagascar",
    birds: {
        swan: "🦢",
        cockerel: "🐓",
        turkey: "🦃",
        flamingo: "🦩",
        parrot: "🦜"
    },
    mammals: {
        skunk: "🦨",
        raccoon: "🦝",
        kangaroo: "🦘",
        badger: "🦡",
        llama: "🦙"
    }
}

function whereis({location,mammals: {raccoon: image}}) {
    return `${image} is located at ${location}`
}

function whichGroup({birds: {swan: bird},mammals: {badger: mammal}}) {
    return `${bird} is a bird and ${mammal} is a mamal`
}

console.log(whereis(data))//🦝 is located at Madagascar
console.log(whichGroup(data))//🦢 is a bird and 🦡 is a mamal