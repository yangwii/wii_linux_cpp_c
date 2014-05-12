#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

template <class T>
class Runtime{
public:
	enum cmp_mode{normal, reverse};
private:
	cmp_mode mode;
public:
	Runtime(cmp_mode m = normal):mode(m){}

	bool operator()(const T &t1, const T &t2)
	{
		return mode == normal? t1 < t2: t2 < t1;
	}

	bool operator==(const Runtime &rc)
	{
		return mode = rc.mode;
	}
};

typedef set<int, Runtime<int> > IntSet;

void file(IntSet & set);

int main()
{
	cout<<sizeof("hello")<<endl;
	IntSet set1;
	file(set1);
	copy(set1.begin(), set1.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;
	Runtime<int> reverse_order(Runtime<int>::reverse);
	IntSet set2(reverse_order);
	file(set2);
	copy(set2.begin(), set2.end(), ostream_iterator<int>(cout, " "));
	return 0;
}
void file(IntSet & set)
{
	set.insert(4);
	set.insert(7);
	set.insert(5);
	set.insert(1);
	set.insert(2);
	set.insert(5);
}
