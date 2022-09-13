#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string to_string_n(double number, int precision = 2) {
    stringstream ss;
    ss << fixed << setprecision(precision) << number;
    return ss.str();
}

int countWords(string str) {
    // Breaking input into word
    // using string stream
    stringstream s(str);

    // To store individual words
    string word;

    int count = 0;
    while (s >> word)
        count++;
    return count;
}

struct Person {
    string name;
    int age;
    double weight;
};

Person parsePerson(string str) {
    stringstream ss(str);
    Person p;
    string temp;
    getline(ss, temp, ',');
    p.name = temp;
    getline(ss, temp, ',');
    p.age = stoi(temp);
    ss >> p.weight;
    return p;
}

int main() {

    string str = "10 20";
    stringstream ss(str);
    int a, b;
    ss >> a >> b;
    cout << a << "+" << b << "=" << a + b << endl; // 10+20=30

    auto person = parsePerson("John, 23, 80.5");
    cout << person.name << " " << person.age << " " << person.weight << endl; // John 23 80.5

    double number = 123.456789;
    cout << to_string_n(number) << endl;
    string s = "Hello World "
               "Hello Cpp";
    cout << " Number of words are: " << countWords(s); // 4
    return 0;
}