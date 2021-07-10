#include <bits/stdc++.h>
using namespace std;
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define reset "\e[0m"
/* 
! Find minimum number of coins that make a given value:

* Given a value V, if we want to make change for V cents, and we have infinite * supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum 
* number of coins to make the change? If it’s not possible to make change, 
* print -1.

Examples:  

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents

https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

*/
bool compare(int a, int b) {
    return a <= b;
}
int main() {

    //BD money change
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int n = sizeof(coins) / sizeof(int);
    int money = 168;
    //algo:
    /* 
      168-100=68 where 100 is the 
      68-50=18
      18-10....
     */
    while (money > 0) {
        int lb = lower_bound(coins, coins + n, money, compare) - coins - 1;
        //[lb_address - baseaddres - 1]
        // cout << lb << endl;
        int m = coins[lb];
        cout << m << ", ";
        money = money - m;
    }
    //ANS: 100, 50, 10, 5, 2, 1,

    return 0;
}