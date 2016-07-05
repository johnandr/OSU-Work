#include "cirListDeque.h"
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

int main(int argc, char* argv[]) 
{        
	printf("\nHello from test code!\n");

    printf("\nCreating Circlular linked list\n");
    struct cirListDeque *cir = createCirListDeque();
    assertTrue(isEmptyCirListDeque(cir), "Checking if List is Empty!");

    printf("Adding 3 to the front!\n");
    addFrontCirListDeque(cir, 3);
    
    printf("Adding 7 to the back\n");
    addBackCirListDeque(cir, 7);
    
    assertTrue(EQ(frontCirListDeque(cir),3), "Checking if front of list is 3 with FRONTLIST");
    assertTrue(EQ(backCirListDeque(cir),7), "Checking if back of list is 7 with BACKLIST");
    printCirListDeque(cir);

    printf("Adding 1 to the front\n");
    addFrontCirListDeque(cir, 1);
    assertTrue(EQ(frontCirListDeque(cir),1),"Checking front of list is 1");
    printf("%f\n", frontCirListDeque(cir));

    //printf("Printing contents of the list\n");
    printCirListDeque(cir);

    printf("Reversing the list\n");
    reverseCirListDeque(cir);
    printCirListDeque(cir);

    printf("Removing value from the back of the List\n");
    removeBackCirListDeque(cir);
    assertTrue(!EQ(backCirListDeque(cir),1),"Checking that back of list is not 1");

    printf("Removing value from the front of the List\n");
    removeFrontCirListDeque(cir);
    assertTrue(!EQ(frontCirListDeque(cir),7),"Checking that front of list is not 7");

    assertTrue(!isEmptyCirListDeque(cir),"Checking that the list is not empty");
    printCirListDeque(cir);
    deleteCirListDeque(cir);

    printf("\nYOU DIDN'T SAY HELLO BACK! :[\nOh well I forgive you if you give us 100% :]\n");
	return 0;
}


