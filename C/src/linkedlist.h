//
// Created by ady on 10.10.2018.
//

#ifndef C_LINKEDLIST_H
#define C_LINKEDLIST_H

typedef struct node {
    int data;
    struct node* next;
} node;

typedef void (*callback)(node* data, int index);

node* create(int data, node *next);

node push(node **pNode, int data);

void prepend(node **pNode, int data);

void display(node **pNode);

node *append(node **pNode, int data);

void traverse(node* head, callback f);

int count(node *pNode);

node* insert_after(node **head, int data, node* prev);

node* insert_before(node **head, int data, node* prev);

node* getNode(node** pNode, int i);

node* search(node** head, int data);

node* insertion_sort(node **head);

node* reverse(node** head);

node* remove_front(node **head);

node* remove_back(node **head);

node* remove_any(node **head, node* nd);

void dispose(node *list);

#endif //C_LINKEDLIST_H
