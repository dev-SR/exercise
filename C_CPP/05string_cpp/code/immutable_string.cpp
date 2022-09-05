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
    string s = "Hello";
    cout << s << endl;
    s[0] = 'X';
    cout << s << endl; // Xello
    s.append(" World");
    cout << s << endl; // Xello World

    char ch[20] = "Hello";
    ch[0] = 'X';
    printf("%s\n", ch); // Xello
    strcat(ch, " World");
    printf("%s\n", ch); // Xello World
    strcpy(ch, "Hello World");
    printf("%s\n", ch); // Hello World
}