import { join } from 'path';
import { exec } from 'child_process';
// promisify converts a callback-based function to a promise-based one
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
