#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#define MAX_SIZE 10

typedef int Data;

typedef struct {
    Data elems[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* stack);
int isEmpty(Stack stack);
int isFull(Stack stack);
void push(Stack* stack, Data item);
void pop(Stack* stack);
Data peek(Stack stack);
void display(Stack stack);

#endif
