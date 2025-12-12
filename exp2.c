#include <stdio.h>
int countRotations(int arr[], int size){
    int low = 0;
    int high = size - 1;
    while (low<=high){
        if (arr[low] <= arr[high]){
            return low;
        }
        int mid = (low + high)/2;
        int next = (mid+1)%size;
        int prev = (mid + size -1)%size;
        if (arr[mid] <= arr[next] && arr[mid]<= arr[prev]){
            return mid;
        }
        if (arr[mid] >= arr[low]){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements in rotated sorted order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int rotations = countRotations(arr, size);
    printf("the array has been rotated %d times", rotations);
    return 0;
}