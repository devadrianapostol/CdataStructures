//
// Created by ady on 12.10.2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "doublelinkedlist.h"
callback printF(node* curr, int index){
    printf("Node %d: %d\n", index, curr->data);
}

enum {
    FORWARD = 1,
    BACKWARD = 2
};

int main(){
    node* list = create(10,NULL, NULL);

    push(&list, 100 );
    push(&list, 1000 );
    push(&list, 1002 );
    push(&list, 1001 );
    prepend(&list, 1005);
    traverse(list,FORWARD, (callback) printF);
    /*push(&list, 1003 );
    append(&list, 19999);
    insert_after(&list, 2, getNode(&list, 1) );
    insert_before(&list, 3, getNode(&list, 5));
    append(&list, 5000);

    traverse(list, (callback) printF);
    printf("Nr of nodes: %d\n", count(list));

    printf("Search for %d: %d\n", 1003, search(&list, 1003)->data );
    insertion_sort(&list);
    traverse(list, (callback) printF);

    printf("reverse....\n" );
    list = reverse(&list);
    traverse(list, (callback) printF);

    printf("remove back...\n");
    remove_back(&list);
    traverse(list, (callback) printF);

    printf("remove any...\n");
    remove_any(&list, getNode(&list, 3) );
    traverse(list, (callback) printF);

    dispose(list);
    free(list);*/

    return 0;
}

node *create(int data,node* prev, node *next) {
    node *tmp = malloc(sizeof(node)*2 + sizeof(int));
    if(tmp == NULL){
        printf("Could not create new node");
        exit(0);
    }
    tmp->data = data;
    tmp->previous = prev;
    tmp->next = next;
    return tmp;
}

void traverse(node* head,int direction, callback f){
    if(direction == BACKWARD){

    } else if (direction == FORWARD){
        int c = 0;
        node* curr = head;
        while (curr != NULL){
            f(curr, ++c);
            curr = curr->next;
        }
    }

}

node push(node **pNode, int data) {
    node* tmp = create(data, *pNode, NULL);
    node* curr = *pNode;

    node* prev = curr;
    if(curr->next != NULL){
        curr = curr->next;
    }
    while(curr != NULL){
        tmp->previous = prev;
        if(curr->next == NULL){
            curr->next = tmp;
            break;
        }

        curr = curr->next;
    }
    return **pNode;
}

void prepend(node **pNode, int data){
    node* temp = create(data, NULL, *pNode);
    node* curr = *pNode;
    curr->previous = temp;
    *pNode = temp;
}