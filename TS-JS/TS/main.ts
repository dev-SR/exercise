import { run1 } from '@/04_io/cwd_dirname';
import { runCopyFn } from './04_io/copy';
export const run2 = () =>
	console.log(__dirname, process.cwd(), __dirname === process.cwd(), __filename);

console.log('RUN: 04_io/cwd_dirname.ts--------------------');
run1();
run2();
console.log('\n\nRUN: 04_io/copy.ts-----------------------');
runCopyFn();
