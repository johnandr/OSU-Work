/* CS261- Assignment 1 - Q. 0*/
/* Name: Andrew Johnson
 * Date: 4/7/15
 * Solution description: 
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value of the integer pointed to by iptr*/
     printf("%d\n", *iptr);
     /*Print the address pointed to by iptr*/
     printf("%p\n", iptr);
     /*Print the address of iptr itself*/
     printf("%p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 3;    
    /*print the address of x*/
    printf("%p\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    
    return 0;
}
