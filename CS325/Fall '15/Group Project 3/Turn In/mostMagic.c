/***************************************************
 *
 * Programmer : 	Andrew Johnson
 * Class : 			OSU CS325 Fall '15 
 * Program Name :	Divide and Conquer
 *					Most Magical Subsequence
 *
 * Directory :		minOf: 		 Line 21
 *					sumOf: 		 Line 42
 *					maxOf: 		 Line 60
 *					mostMagical: Line 78
 *					GreedyMagic: Line 116
 *					DivMagic:	 Line 193
 *					main:		 Line 287
 *					
 *************************************************/

#include <stdio.h>
#include <stdlib.h>

/******************************
 * Function: 	MinOf
 * Parameters: 	Array, two endpoints; i<j
 * Description: Searches through desired part of an array
 * Returns: 	Smallest value found during search
 *****************************/

unsigned long long int minOf(unsigned long long int A[], int i, int j)
{
	unsigned long long int min = A[i];
	for(int k=i; k<=j; k++)
	{
		if(min > A[k])
		{
			min = A[k];
		}
	}
	
	return min;
}

/********************
 * Function:	sumOf
 * Parameters:	Array, two endpoints; i<j 
 * Description:	Adds all values of A[i,..,j]
 * Returns:		Sum of all values
 *******************/

unsigned long long int sumOf(unsigned long long int A[], int i, int j)
{
	unsigned long long int sum = 0;
	for(int k=i; k<=j; k++)
	{
		sum = sum + A[k];
	}
	
	return sum;
}

/********************
 * Function:	maxOf
 * Parameters:	Two integers
 * Description:	Compares two integers to see which is larger
 * Result: 		Return larger number
 *******************/

unsigned long long int maxOf(unsigned long long int a, unsigned long long int b)
{
	if(a > b)
	{
		return a;
	}else
	{
		return b;
	}
}

/********************
 * Function:	mostMagical
 * Parameters:	Array, and size of array
 * Description:	O(n^2) search of Most Magical Subsequence
 *				algorithm. Looks through all possible 
 *				sub arrays of the given array and remembers
 *				the sub array that gives the highest magic value
 * Returns:		An array containing { Highest magic number,
 									  start of subarray,
									  end of subarray }
 *******************/ 

unsigned long long int *mostMagical(unsigned long long int arr[], int n)
{
	unsigned long long int max=0;
	unsigned long long int magic=0;
	int start=0;
	int end=0;

	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			magic = minOf(arr,i,j) * sumOf(arr,i,j);
			if(magic > max)
			{
				max = magic;
				start = i;
				end = j;
			}
		}
	}
	unsigned long long int res[3] = {max, (unsigned long long int)start, (unsigned long long int)end};

	return res;
}


/********************
 * Function:	GreedyMagic
 * Parameters:	Array, Array Endpoint, Array Size, midpoint; m!=0 || m!=Endpoint
 * Description:	Starts at A[m], looks at neighbors of the starting array and
 *				adds the larger neighbor to the "temp array", continues until
 *				search has reached the Array Size.
 * Returns:		Array containing { Most Magical Subsequence containing A[m],
 								   Starting point of array,
								   endpoint of array }
 *******************/ 

unsigned long long int *GreedyMagic(unsigned long long int A[], int arrSize, int size, int m)
{
	unsigned long long int max = A[m]*A[m];
	int start = 0;
	int end = 0;
	unsigned long long int magic = 0;
	int i = m;
	int j = 0;

// Checking intial neighbors

	if(A[i+1] >= A[i-1])
	{
		j = i+1;
	}else
	{
		j = i;
		i--;
	}

// Looking at addtional neighbors until size is reached

	while(j-i != size-1)
	{
		magic = minOf(A,i,j) * sumOf(A,i,j);
		if(magic > max)
		{
			max = magic;
			start = i;
			end = j;
		}
		if(i == 0)
		{
			j++;
		}else if(j == size-1)
		{
			i--;
		}else if(j == arrSize)
		{
			i--;
		
		}else if(A[i-1] >= A[j+1])
		{
			i--;
		}else
		{
			j++;
		}
	}
	
// Doing one final check of the entire array

	magic = minOf(A,i,j) * sumOf(A,i,j);
	if(magic > max)
	{
		max = magic;
		start = i;
		end = j;
	}

	unsigned long long int res[3] = {max, (unsigned long long int)start, (unsigned long long int)end};

	return res;

}

