#include <stdio.h>

#define SIZE 10

int main() {
    int list[SIZE] = {1, 2, 4, 5, 6};
    int n = 5, num, pos;

    printf("Enter number to insert: ");
    scanf("%d", &num);
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n || n >= SIZE) {
        printf("Invalid position or list is full\n");
        return 1;
    }

    for (int i = n; i >= pos; i--)
        list[i + 1] = list[i];

    list[pos] = num;
    n++;

    printf("List after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}

