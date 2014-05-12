#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

struct IsOdd
{
	bool operator()(int x) const
	{
		return x %2 != 0;
	}
};

bool isOdd(int x)
{
	return x % 2 != 0;
}

bool isNegtive(int x)
{
	return x < 0;
}
int main(void)
{
	int oddeven[] = {1, 2, 3, 4, 5, 6};
	int negpas[] = {2, -1, 3, 5, -5, -7, 10, 11};
	stable_partition(oddeven, oddeven + 6, IsOdd());
	stable_partition(negpas, negpas + 8, isNegtive);
	copy(oddeven, oddeven + 6, ostream_iterator<int>(cout, ", "));
	cout<<endl;
	copy(negpas, negpas + 8, ostream_iterator<int>(cout, ", "));
	cout<<endl;
	return 0;
}
