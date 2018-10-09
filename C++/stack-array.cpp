//
// Created by ady on 09.10.2018.
//
#include <iostream>

class Stack {
    private:
        int size;
        int stack[];
        int top;

    public:
        Stack(int Stack[],int sizeS){
            *stack = *Stack;
            size = sizeS;
            top = 0;
        };

        int getSize(){
          return size;
        };

        void displayStack(){
            int i;
            for(i=0;i<top;i++){
                std::cout << stack[i] << "\n";
            }
        }

        void push(int data){
            stack[top] = data;
            top += 1;
        }


};




int main(){
    const int MAX = 5;
    int arr[MAX] = {0,0,0,0,0};
    Stack *stack;
    stack = new Stack(arr, MAX);

    stack->push(10);
    stack->push(100);
    stack->push(1000);
    stack->displayStack();
    return 0;
}
