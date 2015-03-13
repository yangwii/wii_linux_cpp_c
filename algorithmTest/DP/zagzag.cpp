#include <iostream>
#include <algorithm>
#include <limits.h>
#include <iterator>
#include <ostream>

using namespace std;

/*
A sequence of numbers is called a zig-zag sequence if the differences between 
successive numbers strictly alternate between positive and negative. The first
difference (if one exists) may be either positive or negative. A sequence with 
fewer than two elements is trivially a zig-zag sequence.

For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) 
are alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not 
zig-zag sequences, the first because its first two differences are positive and the 
second because its last difference is zero.
*/

int main(){ 
	int v[19] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
	//int v[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int max[19];
	int x[19];
	x[0] = 0;
	for(int i = 1; i < 19; i++){ 
		x[i] = v[i] - v[i - 1];
	}
	fill(max, max + 19, 1);
	max[0] = 1;
	max[1] = 2;
	for(int i = 2; i < 19; i++){ 
		for(int j = 1; j < i; j++){ 
			if((v[i] - v[j] > 0 && x[j] < 0) || (v[i] - v[j] < 0 && x[j] > 0)){
				if(max[i] < max[j] + 1){ 
					max[i] = max[j] + 1;
				}
			}
		}
	}
	copy(max, max + 19, ostream_iterator<int>(cout, " "));
	return 0;
}
