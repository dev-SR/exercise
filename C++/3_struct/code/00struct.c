#include <stdio.h>
#include <string.h>

typedef struct StudentType {
    int id;
    char name[40];
    // char *name;
    int course_ids[5];
} Student;

typedef struct Profile {
    char *description;
    Student owner;
} Profile;

int main() {
    // Initializing Structures
    Student s1 = {
        .name = "Soikat Rahman",
        .id = 1,
        .course_ids = {201, 202, 203}};

    Profile p = {
        .description = "Student Profile",
        .owner.name = "X",
        .owner = {
            .id = 1,
            .name = "Soikat Rahman",
            .course_ids = {201, 202, 204}}};

    // Assignment
    s1.id = 100;
    // watch out!! assigning to a char arr[]
    // s1.name = "Soikat";
    // error: assignment to expression with array type
    // 		 | s1.name = "Soikat Rahman";
    // strcpy(s1.name, "Soikat Rahman");

    // p.description = "New";
    // p = (Profile){
    //     .description = "Newer",
    //     .owner = {
    //         .name = "A"}

    // };

    printf("ID: %d, Name: %s\n", s1.id, s1.name);          // ID: 1, Name: Soikat Rahman
    printf("%s, Name: %s\n", p.description, p.owner.name); // ID: 1, Name: Soikat Rahman

    for (int i = 0; i < 5; i++) {
        if (s1.course_ids[i])
            printf("course taken: id - %d\n", s1.course_ids[i]);
    }

    return 0;
}
