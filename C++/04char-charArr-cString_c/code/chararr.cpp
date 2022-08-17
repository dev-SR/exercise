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
    // char name[]{"Jhon"};                       // (invalid in c )
    // <-- string literal
    // char name2[] = "Jhon";                     // <-- string literal
    // char name3[] = {'J', 'h', 'o', 'n', '\0'}; // <-- char array ; explicit null
    // termination is required

    // uses loop to print whole array
    //  cout << name << endl;
    // cout << strlen(name) << endl; // 4

    // in c
    //   printf("%s\n", name2);
    //  printf("%s\n", name3);

    // char greeting[100];
    //  char username[20];
    // char fullName[100];
    //  cin >> username;          // << dev-sr new
    // cout << username << endl; // >> dev-sr
    // discards the input buffer
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // cin.getline(fullName, 100); // << soikat rahman
    // cout << fullName << endl;   // >> soikat rahman
    //  cin.getline(greeting, 100, '.');
    // cout << endl
    //      << greeting << endl; //

    char name[100];
    // name = "Jhon"; // error: char[100] is not assignable
    strcpy(name, "Jhon");
    cout << name << endl; // Jhon
    strcat(name, " Smith");
    cout << name << endl; // Jhon Smith

    // char sentence[100] = "I love reading books on science";
    // char word[100];
    // cin >> word; // books

    /*
        cout << strstr(sentence, word); // books on science

        strstr() returns a `pointer` to the first occurrence of the substring in the string.
        That's why it print `books on science`
    */

    // char *output = strstr(sentence, word);
    // if (output != NULL) {
    //     cout << word << " is found" << endl;
    // } else {
    //     cout << "Not found" << endl;
    // }

    char a[] = "hello";
    // a = "new";
    a[0] = 'n';
    a[1] = 'e';
    a[2] = 'w';
    a[3] = '\0';
    // cin >> a;
    // cout << a << endl;
    // char *p = "Hello";
    // cin >> p;
    // *(p + 1) = 'H'; // wrong, "hello" is in read-only data-segment, we cannot change
    // cout << p << endl;

    char options[][10] = {"MEDIUM", "HARD", "EASY"};

    string op[] = {"MEDIUM", "HARD", "EASY"};
    char choose[10];
    cin >> choose;
    for (int i = 0; i < 4; i++) {
        if (strcmp(choose, op[i].c_str()) == 0) {
            cout << "You choose: " << options[i] << endl;
            break;
        }
    }
    string ch;
    cin >> ch;
    for (int i = 0; i < 4; i++) {
        if (ch == op[i]) {
            cout << "You choose: " << options[i] << endl;
            break;
        }
    }
}

/*

 */