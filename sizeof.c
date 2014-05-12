#include <stdio.h>

int main()
{
	int a = 10;
	int b = 9;
	int x[10];
	int *p = x;
	printf("%d\n", sizeof(x)/sizeof(*x));
	printf("%d\n", sizeof(p)/sizeof(*p));
	printf("%d\n", sizeof(main()));
	printf("%d\n", sizeof(a < b));
	return 0;
}
