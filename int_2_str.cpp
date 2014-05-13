#include <iostream>
#include <algorithm>

using namespace std;

const char* convert(char buf[], int val)
{
	static char digits[19] =
				{'9', '8', '7', '6', '5', '4', '3', '2', '1', '0', '1', '2',
					'3', '4', '5', '6', '7', '8', '9'};
	static const char* zero = digits + 9;

	int i = val;
	char* p = buf;
	do
	{
		int lsd = i % 10;
		i = i / 10;
		*p++ = zero[lsd];
	}while(i != 0);

	if(val < 0)
	{
		*p++ = '-';
	}
	*p = '\0';

	reverse(buf, p);
	return p;
}

int main(int argc, char **argv)
{
	char p[10];
	int i = atoi(argv[1]);
	convert(p, i);
	cout<<p<<endl;
	return 0;
}
