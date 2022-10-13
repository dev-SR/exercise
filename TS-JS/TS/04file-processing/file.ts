// import path
import path from 'path';
const filePath = path.join(process.cwd(), 'root', 'file.x');
// import fs/promises
import fs from 'fs/promises';
import { Dirent } from 'fs';
// read file
console.log('Reading file...');
// fs.readFile(filePath, 'utf-8').then((data) => console.log(data));
async function readFile() {
	const dirent: Dirent[] = await fs.readdir(path.join(process.cwd(), 'root'), {
		withFileTypes: true
	});
	console.log(dirent);
	dirent.forEach((entry) => {
		if (entry.isFile()) {
			console.log(`file name: ${entry.name}`);
		} else if (entry.isDirectory()) {
			console.log(`directory name: ${entry.name}`);
		} else if (entry.isSymbolicLink()) {
			console.log(`symbolic link name: ${entry.name}`);
		}
	});
}
readFile();
console.log("I'm not blocked!");

// copy entire directory
const cwd = process.cwd();
const sourcePath = path.join(cwd, 'root');
const destinationPath = path.join(cwd, 'copied');

fs.cp(sourcePath, destinationPath, { recursive: true });
