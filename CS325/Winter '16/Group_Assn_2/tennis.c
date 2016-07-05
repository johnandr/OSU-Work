#include <stdio.h>
#include <stdlib.h>

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

void distance(int keys[], int balls[], int t, int m, int save_t[][t])
{
	int i, j, k, dif;
	for (i = 0; i < m; i++)
	{
		for(j = 0; j < t; j++)
		{
			dif = balls[j] - keys[i];
			
			save_t[i][j] = dif;
			printf("%d ", dif);
		}
		printf("\n");
		/*for(j = 0; j < t; j++)
		{
			if(save_t[i][j] < 0 && j > 0)
			{
				save_t[i][j] = 0;
			}
			else if(save_t[i][j] > 0)
			{
				for(k = 0; k < t; k++)
				{
					save_t[i][k] -= save_t[i][j];
				}
			}
			printf("%d ", save_t[i][j]);
		}
		printf("\n\n");*/
	}
}

int recursion(int test[], int t, int a_size, int count, int dist_key1[][t])
{
	if(count > 0) {
        test[ a_size - count] = 0;
        recursion(test, t, a_size, count - 1, dist_key1);
        test[ a_size - count] = 1;
        recursion(test, t, a_size, count - 1, dist_key1);
    }

	else {
		int sum = 0, i, max, min, key1, key2, key3, count;
        for(i = 0; i < a_size; i++)
        {
        	sum = sum + test[i];
        	printf("%d", test[i]);
        }
        printf("\n");
        if(sum > 0)
        {
    		/*for(i = 0; i < a_size; i++)
    		{
    			if(test[i] == 1)
    			{
    				key1 = i;
    				break;
    			}
    		}
    		max = dist_key1[key1][0];
    		min = dist_key1[key1][0];
    		for(i = 1; i < t; i++)
    		{
    			if(max < dist_key1[key1][i])
    			{
    				max = dist_key1[key1][i];
   				}
   				if(min > dist_key1[key1][i])
    			{
    				min = dist_key1[key1][i];
   				}
    		}
    		printf("key: %d\n\tmax: %d\n\tmin: %d\n", key1, max, min);
    		return;
    		*/
        }
    }

}

int main()
{
	//int keys[] = {1, 3, 8}, balls[] = {2, 5, 6, 9};
	int keys[] = {6, 4, 2, 7, 5}, balls[] = {13, 1, 6, 9, 4, 2};
	int n = 3, m = sizeof(keys)/ sizeof(int), t = sizeof(balls)/ sizeof(int), i, j, k;
	int pref_key1[m][t], used[n], test[m];

	sort(keys, balls, m, t);

	distance(keys, balls, t, m, pref_key1);

	recursion(test, t, m, m, pref_key1);

}