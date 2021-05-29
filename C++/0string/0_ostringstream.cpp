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

    /**
     Output stream class to operate on strings.

    Objects of this class use a string buffer that contains a sequence of characters. This sequence of characters can be accessed directly as a string object, using member str.

    Characters can be inserted into the stream with any operation allowed on output streams.
    */

    //! Concatanating values of different data types into single String buffer

    string s = "Jhon";
    int d = 10;
    ostringstream oss;
    oss << s << " : " << d;

    /**
                                    ------------------
    'oss' stream buffer pipeline ➜ | Jhon : 10       |
                                    ------------------
    */

    //convert back to string
    string str = oss.str();
    cout << GRN << str << endl;
}