#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
struct Person {
    int id;
    string name;
    int age;
};

int main() {
    ifstream file;
    file.open("test.csv");
    vector<Person> people;

    if (file.is_open()) {
        string row;
        // ignore the first row
        getline(file, row);

        while (!file.eof()) {
            getline(file, row);
            // cout << row << endl;

            stringstream str_stream(row); // convert string to stream
                                          /*
                                          A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin)
                                           */
            string field;
            Person person;
            getline(str_stream, field, ',');
            if (field.empty())
                continue;
            person.id = stoi(field);
            getline(str_stream, field, ',');
            person.name = field;
            getline(str_stream, field, ',');
            person.age = stoi(field);

            people.push_back(person);
        }
    }
    for (const auto &person : people) {
        cout << person.id << " " << person.name << " " << person.age << endl;
    }

    file.close();

    return 0;
}