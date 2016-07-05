/* CS261- Assignment 1 - Q.1*/
/* Name: Andrew Johnson
 * Date:4/7/15
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     //struct student list[10];
     struct student *list = malloc(10 * sizeof(struct student));
     /*return the pointer*/
     return list;
}

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
     int taken[10] = {0,0,0,0,0,0,0,0,0,0};
     int val = 0;
     int num = 0; 
     //srand
     for(int i=0;i<10;i++)
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

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
     for(int i=0;i<10;i++)
     {
        printf("ID%d %d\n", students[i].id, students[i].score);
     }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int high = 0;
     int low = 100;
     double sum = 0;
     for(int i=0;i<10;i++)
     {
        if(students[i].score < low)
        {
            low = students[i].score;
        }
        if(students[i].score > high)
        {
            high = students[i].score;
        }
        sum = sum + students[i].score;
     }
     sum = sum / 10;
     printf("The Highest score is %d\n", high);
     printf("The Lowest score is %d\n", low);
     printf("The Average score is %f\n", sum);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
