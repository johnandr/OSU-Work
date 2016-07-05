#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink 
{
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList
{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) 
{
    lst->firstLink = malloc(sizeof(struct DLink));
    lst->lastLink = malloc(sizeof(struct DLink));
    lst->size = 0;
    lst->firstLink->next = lst->lastLink;
    lst->lastLink->prev = lst->firstLink;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Creates and adds a new link before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	/* FIXME: you must write this */
    struct DLink *newLink = malloc(sizeof(struct DLink));
    newLink->next = l;
    newLink->prev = l->prev;
    l->prev->next = newLink;
    l->prev = newLink;
    lst->size++;
    newLink->value = v;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/
void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* FIXME: you must write this */
	struct DLink *temp = malloc(sizeof(struct DLink));
    temp = l;
    l->prev->next = l->next;
    l->next->prev = l->prev;
    lst->size--;
    free(temp);
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/
int isEmptyList(struct linkedList *lst) {
    if(lst->size == 0)
    {
        //printf("Your List is Empty!");
        return 1;
    }
    //printf("Your List isn't Empty!");
	return 0;
}

/* De-allocate all links of the list

	param: 	lst		pointer to the linked list
	pre:	none
	post:	All links (including the two sentinels) are de-allocated
*/
void freeLinkedList(struct linkedList *lst)
{
	while(!isEmptyList(lst)) 
    {
		/* remove the link right after the first sentinel */
		_removeLink(lst, lst->firstLink->next);
	}		
	/* remove the first and last sentinels */
	free(lst->firstLink);
	free(lst->lastLink);	
}

/* 	Deallocate all the links and the linked list itself. 

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteLinkedList(struct linkedList *lst)
{
	assert (lst != 0);
	freeLinkedList(lst);
	free(lst);
}


/* Function to print list
 Pre: lst is not null
 */
void printList(struct linkedList* lst)
{
    struct DLink *temp = lst->firstLink->next;
    printf("Printing List Contents...\n");
    while(temp != lst->lastLink)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }    
    printf("\n");
}

/* ************************************************************************
	Deque Interface Functions
************************************************************************ */

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addFrontList(struct linkedList *lst, TYPE e)
{
    struct DLink *newLink = malloc(sizeof(struct DLink));
    newLink->next = lst->firstLink->next;
    lst->firstLink->next = newLink;
    newLink->prev = lst->firstLink;
    newLink->next->prev = newLink;
    newLink->value = e;
    lst->size++;
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addBackList(struct linkedList *lst, TYPE e) 
{
    struct DLink *newLink = malloc(sizeof(struct DLink));
    newLink->prev = lst->lastLink->prev;
    lst->lastLink->prev = newLink;
    newLink->next = lst->lastLink;
    newLink->prev->next = newLink;
    newLink->value = e;
    lst->size++;
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/
TYPE frontList (struct linkedList *lst) 
{
	return lst->firstLink->next->value;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/
TYPE backList(struct linkedList *lst)
{
	return lst->lastLink->prev->value;
}



/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/
void removeFrontList(struct linkedList *lst) 
{
    struct DLink *temp = malloc(sizeof(struct DLink));
    temp = lst->firstLink->next;
    lst->firstLink->next = temp->next;
    lst->firstLink->next->prev = lst->firstLink;
    lst->size--;
    free(temp);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/
void removeBackList(struct linkedList *lst)
{	
    struct DLink *temp = malloc(sizeof(struct DLink));
    temp = lst->lastLink->prev;
    lst->lastLink->prev = temp->prev;
    lst->lastLink->prev->next = lst->lastLink;
    lst->size--;
    free(temp);
}


/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
    addBackList(lst, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) 
{
    struct DLink *temp;
    temp = lst->firstLink->next;
    for(int i=0;i < lst->size;i++)
    {
        if(temp->value == e)
        {
            return 1;
        }
        temp = temp->next;
    }
	return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) 
{
    struct DLink *temp;
    temp = lst->firstLink->next;
    printf("Searching for %d...\n", e);
    for(int i=0;i < lst->size;i++)
    {
        if(temp->value == e)
        {
            printf("Found Value! Deleting!\n");
            _removeLink(lst, temp);
            return;
        }
        temp = temp->next;
    }
    printf("That value was not found in the bag\n");
    free(temp);        
}
