#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
    int data[MAX];
    int top;
} Stack;
void init(Stack *s){
    s->top = -1;
}
int isempty(Stack *s){
    return s->top == -1;
}
void push(Stack *s, int value){
    if (s->top == MAX -1 ){
        printf("stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}
int pop(Stack *s){
    if (isempty(s)){
        printf("stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}
int peek(Stack *s){
    if (isempty(s)){
        printf("stack is empty\n");
        exit(1);
    }
    return s->data[s->top];
}
void sortstack(Stack *input){
    Stack temp;
    init(&temp);
    while (!isempty(input)){
        int tempval = pop(input);
        while (!isempty(&temp) && peek(&temp) > tempval){
            push(input, pop(&temp));
        }
        push(&temp, tempval);
    }
    while (!isempty(&temp)){
        push(input, pop(&temp));
    }
}
void display(Stack *s){
    if (isempty(s)){
        printf("stack is empty\n");
        return;
    }
    printf("stack: ");
    for (int i = s->top; i>= 0; i--){
        printf("%d", s->data[i]);
    }
    printf("\n");
}
int main(){
    Stack s;
    init(&s);
    int n, val;
    printf("enter number of elements: ");
    scanf("%d", &n);
    printf("enter elements: \n");
    for (int i = 0; i < n; i++){
        scanf("%d",&val);
        push(&s, val);
    }
        printf("\noriginal stack:\n");
        display(&s);
        sortstack(&s);
        printf("\nsorted stack:\n");
        display(&s);
        return 0;
    
}