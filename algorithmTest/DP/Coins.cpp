#include <iostream>
#include <algorithm>
#include <limits.h>
#include <iterator>
#include <ostream>

/*
如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？
*/

using namespace std;

int main(){ 
	int v[3] = {1, 3, 5};
	int min[12];
	fill(min, min + 12, INT_MAX);
	min[0] = 0;
	for(int i = 1; i < 12; i++){ 
		for(int j = 0; j < 3; j++){ 
			if(i >= v[j] && min[i] > min[i - v[j]] + 1){ 
				min[i] = min[i - v[j]] + 1;
			}
		}
	}
	copy(min, min + 12, ostream_iterator<int>(cout, " "));
	return 0;
}