/********************
 * Function:	DivMagic
 * Parameters:	Array, Array Enpoint, Array Size, Starting Point , End point (of subarray)
 * Description:	Uses Divide and Conquer with Greedy Algorithm to find Most Magical Subsequence
 * Returns: 	Array containing { Most Magaical Number of Array,
 								   Starting Point,
								   End Point,
 *******************/ 

unsigned long long int *DivMagic(unsigned long long int A[], int arrSize, int size, int i, int j)
{
	unsigned long long int magic = 0;

	// Base Case

	if(size < 3)
	{
		magic = minOf(A, i, j) * sumOf(A, i, j);
		unsigned long long int res[3] = {magic, (unsigned long long int)i, (unsigned long long int)j};
		return res;
	}

	unsigned long long int *greed;
	unsigned long long int *first;
	unsigned long long int *last;

	// Place holders so values aren't 
	// written during recursive calls

	unsigned long long int greedHold[3];
	unsigned long long int firstHold[3];
	unsigned long long int lastHold[3];

	double halfSize = (double)size/2;
	int half = size/2;

	if(half < halfSize)    	//Odd Size Case
	{
		first = DivMagic(A, arrSize, half, i, i+half-1);
		firstHold[0] = first[0];
		firstHold[1] = first[1];
		firstHold[2] = first[2];

		last = DivMagic(A, arrSize, half, j-half+1, j);
		lastHold[0] = last[0];
		lastHold[1] = last[1];
		lastHold[2] = last[2];

		greed = GreedyMagic(A, arrSize, size, i+half);
		greedHold[0] = greed[0];
		greedHold[1] = greed[1];
		greedHold[2] = greed[2];

	}else					//Even Size Case
	{
		first = DivMagic(A, arrSize, half, i, i+half-1);
		firstHold[0] = first[0];
		firstHold[1] = first[1];
		firstHold[2] = first[2];

		last = DivMagic(A, arrSize, half-1, j-half+2, j);
		lastHold[0] = last[0];
		lastHold[1] = last[1];
		lastHold[2] = last[2];

		greed = GreedyMagic(A, arrSize, size, i+half);
		greedHold[0] = greed[0];
		greedHold[1] = greed[1];
		greedHold[2] = greed[2];
	}


	magic = maxOf(maxOf(greedHold[0],firstHold[0]),lastHold[0]);
	
	if(magic == greedHold[0])
	{
		return greedHold;
	}
	if(magic == firstHold[0])
	{
		return firstHold;
	}
	if(magic == lastHold[0])
	{
		return lastHold;
	}

	// Return 0's if algorithm goes wrong

	unsigned long long int def[3] = {0};
	return def;

}

int main()
{
	int arraySize = 0;
	FILE *testFile;
/*
 *	CHANGE TEXT FILE HERE vvv
*/
	testFile = fopen("T8.txt","r");


	fscanf(testFile,"%d ", &arraySize);

	unsigned long long int array[arraySize];

	for(int i=0; i<arraySize; i++)
	{
		fscanf(testFile, "%llu ", &array[i]);
	}

	unsigned long long int *result;

	//result = mostMagical(array, arraySize);	
	result = DivMagic(array, arraySize-1, arraySize, 0, arraySize-1);

	printf("%llu %llu %llu\n", result[0], result[1], result[2]);

	return 0;

}
