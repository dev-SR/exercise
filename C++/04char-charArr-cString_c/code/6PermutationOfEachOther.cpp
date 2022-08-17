//https://www.geeksforgeeks.org/check-if-two-strings-are-permutation-of-each-other/

//For example, “abcd” and “dabc” are Permutation of each other.

/**
 * abccb
 * ccbba
 * Yes it is a permutation
*/

/**
Method 1 (Use Sorting) 
1) Sort both strings 
2) Compare the sorted strings 

Method 2 (Count characters) 
This method assumes that the set of possible characters in both strings is small. In the following implementation, it is assumed that the characters are stored using 8 bit and there can be 256 possible characters. 
1) Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0. 
2) Iterate through every character of both strings and increment the count of character in the corresponding count arrays. 
3) Compare count arrays. If both count arrays are same, then return true.

*/

#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
bool arePermutationUsingString() {
    // Create 2 count arrays and initialize
    // all values as 0
    string str1 = "geeksforgeeks";
    string str2 = "forgeeksgeeks";
    int count1[NO_OF_CHARS] = {0};
    int count2[NO_OF_CHARS] = {0};
    int i;

    // For each character in input strings,
    // increment count in the corresponding
    // count array
    for (i = 0; str1[i] && str2[i]; i++) {
        count1[str1[i]]++;
        count2[str2[i]]++;
    }

    // If both strings are of different length.
    // Removing this condition will make the
    // program fail for strings like "aaca"
    // and "aca"
    if (str1[i] || str2[i])
        return false;

    // Compare count arrays
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count1[i] != count2[i])
            return false;

    return true;
}

bool isPermutationByChar(char *s1, char *s2) {
    int l1 = strlen(s1);
    int l2 = strlen(s1);

    if (l1 != l2) {
        return false;
    }

    int freq[26] = {0};

    //add to frequency
    for (int i = 0; i < l1; i++) {
        freq[s1[i] - 'a']++;
    }
    //remove from Frequency
    for (int i = 0; i < l2; i++) {
        freq[s2[i] - 'a']--;
    }

    //Finally check if all frequencies are zero.

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }
    return true;

    //Check for Frequency O
}

int main() {

    char s1[100], s2[100];
    cin >> s1 >> s2;
    if (isPermutationByChar(s1, s2)) {
        cout << "Yes it is a permutation";
    } else {
        cout << "No it is not a permutation";
    }
}
