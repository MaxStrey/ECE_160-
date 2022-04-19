#include <stdio.h>

int largest_num(int array[], int n)
{	
	int l = array[0];
	for (int i = 1; i < n; i++)
	{
		if (array[i] > l)
		{
			l = array[i];
		}
	}
	return l;
}	

int smallest_num(int array[], int n)
{
	int s = array[0];
	for (int i = 1; i < n; i++)
	{
		if (array[i]<s)
		{
			s = array[i];
		}
	}
	return s;
}

int main()
{
	int array[4] = {0, 3, 6, 2};
	int n = sizeof(array)/sizeof(int);
	// printf("%d\n",array[0]);
	// printf("%d\n",n);
	printf("largest %d\n", largest_num(array, n));
	printf("smallest %d\n", smallest_num(array, n));
	return 0;
}
