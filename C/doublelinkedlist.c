//
// Created by ady on 12.10.2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

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

node *sortedInsert(node *pNode, node *curr, node *pNode1);

int main(){
    node* list = create(10,NULL, NULL);

    push(&list, 100 );
    push(&list, 1000 );
    push(&list, 1002 );
    push(&list, 1001 );
    prepend(&list, 1006);
    prepend(&list, 1005);

    push(&list, 1003 );

    append(&list, 19999);

    insert_after(&list, 2, getNode(&list, 1) );
    insert_before(&list, 3, getNode(&list, 5));

    append(&list, 5000);

    traverse(list,FORWARD, (callback) printF);
    printf("Nr of nodes: %d\n", count(list));

    printf("Search for %d: %d\n", 1003, search(&list, 1003)->data );
    insertion_sort(&list);
    traverse(list,FORWARD, (callback) printF);

    /*printf("reverse....\n" );
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
        //tmp->previous = prev;
        if(curr->next == NULL){
            tmp->previous = curr;
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

node *append(node **pNode, int data){
    node* curr = *pNode;
    while (curr != NULL){
        if(curr->next == NULL){
            node* tmp= create(data,NULL, NULL);
            tmp->previous = curr;
            curr->next = tmp;
            break;
        }
        curr = curr->next;
    }
    return *pNode;
}

node* getNode(node **pNode, int i) {
    node* curr = *pNode;
    int c = 0;
    while (curr != NULL){
        if(c == i-1){
            return curr;
        }
        c++;
        curr = curr->next;
    }
    return NULL;
}

node* insert_after(node **head, int data, node* prev){
    node* curr = *head;
    while (curr != NULL){
        if(curr == prev){
            node* tmp = create(data, curr, curr->next);
            curr->next = tmp;
            curr->next->previous = curr;
            tmp->next->previous = tmp;
        }
        curr = curr->next;
    }
    //free(curr);
    return *head;
}

node* insert_before(node **head, int data, node* prev){
    node* curr = *head;
    if(prev == *head){
        prepend(head, data);
        return *head;
    }
    while (curr != NULL){
        if(curr->next == prev){
            node* temp = create(data,curr, prev);
            curr->next = temp;
            temp->next->previous = temp;
            break;
        }
        curr = curr->next;
    }
    return *head;
}

int count(node *pNode) {
    node* curr = pNode;
    int c = 0;
    while (curr != NULL){
        c++;
        curr = curr->next;
    }
    return c;
}

node* search(node** head, int data){
    node* curr = *head;
    while (curr != NULL){
        if(curr->data == data){
            return curr;
        }
        curr = curr->next;
    }
    free(curr);
    return NULL;
}

node * insertion_sort(node **head){
    node* curr = *head;
    node* e;
    node* temp;
    *head = NULL;

    while (curr != NULL){
        e = curr;
        curr=curr->next;
        if(*head != NULL){
            node* hdata = *head;
            if(e->data > hdata->data ){
                temp = *head;
                while( (temp->next != NULL) && (e->data > temp->next->data)){
                    temp = temp->next;
                }

                e->next = temp->next;
                e->previous = temp;

                temp->next = e;
                if(e->next != NULL) e->next->previous = e;

            } else {
                e->previous = NULL;
                hdata->previous = e;
                e->next = hdata;
                *head = e;
            }
        } else {
            e->next = NULL;
            //e->previous = NULL;
            *head = e;
        }
    }
    free(curr);
    return *head;
}