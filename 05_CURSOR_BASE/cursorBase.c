#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cursorBase.h"

Student newStudent(	int studID, String studName, char sex, String program){
	Student s;
	
	s.studID = studID;
	strcpy(s.studName, studName);
	s.sex = sex;
	strcpy(s.program, program);
	
	return s;
}

VirtualHeap newVirtualHeap() {
	VirtualHeap vh;
	int i;
	
	for(i = 0 ; i < MAX ; i++) {
		vh.elems[i].elem = newStudent(0, "", ' ', "");
		vh.elems[i].next = i-1;
	}
	
	vh.avail = MAX-1;
	return vh;
}

int allocSpace(VirtualHeap *vh) {
	int retVal = vh->avail;
	
	if(retVal != -1) {
		vh->avail = vh->elems[vh->avail].next;
	}
	
	return retVal;
}

void insertFront(VirtualHeap *vh, List *list, Student s) {
	List temp = allocSpace(vh);
	
	if(temp != -1) {
		vh->elems[temp].next = *list;		//assigning
		*list = temp;						//assigning
		vh->elems[temp].elem = s;			//setting value
	}
}

void displayList(VirtualHeap vh, List list) {
	int i;
	
	printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
	printf("---------------------------------------------\n");
	for(i = list; i < MAX; i++){
		if(vh.elems[i].elem.studID == 0) continue;
			else printf("%5d | %4d - %23s | %d\n", i, vh.elems[i].elem.studID, vh.elems[i].elem.studName, vh.elems[i].next);
	}
	printf("---------------------------------------------\n");
}

void visualizeSpace(VirtualHeap vh) {
	int i;
	
	printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
	printf("---------------------------------------------\n");
	
	for(i = 0; i < MAX; i++) {
		printf("%5d | ", i);
		if(vh.elems[i].elem.studID == 0) {
			printf("%30s | ", "Empty");
		} else {
			printf("%4d - %23s | ", vh.elems[i].elem.studID, vh.elems[i].elem.studName);
		}
		printf("%d\n", vh.elems[i].next);
	}

	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n", i);
}

void deallocSpace(VirtualHeap *vh, int index) {
	if(index != -1 && index < MAX){ 
		vh->elems[index].next = vh->avail;
		vh->elems[index].elem = newStudent(0, "", ' ', "");
		vh->avail = index;
	}
}

Student removeStudent(VirtualHeap *vh, List *list, String keyword) {
	int i = *list;
	int prev = -1;
	
	while(i != -1){
		if(strcmp(keyword, vh->elems[i].elem.studName) == 0) {
			if(prev != -1) {
				vh->elems[prev].next = vh->elems[i].next;
				Student removedStudent = vh->elems[i].elem;
				deallocSpace(vh, i);
				return removedStudent;
			} else {
				*list = vh->elems[i].next;
				Student removedStudent = vh->elems[i].elem;
				deallocSpace(vh, i);
				return removedStudent;
			}
		}
		prev = i;
		i = vh->elems[i].next;
	}
	Student emptyStudent = newStudent(0, "", ' ', "");
	return emptyStudent;
}


