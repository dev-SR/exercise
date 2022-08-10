#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

int main() {
    int marks[100] = {0};

    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    // Assign a value
    marks[0] = -1;

    // Input
    for (int i = 1; i <= n; i++) {
        cout << "Enter the marks of student " << i << ": ";
        cin >> marks[i];
    }

    // Output
    for (int i = 1; i <= n; i++) {
        cout << "Student " << i << " marks: " << marks[i] << endl;
    }
    return 0;
}