#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[100];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << endl;
    // {0,0} {0,1} {0,2}    :[0-2][j=i=0 ->j++]
    // {1,1} {1,2}          :[1-2][j=i=1 ->j++]
    // {2,2}                :[2-2][j=i=2 ->j++]
    //Generating All Subarray
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "printing in range :{" << i << "," << j << "}"
                 << " -> ";
            //Print all from i to j
            //Elements of subarray(i,j)
            for (int k = i; k <= j; k++) {
                cout << a[k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
/**
 *
IN: 3
IN: 1 2 3

OUT:
{0,0} 1     
{0,1} 1 2   
{0,2} 1 2 3 

{1,1} 2     
{1,2} 2 3   

{2,2} 3  
*/