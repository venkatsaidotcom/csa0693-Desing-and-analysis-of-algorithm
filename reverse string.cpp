#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int length;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
     length = strlen(str) - 1;   
    printf("Reversed string: ");
    for (int i = length; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
