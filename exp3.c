#include <stdio.h>
int searchInRotatedArray(int arr[], int size, int target){
    int low = 0;
    int high = size - 1;
    while (low <= high){
        int mid = (low + high)/2;
        if (arr[mid] == target){
            return mid;
        }
        if (arr[low] <= arr[mid]){
            if (target >= arr[low] && target < arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else {
            if (target > arr[mid] && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
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
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int index = searchInRotatedArray(arr, size, key);
    if (index != -1){
        printf("index of target %d: %d\n", key, index);
    } 
    else{
        printf("target not found.");
    }
    return 0;
}