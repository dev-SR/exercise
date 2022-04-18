#include <bits/stdc++.h>
using namespace std;
/**
 * Given a string rotate it by N characters. e.g. if the string
 * is 'CodingBlocks' and n=3 then the Output should be 'cksCodingBlo'
 * 
 * Hello\0
 * 1st right shift:
 * ->
 * HeHello\0
 * 2nd i is now at \0 so, rotate from i-k to i-1
 * loHello\o
*/

void rotate(char *a, int k) {
    int i = strlen(a);
    //right shift
    while (i >= 0) {
        a[i + k] = a[i];
        i--;
    }
    i = strlen(a);
    // rotate: from i-k to i-1
    int j = i - k;
    int s = 0;
    while (j < i) {
        a[s] = a[j];
        s++;
        j++;
    }
    a[i - k] = '\0';
}

int main() {
    char a[100] = "Coding Blocks";
    int k = 3;
    rotate(a, k);
    cout << a << endl;
}