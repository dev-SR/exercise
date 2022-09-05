#include <stdio.h>
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define NC "\e[0m"
int main() {
    const char *line = "Add  id:324  name:\"john\" name2:\"doe\" num1:2009 num2:5 num3:20";
    char op[32], name[32], name2[32];
    int id, num1, num2, num3;
    int count =
        sscanf(line,
               "%s "
               "id:%d "
               "name:\"%[^\"]\" " /* use "name:%s" if you want the quotes */
               "name2:\"%[^\"]\" "
               "num1:%d "
               "num2:%d "
               "num3:%d ", /* typo? */
               op, &id, name, name2, &num1, &num2, &num3);
    if (count == 7)
        printf("%s %d %s %s %d %d %d\n", op, id, name, name2, num1, num2, num3);
    else
        printf("error scanning line\n");
    return 0;
}
