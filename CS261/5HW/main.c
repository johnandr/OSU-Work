#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
    char cmd = ' ';
    DynArr* mainList = createDynArr(10);

    printf("\n\n** TO-DO LIST APPLICATION **\n\n");

    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
              );
      /* get input command (from the keyboard) */
        cmd = getchar();
      /* clear the trailing newline character */
        while (getchar() != '\n');
        
            FILE *fl = fopen("todo.txt", "r+");
            FILE *fs = fopen("todoS.txt", "r+");
            int prior = 0;
            char desc[128];
            switch(cmd){
                case 'l':
                    loadList(mainList, fl);
                    break;
                case 's':
                    saveList(mainList,fs);
                    break;
                case 'a':
                    printf("What is the priority of the task?\n");
                    scanf("%d", &prior);
                    while(prior > 999)
                    {
                        printf("Please put a valid number\n");
                        scanf("%d", &prior);
                    }
                    printf("What is the description of the task?\n");
                    scanf("%s", desc);
                    //fgets(desc, 128, stdin);
                    addHeap(mainList,createTask(prior, desc),compare); 
                    break;
                case 'g':
                    if(isEmptyDynArr(mainList) == 1)
                    {
                        printf("Your list is empty!\n");
                    }else{
                    printf("Your First task is \n");
                    print_type(getMinHeap(mainList)); 
                    }
                    break;
                case 'r':
                    if(isEmptyDynArr(mainList) == 1)
                    {
                        printf("Your list is empty!\n");
                    }else{
                        printf("REMOVING ");
                        print_type(getMinHeap(mainList));
                        removeMinHeap(mainList,compare); 
                    }
                    break;
                case 'p':
                    if(isEmptyDynArr(mainList) == 1)
                    {
                        printf("Your list is empty!\n");
                    }else{
                    printList(mainList);
                    }
                    break;
                default:
                    break;
            } 

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  printf("bye!\n");
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
