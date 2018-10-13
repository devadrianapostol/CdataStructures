//
// Created by ady on 13.10.2018.
//

#include "xorll.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uintptr_t xor(node **pNode, node **pVoid);

node *curr_next(node *pNode);

int main(){
    node* list = create(10, NULL);
    push(&list, 100);
    /*node* curr = list;
    while(curr != NULL){
        curr = curr_next(curr);
    }*/

   /* uintptr_t lor = xor(&a, 0);
    printf("a = %p, 0, xor = %p\n",&a, lor);

    uintptr_t lor2 = xor(&a, &b);
    printf("a = %p, b= %p, xor = %p\n",&a,&b, lor2);*/

}

node *curr_next(node *pNode) {

}

uintptr_t xor(node **pNode, node **pVoid) {
    if(pVoid == NULL) return (uintptr_t)pNode^0;
    return (uintptr_t)pNode ^ (uintptr_t)pVoid;
}

node *create(int data, uintptr_t npx) {
    node *tmp = malloc(sizeof(node) + sizeof(int));
    if(tmp == NULL){
        printf("Could not create new node");
        exit(0);
    }
    tmp->data = data;
    tmp->npx = npx;

    return tmp;
}

node push(node **pNode, int data) {
    node* tmp = create(data, xor(pNode,(uintptr_t)0));
    node* curr = *pNode;

    node* prev = curr;

    /*if(curr->next != NULL){
        curr = curr->next;
    }*/
    while(curr != NULL){
        //tmp->previous = prev;
        if(curr->npx == NULL){
            curr->npx = xor((node **) *pNode, &tmp);
            break;
        }

        curr = (node *) xor((node **) curr->npx, (uintptr_t) 0);
    }
    return **pNode;
}