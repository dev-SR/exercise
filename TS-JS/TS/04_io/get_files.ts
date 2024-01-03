// import path
import path, { join } from 'path';
// Synchronous  version
import fs from 'fs';
const dirPath = path.join(process.cwd(), 'root');
const files = fs.readdirSync(dirPath);
// console.log(files);

// Asynchronous version
// import fs from 'fs/promises';
// async function readFile() {
// 	const files = await fs.readdir(dirPath);
// 	console.log(files);
// }

const getOnlyFileList = (dirName: string) => {
	let files: string[] = [];
	const items = fs.readdirSync(dirName, { withFileTypes: true });

	for (const item of items) {
		// {withFileTypes: true} is required to access the isFile(),isDirectory method
		if (!item.isDirectory()) {
			const fullPath = join(dirName, item.name);
			files.push(fullPath);
		}
	}

	return files;
};

const only_files = getOnlyFileList(dirPath);
// console.log(only_files);

const getAllFileList = (dirName: string) => {
	let files: string[] = [];
	const items = fs.readdirSync(dirName, { withFileTypes: true });

	for (const item of items) {
		const fullPath = join(dirName, item.name);
		if (item.isDirectory()) {
			files.push(fullPath); //(optional) push also the directory name to the array
			// recursive call
			const oldFiles = [...files];
			const subFiles = getAllFileList(fullPath);
			files = oldFiles.concat(subFiles);
			// files = [...files, ...subFiles];
		} else {
			files.push(fullPath);
		}
	}

	return files;
};

const allFiles = getAllFileList(dirPath);
function isDir(path: string) {
	try {
		var stat = fs.lstatSync(path);
		return stat.isDirectory();
		/*
		Objects returned from `fs.stat()` and `fs.lstat()` are of this type.
		stats.isFile()
		stats.isDirectory()
		stats.isBlockDevice()
		stats.isCharacterDevice()
		stats.isSymbolicLink() // (only valid with fs.lstat())
		stats.isFIFO()
		stats.isSocket()

		*/
	} catch (e) {
		// lstatSync throws an error if path doesn't exist
		return false;
	}
}
const getSeries: string[] = [];
allFiles.forEach((file) => {
	if (isDir(file)) {
		getSeries.push(file);
	}
});
console.log(getSeries);
