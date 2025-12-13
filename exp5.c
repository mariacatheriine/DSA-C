#include <stdio.h>
void insertionSort(int arr[], int size){
    for (int i = 1; i <= size - 1; i++){
        int temp = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    insertionSort(arr, size);
    printf("array after sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
