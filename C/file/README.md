# File in C

- [File in C](#file-in-c)
  - [File Introduction](#file-introduction)
    - [Check if a file exists](#check-if-a-file-exists)
    - [Writing to a file](#writing-to-a-file)
    - [Reading: Taking Input From a File](#reading-taking-input-from-a-file)
    - [`fseek()`: Moving to a specific location in a file](#fseek-moving-to-a-specific-location-in-a-file)
  - [Formatted IO: `printf()`, `scanf()`, `fprintf()`, `fscanf()`](#formatted-io-printf-scanf-fprintf-fscanf)
  - [Record IO: `fread()`, `fwrite()`](#record-io-fread-fwrite)

## File Introduction

Following are the most important file management functions available in C:

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
    <td><code>char *fgets(buffer,n,fp)</code></td>
    <td>
        <ul>
            <li>Reads a file line by line and stores it in a buffer.</li>
            <li> It reads <code>n-1</code> characters from the file and stores the string in a buffer in which the <code>NULL</code> character <code>‘\0’</code> is appended as the last character.</li>
            <li> <code>Arguments</code>:
                <ul>
                    <li><code>buffer</code>: Buffer to store the data</li>
                    <li><code>n</code>: Size of the buffer</li>
                    <li><code>fp</code>: File pointer</li>
                </ul>
            </li>
            <li><code>Returns</code>: On <bold>successful</bold> read, the pointer to <code>str</code> is returned. If there was an <code>error</code> or the  end of file (<cod>EOF</cod>) character is encountered before any content could be read, a <code>NULL</code> pointer is returned.
            </li>
        </ul>
    </td>
  </tr>
  <tr>
    <td><code>int fputs(str, fp)</code></td>
    <td>
        <ul>
            <li>It writes a string to the file pointed to by file pointer (<code>fp</code>)</li>
            <li> <code>Arguments</code>:
                <ul>
                    <li><code>str</code>: String of characters to be written</li>
                    <li><code>fp</code>: File Pointer</li>
                </ul>
            </li>
            <li>`fp`: File pointer</li>
            <li>
             <code>Returns</code>: On success, this function returns the number of values read and on error or end of the file it returns <code>EOF</code> or <code>-1</code>.
             </li>
        </ul>
    </td>
  </tr>
 <!-- row 2 -->
<tr>
    <td rowspan="2">Formatter IO</td>
    <td><code>int  fprintf(fp, formatted_str,...vars)</code></td>
    <td>
        <ul>
            <li> It prints a <code>string</code> to the file pointed to by file pointer (<code>fp</code>). The string can optionally include <code>format specifiers</code> and a list of variables <code>(...vars)</code>.</li>
            <li> <code>Arguments</code>:
                <ul>
                    <li><code>fp</code>:  File Pointer </li>
                    <li><code>formatted_str</code>: A formatted String (optionally) having n number of for format specifier. For Example: This formatted string has 3 format specifier - <code>Sum of %d and %d is %d</code></li>
                    <li><code>...vars</code>: List of variable for <code>n</code> number for format specifier used in formatter string. For example: <code>(a,b,sum)</code> for above formatted string </li>
                    <li>Ex: <code>fprintf (fp, "Sum of %d and %d is %d:, a, b, a + b )</code> ; </li>
                </ul>
            </li>
            <li>
             <code>Returns</code>: On success, this function returns the number of values read and on error or end of the file it returns <code>EOF</code> or <code>-1</code>.
            </li>
        </ul>
    </td>
  </tr>
  <tr>
    <td> <code>int fscanf(fp, conversion_specifiers, variable_addresses) </code> </td>
    <td>
        <ul>
            <li>Read formatted content from a File. and assigns the input to a list of variable pointers <code>variable_addresses</code> using <code>conversion specifiers</code>
            </li>
            <li> <code>Arguments</code>:
                <ul>
                    <li><code>fp</code>:  File Pointer </li>
                    <li><code>conversion_specifiers</code>: A format specifier as <code>[=%[*][width][modifiers]type=]</code> </li>
                    <li><code>variable_addresses</code>: List of variable addresses</li>
                    <li>Ex: <code>fscanf(file_pointer, "%s %s %s %s", str1, str2, str3, str4);</code></li>
                </ul>
            </li>
            <li><code>Returns</code>: On success, this function returns the number of values read and on error or end of the file it returns <code>EOF</code> or <code>-1</code>.</li>
            <li>Keep in mind that as with scanf, fscanf stops reading a string when space or newline is encountered.</li>
        </ul>
     </td>
  </tr>
<!-- row 3 -->
  <tr>
    <td rowspan="2">Character IO</td>
    <td><code>fputc(char, file_pointer)</code></td>
    <td>
        <ul>
            <li>It writes a character to the file pointed to by file_pointer.</li>
        </ul>
    </td>
  </tr>
  <tr>
    <td><code>fgetc(file_pointer)</code></td>
    <td>
        <ul>
            <li>
            It returns the next character from the file pointed to by the file pointer. When the end of the file has been reached, the EOF is sent back.
            </li>
        </ul>
    </td>
  </tr>
<!-- row 4 -->
  <tr>
    <td rowspan="2">Record IO</td>
    <td><code>size_t fwrite(ptr,size,nitems,fp);</code></td>
    <td>
        <ul>
            <li> Write binary data| blocks of data (arr/struct) to file</li>
             <li>
                 <code>Arguments</code>:
                 <ul>
                    <li><code>ptr</code>:  It points to the block of memory which contains the data items to be written. </li>
                    <li><code>size</code>: It specifies the number of bytes of <b>each item</b> to be written.</li>
                    <li><code>nitems </code>:It is the number of items to be written.</li>
                    <li><code>fp</code>: File Pointer</li>
                    <li>Ex: writing 2 element of an arr: <code>fwrite(arr, sizeof(int), 2, fp);</code>| writing structure <code>fwrite(&student_1, sizeof(student_1), 1, fp)</code>| writing 2 structure element of a array of structure: <code>fwrite(students, sizeof(students), 2, fp);</code></li>
                 </ul>
             </li>
             <li><code>Returns</code>: On success, it returns the count of the number of items successfully written to the file. On error, it returns a number less than <code>nitems</code>.
             </li>
        </ul>
    </td>
  </tr>
  <tr>
    <td><code>size_t fread(ptr,size,nitems,fp);</code></td>
    <td>
        <ul>
            <li> Read binary data| blocks of data (arr/struct) from file</li>
             <li>
                 <code>Arguments</code>:
                 <ul>
                    <li><code>ptr</code>:  It points to the block of memory which contains the data items to be written. </li>
                    <li><code>size</code>: It specifies the number of bytes of <b>each item</b> to be written.</li>
                    <li><code>nitems </code>:It is the number of items to be written.</li>
                    <li><code>fp</code>: File Pointer</li>
                    <li>Ex: reading the first 5 elements of an array: <code>int arr[10]; fread(arr, sizeof(int), 5, fp);</code></li>
                 </ul>
             </li>
             <li><code>Returns</code>:  On success, it reads n items from the file and returns n. On error or end of the file, it returns a number less than n.
             </li>
        </ul>
    </td>
  </tr>
<!-- row 5 -->
  <tr>
    <td rowspan="2">Integer IO</td>
    <td><code>int getw(fp)</code></td>
    <td>
        <ul>
            <li>getw function reads an integer value from a file pointed by fp. </li>
        </ul>
    </td>
  </tr>
  <tr>
    <td><code>int putw(number,fp)</code></td>
    <td>
        <ul>
            <li>putw function is used to write an integer into a file.</li>
        </ul>
    </td>
  </tr>
</tbody>
</table>

- [https://www.guru99.com/c-file-input-output.html](https://www.guru99.com/c-file-input-output.html)

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

## Formatted IO: `printf()`, `scanf()`, `fprintf()`, `fscanf()`

- [https://linuxhint.com/fprintf-fscanf-in-c/](https://linuxhint.com/fprintf-fscanf-in-c/)

## Record IO: `fread()`, `fwrite()`

- [https://overiq.com/c-programming-101/fwrite-function-in-c/](https://overiq.com/c-programming-101/fwrite-function-in-c/)
- [https://overiq.com/c-programming-101/fread-function-in-c/](https://overiq.com/c-programming-101/fread-function-in-c/)
- [https://www.geeksforgeeks.org/readwrite-structure-file-c/](https://www.geeksforgeeks.org/readwrite-structure-file-c/)
