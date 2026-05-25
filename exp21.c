#include <stdio.h>
#define SIZE 5
int deque[SIZE];
int front = -1;
int rear = -1;
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}
int isEmpty() {
    return (front == -1);
}
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (front == 0) {
        front = SIZE - 1;
    }
    else {
        front--;
    }
    deque[front] = value;
    printf("%d inserted at front\n", value);
}
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (rear == SIZE - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    deque[rear] = value;
    printf("%d inserted at rear\n", value);
}
int deleteFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -1;
    }
    int value = deque[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
    return value;
}
int deleteRear() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -1;
    }
    int value = deque[rear];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0) {
        rear = SIZE - 1;
    }
    else {
        rear--;
    }
    return value;
}
void display() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    int i = front;
    printf("Deque elements are: ");
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                value = deleteFront();
                if (value != -1)
                    printf("Deleted from front: %d\n", value);
                break;
            case 4:
                value = deleteRear();
                if (value != -1)
                    printf("Deleted from rear: %d\n", value);
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}