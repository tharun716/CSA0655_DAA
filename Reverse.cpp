#include <stdio.h>
#include <string.h>  
void reverseString(char *str, int index) {
    if (str[index] == '\0') {
        return;
    }
    reverseString(str, index + 1);
    putchar(str[index]);
}
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("The reversed string is: ");
    reverseString(str, 0);
    printf("\n");
    return 0;
}

