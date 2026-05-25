#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;
int isFull() {
    return (front == (rear + 1) % SIZE);
}
int isEmpty() {
    return (front == -1);
}
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}
int dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % SIZE;
    }
    return value;
}
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    int i = front;
    printf("Queue elements are: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
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