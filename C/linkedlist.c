//
// Created by ady on 09.10.2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

callback printF(node* curr, int index){
    printf("Node %d: %d\n", index, curr->data);
}

int main(){
    node* list = create(10, NULL);
    push(&list, 100 );
    push(&list, 1000 );
    push(&list, 1002 );
    push(&list, 1001 );

    prepend(&list, 1005);
    push(&list, 1003 );
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
    free(list);
    return 0;
}

void dispose(node *list) {
    node *curr, *temp;
    curr = list;
    if(list != NULL){
        curr = curr->next;
        list->next = NULL;
        while(curr != NULL){
            temp = curr->next;
            free(curr);
            curr = temp;
        }
    }
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

int count(node *pNode) {
    node* curr = pNode;
    int c = 0;
    while (curr != NULL){
        c++;
        curr = curr->next;
    }
    return c;
}

node *append(node **pNode, int data) {
    node* curr = *pNode;
    while (curr != NULL){
        if(curr->next == NULL){
            node* tmp= create(data, NULL);
            curr->next = tmp;
            break;
        }
        curr = curr->next;
    }
    return *pNode;
}

void display(node **pNode) {
    node* curr = *pNode;
    printf("Nodes:\n");
    while(curr != NULL){
        printf("%d\n", curr->data);
        curr=curr->next;
    }
}

node push(node **pNode, int data) {
    node* tmp = create(data, NULL);
    node* curr = *pNode;

    while(curr != NULL){
        if(curr->next == NULL){
            curr->next = tmp;
            break;
        }
        curr = curr->next;
    }
    return **pNode;
}

node *create(int data, node *next) {
    node *tmp = malloc(sizeof(node) + sizeof(int));
    if(tmp == NULL){
        printf("Could not create new node");
        exit(0);
    }
    tmp->data = data;
    tmp->data = data;

    tmp->next = next;
    return tmp;
}

void prepend(node **pNode, int data){
    node* temp = create(data, *pNode);
    *pNode = temp;
}

void traverse(node* head, callback f){
    int c = 0;
    node* curr = head;
    while (curr != NULL){
        f(curr, ++c);
        curr = curr->next;
    }
}

node* insert_after(node **head, int data, node* prev){
    node* curr = *head;
    while (curr != NULL){
        if(curr == prev){
            node* tmp = create(data, curr->next);
            curr->next = tmp;
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
            node* temp = create(data, prev);
            curr->next = temp;
            break;
        }
        curr = curr->next;
    }
    return *head;
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
                temp->next = e;

            } else {

                e->next = hdata;
                *head = e;
            }
        } else {
            e->next = NULL;
            *head = e;
        }
    }
    free(curr);
    return *head;
}

node* reverse(node** head){
    //TODO: more efficient, don't use another LL, change in place
    node* curr = *head;
    node* temp = NULL;
    while(curr != NULL){
        if(temp != NULL){
           prepend(&temp, curr->data);
        } else {
           temp = create(curr->data, NULL );
        }
        curr = curr->next;
    }
    free(curr);
    *head = temp;
    return *head;
}

node* remove_front(node **head){
    if(*head == NULL) return NULL;
    node* front = *head;
    *head = front->next;
    front->next = NULL;
    if(front == *head) return NULL;
    free(front);
    return *head;
}

node* remove_back(node **head){
    node* curr = *head;
    *head = NULL;
    node* prev;

    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;

        if(*head != NULL){
            append(head, prev->data);
            if(curr->next == NULL){
                break;
            }
        } else {
            *head = create(prev->data, NULL);
        }
    }
    free(curr);
    return *head;
}

node* remove_any(node **head, node* nd){
    if(*head == nd) return remove_front(head);
    if(nd->next == NULL) return remove_back(head);
    node* curr = *head;
    while(curr != NULL){
        if(curr->next == nd) break;
        curr = curr->next;
    }
    if(curr != NULL ){
        node* tmp = curr->next;
        curr->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return *head;
}