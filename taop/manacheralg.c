#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int manacher(char *s);

int main(int argc, char **argv)
{
	manacher(argv[1]);
	return 0;
}

int manacher(char *s)
{
	int len = strlen(s);
	if(len == 0)
	{
		return 0;
	}
	//构造辅助数组;
	int p[2 * len + 2];
	memset(p, 0, 2 * len + 2);

	char _s[2 * len + 3];
	
	_s[0] = '$';
	_s[1] = '#';
	for(int i = 0, j = i + 2; i < len; i++)
	{
		_s[j] = s[i];
		_s[j + 1] = '#';
		j = j + 2;
	}
	_s[2 * len + 2] = '\0';

	//printf("%s\n", s);
	//printf("%s\n", _s);

	int mx = 0;
	int id;
	for(int i = 1; i < strlen(_s); i++)
	{
		if(mx > i)
		{
			if(p[2 * id - i] < mx - i)
			{
				p[i] = p[2 * id - i];
			}
			else
			{
				p[i] = mx - i;
			}
		}
		else
		{
			p[i] = 1;
		}

		for(; _s[i + p[i]] == _s[i - p[i]]; p[i]++)
				;
	
		if(p[i] + i > mx)
		{
			mx = p[i] + i;
			id = i;
		}
	}

	int max = p[0];
	for(int i = 1; i < 2 * len + 2; i++)
	{
		if(max < p[i])
			max = p[i];
	}

	printf("%d\n", max);
}
