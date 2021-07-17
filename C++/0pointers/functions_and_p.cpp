#include <bits/stdc++.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
using namespace std;
//!Receiving variable's address in functions
void print(int *p) {
    cout << *p << endl; //10
}
void incrementPointer(int *p) {
    p = p + 1;
    //address's been incremented; P now point to a garbage value
    cout << *p << " " << p << " <-- p inside incrementPointer" << endl;
    //6422036 0x61fe18 <-- p inside incrementPointer
}
void increment(int *p) {
    (*p)++;
}

/* 
! Note that a[] for fun is just a pointer even if square brackets are used
! The name of an array acts as a special kind of variable -- a pointer -- which stores the starting address of the array

-   Because an array is not a single item, the array contents are not passed 
    "by value" as we are used to with normal variables.
        -   The normal meaning of "pass by value" is that the actual argument value
            is copied into a local formal parameter variablecin.
        -   In the case of arrays, just the pointer is copied as a parameter.
-   When an array is sent into a function, only its starting address is really sent
-   This means the function will always have access to the actual array sent in
-   Returning an array from a function works similarly, but we need pointers to use
    them well

So, There are 3 ways to declare the function which is intended to receive an array as an argument.

return_type function(type arrayname[])  
return_type function(type arrayname[SIZE])  
return_type function(type *arrayname)  

 */

int fun(int a[], int size) {
    cout << GRN << "SIZE:[fun]: " << NC << sizeof(a) << endl;
    //SIZE:[sum]: 8 <- 'a' is effectively a pointer
    cout << "a[0]: " << a[0] << endl; //1
    cout << "*(a+1): " << *(a + 1);   //2
    cout << endl;

    return 0;
}
int fun2(int *a, int size) {
    cout << GRN << "SIZE:[fun2]: " << NC << sizeof(a) << endl;
    cout << "a[0]: " << a[0] << endl; //1: So, use can use [] as well
    cout << "*(a+1): " << *(a + 1);   //2
    cout << endl;
    return 0;
}
int partialSum(int *a, int size) {
    cout << GRN << "partialSum: " << NC << endl;
    int ans = 0;
    // cout << a[0] << " " << size << endl; //4 2
    for (int i = 0; i < size; i++) {
        ans += a[i];
    }
    return ans;
}
void modifyReceivedArr(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = i;
}

int find_all_occurrences(char str[], char c, int indexes[]) {
    int found = 0;
    char *pstr = str;

    do {
        pstr = strchr(pstr, c);
        if (pstr) {
            int offset = pstr++ - str;
            // pstr++;
            /* 
            char *a = "Hello";
            char *f = strchr(a, 'o');
            printf("%p\n", f);   //00405068
            printf("%p\n", a);   //00405064
            printf("%d", f - a); //4 = offset=(found_address - base_address ) 
            */
            indexes[found++] = offset;
            pstr++;
        }
    } while (pstr); // while (pstr!=NULL)
    return found;
}

void print_occurrences(char str[], int occurrences_indexes[], int found) {
    char pattern[strlen(str) + 1];
    memset(pattern, ' ', sizeof(pattern));
    for (int i = 0; i < found; i++) {
        pattern[occurrences_indexes[i]] = '^';
    }
    pattern[sizeof(pattern) - 1] = '\0';
    printf("%s\n", str);
    printf("%s\n", pattern);
}

int main() {
    int i = 10;
    int *p = &i;
    print(p);

    cout << i << " " << p << endl; //10 0x61fe14
    incrementPointer(p);
    cout << i << " " << p << endl; //10 0x61fe14
    increment(p);
    cout << i << " " << p << endl; //11 0x61fe14

    int a[5] = {1, 2, 3, 4, 5};
    cout << CYN << "The name of an array acts as  a pointer" << NC << endl;
    cout << GRN << "SIZE:[main]: " << NC << sizeof(a) << endl;
    //SIZE:[main]: 40
    fun(a, sizeof(a) / sizeof(a[0]));
    fun2(a, sizeof(a) / sizeof(a[0]));
    int len = sizeof(a) / sizeof(a[0]);

    //!Only, the Partial parts of an array can be passed
    cout << CYN << "passing parital array" << NC << endl;
    cout << partialSum(a + 3, len - 3) << endl; // 9 [4+5]

    cout << CYN << "functions have access to the actual array sent in and can modify it" << NC << endl;

    /* 
    When an array is sent into a function, only its starting address is really sent
    This means the function will always have access to the actual array sent in and
    can modify the array

    In our case - `occurrences_indexes` is modified inside  `find_all_occurrences` function.
     */
    int ar[5];
    int n = sizeof(ar) / sizeof(int);
    modifyReceivedArr(ar, n);
    for (int i = 0; i < n; i++) {
        printf("%d", ar[i]);
    }
    printf("\n");
    cout << CYN << "EX:" << NC << endl;

    char str[] = "This, is a. sample-string";
    int occurrences_indexes[sizeof(str)];
    int found = find_all_occurrences(str, 's', occurrences_indexes);
    print_occurrences(str, occurrences_indexes, found);
}