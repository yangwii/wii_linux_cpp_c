#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main(void)
{
	int elements[] = {2, 3, 4, 1};
	vector<int> ivec;
	copy(elements, elements + 4, back_inserter(ivec));
	sort(ivec.begin(), ivec.end());
	copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, "\t"));
	int count = 0;
	do
	{
		cout<<++count<<" ";
		copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, "\t"));
		cout<<endl;
	}while(next_permutation(ivec.begin(), ivec.end()));
	return 0;
}
