#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int arr[MAX];
int top1 = -1;
int top2 = MAX;
void push1(int x){
    if (top1 + 1 == top2){
        printf("stack overflow, cannot push\n");
    }
    else{
        top1++;
        arr[top1] = x;
    }
}
void push2(int x){
    if (top1 + 1 == top2){
        printf("stack overflow, cannot push\n");
    }
    else{
        top2--;
        arr[top2] = x;
    }
}
int pop1(){
    if (top1 == -1){
        printf("stack underflow, cannot pop\n");
        return -1;
    }
    else{
        int popped = arr[top1];
        top1--;
        return popped;
    }
}
int pop2(){
    if (top2 == MAX){
        printf("stack underflow, cannot pop\n");
    }
    else{
        int popped = arr[top2];
        top2++;
        return popped;
    }
}
int main(){
    int choice, value;
    printf("1.push 1\n");
    printf("2.push 2\n");
    printf("3.pop 1\n");
    printf("4.pop 2\n");
    printf("5.exit\n");
    while (1){
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("enter value to push: ");
            scanf("%d", &value);
            push1(value);
            break;
            case 2:
            printf("enter value to push: ");
            scanf("%d", &value);
            push2(value);
            break;
            case 3:
            pop1();
            break;
            case 4:
            pop2();
            break;
            case 5:
            exit(0);
            default:
            printf("invalid choice.");
        }
    }
    return 0;
}