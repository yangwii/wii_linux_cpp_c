#include <stdio.h>

int valueofcoin(int i)
{
	switch(i)
	{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 5;
		case 4:
			return 10;
	}
}
int cc(int amount, int kindofcoin)
{
	if(amount == 0)
		return 1;
	else if(amount < 0 || kindofcoin == 0)
		return 0;
	else 
		return cc(amount, kindofcoin - 1) + cc (amount - valueofcoin(kindofcoin), kindofcoin);
}
int main(int argc, char **argv)
{
	printf("%d\n", cc(100, 4));
	return 0;
}
