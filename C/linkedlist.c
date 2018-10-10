//
// Created by ady on 09.10.2018.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create(int data, void *next);

node* push(node *pNode, int data);

node* prepend(node* pNode, int data);

void display(node **pNode);

node *append(node *pNode, int data);

typedef void (*callback)(node* data, int index);

void traverse(node* head, callback f);

int count(node *pNode);

callback printF(node* curr, int index){
    printf("Node %d: %d\n", index, curr->data);
}

node* insert_after(node* head, int data, node* prev);

node* insert_before(node* head, int data, node* prev);

node * getNode(node **pNode, int i);

int main(){
    node* head = create(10, NULL);
    head = push(head, 100 );
    head = push(head, 1000 );
    head = push(head, 1001 );
    head = push(head, 1002 );
    head = prepend(head, 1005);
    head = push(head, 1003 );
    head = append(head, 19999);
    head = insert_after(head, 2, getNode(&head, 1));
    head = insert_before(head, 3, getNode(&head, 5));
    head = append(head, 5000);

    traverse(head, (callback) printF);
    printf("Nr of nodes: %d\n", count(head));
    return 0;
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

node *append(node *pNode, int data) {
    node* curr = pNode;
    while (curr != NULL){
        if(curr->next == NULL){
            node* tmp= create(data, NULL);
            curr->next = tmp;
            break;
        }
        curr = curr->next;
    }
    return pNode;
}

void display(node **pNode) {
    node* curr = *pNode;
    while(curr != NULL){
        printf("%d\n", curr->data);
        curr=curr->next;
    }
}

node* push(node *pNode, int data) {
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

node* create(int data, void *next) {
    node* tmp = malloc(sizeof(node));
    if(tmp == NULL){
        printf("Could not create new node");
    }
    tmp->data = data;
    tmp->next = next;
    return tmp;
}

node* prepend(node* pNode, int data){
    node* temp = create(data, pNode);
    pNode = temp;
    return pNode;
}

void traverse(node* head, callback f){
    int c = 0;
    node* curr = head;
    while (curr != NULL){
        f(curr, ++c);
        curr = curr->next;
    }
}

node* insert_after(node* head, int data, node* prev){
    node* curr = head;
    while (curr != NULL){
        if(curr == prev){
            node* tmp = create(data, curr->next);
            curr->next = tmp;
        }
        curr = curr->next;
    }
    return head;
}

node* insert_before(node* head, int data, node* prev){
    node* curr = head;
    node* pre;
    if(prev == head){
        return prepend(head, data);
    }
    while (curr != NULL){
        pre = curr;
        curr = curr->next;
        if(curr == prev){
            node* temp = create(data, prev);
            pre->next = temp;
            break;
        }
    }
    return head;
}