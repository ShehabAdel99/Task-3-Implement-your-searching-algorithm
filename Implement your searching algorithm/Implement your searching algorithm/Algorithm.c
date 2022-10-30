#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include<stdio.h>

// Sorting function that takes an array and sorts it using quick sort method

void quicksort(int number[], int first, int last) {
    int i, j, pivot, temp; // getting our variables ready
    if (first < last) { // check that the first didn't exceed the last
        pivot = first;
        i = first;
        j = last;
        // making the elements less than pivot on the left and the elements greater than it on the right
        while (i < j) {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1); // sorting the left section of the pivot
        quicksort(number, j + 1, last); // sorting the right section of the pivot
    }
}

// Searching function that takes a sorted array and a key to search for in that array using binary search method

int binarySearch(int array[], int x, int low, int high) {
    while (low <= high) { // as long as the low didn't exceed the high continue (as element is not found yet)

        int mid = low + (high - low) / 2; // assigning the middle

        if (array[mid] == x) // check if we had a lucky shot and the key is in the middle
            return mid;

        if (array[mid] < x) // if the middle is greater than the key
            low = mid + 1;  // we neglect the lower part and focus on the new section as our target
        else                // the middle is less than the key
            high = mid - 1; // we neglect the greater part and focus on the new section as our target
    }

    return -1;
}

// Main function

int main() {
    int i, count, number[25];
    // Taking elements from user
    printf("How many elements are you going to enter?\n");
    scanf("%d", &count);
    printf("Enter %d elements\n", count);
    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);
    quicksort(number, 0, count - 1); // Start sorting the elements
    printf("Order of Sorted elements:\n");// preview
    for (i = 0; i < count; i++)
        printf(" %d", number[i]);
    int x;
    // getting the key to look for
    printf("\nwhat is the element you are searching for?\n");
    scanf("%d", &x);
    int result = binarySearch(number, x, 0, (count - 1)); // Start searching for the key
    if (result == -1)
        printf("Not found\n");
    else
        printf("Element is found at index %d\n", result);

    return 0;
}