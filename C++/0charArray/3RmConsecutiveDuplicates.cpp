#include <bits/stdc++.h>
using namespace std;
//Cccoooding -> coding

/**
 *  c c o o ding
 *  j i [c=c] -> i++
 * 
 *  c c o o ding
 *  j   i [c!=o] -> j++ , a[j]=a[i] , i++
 * 
 *  c o o o ding
 *    j   i 
 * 
 *  c o d ing
 *      
*/

void removeDuplicates(char a[]) {
    int l = strlen(a);
    if (l == 1 or l == 0) {
        return;
    }

    int prev = 0;
    for (int current = 1; current < l; current++) {
        if (a[current] != a[prev]) {
            prev++;
            a[prev] = a[current];
        }
    }
    a[prev + 1] = '\0';
    return;
}
int main() {
    char a[100];
    cin.getline(a, 100);
    removeDuplicates(a);
    cout << a << endl;
}