#include <stdio.h>
#include <stdlib.h>

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