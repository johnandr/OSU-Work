#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include <math.h>

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anything in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */
    TYPE val;
    val = topDynArr(stack);
    popDynArr(stack);
    val = val + topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
    TYPE val;
    val = topDynArr(stack);
    popDynArr(stack);
    val = topDynArr(stack) - val;
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
    TYPE val;
    val = topDynArr(stack);
    popDynArr(stack);
    val = topDynArr(stack) / val;
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their multiplicty is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
	/* FIXME: You will write this function */
    TYPE val;
    val = topDynArr(stack);
    popDynArr(stack);
    val = topDynArr(stack) * val;
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	the first number to the power of the second
    is pushed back onto the stack.
*/
void power(struct DynArr *stack)
{
    TYPE val;
    val = topDynArr(stack);
    popDynArr(stack);
    val = pow(topDynArr(stack), val);
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	that number is taken to the square root and
    is then pushed back onto the stack.
*/
void squareRoot(struct DynArr *stack)
{
    TYPE val;
    val = sqrt(topDynArr(stack));
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	that number is squared and is then
    pushed back onto the stack.
*/
void squaring(struct DynArr *stack)
{
    TYPE val;
    val = pow(topDynArr(stack), 2);
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	that number is cubed and is then
    pushed back onto the stack.
*/
void cubing(struct DynArr *stack)
{
    TYPE val;
    val = pow(topDynArr(stack), 3);
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	that number is made positive and then
    pushed back onto the stack.
*/
void absValue(struct DynArr *stack)
{
    TYPE val;
    val = fabs(topDynArr(stack));
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and 
	that number is taken to the exponential and
    then pushed back onto the stack.
*/
void exponential(struct DynArr *stack)
{
    TYPE val;
    val = exp(topDynArr(stack));
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and then
	natural log is taken of that number and
    then pushed back onto the stack.
*/
void natLog(struct DynArr *stack)
{
    TYPE val;
    val = log(topDynArr(stack));
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and then
	log base 10 is taken of that number and
    then pushed back onto the stack.
*/
void commonLog(struct DynArr *stack)
{
    TYPE val;
    val = log10(topDynArr(stack));
    popDynArr(stack);
    pushDynArr(stack, val);
    //printf("%f\n", val);
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
            squaring(stack);
		else if(strcmp(s, "^3") == 0)
			cubing(stack);
		else if(strcmp(s, "abs") == 0)
            absValue(stack);
		else if(strcmp(s, "sqrt") == 0)
            squareRoot(stack);
		else if(strcmp(s, "exp") == 0)
            exponential(stack);
		else if(strcmp(s, "ln") == 0)
            natLog(stack);
		else if(strcmp(s, "log") == 0)
			commonLog(stack);
		else 
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
	        double val;
            int valid = 0;
            while(valid == 0)
            {
                if(strcmp(s, "e") == 0)
                {
                    pushDynArr(stack, 2.71828);
                    valid = 1;
                }
                else if(strcmp(s, "pi") == 0)
                {
                    pushDynArr(stack, 3.14159);
                    valid = 1;
                }
                else if(isNumber(s, &val) == 1)
                {
                    pushDynArr(stack, val);
                    valid = 1;
                }else
                {
                    printf("Error\n");
                    printf("You inputed %s incorrectly\nPlease replace it with a valid input\n", s);
                    scanf("%s", s);
                }
                /*This makes sure the user doesn't mess up*/
            }
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
     *          Fixed Invalid Inputs above :)
	 * (2) Store the final value in result and print it out.
	 */
	result = topDynArr(stack);
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	printf("%f\n", calculate(argc,argv));
	return 0;
}
