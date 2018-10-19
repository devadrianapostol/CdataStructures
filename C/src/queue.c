//
// Created by ady on 09.10.2018.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void init(int* head, int* tail){
    *head = *tail = 0;
}

int empty(int head, int tail){
    return head==tail;
}

void enqueue(int *stack, int *tail, int data){
    if(*tail < MAX){
        stack[(*tail)++] = data;
    } else {
        printf("Queue full\n");
    }

}

void dequeue(int *head){
    (*head)++;
}

void display(int* stack, int head, int tail ){
    int i;
    for(i=head; i < tail; i++){
        printf("%d\n", stack[i]);
    }
}

int full(int tail, int size){
    return tail==size;
}

int main(){
    int head, tail;
    int stack[MAX];

    init(&head, &tail);

    enqueue(stack, &tail, 10);
    dequeue(&head);
    enqueue(stack, &tail, 100);
    dequeue(&head);
    enqueue(stack, &tail, 1000);
    enqueue(stack, &tail, 10000);
    enqueue(stack, &tail, 1000000);
    enqueue(stack, &tail, 2000000);

    //printf("%d\n", tail);
    //printf("Empty : %d\n", empty(&head, &tail));
    display(stack, head, tail);
}