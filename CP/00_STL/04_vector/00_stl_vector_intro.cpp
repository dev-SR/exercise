#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"

#define debug(x) cerr << #x << " is " << x << endl;
#define print(x) cerr << x << " ";
#define init(arr, val) memset(arr, val, sizeof(arr))
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORe(i, a, b) for (int i = a; i <= b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define FORS(i, a, b, step) for (int i = a; i < b; i += step)
#define RFORS(i, a, b, step) for (int i = a; i >= b; i -= step)

// #define V vector
#define all(a) a.begin(), a.end()

#define pb push_back
#define pp pop_back
#define pf push_front
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
    int i;
}

int main() {
    //initialise and create vector
    vector<int> a;
    vi b(5, 0); //init a vector of zeros(n,0)
    // vi c(b.begin(), b.end());
    vi c(all(b));
    vi d{1, 2, 3, 10, 14};

    // Iterate
    cout << GRN << "vi c(b.begin(),b.end())-> where vi b(5,10)" << endl
         << NC;
    cout << YEL << "for loop:" << endl
         << NC;
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl
         << YEL << "for loop using iterator:" << endl
         << NC;
    for (auto it = b.begin(); it != b.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl
         << YEL << "for each" << endl
         << NC;

    for (int x : d) {
        cout << x << " ";
    }

    // Taking input
    cout << endl
         << "Enter no.:";
    vi v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter " << i + 1 << " th: ";
        int no;
        cin >> no;
        // v.push_back();
        v.pb(no);
    }
    for (int x : v)
        cout << x << " ";
    cout << endl;
    cout << "v.size(): " << v.size() << endl;
    cout << "v.capacity(): " << v.capacity() << endl;
    cout << "v.max_size(): " << v.max_size() << endl;

    return 0;
}