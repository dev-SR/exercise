#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

// allocate memory dynamically for 1d array
int *allocateMemory(int n) {
    int *arr = new int[n];
    return arr;
}
// take input
int *takeInput(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// delete dynamically allocated 1d array
void delete1d(int *arr) {
    delete[] arr;
    cout << "Deleted !!!\n";
}

// generate random array dynamically
int *generateRandomArray(int n) {
    // Use current time as seed for random generator
    srand(time(0)); // or time(NULL);
    /**
        Note: Without first calling srand(), program will create the same sequence of numbers each time it runs.
    */
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

void display(int *p, int n) {
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *p = allocateMemory(n);
    p = takeInput(p, n);
    display(p, n);
    delete1d(p);
    //
    cout << "Generating random array of size " << n << endl;
    p = generateRandomArray(n);
    display(p, n);
    delete1d(p);
}
