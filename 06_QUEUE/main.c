#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

int main(int argc, char *argv[]) {
    Queue myQueue;
    int choice;
    String menuOption[7] = {"Enqueue", "Dequeue",
                            "isEmpty", "isFull",
                            "Display", "Visualize",
                            "Front"};
    int i, value;
    
    initQueue(&myQueue);
    
    do {
        system("cls");
        printf("MENU\n");
        for(i = 0; i < 7; ++i) {
            printf("[%d] %s\n", i+1, menuOption[i]);
        }
        printf("Enter your choice <0 to EXIT>: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enqueue\n");
                printf("Enter a number: ");
                scanf("%d", &value);
                enqueue(&myQueue, value);
                visualize(myQueue);
                break;
                
            case 2:
                printf("Dequeue\n");
                dequeue(&myQueue);
                visualize(myQueue);
                break;
                
            case 3:
                printf("Check if empty:\n");
                if(isEmpty(myQueue) == true) {
                    printf("Queue is Empty\n");
                } else {
                    printf("Queue Not Empty\n");
                }
                
                break;
                
            case 4:
                printf("Check if full:\n");
                if(isFull(myQueue) == true) {
                    printf("Queue is Full\n");
                } else {
                    printf("Queue Not Full\n");
                }
                break;
                
            case 5:
                printf("Display Queue\n");
                display(myQueue);
                break;
                
            case 6:
                printf("Visualize \n");
                visualize(myQueue);
                break;    
                
            case 7:
                printf("Front: %d\n", front(myQueue));
                break;
                
            case 0:
                printf("Thank you!\n");
            default:
                printf("Invalid Choice...\n");
        }
        
        system("pause");
    } while(choice != 0);
    printf("Bye!!\n");
    
    visualize(myQueue);
    
    return 0;
}

