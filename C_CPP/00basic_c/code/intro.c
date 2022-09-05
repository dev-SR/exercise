#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    int a = 10.10, b = 10, sum;
    sum = a + b;
    printf("%d + %d = %d\n", a, b, sum); // 10 + 10 = 20

    int aa = -50.50;
    printf("%d", aa); //-50

    int n;
    double d;

    d = 10.10;
    n = d;
    printf("%d\n", n);  //-5010 [garbage]
    printf("%lf\n", d); // 10.1000

    n = (int)d;
    printf("%d\n", n); // 10

    d = n;
    printf("%lf\n", d); // 10.1000

    n = 1000020004000503;
    printf("%d\n", n); // 1293636343| warning: overflow in conversion from 'long long int' to 'int' changes value from '1000020004000503' to '1293636343'
    n = -4325987632;
    printf("%d\n", n); // -31020336| warning: overflow in conversion from 'long long int' to 'int' changes value from '-4325987632' to '-31020336' [-overflow]

    char str[] = "HelloWorld";
    printf("%20s\n", str);
    printf("%-20s\n", str);
    printf("%20.5s\n", str);
    printf("%-20.5s\n", str);
    double i = 101.12345;
    printf("%.02lf", i);
    /*
                HelloWorld
    HelloWorld
                Hello
    Hello
    101.12
    */

    return 0;
}
