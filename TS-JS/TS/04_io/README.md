# File Processing

- [File Processing](#file-processing)
  - [Path](#path)
    - [Joining paths](#joining-paths)
      - [with cwd()](#with-cwd)
    - [Parsing paths](#parsing-paths)
  - [Working Directory:`process.cwd()` vs `__dirname`](#working-directoryprocesscwd-vs-__dirname)
  - [`fs` module](#fs-module)
    - [Comparing the `fs` module APIs](#comparing-the-fs-module-apis)
      - [Blocking Way: Synchronous API](#blocking-way-synchronous-api)
      - [Promise API](#promise-api)
    - [Reading files](#reading-files)
    - [Writing files](#writing-files)
    - [File metadata](#file-metadata)
  - [Working with directories](#working-with-directories)
    - [⭐ Getting Files in a Directory (without Sub-Directories): `readdir`, `readdirSync`](#-getting-files-in-a-directory-without-sub-directories-readdir-readdirsync)
    - [⭐ Getting Files in a Directory (with Sub-Directories): `readdir`, `readdirSync`](#-getting-files-in-a-directory-with-sub-directories-readdir-readdirsync)
    - [check if a directory/file exists](#check-if-a-directoryfile-exists)
    - [⭐ `fs.lstat()` to check if a path is a file or directory](#-fslstat-to-check-if-a-path-is-a-file-or-directory)
    - [Copying files with `fs.copyFile` and `fs.cp()`](#copying-files-with-fscopyfile-and-fscp)
      - [`fs.copyFile()`](#fscopyfile)
      - [🔥 `fs.cp()`](#-fscp)
      - [🔥 Coping full directory with ignore list with 'fs-extra'](#-coping-full-directory-with-ignore-list-with-fs-extra)
        - [Copy the entire directory, including subdirectories](#copy-the-entire-directory-including-subdirectories)
    - [create,remove,rename dir](#createremoverename-dir)

Node.js has a module called `PATH` to interact with file and directory paths. Node.js has a module called `FS` to interact with file and directory systems i.e., create, modify and delete while listing files.

- [https://blog.logrocket.com/file-processing-node-js-comprehensive-guide/](https://blog.logrocket.com/file-processing-node-js-comprehensive-guide/)

## Path

- [https://blog.logrocket.com/mastering-node-js-path-module/](https://blog.logrocket.com/mastering-node-js-path-module/)

The Node.js path module is a built-in module that helps you work with file system paths in an OS-independent way. The path module is essential if you’re building a CLI tool that supports OSX, Linux, and Windows.

### Joining paths

```ts
// const path = require('path');
// import * as path from 'path';
import path from 'path';
const fullPath = path.join('/path', 'to', 'test.txt');
```

In Windows, the path will be `path\to\test.txt`. In Linux, the path will be `/path/to/test.txt`.

This is a very useful method when you’re building a CLI tool that supports multiple operating systems. And it's why we are not using native string concatenation to join paths (`['/path', 'to', 'test.txt'].join('/')`).

Additionally, Numerous edge cases pop up when working with file system paths. For example, you may accidentally end up with a duplicate path separator if you try to join two paths manually. The `path.join()` function handles leading and trailing slashes for you, like so:

```typescript
path.join('data', 'test.txt'); // 'data/test.txt'
path.join('data', '/test.txt'); // 'data/test.txt'
path.join('data/', 'test.txt'); // 'data/test.txt'
path.join('data/', '/test.txt'); // 'data/test.txt'
```

#### with cwd()

```typescript
import path from 'path';
const RootDir = path.join(process.cwd(), 'root');
console.log(RootDir);
```

### Parsing paths

The `path.parse()` function returns an object containing the path broken up into five different components, including the extension and directory. The path.parse() function is also how you can get the file’s name without any extension.

```typescript
// parsing path
console.log(path.parse('/path/to/test.txt'));
```

Output:

```ts
{
  root: '/',
  dir: '/path/to',
  base: 'test.txt',
  ext: '.txt',
  name: 'test'
}
```

we have single functions as well to get the file name, extension, and directory name.

```typescript
console.log(path.basename(pathName)); // test.txt
console.log(path.dirname(pathName)); // /path/to
console.log(path.extname(pathName)); // .txt
```


## Working Directory:`process.cwd()` vs `__dirname`

- `process.cwd()` - from where we run the node process by `node main.js`
- `__dirname` - where the source file is located

```bash?
Project
└──lib
|   └── script.js
├── main.js

```

`script.ts`:

```typescript
export const run1 = () => console.log(__dirname, process.cwd(), __dirname === process.cwd());
```

`main.ts`:

```typescript
import { run1 } from '@/script';
export const run2 = () => console.log(__dirname, process.cwd(), __dirname === process.cwd());

run1();
run2();
```

Output:

```bash
~/Project/lib ~/Project false
~/Project ~/Project true
```

Similarly, `__filename` is the full path of the current file. `__filename` is the same as `__dirname` + `path.basename(__filename)`.


If you have enabled ES modules in Node.js (via `"type": "module"` in `package.json`) or using ES modules through a module bundler like Webpack, you’ll no longer have access to `__dirname` variables. In that case, to get the current file path:

```typescript
import path from 'path';
const __dirname = path.resolve();
```

## `fs` module

### Comparing the `fs` module APIs

#### Blocking Way: Synchronous API

The synchronous API exposes a set of functions that **block execution to perform file system operations**.

```typescript
import path from 'path';
import fs from 'fs';
const filePath = path.join(process.cwd(), 'root','file.x');

console.log('Reading File...');
const data = fs.readFileSync(filePath, 'utf-8');
console.log(data);
console.log('Do something else');
```

```txt
Reading File...
Hello World
Do something else
```

#### Promise API

If synchronous APIs should be avoided when possible, and callback APIs may not be ideal, that leaves us with the promise API:

```typescript
// import path
import path from 'path';
const filePath = path.join(process.cwd(), 'root', 'file.x');
// import fs/promises
import fs from 'fs/promises';
// read file
console.log('Reading file...');
// fs.readFile(filePath, 'utf-8').then((data) => console.log(data));
async function readFile() {
 const data = await fs.readFile(filePath, 'utf-8');
 console.log(data);
}
readFile();
console.log("I'm not blocked!");
```

```txt
Reading file...
I'm not blocked!
Hello World
```

### Reading files

```typescript
async function readFile() {
 const data = await fs.readFile(filePath, 'utf-8');
 console.log(data);
}
readFile();
```

### Writing files

There are three ways to write to a file:

- Append to a file
- Write to a file
- Truncate a file

Each of these functions helps to implement different use cases.

```typescript
// example 1: append to an existing file
// content of data.txt before: 12345
await fsPromises.appendFile('data.txt', '67890');
// content of data.txt after: 1234567890

// example 2: append to a file that doesn't exist yet
await fsPromises.appendFile('data2.txt', '123');
// Error: ENOENT: no such file or directory, open 'data2.txt'

// example 3: write to an existing file
// content of data3.txt before: 12345
await fsPromises.writeFile('data3.txt', '67890');
// content of data3.txt after: 67890

// example 4: write to a file that doesn't exist yet (new file is created)
await fsPromises.writeFile('data4.txt', '12345');

// example 5: truncate data in an existing file
// content of data5.txt before: 1234567890
await fsPromises.truncate('data5.txt', 5);
// content of data5.txt after: 12345
```

### File metadata

So far, we have focused on reading and modifying the contents of a file, but you may also need to read and update a file’s metadata. File metadata includes its size, type, permissions, and other file system properties.

The `stat` function is used to retrieve file metadata, or “statistics” like file size, permissions, and ownership.

```typescript
async function readFile() {
 const fileStats = await fs.stat(filePath);
 console.log(fileStats);
}
readFile();
```

```bash
Stats {
  dev: 811130011,
  mode: 33206,
  nlink: 1,
  uid: 0,
  gid: 0,
  rdev: 0,
  blksize: 4096,
  ino: 844424930215605,
  size: 11,
  blocks: 0,
  atimeMs: 1665640821623.7263,
  mtimeMs: 1665639845962.336,
  ctimeMs: 1665639845962.336,
  birthtimeMs: 1665639428418.6167,
  atime: 2022-10-13T06:00:21.624Z,
  mtime: 2022-10-13T05:44:05.962Z,
  ctime: 2022-10-13T05:44:05.962Z,
}
```

## Working with directories

### ⭐ Getting Files in a Directory (without Sub-Directories): `readdir`, `readdirSync`


```text
root/
├── deep-learning
│   ├── 01-deep-learning.md
│   ├── 02-deep-learning.md
│   └── 03-deep-learning.md
├── machine-learning
│   ├── 01-machine-learning.md
│   ├── 02-machine-learning.md
│   └── 03-machine-learning.md
├── random-1.md
├── random-2.md

```

The `readdir` function returns a list of the names of all the files and folders directly below the requested directory.

```typescript
// import path
import path from 'path';
// Synchronous  version
import fs from 'fs';
const dirPath = path.join(process.cwd(), 'root');
const files = fs.readdirSync(dirPath);
console.log(files);

// Asynchronous version
import fs from 'fs/promises';
async function readFile() {
 const files = await fs.readdir(dirPath);
 console.log(files);
}
```

Output:

```bash
[ 'deep-learning', 'machine-learning', 'random-1.md', 'random-2.md' ]
```

Get only files with full path

```typescript
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
console.log(only_files);
```

Output:

```bash
[
  '~\\exercise\\TS-JS\\TS\\04file-processing\\root\\random-1.md',
  '~\\exercise\\TS-JS\\TS\\04file-processing\\root\\random-2.md'
]
```

### ⭐ Getting Files in a Directory (with Sub-Directories): `readdir`, `readdirSync`


```typescript
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
```

```bash
[
  '~\\root\\deep-learning',
  '~\\root\\deep-learning\\01-deep-learning.md',
  '~\\root\\deep-learning\\02-deep-learning.md',
  '~\\root\\deep-learning\\03-deep-learning.md',
  '~\\root\\machine-learning',
  '~\\root\\machine-learning\\01-machine-learning.md',
  '~\\root\\machine-learning\\02-machine-learning.md',
  '~\\root\\machine-learning\\03-machine-learning.md',
  '~\\root\\random-1.md',
  '~\\root\\random-2.md'
]

```

### check if a directory/file exists

```typescript
import fs from 'fs/promises';
import path from 'path';

if (fs.existsSync(path.join(process.cwd(), 'root'))) {
 console.log('Content exists.');
} else {
 console.log('Content does not exist.');
}
```

### ⭐ `fs.lstat()` to check if a path is a file or directory

```typescript
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
```

Output:

```bash
[ '~\\root\\deep-learning', '~\\root\\machine-learning' ]
```


### Copying files with `fs.copyFile` and `fs.cp()`

#### `fs.copyFile()`

The copyFile function can make a copy of a file and give you some control over what happens if the destination file exists already:

```typescript
// example 1: create a copy, overwite the destination file if it exists already
await fsPromises.copyFile('source.txt', 'dest.txt');

// example 2: create a copy but fail because the destination file exists already
await fsPromises.copyFile('source.txt', 'dest.txt', fs.constants.COPYFILE_EXCL);
// Error: EEXIST: file already exists, copyfile 'source.txt' -> 'dest.txt'
```

Example 1 will overwrite dest.txt if it exists already. In example 2, we pass in the COPYFILE_EXCL flag to override the default behavior and fail if dest.txt exists already.

#### 🔥 `fs.cp()`

Starting with version 16.7.0, nodejs has a new `fs.cp()` method that **copies the entire directory structure from src to dest asynchronously, including subdirectories and files.**

This method can copy both a particular file and a directory. The `recursive` property in the configuration needs to be set to true when a directory needs to be copied.

To copy files:

```typescript
fs.cp(sourcePath, destinationPath, { recursive: true }, (err) => {
  if (err) {
    console.error(err);
  }
});

fs.cpSync(sourcePath, destinationPath, {
  recursive: true,
  filter: (src, dest) => {
    return !src.includes('node_modules');
  }
});
```

#### 🔥 Coping full directory with ignore list with 'fs-extra'

```typescript
import path from 'path';
import fs from 'fs-extra';

export const copy_dir = (sourceDir: string, destinationDir: string, ignoreList: string[] = []) => {
 fs.copySync(sourceDir, destinationDir, {
  overwrite: true,
  filter: (src, dest) => {
   // Get the relative path of the file/directory
   const relativePath = path.relative(sourceDir, src);
   // Check if the relative path matches any pattern in the ignore list
   return !ignoreList.some((pattern) => relativePath.startsWith(pattern));
  }
 });
};

const sourceDir = path.join(__dirname, 'old');
const destinationDir = path.join(__dirname, 'new');
const ignoreList = ['node_modules','.git','.next'];

copy_dir(sourceDir, destinationDir, ignoreList);
```


##### Copy the entire directory, including subdirectories

```typescript
// copy entire directory
const cwd = process.cwd();
const sourcePath = path.join(cwd, 'root');
const destinationPath = path.join(cwd, 'copied');

fs.cp(sourcePath, destinationPath, { recursive: true });
```

As we can see, this method works much better than the previous one:

1. there is no more need to make sure that the dest directory must exist, if the dest directory does not exist, it will be created automatically (no matter how many levels of directories).
2. you can copy the entire folder, including the subdirectories, without having to do it recursively and separately

### create,remove,rename dir

```typescript
// example 1: create a directory
await fsPromises.mkdir('sampleDir');

// example 2: create multiple nested directories
await fsPromises.mkdir('nested1/nested2/nested3', { recursive: true });

// example 3: rename a directory
await fsPromises.rename('sampleDir', 'sampleDirRenamed');

// example 4: remove a directory
await fsPromises.rmdir('sampleDirRenamed');

// example 5: remove a directory tree
await fsPromises.rm('nested1', { recursive: true });

// example 6: remove a directory tree, ignore errors if it doesn't exist
await fsPromises.rm('nested1', { recursive: true, force: true });
```

Examples 2, 5, and 6 demonstrate the `recursive` option, which is especially helpful if you don’t know if a path will exist before creating or deleting it.