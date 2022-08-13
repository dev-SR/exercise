# File in C

- [File in C](#file-in-c)
  - [File Introduction](#file-introduction)
  - [Check if a file exists](#check-if-a-file-exists)
  - [Writing to a file](#writing-to-a-file)
  - [Reading: Taking Input From a File](#reading-taking-input-from-a-file)
    - [word by word](#word-by-word)
    - [line by line: `fscanf(fp, "%[^\n] ", &var)` | `gets(var,n,fp)`](#line-by-line-fscanffp-n--var--getsvarnfp)
      - [Reading formatted data: `fscanf(fp, format, ...)` | `fgets() + sscanf()`](#reading-formatted-data-fscanffp-format---fgets--sscanf)
  - [`fseek()`: Moving to a specific location in a file](#fseek-moving-to-a-specific-location-in-a-file)
  - [Serialization | Deserialization with `fread()`, `fwrite()`](#serialization--deserialization-with-fread-fwrite)
  - [Example](#example)
    - [Copy file](#copy-file)
    - [File size](#file-size)

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
    <td rowspan="2">Unformatted String IO</td>
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
    <td rowspan="2">🚀Formatted String IO</td>
    <td><code>int fprintf(fp, formatted_str,...vars)</code></td>
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
    <td rowspan="2">🚀Character IO</td>
    <td><code><b>int</b> fputc(char, file_pointer)</code></td>
    <td>
        <ul>
            <li>It writes a character to the file pointed to by file_pointer.</li>
        </ul>
    </td>
  </tr>
  <tr>
    <td><code><b>int</b> fgetc(file_pointer)</code></td>
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
    <td rowspan="2">🚀Serialization</td>
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

## Check if a file exists

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

## Writing to a file

Things needed to write to a file:

- file handler/pointer declaration: `FILE *fp;`
- `FILE *fopen(char *fileName,char *mode)` to open a file in (`"w"`) writing mode
- `fprintf()`,`fputs()` etc. to write to the file
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
    fprintf(fp, "This file is created by my program!; Additionally this a formatted string \n");
    fprintf(fp, "Feeling Great\n");
    fprintf(fp, "Additionally; `fprintf()` takes formatted string:");
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "Formatted string with format specifier `%%d` -> %d\n", i);
    }

    // close the file with
    fclose(fp);

    // opening again but for appending
    fp = fopen("new.my", "a");
    fprintf(fp, "Again opening the file but for appending this line");

    return 0;
}
```

Output in the file:

```text
This file is created by my program!; Additionally this a formatted string
Feeling Great
Additionally; `fprintf()` takes formatted string:formatted string with format specifier `%d` -> 0
Formatted string with format specifier `%d` -> 1
Formatted string with format specifier `%d` -> 2
Formatted string with format specifier `%d` -> 3
Formatted string with format specifier `%d` -> 4
Again opening the file but for appending this line
```

## Reading: Taking Input From a File

### word by word

Create a file with two int

`in1.txt`

```text
Jhon Snow
Bob
Rock
```

Below is the program to read the file, and it will be read word by word just like `scanf()` itself.

```c
int main() {
    FILE *fp;

    fp = fopen("in1.txt", "r");

    char names[10][10];
    int i = 0;
    // first two word
    fscanf(fp, "%s", names[i]);
    printf("> %s\n", names[i]);
    i++;
    fscanf(fp, "%s", names[i]);
    printf("> %s\n", names[i]);
    // rest
    while (fscanf(fp, "%s", names[i]) != EOF) {
        printf("> %s\n", names[i]);
        i++;
    }

    fclose(fp);

    return 0;
}
```

```bash
> Jhon
> Snow
> Bob
> Rock
```

Therefore we can see that `Jhon Snow` is not as a whole line, but as two words.

### line by line: `fscanf(fp, "%[^\n] ", &var)` | `gets(var,n,fp)`

Just like reading line by line with `scanf()` , `gets()` we can also use those techniques to read the file line by line.

`in2.txt`

```text
Jhon Snow
Bob
Rock
```

`fscanf(fp, "%[^\n] ", &var)`:

```cpp
#include <stdio.h>
int main() {
    FILE *fp;
    fp = fopen("in2.txt", "r");

    char names[10][100];
    int i = 0;
    while (fscanf(fp, "%[^\n] ", names[i]) != EOF) {
        printf("> %s\n", names[i]);
        i++;
    }
    fclose(fp);
    return 0;
}
```

`gets(var,n,fp)`:

```c
#include <stdio.h>
int main() {
    FILE *fp;

    fp = fopen("in2.txt", "r");

    char names[10][100];
    int i = 0;
    while (fgets(names[i], 100, fp)) {
        printf("> %s", names[i]);
        i++;
    }

    fclose(fp);

    return 0;
}
```

Now the output will be, text read line by line :

```c
> Jhon Snow
> Bob
> Rock
```

#### Reading formatted data: `fscanf(fp, format, ...)` | `fgets() + sscanf()`

Now that we have read the file line by line, How can we read line with formatted data?? For Example:

`in2.txt`

```text
Jhon 1
Bob 2
Rock 3
```

```c
int main() {
    FILE *fp;

    fp = fopen("in4.txt", "r");

    char name[30];
    int age;

    while (fscanf(fp, "%s %d", name, &age) != EOF) {
        printf("Name: %s ID: %d\n", name, age);
    }

    fclose(fp);
    return 0;
}
```

One options would be, first, to read them as line with `fgets()` and then from that line read two int with `sscanf()`. In other words, Each line read from the file can be processed using the command sscanf (string scanf). sscanf is the same as scanf except it works on a string, rather than the input stream. The format for sscanf is: `sscanf(buffer, format_string, arg1, arg2, ... argN);`

```c
int main() {
    FILE *fp;

    fp = fopen("in3.txt", "r");

    char lines[10][100];
    int i = 0;
    char name[30];
    int age;
    // 1. Read Lines
    while (fgets(lines[i], 100, fp)) {
        printf("> %s", lines[i]);
        // 2. Now reads the formatted input from that line
        sscanf(lines[i], "%s %d", name, &age);
        printf("Name: %s ID: %d\n", name, age);
        i++;
    }

    fclose(fp);

    return 0;
}

```

Output:

```bash
> Jhon 19
Name: Jhon ID: 19
> Bob 20
Name: Bob ID: 20
> Rock 30Name: Rock ID: 30
```

Example of sscanf:

```c
int main() {
    const char *line = "Add  id:324  name:\"john\" name2:\"doe\" num1:2009 num2:5 num3:20";
    char op[32], name[32], name2[32];
    int id, num1, num2, num3;
    int count =
        sscanf(line,
               "%s "
               "id:%d "
               "name:\"%[^\"]\" " /* use "name:%s" if you want the quotes */
               "name2:\"%[^\"]\" "
               "num1:%d "
               "num2:%d "
               "num3:%d ", /* typo? */
               op, &id, name, name2, &num1, &num2, &num3);
    if (count == 7)
        printf("%s %d %s %s %d %d %d\n", op, id, name, name2, num1, num2, num3);
        // Add 324 john doe 2009 5 20
    else
        printf("error scanning line\n");
    return 0;
}
```

## `fseek()`: Moving to a specific location in a file

`in4.txt`

```text
Name Age
Jhon 19
Bob 20
Rock 30
```

How would i skip the first line in the file?

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
    FILE *fp;

    fp = fopen("in4.txt", "r");

    char lines[10][100];
    int i = 0;
    char name[30];
    int age;
    // skip first line:
    fseek(fp, 8 + 2, SEEK_SET); // len("Name Age\n") = 8, SEEK_SET=0=> start from begin
    // reads from second line
    // 1. Read Lines
    while (fgets(lines[i], 100, fp)) {
        printf("> %s", lines[i]);
        // 2. Now reads the formatted input from that line
        sscanf(lines[i], "%s %d", name, &age);
        printf("Name: %s ID: %d\n", name, age);
        i++;
    }

    fclose(fp);

    return 0;
}
```

```bash
> Jhon 19
Name: Jhon ID: 19
> Bob 20
Name: Bob ID: 20
> Rock 30Name: Rock ID: 30
```

## Serialization | Deserialization with `fread()`, `fwrite()`

- [https://overiq.com/c-programming-101/fwrite-function-in-c/](https://overiq.com/c-programming-101/fwrite-function-in-c/)
- [https://overiq.com/c-programming-101/fread-function-in-c/](https://overiq.com/c-programming-101/fread-function-in-c/)
- [https://www.geeksforgeeks.org/readwrite-structure-file-c/](https://www.geeksforgeeks.org/readwrite-structure-file-c/)

For writing in file, it is easy to write `string` or `int` to file using `fprintf` and `putc`, but you might have faced difficulty when writing contents of `struct`. `fwrite` and `fread` make task easier when you want to write and read blocks of data.

To better understand fwrite() function consider the following examples:

Example 1: Writing a variable

```c
float *f = 100.13;
fwrite(&p, sizeof(f), 1, fp);
```

This writes the value of variable f to the file.

Example 2: Writing an array

```c
int arr[3] = {101, 203, 303};
fwrite(arr, sizeof(arr), 1, fp);
```

This writes the entire array into the file.

Example 3: Writing some elements of array

```c
int arr[3] = {101, 203, 303};
fwrite(arr, sizeof(int), 2, fp);
```

This writes only the first two elements of the array into the file.

Example 4: Writing structure

```c
typedef struct {
    char name[10];
    int roll;
    float marks;
} Student;

Student s1 = {"Jhon", 12, 88.123};
fwrite(&s1, sizeof(s1), 1, fp);
```

This writes contents of variable `s1` into the file.

Example 5: Writing array of structure


```c
Student students[3] = {
        {"Tina", 12, 88.123},
        {"Jack", 34, 71.182},
        {"May", 12, 93.713}};
fwrite(students, sizeof(students), 1, fp);
```

This writes the whole array students into the file.

Let's say we don't' want to write all elements of the array into the file, instead, we want is to write only 0th and 1st element of the array into the file.

```c
fwrite(students, sizeof(struct student), 2, fp);
```

```c
typedef struct Student {
    char name[50];
    int age;
} Student;

int main() {
    int n, i, chars;
    FILE *fp;

    fp = fopen("student.txt", "wb");

    printf("Enter the number of student: ");
    scanf("%d", &n);

    Student s;
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d \n", i + 1);

        while ((getchar()) != '\n')
            ; //
        printf("Name: ");
        gets(s.name);

        printf("Age: ");
        scanf("%d", &s.age);

        chars = fwrite(&s, sizeof(s), 1, fp);
        printf("Number of items written to the file: %d\n", chars);
    }
    fclose(fp);

    FILE *fp_read;
    fp_read = fopen("student.txt", "rb");

    printf(" \nTesting fread() function:\n");
    while (fread(&s, sizeof(s), 1, fp_read) == 1) {
        printf("Name: %s \n", s.name);
        printf("Age: %d \n", s.age);
    }
    fclose(fp_read);

    return 0;
}
```

```texts
Enter the number of student: 2

Enter details of student 1
>>Name: jhon
>>Age: 20
Number of items written to the file: 1

Enter details of student 2
>>Name: rock
>>Age: 33
Number of items written to the file: 1

Testing fread() function:
Name: jhon
Age: 20
Name: rock
Age: 33
```

## Example

### Copy file

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp_in, *fp_out;
    char *input_file = "main.jpg";
    char *output_file = "copied.jpg";
    // char ch;
    int ch; // `fgetc` returns int!! -> see the difference with `char ch`;

    fp_in = fopen(input_file, "rb");
    if (!fp_in) {
        perror("Error ");
        return EXIT_FAILURE;
    }

    fp_out = fopen(output_file, "wb");

    while ((ch = fgetc(fp_in)) != EOF)
        fputc(ch, fp_out);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
```

### File size

```c
#include <stdio.h>
int main() {
    FILE *fp;
    char *input_file = "main.jpg";
    fp = fopen(input_file, "rb");

    fseek(fp, 0, SEEK_END);  // move to the file end
    double size = ftell(fp); // ftell() returns the current file position of the specified stream with respect to the starting of the file.

    printf("File Size: %.2f bytes\n", size);
    printf("File Size: %.2f Kb\n", size / 1024);
    return 0;
}
```
