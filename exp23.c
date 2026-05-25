#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed into stack\n", data);
}
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}
int peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }
    return top->data;
}
void display() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 3:
                value = peek();
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}