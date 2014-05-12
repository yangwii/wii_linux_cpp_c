#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main(void)
{
	vector<int> ivec;
	int i;
	while(cin>>i)
			ivec.push_back(i);
	vector<int>::iterator iter = find_if(ivec.begin(), 
					ivec.end(),  bind2nd(modulus<int>(), 2));
	if(iter == ivec.end())
			cout<<"zhengchu!!"<<endl;
	else
			cout<<"NO!"<<endl;
	return 0;
}
