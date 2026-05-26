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
void display(Node* head, int limit) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < limit) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
        count++;
    }
    printf("\n");
}
int detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}
int main() {
    Node* head = NULL;
    int n, value, pos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }
    printf("Enter position to create loop (-1 for no loop): ");
    scanf("%d", &pos);
    if (pos != -1) {
        Node* loopNode = head;
        Node* tail = head;
        for (int i = 0; i < pos; i++) {
            loopNode = loopNode->next;
        }
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = loopNode;
    }
    int result = detectLoop(head);
    if (result)
        printf("Loop detected\n");
    else
        printf("No loop detected\n");
    return 0;
}