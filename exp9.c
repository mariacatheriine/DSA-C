#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
    int data[MAX];
    int top;
} Stack;
void initialize(Stack *s){
    s->top = -1;
    printf("stack initialized\n");
}
int isfull(Stack *s){
    return s->top == MAX-1;
}
int isempty(Stack *s){
    return s->top == -1;
}
void push(Stack *s, int x){
    if (isfull(s)){
        printf("stack overflow. cannot push\n");
    }
    else{
        s->top++;
        s->data[s->top] = x;
    }
}
int pop(Stack *s){
    if (isempty(s)){
        printf("stack underflow. cannot pop\n");
        return -1;
    }
    else{
        int popped = s->data[s->top];
        s->top--;
        return popped;
    }
}
int peek(Stack *s){
    if (isempty(s)){
        printf("stack is empty\n");
        return -1;
    }
    else{
        return s->data[s->top];
    }
}
int main(){
    Stack s;
    int choice, value;
    initialize(&s);
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.peek\n");
    printf("4.check if empty\n");
    printf("5.check if full\n");
    printf("6.exit\n");
    while(1){
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
            printf("enter value to push");
            scanf("%d ",&value);
            push(&s,value);
            break;
            case 2:
            pop(&s);
            break;
            case 3:
            value = peek(&s);
            if (value != -1){
                printf("top element is: %d", value);
            }
            break;
            case 4:
            if (isempty(&s)){
                printf("stack is empty");
            }
            else{
                printf("stack is not empty");
            }
            break;
            case 5:
            if (isfull(&s)){
                printf("stack is full");
            }
            else{
                printf("stack is not full");
            }
            break;
            case 6:
            exit(0);
            default:
            printf("invalid choice");
        }
    }
    return 0;
}