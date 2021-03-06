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

#define TOFIND 3

int main(){
    node* head =  NULL;

    node* list = create(1, NULL, NULL, &head);
    push(&list, 100, &head );
    push(&list, 1000, &head);
    prepend(&list, 99, &head);
    traverse(list,FORWARD, &head, (callback) printF);
    display(&list, &head);
    append(&list->next, 19999, &head);
    insert_after(&list, 2, getNode(&list, 5, &head), &head );
    insert_before(&list, 3, getNode(&list, 3, &head), &head);
    traverse(list,FORWARD, &head, (callback) printF);

    printf("Nr of nodes: %d\n", count(list, &head));

    node* found = search(&list, TOFIND, &head);

    if( found != NULL ) {
        printf("Search for %d: %d\n", TOFIND, found->data );
    } else {
        printf("Node with data: %d not found",TOFIND );
    }

    printf("insertion sort...\n");
    list = insertion_sort(&list, &head);
    traverse(list,FORWARD, &head, (callback) printF);


    /*printf("reverse...");
    list = reverse(&list, &head);
    traverse(list,FORWARD, &head, (callback) printF);

    printf("remove front...\n");
    remove_front(&list, &head);
    traverse(list,FORWARD, &head, (callback) printF);

    printf("remove back...\n");
    remove_back(&list, &head);
    traverse(list,FORWARD, &head, (callback) printF);

    printf("remove any... node 3: 100 \n");
    remove_any(&list, getNode(&list, 2, &head), &head );
    traverse(list,FORWARD, &head, (callback) printF);*/

    dispose(list, &head);
    free(head);
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

void display(node **list, node** head){
    node* curr = *list;
    printf("Nodes:\n");
    while(curr->next != *head){
        printf("%d\n", curr->data);
        curr=curr->next;
    }
    printf("%d\n", curr->data);
}

node *append(node **list, int data, node** head){
    node* curr = *list;
    while (curr != *head){
        curr = curr->next;
    }
    if(curr == *head){
        node* tmp = create(data, (*head)->previous, (*head), head);
        (*head)->previous->next = tmp;
        (*head)->previous = tmp;
    }
    return *list;
}

int count(node *list, node** head){
    node* curr = list;
    int c = 0;
    while (curr->next != *head){
        c++;
        curr = curr->next;
    }
    c++;
    return c;
}

node* insert_after(node **list, int data, node* prev, node** head){
    if(prev == NULL) return *list;
     node* newNode = create(data, prev, prev->next, head );
     prev->next->previous = newNode;
     prev->next = newNode;
     return *list;
}

node* getNode(node** list, int i, node** head){
    node* curr = *list;
    int c = 1;
    while (curr->next != *head){
        if(c == i){
            return curr;
        }
        c++;

        curr = curr->next;
    }
    c++;
    if(c == i) return  curr;
    return NULL;
}

node* insert_before(node **list, int data, node* prev, node** head){
    if(prev == NULL ) return *list;
    int isHead = prev == *head ? 1 : 0;
    node* newNode;
    newNode = create(data, prev->previous, prev, head);
    prev->previous->next = newNode;
    prev->previous = newNode;
    if(isHead){
        *list = newNode;
    }
    return *list;

}

node* search(node** list, int data, node** head){
    node* curr = *list;
    if((*head)->data == data) return *head;
    while (curr->next != *head){
        if(curr->data == data){
            return curr;
        }
        curr = curr->next;
    }
    if(curr->data == data) return curr;
    free(curr);
    return NULL;
}

node * reverse(node** list, node** head){
    node* curr;
    node* newList;
    curr = *list;
    newList = NULL;
    node* newHead;

    while(curr->next != *head){
        if(newList == NULL){
            newList = create(curr->data, NULL, NULL, head);
            newHead = newList;
        } else {
            prepend(&newList,curr->data, &newHead);
        }
        curr = curr->next;
    }
    prepend(&newList,curr->data, &newHead);

    *head = newHead;
    return newList;
}

node *remove_front(node **list, node **head) {
    if(*list == NULL) return NULL;
    *list = (*list)->next;
    (*list)->previous = (*list)->previous->previous;
    (*list)->previous->next = (*list);
    *head = *list;
    return *list;
}

node *remove_back(node **list, node **head) {
    node* tmp = (*head)->previous;
    (*head)->previous = (*head)->previous->previous;
    (*head)->previous->next = *head;
    free(tmp);
    return *list;
}

void dispose(node *list, node **head) {
    node *curr, *temp;
    curr = list;
    if(list != NULL){
        curr = curr->next;
        list->previous = NULL;
        list->next = NULL;
        while(curr != *head ){
            temp = curr->next;
            free(curr);
            curr = temp;
        }

    }
}

node *remove_any(node **list, node *nd, node **head) {
    if(*head == nd){
        *list = nd->next;
        (*list)->previous = nd->previous;
        (*list)->previous->next = *list;
        *head = *list;
        nd->previous = NULL;
        return *list;
    }

    if(nd->next == *head) return remove_back(list, head);

    node* curr = *list;
    while(curr->next != *head){
        if(curr->next == nd) break;
        curr = curr->next;
    }

    if(curr->next != *head ){

        // curr->next is to be removed
        node* tmp = curr->next;
        curr->next = tmp->next;
        if(curr->next != *head ) curr->next->previous = curr;
        tmp->next = NULL;
        free(tmp);
    }
    return *list;
}

node* insertion_sort(node** list, node** head){
    node* oldHead = *head;
    node* curr = *head;
    node* e;
    node* temp;
    *head = NULL;

    while (curr->next != oldHead){
        e = curr;
        curr=curr->next;
        if(*head != NULL){
            node* hdata = *head;
            //TODO : losing last node
            if(e->data > (*head)->data ){
                temp = *head;

                while( (temp->next != (*head)) && (e->data > temp->next->data)){
                    temp = temp->next;
                }

                e->next = temp->next;
                e->previous = temp;

                temp->next = e;

                e->next->previous = e;
                //if(e->next != (*head)) e->next->previous = e;


            } else {
                // e->data < hdata->data - prepend to head
                e->previous = (*head)->previous;
                e->previous->next = e;
                (*head)->previous = e;
                e->next = (*head);
                *head = e;

            }
        } else {
            e->next = e;
            e->previous = e;
            *head = e;
        }
    }
    free(curr);

    return *head;
}
