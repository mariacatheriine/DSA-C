#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void display(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(Node* heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && heap[left]->data < heap[smallest]->data)
        smallest = left;
    if (right < size && heap[right]->data < heap[smallest]->data)
        smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}
void insertHeap(Node* heap[], int* size, Node* node) {
    int i = (*size)++;
    heap[i] = node;
    while (i != 0 && heap[(i - 1) / 2]->data > heap[i]->data) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
Node* extractMin(Node* heap[], int* size) {
    if (*size <= 0)
        return NULL;
    Node* root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return root;
}
Node* mergeKSortedLists(Node* lists[], int K) {
    Node* heap[100];
    int heapSize = 0;
    for (int i = 0; i < K; i++) {
        if (lists[i] != NULL) {
            insertHeap(heap, &heapSize, lists[i]);
        }
    }
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
    while (heapSize > 0) {
        Node* minNode = extractMin(heap, &heapSize);
        tail->next = minNode;
        tail = tail->next;
        if (minNode->next != NULL) {
            insertHeap(heap, &heapSize, minNode->next);
        }
    }
    tail->next = NULL;
    return dummy.next;
}
int main() {
    int K;
    printf("Enter number of linked lists: ");
    scanf("%d", &K);
    Node* lists[K];
    for (int i = 0; i < K; i++) {
        lists[i] = NULL;
        int n, value;
        printf("Enter number of elements in List %d: ", i + 1);
        scanf("%d", &n);
        printf("Enter elements in sorted order:\n");
        for (int j = 0; j < n; j++) {
            scanf("%d", &value);
            insert(&lists[i], value);
        }
    }
    printf("\nInput Lists:\n");
    for (int i = 0; i < K; i++) {
        printf("List %d: ", i + 1);
        display(lists[i]);
    }
    Node* mergedHead = mergeKSortedLists(lists, K);
    printf("\nMerged Sorted List:\n");
    display(mergedHead);
    return 0;
}