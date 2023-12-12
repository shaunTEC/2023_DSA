#include <stdio.h>
#include <stdlib.h>
#include "stackArray.h"

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack stack) {
    return stack.top == -1;
}

int isFull(Stack stack) {
    return stack.top == MAX_SIZE - 1;
}

void push(Stack* stack, Data item) {
    if (isFull(*stack)) {
        printf("Stack is full. Cannot perform push operation.\n");
        return;
    }

    stack->elems[++stack->top] = item;
}

void pop(Stack* stack) {
    if (isEmpty(*stack)) {
        printf("Stack is empty. Cannot perform pop operation.\n");
        return;
    }

    stack->top--;
}

Data peek(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot perform peek operation.\n");
        return -1;
    }

    return stack.elems[stack.top];
}

void display(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.elems[i]);
    }
    printf("\n");
}
