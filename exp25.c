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
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}
int getMiddle(Node* head) {
    if (head == NULL) {
        return -1;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main() {
    Node* head = NULL;
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }
    printf("\nLinked List: ");
    display(head);
    int middle = getMiddle(head);
    if (middle != -1)
        printf("Middle element: %d\n", middle);
    return 0;
}