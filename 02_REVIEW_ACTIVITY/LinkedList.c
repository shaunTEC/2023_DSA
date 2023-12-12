#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void initList(List *list) {
    *list = NULL;
}

List newList() {
    return NULL;
}

NodeType *createNode(DATA data) {
    NodeType *temp = malloc(sizeof(NodeType));
    if (temp != NULL) {
        temp->data = data;
        temp->next = NULL;
    }
    return temp;
}

void displayList(List list) {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }
    NodePtr trav = list;
    printf("List: [ ");
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("]\n");
}

bool insertFront(List *list, DATA item) {
    NodeType *temp = createNode(item);
    if (temp == NULL) {
        printf("New node failed\n");
        return false;
    }
    temp->next = *list;
    *list = temp;
    return true;
}


bool insertRear(List *list, DATA item) {
    NodeType *temp = createNode(item);
    if (temp == NULL) {
        printf("New node failed\n");
        return false;
    }
    temp->next = NULL;
    if (*list == NULL) {
        *list = temp;
    } else {
        NodePtr trav = *list;
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = temp;
    }
    return true;
}

bool insertAt(List *list, DATA item, int loc) {
    if (loc < 0) {
        printf("Invalid location\n");
        return false;
    }
    NodeType *temp = createNode(item);
    if (temp == NULL) {
        printf("New node failed\n");
        return false;
    }
    if (loc == 0) {
        temp->next = *list;
        *list = temp;
    } else {
        NodePtr trav = *list;
        int count = 0;
        while (count < loc - 1 && trav != NULL) {
            trav = trav->next;
            count++;
        }
        if (trav == NULL) {
            printf("Invalid location\n");
            return false;
        }
        temp->next = trav->next;
        trav->next = temp;
    }
    return true;
}

bool insertSorted(List *list, DATA data) {
    NodeType *temp = createNode(data);
    if (temp == NULL) {
        printf("New node failed\n");
        return false;
    }
    NodePtr trav = *list;
    NodePtr previous = NULL;
    while (trav != NULL && trav->data < data) {
        previous = trav;
        trav = trav->next;
    }
    if (previous == NULL) {
        temp->next = *list;
        *list = temp;
    } else {
        temp->next = trav;
        previous->next = temp;
    }
    return true;
}

bool searchItem(List list, DATA key) {
    NodePtr trav = list;
    while (trav != NULL) {
        if (trav->data == key) {
            printf("Key found in list\n");
            return true;
        }
        trav = trav->next;
    }
    printf("Key not found in list\n");
    return false;
}

int getItem(List list, DATA key) {
    NodePtr trav = list;
    int index = 0;
    while (trav != NULL) {
        if (trav->data == key) {
            return index;
        }
        trav = trav->next;
        index++;
    }
    return -1;
}

bool deleteFront(List *list) {
    if (*list == NULL) {
        printf("List is empty\n");
        return false;
    }
    NodePtr temp = *list;
    *list = temp->next;
    free(temp);
    return true;
}

bool deleteRear(List *list) {
    if (*list == NULL) {
        printf("List is empty\n");
        return false;
    }
    if ((*list)->next == NULL) {
        free(*list);
        *list = NULL;
        return true;
    }
    NodePtr trav = *list;
    while (trav->next->next != NULL) {
        trav = trav->next;
    }
    free(trav->next);
    trav->next = NULL;
    return true;
}

int deleteAt(List *list, int loc) {
    if (*list == NULL) {
        printf("List is empty\n");
        return -1;
    }
    if (loc < 0) {
        printf("Invalid location\n");
        return -1;
    }
    if (loc == 0) {
        NodePtr temp = *list;
        *list = temp->next;
        free(temp);
        return 1;
    }
    NodePtr trav = *list;
    int count = 0;
    while (count < loc - 1 && trav != NULL) {
        trav = trav->next;
        count++;
    }
    if (trav == NULL || trav->next == NULL) {
        printf("Invalid location\n");
        return -1;
    }
    NodePtr temp = trav->next;
    trav->next = temp->next;
    free(temp);
    return 1;
}

bool deleteItem(List *list, DATA key) {
    if (*list == NULL) {
        printf("List is empty\n");
        return false;
    }
    if ((*list)->data == key) {
        NodePtr temp = *list;
        *list = temp->next;
        free(temp);
        return true;
    }
    NodePtr trav = *list;
    while (trav->next != NULL) {
        if (trav->next->data == key) {
            NodePtr temp = trav->next;
            trav->next = temp->next;
            free(temp);
            return true;
        }
        trav = trav->next;
    }
    printf("Key not found in list\n");
    return false;
}

int deleteAllItem(List *list, DATA key) {
    if (*list == NULL) {
        printf("List is empty\n");
        return -1;
    }
    int count = 0;
    while (*list != NULL && (*list)->data == key) {
        NodePtr temp = *list;
        *list = temp->next;
        free(temp);
        count++;
    }
    NodePtr trav = *list;
    while (trav != NULL && trav->next != NULL) {
        if (trav->next->data == key) {
            NodePtr temp = trav->next;
            trav->next = temp->next;
            free(temp);
            count++;
        } else {
            trav = trav->next;
        }
    }
    return count;
}

