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

/* returns XORed value of the node addresses */
struct node* XOR (struct node *a, struct node *b)
{
    return (node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

node *create(int data, node* npx) {
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
    printf("address of list: %p\n", pNode);
    node* head = *pNode;
    node* newnode = create(data, XOR(head,NULL));
    printf("address of new: %p, %d\n", &newnode, ((node*) XOR(head,NULL))->data );

    node* curr = *pNode;

    node* prev = curr;

    /*if(curr->next != NULL){
        curr = curr->next;
    }*/
    while(curr != NULL){
        prev = curr;
        if(curr->npx == NULL){
            curr->npx = XOR(head,newnode);
            //printf("address of new: %p , %d\n", XOR(head,newnode), ((node*)XOR(head, curr->npx))->data);
            break;
        }
        curr = XOR(curr->npx,prev->npx );
    }
    return **pNode;
}