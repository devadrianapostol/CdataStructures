#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

/*
    enqueue an element into stack
*/
node* push(node *head, int data){
    node* temp = malloc(sizeof(node));
    if(temp == NULL){
        printf("Could not create node");
        exit(0);
    }
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

node* pop(node* head){
    head = head->next;
    return head;
}

void display(node* head){
    node* curr = head;
    if(head->next == NULL){
        printf("Stack is empty");
    }
    printf("Stack: \n");
    while(curr != NULL){
        printf("%d\n", curr->data);
        curr=curr->next;
    }

}

void init(node* head){
    head = NULL;
}

int main(){
    node* head;
    init(head);

    int i;
    for(i=0;i<=50;i++){
        head = push(head, i);
    }
    /*head = push(head, 5);
    head = push(head, 10);
    head = push(head, 20);
    head = enqueue(head, 30);*/
    display(head);

    return 0;
}