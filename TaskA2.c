#include <stdio.h>

int main() {
    int arr[6] = {10, 20, 30, 40, 50}; 
    int size = 5;

    // Display 
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }

    //Update 
    arr[2] = 99;
    printf("\nAfter modifying element at index 2:\n");
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }

    //Insert 60 at index 3
    int indexToInsert = 3;
    int newValue = 60;

    for (int i = size; i > indexToInsert; i--) {
        arr[i] = arr[i - 1]; 
    }
    arr[indexToInsert] = newValue;
    size++;

    printf("\nAfter inserting 60 at index 3:\n");
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }

    // Remove the element at index 1
    int indexToDelete = 1;
    for (int i = indexToDelete; i < size - 1; i++) {
        arr[i] = arr[i + 1]; 
    }
    size--; 

    printf("\nAfter deleting element at index 1:\n");
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }

    int indexToSearch = 2;
    printf("\nElement at index %d: %d\n", indexToSearch, arr[indexToSearch]);

}
