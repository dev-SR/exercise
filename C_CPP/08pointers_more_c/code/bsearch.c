#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int key, *item, n = 5;

    int arr[] = {1, 2, 5, 8, 10};
    while (1) {
        printf("Enter the value of the key: ");
        scanf("%d", &key);

        if (key == 0) {
            break;
        }

        item = (int *)bsearch(&key, arr, n, sizeof(int), compare);

        if (item != NULL) {
            printf("%d Found\n", *item);
        } else {
            printf("Item not found in array\n");
        }
    }

    return 0;
}
