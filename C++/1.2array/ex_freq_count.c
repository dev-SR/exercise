#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    // int marks[100] = {0};
    int total_marks[] = {86, 78, 94, 88, 86, 65, 64, 62, 72, 61, 72, 66, 65, 67, 88, 84, 64, 85, 86, 68, 90, 65};
    int n = sizeof(total_marks) / sizeof(total_marks[0]);
    int marks_count[100] = {0};
    // for (int i = 0; i < 100; i++) {
    //     marks_count[i] = 0;
    // }
    for (int i = 0; i < n; i++) {
        marks_count[total_marks[i]]++;
        // or
        // mark = total_marks[i];
        // marks_count[mark]++;
    }
    for (int i = 0; i < 100; i++) {
        printf("Marks: %d Count:%d\n", i, marks_count[i]);
    }
    return 0;
}
