#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DynamicArray.h"

void initList(List *list) {
	list->count = 0;
}
List* newList(int max) {
	List *list = malloc(sizeof(List));
	
	if(list != NULL) {
		list->max = max;
		initList(list);
	}
	return list;
}

void displayList(List list) {
	if(list.count == 0) {
		printf("List is empty\n");
	}
	
	int i;
	printf("Array: [ ");
	for(i = 0; i < list.count; i++) {
		printf("%d ", list.elems[i]);
	}
	printf("]\n");
}
bool insertFront(List *list, DATA item) {
	if(list->count == list->max) {
		printf("List is Full\n");
		return false;
	}
	int i;
	for(i = list->count; i > 0; i--) {
		list->elems[i] = list->elems[i-1];
	}
	list->elems[i] = item;
	list->count++;
	return true;
}
bool insertRear(List *list, DATA item) {
	if(list->count == list->max) {
		printf("List is Full\n");
		return false;
	}
	list->elems[list->count] = item;
	list->count++;
	return true;
}
bool insertSorted(List *list, DATA item) {
	if(list->count == list->max) {
		printf("List is Full\n");
		return false;
	}
	int i;
	for(i = list->count; list->elems[i] == item; i--) {
		list->elems[i] = list->elems[i+1];
	} 
	list->elems[i] = item;
	return true;
}
bool insertAt(List *list, DATA item, int loc) {
	if(list->count == list->max) {
		printf("List is Full\n");
		return false;
	}
	int i;
	for(i = list->count; i > loc; i++) {
		list->elems[i] = list->elems[i+1];
	}
	list->elems[i] = item;
	return true;
}

bool searchItem(List list, DATA key) {
	int i;
	for(i = 0; i < list.max; i++) {
		if(key == list.elems[i]) {
			printf("Key found in List\n");
			return true;
		}
	}
	printf("Key not found in List\n");
	return false;
}
int getItem(List list, DATA key) {
	int i;
	
	for(i = 0; i < list.count; i++) {
		if(list.elems[i] == key) {
			return i;
		}
	}
	return -1;
}

bool deleteFront(List *list) {
	if(list->count == 0) {
		printf("List is Empty\n");
		return false;
	}
	int i;
	for (i = 0; i < list->count - 1; i++) {
		list->elems[i] = list->elems[i+1];
	}
	list->count--;
	return true;
}
bool deleteRear(List *list) {
	if(list->count == 0) {
		printf("List is Empty\n");
		return false;
	}
	list->count--;
	return true;
}
int deleteAt(List *list, int loc) {
	if(list->count == 0) {
		printf("List is Empty\n");
		return -1;
	}
	if(loc == 0 || loc > list->count) {
		printf("Location unavailable\n");
		return -1;
	}
	
	while(loc < list->count-1){
		list->elems[loc] = list->elems[loc+1];
		loc++;
	}
	list->count--;
	return 1;
}
bool deleteItem(List *list, DATA key) {
	if(searchItem(*list, key) == false) {
		printf("Value not found\n");
		return false;
	}
	deleteAt(list, getItem(*list, key));
	return true;
}
int deleteAllItem(List *list, DATA key) {
	if(searchItem(*list, key) == false) {
		printf("Value not found\n");
		return -1;
	}
    
    while(searchItem(*list, key) == true) {
    	deleteAt(list, getItem(*list, key));
	}
	return 1;
}
