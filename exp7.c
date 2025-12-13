#include <stdio.h>
void merge(int arr[], int low, int mid, int high){
    int b[high-low+1];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j<= high){
        if (arr[i] < arr[j]){
            b[k] = arr[i];
            i++;
        }
        else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid){
        while (j <= high){
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while (i<=mid){
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for (int z = low; z <= high; z++){
        arr[z]=b[z];
    }
}
void mergesort(int arr[], int low, int high){
    if (low < high){
        int mid = (low + mid)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
    mergesort(arr, 0, size-1);
    printf("array after sorting:\n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0; 
}







 





