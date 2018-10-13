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
    uintptr_t npx;
} node;
node *create(int data, unsigned long npx);

node push(node **pNode, int data);

#endif //C_XORLL_H
