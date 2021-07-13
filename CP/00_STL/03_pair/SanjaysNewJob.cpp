#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

/* 
Sort Game//Sanjay’s New Job [codingblocks]


Sanju needs your help! He gets a list of employees with their salary. The maximum salary is 100.

Sanju is supposed to arrange the list in such a manner that the list is sorted
in decreasing order of salary. And if two employees have the same salary, they
should be arranged in lexicographical manner such that the list contains only
names of those employees having salary greater than or equal to a given number x.

Help Sanju prepare the same!

Input Format
On the first line of the standard input, there is an integer x. The next line contains integer N, denoting the number of employees. N lines follow, which contain a string and an integer, denoting the name of the employee and his salary.

Constraints
1 <= N <= 10^5 1 <= | Length of the name | <= 100 1 <= x, salary <= 100

Output Format
You must print the required list.

Sample Input
79
4
Eve 78
Bob 99
Suzy 86
Alice 86

Sample Output
Bob 99
Alice 86
Suzy 86

 */

/*
    Algorithm:
    1. If score are not same: just return the high score [put high score student first]
    2. If score is same:
        a. If name are different, return in lexicographical order.
        b. If name same, .i.e one name is sub-string of other name, return the longer name first.
*/

bool myComp(pair<string, int> p1, pair<string, int> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}
int main() {
    int min_salary, n;
    pair<string, int> emp[10005];
    cin >> min_salary;
    cin >> n;
    string name;
    int salary;
    for (int i = 0; i < n; i++) {
        cin >> name >> salary;
        emp[i].first = name;
        emp[i].second = salary;
    }
    sort(emp, emp + n, myComp);
    for (int i = 0; i < n; i++) {
        if (emp[i].second >= min_salary)
            cout << emp[i].first << " " << emp[i].second << endl;
    }
    return 0;
}
/* 
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

class Student {
    String name;
    Integer score;

    Student(String name, Integer score) {
        this.name = name;
        this.score = score;
    }
}

class SortByScore implements Comparator<Student> {
    @Override
    public int compare(Student student1, Student student2) {
        if (student1.score.equals(student2.score)) {
            if (student1.name.contains(student2.name) || student2.name.contains(student1.name)) {
                return student2.name.compareTo(student1.name);
            }
            return student1.name.compareTo(student2.name);
        }
        return student2.score - student1.score;
    }
}

public class Array_SortGame {
    public static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        int minScore = scanner.nextInt();
        int noOfStudents = scanner.nextInt();
        ArrayList<Student> students = new ArrayList<>();

        while (noOfStudents-- >0) {
            String name = scanner.next();
            Integer score = scanner.nextInt();
            Student student = new Student(name, score);
            students.add(student);
        }

        students.sort(new SortByScore());

        for (Student student : students) {
            if (student.score >= minScore) {
                System.out.print(student.name + " ");
                System.out.println(student.score);
            }
        }
    }
}
*/