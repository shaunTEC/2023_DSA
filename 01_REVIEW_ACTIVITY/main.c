//***********************************************
//Static Array
/*
#include <stdio.h>
#include <stdlib.h>
#include "StaticArray.h"

int main(int argc, char *argv[]) {
	List myList;
	
	initList(&myList);
	
	//insert front
	
	insertFront(&myList, 1);	displayList(myList);
	insertFront(&myList, 2);	displayList(myList);
	insertFront(&myList, 3);	displayList(myList);
	insertFront(&myList, 4);	displayList(myList);
	insertFront(&myList, 5);	displayList(myList);
	insertFront(&myList, 6);	displayList(myList);
	
	//insert back
	
	//insertRear(&myList, 1);		//displayList(myList);
	//insertRear(&myList, 2);		//displayList(myList);
	//insertRear(&myList, 3);		//displayList(myList);
	//insertRear(&myList, 3);		//displayList(myList);
	//insertRear(&myList, 3);		//displayList(myList);
	//insertRear(&myList, 4);		//displayList(myList);
	//insertRear(&myList, 5);		//displayList(myList);
	//insertRear(&myList, 6);		//displayList(myList);
	
	//displayList(myList);
	
	//insertSorted(&myList, 4);
	//insertAt(&myList, 10, 2);
	//displayList(myList);
	
	//searchItem(myList, 3);
	//printf("%d\n", getItem(myList, 3));
	//printf("%d\n", searchItem(myList, 3));
	
	//deleteFront(&myList);
	//deleteRear(&myList);
	//deleteAt(&myList, 1);
	//deleteItem(&myList, 3);
	//deleteAllItem(&myList, 3);
	//displayList(myList);
	return 0;
}
	*/
//***********************************************
//Dyanamic Array
#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

int main(int argc, char *argv[]) {
	List *myList = newList(10);
    displayList(*myList);
	insertRear(myList, 1);		displayList(*myList);
	insertRear(myList, 2);		displayList(*myList);
	insertRear(myList, 3);		displayList(*myList);
	//insertRear(myList, 3);		//displayList(*myList);
	//insertRear(myList, 3);		//displayList(*myList);
	insertRear(myList, 4);		displayList(*myList);
	insertRear(myList, 5);		displayList(*myList);
	insertRear(myList, 6);		displayList(*myList);
	
	return 0;
}
//***********************************************
