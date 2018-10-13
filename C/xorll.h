//
// Created by ady on 13.10.2018.
//

#ifndef C_XORLL_H
#define C_XORLL_H

#include <stdint.h>

// Node structure of a memory
// efficient doubly linked list
typedef struct node {
    int data;
    struct node* npx;
} node;
node *create(int data, node* npx);

node push(node **pNode, int data);

#endif //C_XORLL_H
