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
    node* head = create(10, NULL);
    head = push(head, 100 );
    head = push(head, 1000 );
    head = push(head, 1002 );
    head = push(head, 1001 );
    head = prepend(head, 1005);
    head = push(head, 1003 );
    head = append(head, 19999);
    head = insert_after(head, 2, getNode(&head, 1));
    head = insert_before(head, 3, getNode(&head, 5));
    head = append(head, 5000);

    traverse(head, (callback) printF);
    printf("Nr of nodes: %d\n", count(head));

    //printf("Search for %d: %d", 1003, search(&head, 1003)->data );
    head = insertion_sort(head);
    traverse(head, (callback) printF);

    printf("reverse....\n" );
    head = reverse(&head);
    traverse(head, (callback) printF);
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
        exit(0);
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
    if(prev == head){
        return prepend(head, data);
    }
    while (curr != NULL){
        if(curr->next == prev){
            node* temp = create(data, prev);
            curr->next = temp;
            break;
        }
        curr = curr->next;
    }
    return head;
}

node* search(node** head, int data){
    node* curr = *head;
    while (curr != NULL){
        if(curr->data == data){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

node * insertion_sort(node *head){
    node* curr = head;
    node* e;
    node* temp;
    head = NULL;

    while (curr != NULL){
        e = curr;
        curr=curr->next;
        if(head != NULL){
            if(e->data > head->data){
                temp = head;
                while( (temp->next != NULL) && (e->data > temp->next->data)){
                    temp = temp->next;
                }
                e->next = temp->next;
                temp->next = e;

            } else {
                e->next = head;
                head = e;
            }
        } else {
            e->next = NULL;
            head = e;
        }
    }

    return head;
}

node* reverse(node** head){
    //TODO: more efficient, don't use another LL, change in place
    node* curr = *head;
    node* temp = NULL;
    while(curr != NULL){
        if(temp != NULL){
           temp = prepend(temp, curr->data);
        } else {
           temp = create(curr->data, NULL );
        }
        curr = curr->next;
    }
    *head = temp;
    return *head;
}

//TODO: test
node* remove_front(node* head){
    if(head == NULL) return NULL;
    node* front = head;
    head = head->next;
    front->next = NULL;
    if(front == head) head = NULL;
    free(front);
    return head;
}

//TODO
node* remove_back(node* head){
    return NULL;
}

//TODO
node* remove_any(node* head,node* nd){
    return NULL;
}