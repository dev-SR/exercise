#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

void watchVideo(int views) {
    views = views + 1;
}

// pass by reference
void applyTax(int &income) {
    float tax = 0.1;
    income = income - (income * tax);
}
int main() {
    int income = 100;
    applyTax(income);
    cout << "Income after tax: " << income << endl; // 100
}