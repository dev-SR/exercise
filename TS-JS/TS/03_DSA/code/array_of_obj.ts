// tsconfig.json: 	"resolveJsonModule": true,	"esModuleInterop": true
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

// find and update
let index = data.findIndex((item) => item.id === 2);
data[index].totalQuantity = 100;
// console.log(data[index]);

// get updated nested inner object from array of objects
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

// get updated nested inner object with extra property attached
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

// get deleted nested inner object from array of objects
let deleted = data.map((item) => {
	// item.products = item.products.filter(
	// 	(product) => product.title !== 'Pubg Printed Graphic T-Shirt'
	// );
	// return item;
	return {
		...item,
		products: item.products.filter((product) => product.title !== 'Spring and summershoes')
	};
});
console.log(deleted[0]);
// write file

// fs.writeFile(filePath, JSON.stringify(data, null, 2), (error) => {
// 	if (error) {
// 		console.log('An error has occurred ', error);
// 		return;
// 	}
// 	console.log('Data written successfully to disk');
// });
