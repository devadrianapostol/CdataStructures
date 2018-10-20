//
// Created by ady on 19.10.2018.
//

#include <stdio.h>
#include <stdlib.h>
#include "circularlinkedlist.h"

callback printF(node* curr, int index){
    int prevData = 0;
    int nextData = 0;
    if(curr->previous != NULL){ prevData = curr->previous->data; }
    if(curr->next != NULL){ nextData = curr->next->data; }
    printf("Node %d --> %d       Previous: %d Next: %d\n ", index, curr->data, prevData, nextData);
}

enum {
    FORWARD = 1,
    BACKWARD = 2
};

int main(){
    node* head =  NULL;

    node* list = create(1, NULL, NULL, &head);
    push(&list, 100, &head );
    push(&list, 1000, &head);
    prepend(&list, 99, &head);
    traverse(list,FORWARD, &head, (callback) printF);

    return 0;
}

node* create(int data,node* prev, node *next, node** head){
    node *tmp = malloc(sizeof(node)*2 + sizeof(int));
    if(tmp == NULL){
        printf("Could not create new node");
        exit(0);
    }
    tmp->data = data;
    if(prev == NULL){
        tmp->previous = tmp;
    } else {
        tmp->previous = prev;
    }
    if(next == NULL){
        tmp->next = tmp;
    } else {
        tmp->next = next;
    }
    if(*head == NULL) *head = tmp;
    return tmp;
}

node push(node **pNode, int data, node** head){
    node* tmp = create(data, *pNode, NULL, head);
    node* curr = *pNode;

    node* prev = curr;

    if(curr->next == *head && curr->previous == *head){
        (*head)->next = tmp;
        (*head)->previous = tmp;
        tmp->previous = *head;
        tmp->next = *head;
        return **pNode;
    }

    while(curr->next != *head){

        curr = curr->next;
    }
    if(curr->next == *head){
        // is last one
        tmp->previous = curr;
        curr->next = tmp;
        tmp->next = *head;
        (*head)->previous = tmp;
    }

    return **pNode;
}

void traverse(node* list,int direction, node** head, callback f){
    if(direction == BACKWARD){

    } else if (direction == FORWARD){
        int c = 0;
        node* curr = list;
        while (curr->next != *head){
            f(curr, ++c);
            curr = curr->next;
        }
        f(curr, ++c);
    }
}

void prepend(node **list, int data,node** head ){
    node* temp = create(data, (*head)->previous, *list, head);
    (*head)->previous->next = temp;
    (*head)->previous = temp;
    node* curr = *list;
    curr->previous = temp;
    *head = temp;
    *list = temp;
}