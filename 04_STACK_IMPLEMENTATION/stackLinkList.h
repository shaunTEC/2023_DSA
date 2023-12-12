#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

typedef int Data;

typedef struct Node {
    Data data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initStack(Stack* stack);
int isEmpty(Stack stack);
void push(Stack* stack, Data item);
void pop(Stack* stack);
Data peek(Stack stack);
void display(Stack stack);

#endif
