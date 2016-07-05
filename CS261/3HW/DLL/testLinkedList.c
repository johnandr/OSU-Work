#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int predicate, char *message)
{
    printf("%s: ", message);
    if(predicate)
        printf("PASSED\n");
    else
        printf("FAILED\n");
}

int main(int argc, char* argv[]) {
    
	printf("Hello from test code!\n\n");
    //struct Dlink *temp = malloc(sizeof(struct DLink));
    struct linkedList *lst;
    printf("Initializing our List\n");
    lst = createLinkedList();
    assertTrue(EQ(isEmptyList(lst),1), "Checking if List is empty!");
    printf("Adding 5 to Front of the list!\n");
    addFrontList(lst, 5);
    assertTrue(EQ(frontList(lst),5), "Checking if 5 is in front of list. Also Checked with FRONTLIST");
    printf("Add 7 to Back of the list!\n");
    addBackList(lst, 7);
    assertTrue(EQ(backList(lst),7), "Checking if 7 is in back of list. Also Checked with BACKLIST");
    printf("Adding 3 to Front of the list!\n");
    addFrontList(lst, 3);
    printf("Here is how the Linked List Looks now (Using PRINTLIST)\n");
    printList(lst);
    assertTrue(EQ(containsList(lst, 3), 1), "Using CONTAINSLIST to checking for 3 in List");
    printf("Removing from the front of the list\n");
    removeFrontList(lst);
    printf("Removing from back of the list\n");
    removeBackList(lst);
    assertTrue(!containsList(lst,3), "Checking if 3 is NOT in the List");
    printList(lst);
    printf("Adding a 1 and then another 5 to the front of list\n");
    addFrontList(lst, 1);
    addFrontList(lst, 5);
    printList(lst);
    printf("Removing First 5 in list with REMOVELIST\n");
    removeList(lst, 5);
    printList(lst);
    

	return 0;
}


