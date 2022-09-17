let numbers = [1, 2, 3, 4, 5];
// find odd number
let oddNumber = numbers.find((n) => n % 2 !== 0);
console.log(oddNumber); // 1
// find index of odd number
let oddIndex = numbers.findIndex((n) => n % 2 !== 0);
console.log(oddIndex); // 0
