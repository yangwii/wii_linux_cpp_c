#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int strToInt(const char *str);

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("./a.out 123456\n");
		return 1;
	}

	printf("%d\n", strToInt(argv[1]));
	return 0;
}

int strToInt(const char *str)
{
	static const int MAX_INT = (int)((unsigned)~0 >> 1);//2^31 - 1
	static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;//-2^31
	unsigned int n = 0;

	if(str == 0)
	{
		return 0;
	}

	//处理正负
	int sign = 1;
	if(*str == '+' || *str == '-')
	{
		if(*str == '-')
		{
			sign = -1;
		}
		++str;
	}

	while(isdigit(*str))
	{
		int c = *str - '0';
		if(sign > 0 && (n > MAX_INT / 10) || (n == MAX_INT / 10 && c > MAX_INT
								% 10))
		{
			n = MAX_INT;
			break;
		}
		else if(sign < 0 && (n > (unsigned)MIN_INT / 10) || (n == (unsigned)MIN_INT / 10 && c > 
								(unsigned)MIN_INT % 10))
		
			n = MIN_INT;
			break;
		}

		n = 10 * n + c;
		++str;
	}

	return sign > 0 ? n : -n;
}
