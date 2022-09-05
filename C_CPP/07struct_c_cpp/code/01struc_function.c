#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int id;
} Student;

// pass by value
void printStudent(const Student s) {
    printf("Name: %s, ID: %d\n", s.name, s.id);
}

// pass by reference
void changeStudent(Student *s) {
    s->id = 1;
    strcpy(s->name, "Soikat Rahman");
}

int main() {
    Student student1 = {.id = 101, .name = "Soikat"}; // initialising the object

    // passing by value
    printStudent(student1);
    // passing by reference
    changeStudent(&student1);

    printStudent(student1);
}
