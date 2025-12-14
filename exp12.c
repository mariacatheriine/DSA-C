#include <stdio.h>
#include <stdlib.h>
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
void push(Stack *s, int value){
    if (s->top == MAX-1){
        printf("cannot push\n");
        exit(1);
    }
    else{
        s->data[++(s->top)] = value;
    }
}
int pop(Stack *s){
    if (isempty(s)){
        printf("cannot pop\n");
        exit(1);
    }
    return s->data[(s->top)--];
}
int postfix(char *expr){
    Stack s;
    init(&s);
    for (int i = 0; expr[i] != '\0'; i++){
        char ch = expr[i];
        if (ch == ' '){
            continue;
        }
        if (isdigit(ch)){
            int operand = ch - '0';
            push(&s, operand);
        }
        else if (ch == '+' || ch == '-'|| ch == '*' || ch == '/'){
            int operand1 = pop(&s);
            int operand2 = pop(&s);
            int result;
            switch(ch){
                case '+':
                result = operand1 + operand2;
                break;
                case '-':
                result = operand1 - operand2;
                break;
                case '*':
                result = operand1 * operand2;
                break;
                case '/':
                if (operand1 != 0){
                    result = operand2/operand1;
                }
                else{
                    printf("invalid");
                }
                break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}
int main(){
    char expr[10];
    printf("enter a postfix expression:");
    fgets(expr, sizeof(expr), stdin);
    int result = postfix(expr);
    printf("result: %d\n", result);
    return 0;
}