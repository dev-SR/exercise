# Functional Interface In Java

## TypeScript Function Types

```typescript
function isEven(num: number) {
 return num % 2 == 0;
}
function MyFilter(ar: number[]): number[] {
 let newArr: number[] = [];
 for (let i = 0; i < ar.length; i++) {
  const currentEl = ar[i];
  if (isEven(currentEl)) {
   newArr.push(currentEl);
  }
 }
 return newArr;
}

console.log(MyFilter([1, 2, 3, 4, 5]));

// Built-in
console.log([1, 2, 3, 4, 5].filter(isEven));
function isOdd(num: number) {
 return num % 2 != 0;
}
console.log([1, 2, 3, 4, 5].filter(isOdd));

// Function Type
function MyFilterCallBack(ar: number[], fn: (n: number) => boolean): number[] {
 let newArr: number[] = [];
 for (let i = 0; i < ar.length; i++) {
  const currentEl = ar[i];
  if (fn(currentEl)) {
   newArr.push(currentEl);
  }
 }
 return newArr;
}
console.log(MyFilterCallBack([1, 2, 3, 4, 5], isEven));
console.log(MyFilterCallBack([1, 2, 3, 4, 5], isOdd));

interface FilterType {
 fn(n: number): boolean;
}
function MyFilterCallBackInterface(ar: number[], { fn }: FilterType): number[] {
 let newArr: number[] = [];
 for (let i = 0; i < ar.length; i++) {
  const currentEl = ar[i];
  if (fn(currentEl)) {
   newArr.push(currentEl);
  }
 }
 return newArr;
}
console.log(MyFilterCallBackInterface([1, 2, 3, 4, 5], { fn: isEven }));
console.log(MyFilterCallBackInterface([1, 2, 3, 4, 5], { fn: isOdd }));

// Arrow Function
// function isEven(num: number) {
//  return num % 2 == 0;
// }
// console.log( [1, 2, 3, 4, 5].filter(isEven));
console.log([1, 2, 3, 4, 5].filter(n=>n%2==0));
```
