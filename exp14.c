#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
    int data[MAX];
    int top;
    int minel;
} SpecialStack;
void init(SpecialStack *s){
    s->top = -1;
}
int isempty(SpecialStack *s){
    return s->top == -1;
}
void push(SpecialStack *s, int x){
    if (s->top == MAX -1){
        printf("Stack overflow\n");
        return;
    }
    if (isempty(s)){
        s->data[++(s->top)] = x;
        s->minel = x;
    }
    else if (x >= s->minel){
        s->data[++(s->top)] = x;
    }
    else{
        int encoded = 2*x-s->minel;
        s->data[++(s->top)] = encoded;
        s->minel = x;
    }
}
void pop(SpecialStack *s){
    if (isempty(s)){
        printf("stack underflow\n");
        return;
    }
    int topval = s->data[(s->top)--];
    if (topval < s->minel){
        int originalmin = s->minel;
        s->minel = 2*s->minel - topval;
    }
}
int top(SpecialStack *s){
    if (isempty(s)){
        printf("stack is empty\n");
        return -1;
    }
    int topval = s->data[s->top];
    if (topval < s->minel){
        return s->minel;
    }
    else{
        return topval;
    }
}
int getmin(SpecialStack *s){
    if (isempty(s)){
        printf("stack is empty\n");
        return -1;
    }
    return s->minel;
}
int main(){
    SpecialStack s;
    init(&s);
    push(&s, 3);
    push(&s, 5);
    printf("current min %d\n", getmin(&s));
    push(&s, 2);
    push(&s, 1);
    printf("current min %d\n", getmin(&s));
    pop(&s);
    printf("current min %d\n", getmin(&s));
    return 0;
}