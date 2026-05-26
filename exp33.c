#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Customer {
    char name[50];
    int priority;
};
struct PriorityQueue {
    struct Customer customers[100];
    int size;
};
void enqueue(struct PriorityQueue* pq, char* name, int category) {
    int i = pq->size - 1;
    while (i >= 0 && pq->customers[i].priority > category) {
        pq->customers[i + 1] = pq->customers[i];
        i--;
    }
    strcpy(pq->customers[i + 1].name, name);
    pq->customers[i + 1].priority = category;
    pq->size++;
    printf("%s added to queue\n", name);
}
void dequeue(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue is Empty\n");
        return;
    }
    struct Customer served = pq->customers[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->customers[i] = pq->customers[i + 1];
    }
    pq->size--;
    printf("Served Customer: %s\n", served.name);
}
void display(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Customers in Queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("%s - ", pq->customers[i].name);
        switch (pq->customers[i].priority) {
            case 1:
                printf("Differently Abled");
                break;
            case 2:
                printf("Senior Citizen");
                break;
            case 3:
                printf("Defence Personnel");
                break;
            case 4:
                printf("Ordinary Person");
                break;
        }
        printf("\n");
    }
}
int main() {
    struct PriorityQueue pq;
    pq.size = 0;
    int choice, category;
    char name[50];
    while (1) {
        printf("\n1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Select Category:\n");
                printf("1. Differently Abled\n");
                printf("2. Senior Citizen\n");
                printf("3. Defence Personnel\n");
                printf("4. Ordinary Person\n");
                printf("Enter category: ");
                scanf("%d", &category);
                enqueue(&pq, name, category);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}