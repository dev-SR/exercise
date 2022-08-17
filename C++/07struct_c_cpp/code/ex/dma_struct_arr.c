#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_SUBJECT 3
typedef struct Student {
    char name[50];
    int id;
    char grade[3];
    int marks[TOTAL_SUBJECT];
} Student;

// pass by ref so that we can modify
void calculate_grade(Student *s) {
    float score, sum = 0;
    for (int i = 0; i < TOTAL_SUBJECT; i++) {
        // printf("%d %f\n", s->marks[i], sum);
        sum += s->marks[i];
    }
    score = sum / TOTAL_SUBJECT;
    // printf("%f\n", score);

    if (score >= 80) {
        strcpy(s->grade, "A+");
    } else if (score >= 70) {
        strcpy(s->grade, "A");
    } else if (score >= 60) {
        strcpy(s->grade, "A-");
    } else if (score >= 50) {
        strcpy(s->grade, "B");
    } else if (score >= 40) {
        strcpy(s->grade, "C");
    } else {
        strcpy(s->grade, "F");
    }
}

void printStudent(const Student s[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", s[i].name);
        printf("ID: %d\n", s[i].id);
        printf("Marks:");
        for (int j = 0; j < TOTAL_SUBJECT; j++) {
            printf("%d ", s[i].marks[j]);
        }
        printf("\nGrade: %s\n\n", s[i].grade);
    }
}
void addStudent(Student *s, int nth) {
    nth++;
    printf("[%d]Enter Name:", nth);
    scanf(" %[^\n]", s->name);

    printf("[%d]Enter Id:", nth);
    scanf("%d", &s->id);

    printf("[%d]Enter marks of Phy., Che. Math:", nth);
    for (int j = 0; j < TOTAL_SUBJECT; j++) {
        scanf("%d", &s->marks[j]);
    }
    printf("\n");
}

int main() {

    Student *student_arr;
    int n, mark;
    printf("Enter number of student:");
    scanf("%d", &n);

    // student_arr = (Student *)malloc(n * sizeof(Student));
    student_arr = (Student *)calloc(n, sizeof(Student));

    if (student_arr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    printf("\nEnter %d Student Name:\n", n);
    for (int i = 0; i < n; i++) {
        // printf("Enter Name:");
        // scanf(" %[^\n]", student_arr[i].name);

        // printf("Enter Id:");
        // scanf("%d", &student_arr[i].id);

        // printf("Enter marks of Phy., Che. Math:");
        // for (int j = 0; j < TOTAL_SUBJECT; j++) {
        //     scanf("%d", &student_arr[i].marks[j]);
        // }
        addStudent(&student_arr[i], i);
        calculate_grade(&student_arr[i]);
    }
    printStudent(student_arr, n);
    free(student_arr);
    return 0;
}