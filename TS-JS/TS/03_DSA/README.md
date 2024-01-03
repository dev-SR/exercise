# Data Structure Utils

- [Data Structure Utils](#data-structure-utils)
	- [Array of Objects](#array-of-objects)
		- [sort](#sort)
		- [example 1](#example-1)
			- [add new object](#add-new-object)
			- [modify inner object](#modify-inner-object)
			- [delete object](#delete-object)
		- [example 2](#example-2)
			- [find and update](#find-and-update)
			- [get updated nested inner object](#get-updated-nested-inner-object)
			- [get updated nested inner object with extra property attached](#get-updated-nested-inner-object-with-extra-property-attached)
			- [get deleted nested inner object from array of objects](#get-deleted-nested-inner-object-from-array-of-objects)

## Array of Objects

### sort

```typescript
let employees = [
   { name: "John", salary: 90000, hireDate: "July 1, 2010" },
   { name: "David", salary: 75000, hireDate: "August 15, 2009" },
   { name: "Ana", salary: 80000, hireDate: "December 12, 2011" },
];
// sort by salary
employees.sort(function (x, y) {
   return x.salary - y.salary;
});

console.table(employees);
```

### example 1

```typescript
const items = [
 {
  id: 1,
  checked: false,
  text: 'Learn React'
 },
 {
  id: 2,
  checked: false,
  text: 'Learn TypeScript'
 }
];
```

#### add new object

```typescript
const addItem = (text: string) => {
 const id = items.length ? items[items.length - 1].id + 1 : 1;
 const newItem = { id, checked: false, text };
 const newItems = [...items, newItem];
 return newItems;
};
```

#### modify inner object

```typescript
const handleCheck = (id: number) => {
 const newItems = items.map((item) =>
  item.id === id
   ? {
     ...item,
     checked: !item.checked
    }
   : item
 );
 return newItems;
};
```

#### delete object

```typescript
const deleteObject = (id: number) => {
 const newItems = items.filter((item) => item.id !== id);
 return newItems;
};
```

### example 2

```typescript
// tsconfig.json:  "resolveJsonModule": true, "esModuleInterop": true
// import data from './data.json';

import fs from 'fs';
import path from 'path';
// https://dummyjson.com/carts#
type Product = {
 id: number;
 title: string;
 price: number;
 quantity: number;
 total: number;
 discountPercentage: number;
 discountedPrice: number;
};
type CartType = {
 id: number;
 total: number;
 discountedTotal: number;
 userId: number;
 totalProducts: number;
 totalQuantity: number;
 products: Product[];
};

// read file
const filePath = path.join(__dirname, 'data.json');
const jsonRaw = fs.readFileSync(filePath, 'utf8');
let data = JSON.parse(jsonRaw) as CartType[];


// write file

// fs.writeFile(filePath, JSON.stringify(data, null, 2), (error) => {
//  if (error) {
//   console.log('An error has occurred ', error);
//   return;
//  }
//  console.log('Data written successfully to disk');
// });
```

#### find and update

```typescript
// find and update
let index = data.findIndex((item) => item.id === 2);
data[index].totalQuantity = 100;
console.log(data[index]);
```

#### get updated nested inner object

```typescript
let updated = data.map((item) => {
 item.products = item.products.map((product) => {
  if (product.title === 'Spring and summershoes') {
   product.price = 100000;
  }
  return product;
 });
 return item;
});
// console.log(updated[0]);
```

#### get updated nested inner object with extra property attached

```typescript
let updated2 = data.map((item) => {
 item.products = item.products.map((product) => {
  return {
   ...product,
   expired: false
  };
 });
 return item;
});
// console.log(updated2[0]);
```

#### get deleted nested inner object from array of objects

```typescript
let deleted = data.map((item) => {
 // item.products = item.products.filter(
 //  (product) => product.title !== 'Pubg Printed Graphic T-Shirt'
 // );
 // return item;
 return {
  ...item,
  products: item.products.filter((product) => product.title !== 'Spring and summershoes')
 };
});
console.log(deleted[0]);
```
