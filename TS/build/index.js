"use strict";
// import 'colors';
// console.log('----------------<ts>---------------'.bgMagenta.black.bold);
let dictionary = {};
const Item = {
    current: 'ABC',
    next: 'sodfhjk'
};
// type Items ={[key:'current'|'next']:string}
dictionary[0] = Item;
console.log(dictionary); //{ '0': { current: 'ABC', next: 'sodfhjk' } }
