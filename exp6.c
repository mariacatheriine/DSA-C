#include <stdio.h>
void selectionSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++){
        int min = i;
        for (int j = i+1; j < size; j++){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        if (min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
    selectionSort(arr, size);
    printf("array after sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}



