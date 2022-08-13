#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include<stdio.h>

void quicksort(int number[], int first, int last) {
    int i, j, pivot, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
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
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
//int binarySearch(int arr[], int x , int l, int r)
//{
//    if (r >= l) {
//        int mid = l + (r - l) / 2;
//
//        // If the element is present at the middle
//        // itself
//        if (arr[mid] == x)
//            return mid;
//
//        // If element is smaller than mid, then
//        // it can only be present in left subarray
//        if (arr[mid] > x)
//            return binarySearch(arr, l, mid - 1, x);
//
//        // Else the element can only be present
//        // in right subarray
//        return binarySearch(arr, mid + 1, r, x);
//    }
//
//    // We reach here when element is not
//    // present in array
//    return -1;
//}

int binarySearch(int array[], int x, int low, int high) {
    // Repeat until the pointers low and high meet each other
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        if (array[mid] == x)
            return mid;

        // If element is larger than mid, then
        // it can only be present in right subarray
        if (array[mid] < x)
            low = mid + 1;
        // Else the element can only be present
        // in left subarray
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int i, count, number[25];
    printf("How many elements are you going to enter?\n");
    scanf("%d", &count);
    printf("Enter %d elements\n", count);
    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);
    quicksort(number, 0, count - 1);
    printf("Order of Sorted elements:\n");
    for (i = 0; i < count; i++)
        printf(" %d", number[i]);
    //int n = sizeof(number)/sizeof(int);
    //printf("\nn: %d", n);
    int x;
    printf("\nwhat is the element you are searching for?\n");
    scanf("%d", &x);
    int result = binarySearch(number, x, 0, (count - 1));
    if (result == -1)
        printf("Not found\n");
    else
        printf("Element is found at index %d\n", result);

    return 0;
}