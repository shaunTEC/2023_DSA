#include <stdio.h>
#include <stdlib.h>
#include "stackLinkedList.h"

void initStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack stack) {
    return stack.top == NULL;
}

void push(Stack* stack, Data item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (isEmpty(*stack)) {
        printf("Stack is empty. Cannot perform pop operation.\n");
        return;
    }

    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

Data peek(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot perform peek operation.\n");
        return -1; 
	}

    return stack.top->data;
}

void display(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    Node* current = stack.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
