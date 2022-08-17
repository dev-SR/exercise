#include <stdio.h>

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

    Student arr[3];
    int n = (sizeof arr / sizeof arr[0]);

    printf("Enter 3 Student Name:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", arr[i].name);
        arr[i].id = i + 1;
    }
    printStudent(arr, n);
    return 0;
}
