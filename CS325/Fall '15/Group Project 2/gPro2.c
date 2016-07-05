#include <stdio.h>
#include <stdlib.h>


/* Programmer's Name: Andrew Johnson
 *
 * So the fist bit of code I tried using a struct to keep count and to use other array's to keep
 * track of the points following. Sadly, ran into multiple problems. Therefore I just have it
 * so that it returns the highest value of the best path. I goes through the right path, I just
 * can't return any extra values, :(
 */









/*
struct Information
{
	int checker;
	int counter;
	int cnt;
//	int rpoint[];
//	int cpoint[];
};

struct Information* findSum(struct Information *temp, int r, int c, int rmax, int cmax, int m[][cmax])
{
	if(r >= rmax || c >= cmax)
	{
		return temp;
	}
	int cell = m[r][c];
	temp->checker += cell;
	if(temp->checker <= 0)
	{
		if(temp->cnt > 0)
		{
			temp->checker -= cell;
			struct Information *temp2 = temp;
			temp2->cnt = 0;
			temp2->counter = 0;
			return max(*temp, max(findSum(*temp2,r+1,c,rmax,cmax,m),findSum(*temp2,r,c+1,rmax,cmax,m)));
		}
		temp->checker = 0;
		temp->cnt = 0;
		temp->counter = 0;
		return max(findSum(*temp,r+1,c,rmax,cmax,m),findSum(*temp,r,c+1,rmax,cmax,m));
	}
	if(temp->checker > 0)
	{
		temp->rpoint[temp->counter] = r;
		temp->cpoint[temp->counter] = c;
		temp->counter += 1;
		temp->cnt += 1;
		return max(findSum(*temp,r+1,c,rmax,cmax,m),findSum(*temp,r,c+1,rmax,cmax,m));
	}

};



struct Information max(struct Information *a, struct Information *b)
{
	if(a->checker > b->checker)
	{
		return &a;
	}
	return &b;
};
*/

int max(int a, int b);


/* Parameters: 	r = current row
 *	       	c = current column
 *	       	rmax = maximum number of rows of matrix
 * 		cmax = maximum number of columns of matrix
 * 		check = temporary maximum sum (Return Value)
 *		count = Supposed to keep track of max count but fails..
 *		m[][cmax] = This is the matrix we are using.
 */


int func(int r, int c, int rmax, int cmax, int check, int *count, int m[][cmax])
{
	if(r >= rmax || c >= cmax)
	{
		return check;
	}
	int cell = m[r][c];
	check += cell;
	if(check <= 0)
	{
		if(count > 0)
		{
			check -= cell;
			cell = 0;
			count = 0;
			return max(check, max(func(r+1,c,rmax,cmax,cell,count,m), func(r,c+1,rmax,cmax,cell,count,m)));
		}
		return max(func(r+1,c,rmax,cmax,0,0,m),func(r,c+1,rmax,cmax,0,0,m));
	}
	if(check > 0)
	{
		count += 1;
		return max(func(r+1,c,rmax,cmax,check,count,m),func(r,c+1,rmax,cmax,check,count,m));
	}
	return 0;
};

int max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	return b;
};

int main()
{
	int rows = 0;
	int cols = 0;
	FILE *ex;
	ex = fopen("EX1.txt","r");	// Change name of "EX1" to any test.txt
	fscanf(ex, "%d ", &rows);	// Takes first number of text file and writes it to rows
	fscanf(ex, "%d ", &cols);	// Takes second number of text files and writes it to cols

	int matrix[rows][cols]; 	// Initialize matrix rows x cols


	// This for loop takes all numbers in text file
	// ans writes them to appropriate cell
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			fscanf(ex, "%d ", &matrix[i][j]);
		}
	}

	// Prints matrix from text file
        for(int i=0; i<rows; i++)
        {
                for(int j=0; j<cols; j++)
                {
                        printf("%d ", matrix[i][j]);
                }
		printf("\n");
        }
/*
	struct Information *info;
	info->cnt = 0;
	info->counter = 0;
	info->checker = 0;
*/
	int count = 0;
	int index = 0;
	int r = 0;			// Starting Row
	int c = 0;			// Starting Column

//	info = findSum(*info,r,c,rows,cols,m);
//	int sum = info->checker;

	// Uses Recursive function func to find max value trail of matrix
	int sum = func(r,c,rows,cols,index,&count,matrix);
		
	
	printf("%d\n", sum);
//	printf("%d\n",count);

	return 0;
}














