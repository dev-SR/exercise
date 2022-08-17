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
    int sum = 0;
    int N;
    cin >> N;
    for (; N != 0; N = N / 10) {
        sum += N % 10;
    }
    cout << sum << endl;

    int calories = 0;
    int time_spent = 0;
    int gf_calls_up = 10;

    while (calories < 30) {
        calories++;
        time_spent++;
        cout << "running & burning :" << (calories) << endl;
        if (time_spent == gf_calls_up) {
            cout << "gf called" << endl;
            break;
        }
    }

    calories = 1;

    while (calories < 30) {
        // print "Well Done" and Skip "running & burning" after every 5 calories
        if (calories % 5 == 0) {
            cout << "Well Done" << endl;
            calories++; // don't forget this line->otherwise infinite loop
            continue;
            // skip below lines; go to next iteration
        }
        cout << "running & burning :" << (calories) << endl;
        calories++;
    }

    return 0;
}

/**
 * 			12345  % 10 = 5
 * (N/10)	1234   % 10 =+4
 * (N/10)	123    % 10 =+3
 * (N/10)	12     % 10 =+2
 * (N/10)	1      % 10 =+1
 * (N/10)	0
 */