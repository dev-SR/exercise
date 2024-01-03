function swapArrayElement<T>(arr_modify_in_place: T[], fromIndex: number, toIndex: number) {
	var element = arr_modify_in_place[fromIndex];
	// delete the element from the array
	arr_modify_in_place.splice(fromIndex, 1);
	// insert the element at the new position
	arr_modify_in_place.splice(toIndex, 0, element);
}

let A = ['ই', 'উ', 'ন', 'ি', 'ক', 'ে', 'া', 'ড', 'ই', 'উ', 'ন', 'ি', 'ক', 'ে', 'া', 'ড'];
console.log(A);

function findAllIndex<T>(arr: T[], value: T) {
	let indexes = [];
	for (let i = 0; i < arr.length; i++) if (arr[i] === value) indexes.push(i);
	return indexes;
}

// moveArrayElement(A, 0, 1);

function findAllAndMoveOneLeft<T>(arr: T[], value: T) {
	let indexes = findAllIndex(arr, value);
	for (let i = 0; i < indexes.length; i++) swapArrayElement(arr, indexes[i], indexes[i] - 1);
}

// findAllAndMoveOneLeft(A, 'ি');
// findAllAndMoveOneLeft(A, 'ে');
// console.log(A);

function findAllIndexAllAtOnce<T>(arr: T[], values: T[]) {
	let indexes = [];
	for (let i = 0; i < arr.length; i++) if (values.includes(arr[i])) indexes.push(i);
	return indexes;
}

function findAllAndMoveOneLeftAllAtOnce<T>(arr: T[], values: T[]) {
	let indexes = findAllIndexAllAtOnce(arr, values);
	for (let i = 0; i < indexes.length; i++) swapArrayElement(arr, indexes[i], indexes[i] - 1);
}
findAllAndMoveOneLeftAllAtOnce(A, ['ি', 'ে']);
console.log(A);
