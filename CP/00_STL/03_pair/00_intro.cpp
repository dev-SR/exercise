#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"

int main() {
    pair<int, char> p;
    p.first = 10;
    p.second = 'A';

    //another way
    pair<int, char> p2(p);
    cout << p2.first << endl;
    cout << p2.second << endl;

    pair<int, string> p3 = make_pair(100, "Audi");
    cout << p3.first << " " << p3.second << endl;

    //Take input
    int a, b;
    cin >> a >> b;
    pair<int, int> p4 = make_pair(a, b);
    cout << p4.first << " " << p4.second << endl;

    pair<pair<int, int>, string> car;
    car.second = "Audi";
    car.first.first = 10;
    car.first.second = 20;
    cout << car.first.first << endl;
    cout << car.second << endl;
    return 0;
}