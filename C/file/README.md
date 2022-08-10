# File in C

- [File in C](#file-in-c)
  - [File Introduction](#file-introduction)
    - [Check if a file exists](#check-if-a-file-exists)
    - [Writing to a file](#writing-to-a-file)
    - [Reading: Taking Input From a File](#reading-taking-input-from-a-file)
    - [`fseek()`: Moving to a specific location in a file](#fseek-moving-to-a-specific-location-in-a-file)

## File Introduction

Different operations that can be performed on a file are:

A File can be used to store a large volume of persistent data. Like many other languages ‘C’ provides following file management functions,

- Creation of a file
- Opening a file
- Reading a file
- Writing to a file
- Closing a file

- Creation of a new file (`fopen` with attributes as “a” or “a+” or “w” or “w+”)
- Opening an existing file (`fopen`)
- Reading from file (`fscanf` or `fgets`)
- Writing to a file (`fprintf` or `fputs`)
- Moving to a specific location in a file (`fseek`, `rewind`)
Closing a file (fclose)
- `sscanf()` to read formatted data from a string.


Following are the most important file management functions available in ‘C,’

<table>
<thead>
  <tr>
    <th>Workings</th>
    <th>Functions</th>
    <th>Description</th>
  </tr>
</thead>
<tbody>
<!-- row 1 -->
  <tr>
    <td rowspan="2">String IO</td>
    <td><code>fgets(buffer,size,fp)</code></td>
    <td>
        <ul>
            <li><code>buffer</code>: Buffer to store the data</li>
            <li>`size`: Size of the buffer</li>
            <li>`fp`: File pointer</li>
        </ul>
    </td>
  </tr>
  <tr>
    <td>`fgets(buffer,size,fp)`</td>
    <td>
        <ul>
            <li>`buffer`: Buffer to store the data</li>
            <li>`size`: Size of the buffer</li>
            <li>`fp`: File pointer</li>
        </ul>
    </td>
  </tr>
 <!-- row 2 -->
<tr>
    <td rowspan="2">Formatter IO</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td></td>
    <td></td>
  </tr>
<!-- row 3 -->
  <tr>
    <td rowspan="2">Character IO</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td></td>
    <td></td>
  </tr>
<!-- row 4 -->
  <tr>
    <td rowspan="2">Record IO</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td></td>
    <td></td>
  </tr>
<!-- row 5 -->
  <tr>
    <td rowspan="2">Integer IO</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td></td>
    <td></td>
  </tr>
</tbody>
</table>


function	purpose
fopen ()	Creating a file or opening an existing file
fclose ()	Closing a file

fprintf ()	Writing a block of data to a file
fscanf ()	Reading a block data from a file
getc ()	Reads a single character from a file
putc ()	Writes a single character to a file
getw ()	Reads an integer from a file
putw ()	Writing an integer to a file
fseek ()	Sets the position of a file pointer to a specified location
ftell ()	Returns the current position of a file pointer
rewind ()	Sets the file pointer at the beginning of a file




### Check if a file exists

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    fp = fopen("x.txt", "r");
    if (!fp) {
    // if(fp == NULL){
        perror("Error "); // Error : No such file or directory
        return EXIT_FAILURE;
    }
    return 0;
}
```


### Writing to a file

Things needed to write to a file:

- file handler/pointer declaration: `FILE *fp;`
- `FILE *fopen(char *fileName,char *mode)` to open a file in (`"w"`) writing mode
- `fprintf()` to write to the file
- `fclose()` to close the file

```c
int main() {
 // declare file pointer/handler
    FILE *fp;

 // open a existing/new file and assign it's address to the file handler
    // char fileName[] = "new.my";
    // fp = fopen(fileName, "w");
 	fp = fopen("new.my", "w");

 // write to the file with
  // fprintf(file_pointer,format_string,...(n input for n format specifier specified in the format string))
    fprintf(fp, "This file is created by my program!\n");
    fprintf(fp, "Feeling Great");
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "This is line %d\n", i);
    }

 // close the file with
    fclose(fp);

    // opening again but for appending
    fp = fopen("new.my", "a");
    fprintf(fp, "Again opening the file but for appending this line");

    return 0;
}
-
```

Output in the file:

```text
This file is created by my program!
Feeling Great!!
Again opening the file but for appending this line
```

### Reading: Taking Input From a File

Create a file with two int

`in.my`

```text
1
2
```

Below is the program to read this two int, print sum of them in a output file:

```c
int main() {
    FILE *fp_in, *fp_out;
    int n1, n2, sum;

    fp_in = fopen("in.my", "r");
    fp_out = fopen("out.my", "w");

    fscanf(fp_in, "%d", &n1);
    fscanf(fp_in, "%d", &n2);

    sum = n1 + n2;
    printf("%d + %d = %d", n1, n2, sum);
    fprintf(fp_out, "%d\n", sum);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
```

👉👉At this moment if we had two integer as line :

```text
1 2
```

One options would be to read them as line with `fgets()` and then from that line read two int with `sscanf()`. `sscanf()` function allows us to read formatted data from a string rather than standard input or keyboard.

```c
#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    FILE *fp_in, *fp_out;
    int n1, n2, sum;

    fp_in = fopen("in.my", "r");
    fp_out = fopen("out.my", "w");

    // fscanf(fp_in, "%d", &n1);
    // fscanf(fp_in, "%d", &n2);
    // or
    // fscanf(fp_in, "%d %d", &n1, &n2);

    // or
    // read as a line with fgets
    char line[80];
    //!! Remember? `char *s;` don't work with scanf()

    fgets(line, 80, fp_in);
   // and then read two int from that line with sscanf()
    sscanf(line, "%s %d", &n1, &n2);

    printf("Line: %s\n", line); // Line: 1 2

    sum = n1 + n2;
    printf("%d + %d = %d", n1, n2, sum);
    fprintf(fp_out, "%d\n", sum);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
```

```text
soikat 191
jhon 192
```

```c
int main() {
    FILE *fp;
    char name[30];
    int id;

    fp = fopen("in1.my", "r");
    char line[80];

    while (fgets(line, 80, fp) != NULL) {
        // printf("%s", line);
        sscanf(line, "%s %d", name, &id);
        printf("Name: %s ID: %d\n", name, id);
    }

    fclose(fp);
    return 0;
}
```

Output:

```text
Name: soikat ID: 191
Name: jhon ID: 192
```

### `fseek()`: Moving to a specific location in a file

