#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct{
    char items[MAX];
    int top;
} Stack;
void initialize(Stack *s){
    s->top = -1;
}
int isempty(Stack *s){
    return s->top == -1;
}
void push(Stack *s, char c){
    if (s->top == MAX - 1){
        printf("stack overflow, cannot push\n");
    }
    else{
        s->top++;
        s->items[s->top] = c;
    }
}
char pop(Stack *s){
    if (isempty(s)){
        return '\0';
    }
    else{
        return s->items[(s->top)--];
    }
}
int ismatchingpair(char open, char close){
    return (open == '(' && close ==')') || (open == '{' && close =='}') || (open == '[' && close ==']');
}
int isbalanced(char *expr){
    Stack s;
    initialize(&s);
    for (int i = 0; expr[i] != '\0'; i++){
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '['){
            push(&s, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']'){
            if (isempty(&s)){
                return 0;
            }
            else{
                char top = pop(&s);
                if (!ismatchingpair(top, ch)){
                    return 0;
                }
            }
        }
    }
    return isempty(&s);
}
int main(){
    char expr[100];
    printf("enter an expression with brackets: ");
    scanf("%s", expr);
    if (isbalanced(expr)){
        printf("balanced\n");
    }
    else{
        printf("not balanced\n");
    }
    return 0;
}