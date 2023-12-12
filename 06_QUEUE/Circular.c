#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    
    int i;
    for(i = 0; i < MAX; ++i) {
        q->elems[i] = EMPTY;
    }
}

void enqueue(Queue *q, int item) {
    if (!isFull(*q)) {
        q->rear = (q->rear + 1) % MAX;
        q->elems[q->rear] = item;
    }
}

void dequeue(Queue *q) {
    if (!isEmpty(*q)) {
        q->elems[q->front] = EMPTY;
        q->front = (q->front + 1) % MAX;
    }
}

int front(Queue q) {
    if (!isEmpty(q)) {
        return q.elems[q.front];
    }
    return EMPTY;
}

bool isEmpty(Queue q) {
    return (q.rear + 1) % MAX == q.front;
}

bool isFull(Queue q) {
    return (q.rear + 2) % MAX == q.front;
}

void display(Queue q) {
    int i, end;
    end = (q.rear + 1) % MAX;
    if (!isEmpty(q)) {
        printf("{ ");
        for (i = q.front; q.elems[i] != q.elems[end]; i = (i + 1) % MAX) {
            printf("%d ", q.elems[i]);
        }
    }
    printf("}\n");
}

void visualize(Queue q) {
    int i;
    printf("%5s | %5s | %s\n", "INDEX", "VALUE", "POSITION");
    printf("------------------------\n");
    
    for (i = 0; i < MAX; ++i) {
        printf("%5d | ", i);
        if (q.elems[i] != EMPTY) {
            printf("%5d | ", q.elems[i]);
        } else {
            printf("%5s | ", " ");
        }
        if (i == q.front) {
            printf("Front ");
        }
        if (i == q.rear) {
            printf("Rear ");
        }
        printf("\n");
    }
    printf("------------------------\n");
}

bool removeItem(Queue *q, int item) {
    int i;
    bool found = false;

    for (i = q->front; i != (q->rear + 1) % MAX; i = (i + 1) % MAX) {
        if (q->elems[i] == item) {
            found = true;
            break;
        }
    }

    if (found) {
        int j, k = 0;
        for (j = q->front; j != (q->rear + 1) % MAX; j = (j + 1) % MAX) {
            if (j != i) {
                q->elems[k] = q->elems[j];
                k = (k + 1) % MAX;
            }
        }
        q->front = 0;
        q->rear = k > 0 ? k - 1 : MAX - 1;
        return true;
    }

    return false;
}

Queue removeEven(Queue *q) {
    Queue evenQueue;
    initQueue(&evenQueue);

    int i;
    for (i = q->front; i != (q->rear + 1) % MAX; i = (i + 1) % MAX) {
        if (q->elems[i] % 2 != 0) {
            enqueue(&evenQueue, q->elems[i]);
        }
    }

    *q = evenQueue;
    return evenQueue;
}

int doubleTheValue(Queue *q, int value) {
    int count = 0;

    int i;
    for (i = q->front; i != (q->rear + 1) % MAX; i = (i + 1) % MAX) {
        if (q->elems[i] == value) {
            q->elems[i] *= 2;
            count++;
        }
    }

    return count;
}

