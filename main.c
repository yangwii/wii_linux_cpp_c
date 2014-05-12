#include <stdio.h>

int main()
{
	int arr[2][2] = {1, 2, 3, 4};
	typedef int int_array[2];
	int_array *a; 
	for(int_array *p = arr; p != arr + 2; p++)
		for(int *q = *p; q != *p + 2; q++) 
		{
			printf("%d\n", *q);	
		}
	return 1; 
}
