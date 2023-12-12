//Linked Lists***********************************************

#include <stdio.h>
#include <stdlib.h>
#include "stackLinkedList.h"

//Arrays*****************************************************
/*
#include <stdio.h>
#include <stdlib.h>
#include "stackArray.h"

#define MAX_SIZE 10
*/
//***********************************************************

int main(int argc, char *argv[]) {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(stack);

    printf("\nTop element: %d\n", peek(stack));

    pop(&stack);
    display(stack);

    return 0;
}
