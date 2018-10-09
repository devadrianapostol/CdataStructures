#include <stdio.h>
#define MAX 5

void init(int* top){
    *top = 0;
}


void push(int* stack, int *top, int data) {
    stack[(*top)++] = data;
}

int pop(int *stack, int *top){
    return stack[--(*top)];
}

int full(int* top,const int size){
    return *top == size ? 1: 0;
}

void display(int* stack, int* top)
{
    int i = 0;
    for(i;i<*top;i++){
        printf("%d - > %d\n", i ,stack[i]);
    }
}

int empty(int* top){
    return *top == 0 ? 1 : 0;
}

int top(int* stack, int *top){
    return stack[*top];
}

int main() {
    int stack[MAX];
    int top,elem;

    init(&top);
    empty(&top) == 1 ? printf("Empty\n") : printf("Not empty\n");

    push(stack, &top, 13);
    push(stack, &top, 10);
    push(stack, &top, 30);
    push(stack, &top, 130);
    push(stack, &top, 100);

    pop(stack,&top);
    //printf("is full: %d\n",full(&top, MAX));
    display(stack,&top);
    full(&top, MAX) == 1 ? printf("Full\n") : printf("Not full\n");



    return 0;
}