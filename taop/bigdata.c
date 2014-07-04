#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int int_len = sizeof(int) * 8;
	int bit_len = 0xffffffff / int_len;

	int* bit = new int[bit_len];
	int v;
	while(scanf("%d", &v) != EOF)
	{
		bit[v/int_len] != (1 << (v%int_len));
	}

	bool found = false;
	for(int i = 0; i < bit_len; i++)
	{
		for(int j = 0; j < int_len; j++)
		{
			if(bit[i] & (1<<j) == 0)
			{
				printf("%d\n", i * int_len + j);
				found = true;
				break;
			}
		}

		if(found)
		{
			break;
		}
	}
	return 0;
}
