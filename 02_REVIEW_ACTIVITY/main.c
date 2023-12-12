#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(int argc, char *argv[]) {	
	
	List myList;
	initList(&myList);
	/*
	insertFront(&myList, 1);	displayList(myList);
	insertFront(&myList, 2);	displayList(myList);
	insertFront(&myList, 3);	displayList(myList);
	insertFront(&myList, 4);	displayList(myList);
	insertFront(&myList, 5);	displayList(myList);
	insertFront(&myList, 6);	displayList(myList);
	*/
	insertRear(&myList, 1);	displayList(myList);
	insertRear(&myList, 2);	displayList(myList);
	insertRear(&myList, 3);	displayList(myList);
	insertRear(&myList, 4);	displayList(myList);
	insertRear(&myList, 5);	displayList(myList);
	insertRear(&myList, 6);	displayList(myList);
	insertRear(&myList, 2);	displayList(myList);
	
	//insertAt(&myList, 10, 3);	displayList(myList);
	//insertSorted(&myList, 4);	displayList(myList);
	
	//searchItem(myList, 2);
	//printf("%d\n", getItem(myList, 2));
	
	//deleteFront(&myList);	displayList(myList);
	//deleteRear(&myList);	displayList(myList);
	//deleteAt(&myList, 2);	displayList(myList);
	//deleteItem(&myList, 3);	displayList(myList);
	deleteAllItem(&myList, 2);	displayList(myList);
	return 0;
}
