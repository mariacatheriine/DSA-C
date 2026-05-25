#include <stdio.h>
#define SIZE 5
int stack1[SIZE];
int stack2[SIZE];
int top1 = -1;
int top2 = -1;
int isFull() {
    return (top1 == SIZE - 1);
}
int isEmpty() {
    return (top1 == -1 && top2 == -1);
}
void push1(int value) {
    stack1[++top1] = value;
}
int pop1() {
    return stack1[top1--];
}
void push2(int value) {
    stack2[++top2] = value;
}
int pop2() {
    return stack2[top2--];
}
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }
    push1(value);
    printf("%d inserted into queue\n", value);
}
int dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return -1;
    }
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
    return pop2();
}
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Deleted element: %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}