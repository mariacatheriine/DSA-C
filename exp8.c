#include <stdio.h>
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int start = low;
    int end = high;
    while (start<end){
    while (arr[start] <= pivot){
        start++;
    }
    while (arr[end] > pivot){
        end--;
    }
    if (start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
}
int temp2 = arr[low];
arr[low] = arr[end];
arr[end] = temp2;
return end;
}
void quicksort(int arr[], int low, int high){
    if (low < high){
        int loc = partition(arr, low, high);
        quicksort(arr, low, loc-1);
        quicksort(arr, loc+1, high);
    }
}
int main(){
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements in ascending (sorted) order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, size-1);
    printf("array after sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}