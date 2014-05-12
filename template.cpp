#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

template <typename T, typename U>
T& operator<<(T& os, vector<U>& vec)
{
	typename vector<U>::iterator begin = vec.begin();
	typename vector<U>::iterator end = vec.end();
	for(; begin != end; begin++)
	{
		os<<*begin<<" ";
	}
	return os;
}

int main(int argc, char *argv[])
{
	string aa[] = {"car", "truck", "rabbit"};
	vector<string> things(aa, aa + 3);

	ostringstream oss;
	oss<<things<<endl;
	string str = oss.str();
	//cout<<str<<endl;
	copy(str.begin(), str.end(), ostream_iterator<char>(cout, ""));
	return 0;
}
