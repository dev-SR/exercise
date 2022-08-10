int main() {
    char str[80], ch;
    printf("Enter a word:");
    scanf("%s", str);
    // clearing input buffer; left over "\n" from previous input
    // getchar();
    while ((getchar()) != '\n')
        ; // Discards '\n'
    printf("Enter a char:");
    ch = getchar();
    printf("Word:%s\n", str);
    printf("Char:%c", ch);
    return 0;
}