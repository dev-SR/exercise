# Sub Process

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
