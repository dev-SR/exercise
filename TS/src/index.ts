// import 'colors';
// console.log('----------------<ts>---------------'.bgMagenta.black.bold);
let dictionary: Record<string, States> = {};
// type Dictionary ={[key:string]:States}
interface States {
   current: string;
   next: string;
}

const Item: Record<keyof States, string> = {
   current: 'ABC',
   next: 'sodfhjk'
};
// type Items ={[key:'current'|'next']:string}

dictionary[0] = Item;

console.log(dictionary); //{ '0': { current: 'ABC', next: 'sodfhjk' } }
