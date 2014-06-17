#include <stdio.h>

int main()
{
	int a = 10;
	int b = 9;
	int x[10];
	int *p = x;
	printf("%d\n", sizeof(x)/sizeof(*x));//10
	printf("%d\n", sizeof(p)/sizeof(*p));//1
	printf("%d\n", sizeof(main()));//4
	printf("%d\n", sizeof(a < b));//1
	return 0;
}
