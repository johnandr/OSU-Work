/* CS261- Assignment 1 - Q.4*/
/* Name: Andrew Johnson
 * Date: 4/7/15
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
     /* Remember, each student must be matched with their original score after sorting */
     int tempI;
     int tempS;
 	 int sort;
    do
	{
		sort = 1;
		for(int i = 0; i < n - 1; i++)
		{
			if(students[i].score > students[i + 1].score)
			{
				tempI = students[i].id;
				students[i].id = students[i + 1].id;
				students[i + 1].id = tempI;

                tempS = students[i].score;
                students[i].score = students[i + 1].score;
				students[i + 1].score = tempS;

				sort = 0;
			}
		}
	}while(sort == 0);
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    /*Allocate memory for n students using malloc.*/
     struct student *students = malloc(n * sizeof(struct student));
    
    /*Generate random IDs and scores for the n students, using rand().*/
     int taken[10] = {0,0,0,0,0,0,0,0,0,0};
     int val = 0;
     int num = 0; 
     
     for(int i=0;i<n;i++)
     {
        val = 0;
        while(val == 0)
        {
            num = (rand() % 10) + 1;
            if(taken[num-1] == 0)
            {
                students[i].id = num;
                students[i].score = (rand() % 101);
                taken[num-1] = 1;
                val = 1;
            }
        }
    }


    /*Print the contents of the array of n students.*/
     for(int i=0;i<n;i++)
     {
        printf("ID%d %d\n", students[i].id, students[i].score);
     }
     printf("\n");

    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    /*Print the contents of the array of n students.*/
     for(int i=0;i<n;i++)
     {
        printf("ID%d %d\n", students[i].id, students[i].score);
     }
    
    return 0;
}
