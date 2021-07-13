#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

#define all(a) a.begin(), a.end()
#define print(x) cerr << x;

template <class X>
void println(X a) {
    cout << a << endl;
}
template <class X, class C>
void println(X a, C color) {
    cout << color << a << NC << endl;
}
#define FOR(v)            \
    for (int i : v)       \
        cout << i << " "; \
    cout << endl;

#define pb push_back
#define pp pop_back
#define pf push_front
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    vector<int> v{1, 2, 3, 4, 10, 14};
    // Push back O(1) for most of the time

    println("v.push_back(v):", GRN);
    v.push_back(16);
    FOR(v);
    // Insert some in pos
    println("v.insert(i,v):", GRN);
    v.insert(v.begin() + 3, 100); //  insert 100 at 3rd index
    FOR(v);

    println("v.insert(i,n,v):", GRN);
    v.insert(v.begin() + 3, 4, 100); // four 100s at 3rd index
    FOR(v);

    // Pop  back/ Removes the last element O(1)
    println("v.pop_back():", GRN);
    v.pop_back();
    FOR(v);

    // Erase some element in the middle
    println("v.erase(si):", GRN);
    v.erase(v.begin() + 2);
    FOR(v);

    println("v.erase(si,ei):", GRN);
    v.erase(v.begin(), v.begin() + 5);
    FOR(v);

    println("v.clear()", GRN);
    v.clear();

    println("v.empty()", GRN);
    if (v.empty())
        println("Empty");

    vi vv;
    int n;
    print("Enter n:");
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        vv.pb(val);
        // capacity double at 2^n i.e  for el=4 cap=4,el=5 cap=8, el=17 cap=32
        cout << "Changing capcity " << vv.capacity() << endl;
    }
    // to avoid doubling ,we will use reserve()
    vv.clear();
    vv.reserve(100);
    print("Enter n:");
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        vv.pb(val);
        // capacity double at 2^n i.e  for el=4 cap=4,el=5 cap=8, el=17 cap=32
        cout << "Changing capcity " << vv.capacity() << endl;
    }
    return 0;
}