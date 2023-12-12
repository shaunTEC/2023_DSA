#ifndef CIRCULAR_H
#define CIRCULAR_H
#define MAX 10
#define EMPTY 9999
#include <stdbool.h>

typedef char String[30];

typedef struct {
    int elems[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int item);
void dequeue(Queue *q);
int front(Queue q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void display(Queue q);
void visualize(Queue q);

bool removeItem(Queue *q, int item);
Queue removeEven(Queue *q);
int doubleTheValue(Queue *q, int value);

#endif

