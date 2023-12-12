#include <stdio.h>
#include <stdlib.h>
#include "cursorBase.h"
// include the library you want to test

int main(int argc, char *argv[]) {
	VirtualHeap myHeap = newVirtualHeap();
	List myList = -1;
	
	
	insertFront(&myHeap, &myList, newStudent(101, "Jonathan", 'm', "BS IT"));
	insertFront(&myHeap, &myList, newStudent(105, "Sebatian", 'm', "BS CS"));
	insertFront(&myHeap, &myList, newStudent(101, "John", 'm', "BS IT"));
	insertFront(&myHeap, &myList, newStudent(105, "James", 'm', "BS CS"));
	insertFront(&myHeap, &myList, newStudent(101, "Roy", 'm', "BS IT"));
	insertFront(&myHeap, &myList, newStudent(105, "Sean", 'm', "BS CS"));
	//visualizeSpace(myHeap);
	displayList(myHeap, myList);
	removeStudent(&myHeap, &myList, "Roy");
	displayList(myHeap, myList);
	return 0;
}
