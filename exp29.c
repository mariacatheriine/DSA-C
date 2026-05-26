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
int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    int diff;
    Node* ptrA = headA;
    Node* ptrB = headB;
    if (lenA > lenB) {
        diff = lenA - lenB;
        for (int i = 0; i < diff; i++) {
            ptrA = ptrA->next;
        }
    }
    else {
        diff = lenB - lenA;
        for (int i = 0; i < diff; i++) {
            ptrB = ptrB->next;
        }
    }
    while (ptrA != NULL && ptrB != NULL) {
        if (ptrA == ptrB) {
            return ptrA;
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    return NULL;
}
int main() {
    Node* headA = NULL;
    Node* headB = NULL;
    insert(&headA, 1);
    insert(&headA, 2);
    insert(&headA, 3);
    Node* common = createNode(4);
    common->next = createNode(5);
    Node* temp = headA;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = common;
    insert(&headB, 6);
    headB->next = common;
    printf("List A: ");
    display(headA);
    printf("List B: ");
    display(headB);
    Node* intersection = getIntersectionNode(headA, headB);
    if (intersection != NULL)
        printf("Intersection point: %d\n", intersection->data);
    else
        printf("No intersection found\n");
    return 0;
}