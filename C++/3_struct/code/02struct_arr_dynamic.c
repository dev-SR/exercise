#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[50];
    int id;
} Student;

void printStudent(const Student arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("name: %s id:  %d\n", arr[i].name, arr[i].id);
    }
}

int main() {

    Student *arr;
    int n;
    printf("Enter number of student:");
    scanf("%d", &n);

    arr = (Student *)malloc(n * sizeof(Student));

    printf("Enter %d Student Name:\n", n);
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", arr[i].name);
        arr[i].id = i + 1;
    }
    printStudent(arr, n);

    free(arr);

    return 0;
}
