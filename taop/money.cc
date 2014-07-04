#include <stdio.h>

int main(int argc, char **argv)
{
	int N = 100;
	int dimes[] = {1,2,5,10};
	int arr[N+1];

	for(int i = 0; i <= N; i++)
	{
		arr[i] = 1;
	}

	for (int i = 0; i < sizeof(dimes)/sizeof(int); ++i)
	{
	    for(int j = dimes[i]; j <= N; ++j) 
	    {
	          arr[j] += arr[j - dimes[i]];
		}
		for(int i = 0; i <= N; i++)
		{
			printf("%d\t", arr[i]);
		}
		printf("\n");
	}

	return 0;
}
