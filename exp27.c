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
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}
Node* rotate(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    int n = 1;
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        n++;
    }
    k = k % n;
    if (k == 0) {
        return head;
    }
    Node* temp = head;
    for (int i = 1; i < k; i++) {
        temp = temp->next;
    }
    Node* newHead = temp->next;
    temp->next = NULL;
    tail->next = head;
    return newHead;
}
int main() {
    Node* head = NULL;
    int n, value, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }
    printf("Enter value of k: ");
    scanf("%d", &k);
    printf("\nOriginal Linked List: ");
    display(head);
    head = rotate(head, k);
    printf("Rotated Linked List: ");
    display(head);
    return 0;
}