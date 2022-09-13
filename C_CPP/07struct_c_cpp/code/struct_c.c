#include <stdio.h>

typedef struct Student {
    int id;
    char name[20];
    int cgpa = 0;

} Student;
int main() {
    Student s = {1, "Soikat Rahman"};
    printf("%d", s.id);
    return 0;
}
