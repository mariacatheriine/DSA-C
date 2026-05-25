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
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int main() {
    Node* head = NULL;
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n > 0) {
        printf("Enter node values:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            insert(&head, value);
        }
    }
    printf("\nOriginal Linked List: ");
    display(head);
    head = reverseList(head);
    printf("Reversed Linked List: ");
    display(head);
    return 0;
}