#include <stdio.h>

// create a structure Coordinate
typedef struct Coordinate {
    // declare structure members
    int x, y;
} Coordinate;

typedef struct Student {
    char name[30];
    int age;
    int roll_number;
} Student;

int main() {
    Coordinate first_point;
    // declaring structure pointer
    Coordinate *cp;
    cp = &first_point;

    (*cp).x = 5;
    (*cp).y = 10;

    printf("First coordinate (x, y) = (%d, %d)", (*cp).x, (*cp).y);
    // First coordinate (x, y) = (5, 10)

    Student student_1;
    Student *sp = &student_1;
    printf("Enter the details of the Student (student_1)\n");
    printf("\tName: ");
    scanf("%s", sp->name);
    printf("\tAge: ");
    scanf("%d", &sp->age);
    printf("\tRoll Number: ");
    scanf("%d", &sp->roll_number);

    printf("\n Display the details of the student_1 using Structure Pointer\n");
    printf("\tName: %s\n", sp->name);
    printf("\tAge: %d\n", sp->age);
    printf("\tRoll Number: %d", sp->roll_number);
}
