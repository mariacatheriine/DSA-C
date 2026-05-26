#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}
void insertHeap(int heap[], int* size, int value) {
    int i = (*size)++;
    heap[i] = value;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
int extractMin(int heap[], int* size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return root;
}
int maxActivityPoints(int A[], int n, int k) {
    int heap[100];
    int size = 0;
    for (int i = 0; i < n; i++) {
        insertHeap(heap, &size, A[i]);
        if (size > k) {
            extractMin(heap, &size);
        }
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += heap[i];
    }
    return sum;
}
int main() {
    int n, k;
    printf("Enter number of events: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter activity points:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Enter maximum number of events allowed: ");
    scanf("%d", &k);
    int result = maxActivityPoints(A, n, k);
    printf("Maximum Activity Points = %d\n", result);
    return 0;
}