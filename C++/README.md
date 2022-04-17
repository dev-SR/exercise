# C++

- [C++](#c)
  - [Setup](#setup)
    - [Install MinGW Compiler](#install-mingw-compiler)
    - [Precompile headers](#precompile-headers)
  - [Compile and Run](#compile-and-run)
    - [cli](#cli)
    - [VScode](#vscode)

## Setup

### Install MinGW Compiler

MinGW is a native Windows port of the GNU Compiler Collection (GCC). Install the
latest MinGW compiler, after downloading from
[here](https://sourceforge.net/projects/mingw/). For installation select :

-  `mingw32-base`
-  `mingw32-gcc-g++`

Your path should preferably be `C:\MinGW`. Finally, add the bin directory,
**`C:\MinGW\bin`** to the System **`PATH`**.

### Precompile headers

Now we can speed up compilation time by precompiling all the header files, i.e.
by precompiling the **`bits/stdc++.h`** header file. This can speed up
compilation time by up to a factor of 12. For this, first, navigate to the
`stdc++.h` file. This will be located at a directory similar to
**`C:\MinGW\lib\gcc\mingw32\6.3.0\include\c++\mingw32\bits`**. Right click while
pressing Shift to open a Powershell/cmd window there. Run the command
**`g++ -std=c++17 stdc++.h`**, to compile the header. Take care to use the same
flags you used in your build system. Check to make sure that the
**`stdc++.h.gch`** file was created in the directory.

## Compile and Run


### cli

```cpp
g++ main.cpp; .\a
g++ main.cpp -o main; .\main
```

### VScode

[Docs](https://www.geeksforgeeks.org/compiling-with-g-plus-plus/)

-  By vscode Code Runner Extension:

```json
 "code-runner.executorMap": {
      "cpp": "cd $dir && g++ -std=c++17 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
 }
```

**Other Vs config:**

```json
{
   "C_Cpp.default.compilerPath": "C:\\MinGW\\bin\\g++.exe"
}
```
