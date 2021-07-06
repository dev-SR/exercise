#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"
class Book {
public:
    string name;
    int price;
    Book() {
    }
    Book(string name, int price) {
        this->name = name;
        this->price = price;
    }
};

//Comparator Class
class BookCompare {
public:
    bool operator()(Book A, Book B) {
        if (A.name == B.name) {
            return true;
        }
        return false;
    }
};

// templates+iterators+comparators
// template <class ForwardIterator , class T, class Compare>
template <class FI, class T, class C>
FI search(FI start, FI end, T key, C cmp) {
    while (start != end) {
        // if (*start == key) {
        if (cmp(*start, key)) {
            return start;
        }
        start++;
    }
    return end;
}

int main() {

    Book b1("C++", 100);
    Book b2("Java", 300);
    Book b3("Python", 200);

    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book bookToFind("C++", 100);

    BookCompare cmp;
    list<Book>::iterator it = search(l.begin(), l.end(), bookToFind, cmp);
    // auto it = search(l.begin(), l.end(), bookToFind, cmp);
    if (it != l.end()) {
        cout << "Book Found";
    } else
        cout << "Book Not found";

    return 0;
}