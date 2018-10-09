//
// Created by ady on 09.10.2018.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node *create(int data, void *next);

node *push(node *pNode, int data);

void display(node **pNode);

int main(){
    node* head = create(10, NULL);
    head = push(head, 100 );
    head = push(head, 1000 );
    head = push(head, 1001 );
    head = push(head, 1002 );
    head = push(head, 1003 );

    display(&head);
    return 0;
}

void display(node **pNode) {
    node* curr = *pNode;
    while(curr != NULL){
        printf("%d\n", curr->data);
        curr=curr->next;
    }
}

node *push(node *pNode, int data) {
    node* tmp = create(data, NULL);
    node* curr = pNode;

    while(curr != NULL){
        if(curr->next == NULL){
            curr->next = tmp;
            break;
        }
        curr = curr->next;
    }

    return pNode;
}

node *create(int data, void *next) {
    node* tmp = malloc(sizeof(node));
    if(tmp == NULL){
        printf("Could not create new node");
    }
    tmp->data = data;
    tmp->next = next;
    return tmp;
}

