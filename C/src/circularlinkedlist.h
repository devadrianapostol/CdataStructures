//
// Created by ady on 19.10.2018.
//

#ifndef C_CIRCULARLINKEDLIST_H
#define C_CIRCULARLINKEDLIST_H

typedef struct node {
    int data;
    struct node* previous;
    struct node* next;
} node;

typedef void (*callback)(node* data, int index);

node* create(int data,node* prev, node *next, node** head);

node push(node **pNode, int data, node** head);

void traverse(node* list,int direction, node** head, callback f);

void prepend(node **list, int data,node** head );

void display(node **list, node** head);

node *append(node **list, int data, node** head);

int count(node *list, node** head);

node* insert_after(node **list, int data, node* prev, node** head);

node* insert_before(node **list, int data, node* prev, node** head);

node* getNode(node** list, int i, node** head);

node* search(node** list, int data, node** head);

node * reverse(node** list, node** head);

node* remove_front(node **list, node** head);

node* remove_back(node** list, node** head);

node* remove_any(node** list, node* nd, node** head);

void dispose(node* list, node** head);

node* insertion_sort(node** list, node** head);

#endif //C_CIRCULARLINKEDLIST_H
