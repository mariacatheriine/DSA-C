#include <stdio.h>
void countingSort(int arr[], int n) {
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int count[max + 1];
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    int output[n];
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d non-negative integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal Array: ");
    displayArray(arr, n);
    countingSort(arr, n);
    printf("Sorted Array: ");
    displayArray(arr, n);
    return 0;
}