#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int Id;
    string Name;
    float GPA = 0.00; // initializing
};

// Recommended
void showStudentRef(Student &student) {
    cout << "[Ref] ID: " << student.Id << " Name: " << student.Name << " GPA:" << student.GPA << endl;
    // we unpack the student object and access its members
    auto [id, name, gpa] = student;
    cout << "[Ref+unpack] ID: " << id << " Name: " << name << " GPA:" << gpa << endl;
}

void showStudentPointer(Student *student) {
    cout << "[Pointer] ID: " << student->Id << " Name: " << student->Name << " GPA:" << student->GPA << endl;
    // we unpack the student object and access its members
    auto [id, name, gpa] = *student;
    cout << "[Pointer+unpack] ID: " << id << " Name: " << name << " GPA:" << gpa << endl;
}

Student getStudent() {
    return {1, "Jhon Snow"};
}

int main() {
    Student s = getStudent();
    showStudentRef(s);
    showStudentPointer(&s);

    // unpacking
    auto [id, name, gpa] = s;
    cout << "ID: " << id << " Name: " << name << " GPA:" << gpa << endl;

    // array of student;
    Student studentArr[2];
    studentArr[0] = {1, "A"};
    studentArr[1] = {2, "B"};

    // ....using vector
    vector<Student> studentVec;
    studentVec.push_back({1, "A"});
    studentVec.push_back({2, "B"});

    for (const auto &student : studentArr)
        cout << student.Name << endl;

    for (const auto &student : studentVec)
        cout << student.Name << endl;

    return 0;
}