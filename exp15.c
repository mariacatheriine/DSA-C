#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
char peek(Stack *s){
    return s->data[s->top];
}
void push(Stack *s, char ch){
    if (s->top == MAX -1){
        printf("stack overflow\n");
        return;
    }
    s->data[++(s->top)] = ch;
}
char pop(Stack *s){
    if (isempty(s)){
        printf("stack empty\n");
        return '\0';
    }
    return s->data[(s->top)--];
}
int precedence(char op){
    switch (op){
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}
int isrightassociative(char op){
    return op == '^';
}
void infixtopostfix(char *infix, char *postfix){
    Stack s;
    init(&s);
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++){
        char ch = infix[i];
        if (ch == ' '){
            continue;
        }
        if (isalnum(ch)){
            postfix[j++] = ch;
        }
        else if (ch == '('){
            push(&s, ch);
        }
        else if (ch == ')'){
            while (!isempty(&s) && peek(&s) != '('){
                postfix[j++] = pop(&s);
            }
            if (!isempty(&s)){
                pop(&s);
            }
        }
        else{
            while (!isempty(&s) && peek(&s) != '(' && ((precedence(ch) < precedence(peek(&s))) || (precedence(ch) == precedence(peek(&s)) && !isrightassociative(ch)))){
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while (!isempty(&s)){
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}
int main(){
    char infix[MAX], postfix[MAX];
    printf("enter an infix expression: ");
    fgets(infix, sizeof(infix),stdin);
    infix[strcspn(infix, "\n")] = '\0';
    infixtopostfix(infix, postfix);
    printf("postfix expression: %s\n", postfix);
    return 0;
}