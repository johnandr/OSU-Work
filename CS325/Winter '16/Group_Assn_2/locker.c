#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Algo1(int N, int M, int T, int K[], int B[]);
int Algo2(int N, int M, int T, int K[], int B[]);
int leastOpened(int K[], int a, int b, int B[], int B_size);
int exists(int val, int B[], int size);
int distance(int a, int b, int key[], int ball[]);
int min(int a,int b);
void sort(int keys[], int balls[], int m, int t);

int main()
{

//	Takes the numbers from text.txt and puts them
//	in their desired labels and arrays.

	int lockers = 0;
	int keys = 0;
	int balls = 0;

	FILE *ex;
	ex = fopen("test.txt", "r");

	fscanf(ex, "%d", &lockers);
	fscanf(ex, "%d", &keys);
	fscanf(ex, "%d", &balls);

	int K[keys];
	int B[balls];

	for(int i=0; i<keys; i++)
	{
		fscanf(ex, "%d", &K[i]);
	}

	for(int i=0; i<balls; i++)
	{
		fscanf(ex, "%d", &B[i]);
	}

	printf("%d %d %d \n", lockers, keys, balls);
	
	sort(K,B,keys,balls);	// Sort the key and ball array

//	Print out the test.txt file in nice output

	for(int i=0; i<keys; i++)
	{
		printf("%d ", K[i]);
	}
		printf("\n");
	for(int i=0; i<balls; i++)
	{
		printf("%d ", B[i]);
	}
		printf("\n\n");

	int answer = Algo2(lockers, keys, balls, K, B);

	printf("%d\n", answer);

	return 0;
}

//	Q.Q

int Algo1(int N, int M, int T, int K[], int B[])
{
/*
	int ans = N;
	for("All subsets of K (2^M)")
	{
		temp = 0;
		for("All pairs (i,j)")
		{
			temp = temp + solve(i,j);
		}
		temp = temp + goLeft(K[0]) + goRight(K[M-1]);
		ans = min(ans, temp);
	}
	
	return ans;
*/

//	int minKey[M][T];
	int D[M][T];

	for(int i=0; i<M; i++)
	{
		for(int j=0;j<T; j++)
		{
			D[i][j] = distance(i,j,K,B);
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}

int Algo2(int N, int M, int T, int K[], int B[])
{
	int D[M];
	int least;

//	Seeing if the first key needs to be used, if the first
//	ball is before the first key then we need to add the 
//	difference of the distance of the first key to first ball

	for(int a=0; a<M;a++)
	{
		D[a] = INT_MAX;
	}
	if(K[0] < B[0])
	{	
		D[0] = 0;
	}else
	{
		D[0] = K[0] - B[0] + 1;
	}

//	These for loops are ran in O(M^2)
//	This runs through and looks at all keys from the second 
//	till the last one

	for(int i=1; i<M; i++)
	{
		for(int j=0; j<i; j++)
		{
			least = leastOpened(K,i,j,B,T);
			if((D[j] + least) < D[i])
			{
				D[i] = D[j] + least;
			}
		}
	}

//	If there is a furthest ball that is further
//	than the furthest key than we must add the 
//  difference of the key and ball

	if(B[T-1] >= K[M-1])
	{
		D[M-1] += (B[T-1] - K[M-1]) + 1;
	}

	return D[M-1];
}

int leastOpened(int K[], int a, int b, int B[], int B_size)
{
	int best = 0;

//	Check if the keys are right next to eachother

	if((K[a]-K[b]) == 1)
	{
		if(exists(K[a],B,B_size) == 1)
		{
			if(exists(K[b],B,B_size) == 1)
			{
				return 1;
			}else
			{
				return 0;	
			}
		}else
		{
			if(exists(K[b],B,B_size) == 1)
			{
				return 1;
			}else
			{
				return 0;
			}
		}
	}else
	{
		for(int i=K[b]+1; i<K[a]; i++)
		{
			int j = i;
			if(exists(i,B,B_size)==1)
			{}
			else
			{
				while((exists(j+1,B,B_size) == 0) && (j < K[a]-1))
				{
					j += 1;
				}
				if((j-i+1) > best)
				{
					best = j - i + 1;
				}
			}
		}
	}
	return (K[a] - K[b] - best);
}

int exists(int val, int B[], int size)
{
	for(int i=0; i<size; i++)
	{
		if(val == B[i])
		{
			return 1;
		}
	}
	return 0;
}

int distance(int a, int b, int key[], int ball[])
{
	int d = ball[b] - key[a];
/*
	if(d<0)
	{
		d = d - 1;
	}else
	{
		d += 1;
	}
*/
	return d;
}

int min(int a, int b)
{
	if(a>b)
	{
		return b;
	}
	return a;
}

void sort(int keys[], int balls[], int m, int t)
{
	int i, j, temp;
    for(i = 0; i < m; i++)
	{
		for(j = i + 1; j < m; j++)
		{
			if(keys[i] > keys[j])
			{
		    	temp = keys[i];
			    keys[i] = keys[j];
			    keys[j] = temp;
			}
		}
	}
	for(i = 0; i < t; i++)
	{
		for(j = i + 1; j < t; j++)
		{
			if(balls[i] > balls[j])
			{
				temp = balls[i];
				balls[i] = balls[j];
				balls[j] = temp;
			}
		}
	}
}


