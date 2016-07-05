/* CS261- Assignment 1 - Q.3*/
/* Name: Andrew Johnson
 * Date: 4/7/15
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    // int position = 0; //position that you are placing next sorted number
    // int low = 21; //Lowest value
    // int lowPos; //position of lowest value
     int temp; //holds value from array
 	 int sort;
    do
	{
		sort = 1;
		for(int i = 0; i < n - 1; i++)
		{
			if(number[i] > number[i + 1])
			{
				temp = number[i];
				number[i] = number[i + 1];
				number[i + 1] = temp;
				sort = 0;
			}
		}
	}while(sort == 0);
/*    for(int i = n;i<n;i++){
        if(number[i] < low){
            low = number[i];
            lowPos = i;
        }
     }
     temp = number[i];
     number[i] = number[position];
     number[position] = temp;
     position++;
     }*/
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n * sizeof(int));
    /*Fill this array with random numbers between 0 and n, using rand().*/
    for(int i=0;i<n;i++)
    {
        array[i] = rand() % 21;
    }
    /*Print the contents of the array.*/
    for(int i=0;i<n;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    /*Pass this array along with n to the sort() function.*/
    sort(array, n);
    /*Print the contents of the array.*/    
    for(int i=0;i<n;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}
