#include <iostream>
#include <algorithm>
#include <limits.h>
#include <iterator>
#include <ostream>

using namespace std;

/*
一个序列有N个数：A[1],A[2],…,A[N]，求出最长非降子序列的长度。
*/

int main(){ 
	int v[6] = {5, 3, 4, 8, 6, 7};
	int max[6];
	fill(max, max + 6, INT_MIN);
	max[0] = 1;
	for(int i = 1; i < 6; i++){ 
		for(int j = 0; j < i; j++){ 
			if(v[i] => v[j] && max[i] < max[j] + 1){ 
				max[i] = max[j] + 1;
			}
		}
	}
	copy(max, max + 6, ostream_iterator<int>(cout, " "));
	return 0;
}