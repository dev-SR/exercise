# Data Structure Utils

- [Data Structure Utils](#data-structure-utils)
	- [Array of Objects](#array-of-objects)
		- [sort](#sort)

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