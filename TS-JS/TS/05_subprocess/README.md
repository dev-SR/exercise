# Sub Process

- [Sub Process](#sub-process)
  - [`exec`](#exec)
  - [Example: Compile and Run a Cpp,Python etc Programs](#example-compile-and-run-a-cpppython-etc-programs)

Node.js allows single-threaded, non-blocking performance but running a single thread in a CPU cannot handle increasing workload hence the child_process module can be used to spawn child processes. The child processes communicate with each other using a built-in messaging system.

The following are the four different ways to create a child process in Node.js:

- `spawn()` method
- `fork()` method
- `exec()` method
- `execFile()` method

## `exec`

```typescript
import { exec } from 'child_process';
// Counts the number of directory in
// current working directory
exec('dir | find /c /v ""', (error, stdout, stderr) => {
 if (error) {
  console.error(`exec error: ${error}`);
  return;
 }
 console.log(`stdout: No. of directories = ${stdout}`);
 if (stderr != '') console.error(`stderr: ${stderr}`);
});
```

## Example: Compile and Run a Cpp,Python etc Programs

```typescript
import { join } from 'path';
import { exec } from 'child_process';
// promisify convert sync function to async function
import { promisify } from 'util';
const execAsync = promisify(exec);

const cwd = process.cwd();
const dirCodes = join(cwd, 'codes');
const inputDirPath = join(cwd, 'inputs');
const pythonCodeFilepath = join(dirCodes, 'main.py');
const cppCodeFilepath = join(dirCodes, 'main.cpp');

const inputPath = join(inputDirPath, 'input.txt');

async function executePy() {
	const { stdout, stderr } = await execAsync(`python ${pythonCodeFilepath} < ${inputPath}`);

	if (stderr != '') console.error(`stderr: ${stderr}`);
	console.log(`stdout: ${stdout}`);
}
executePy();
async function executeCPP() {
	const { stdout, stderr } = await execAsync(`g++ ${cppCodeFilepath} && a.exe < ${inputPath}`);

	if (stderr != '') console.error(`stderr: ${stderr}`);
	console.log(`stdout: ${stdout}`);
}
executeCPP();

```