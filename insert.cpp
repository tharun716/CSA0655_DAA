#include <stdio.h>
#define MAX_SIZE 100 

void insertNumber(int list[], int *size, int number, int position) {
    // Validate the position
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    // Validate if the list is full
    if (*size >= MAX_SIZE) {
        printf("List is full!\n");
        return;
    }
    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }
    // Insert the new number
    list[position] = number;
    (*size)++; 
}

void printList(int list[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE];
    int size = 0, number, position;

    printf("Enter the initial size of the list (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Validate the initial size
    if (size < 0 || size > MAX_SIZE) {
        printf("Invalid size!\n");
        return 1;
    }

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    printf("Enter the number to be inserted: ");
    scanf("%d", &number);

    printf("Enter the position to insert the number (0 to %d): ", size);
    scanf("%d", &position);

    // Insert the number and update the list
    insertNumber(list, &size, number, position);

    // Print the updated list
    printf("Updated list: ");
    printList(list, size);

    return 0;
}

