#include <iostream>
#include <string>

using namespace std;

/**
*  求左部分中的最大值减去右部分最大值的绝对值
*  vec: 输入数组
*  len vec的长度
*  返回：左部分中的最大值减去右部分最大值的绝对值
*/
 
int getMaxABSLeftAndRight(vector<int> vec, int len) {
	int tail = len - 1;
	int head = 0;
	int max = 0;
	if(vec[head] < vec[tail]){ 
		max = tail;
		tail--;
		while(head < tail){ 
			if(vec[max] < vec[tail]){ 
				max = tail;
			}
			tail--;
		}
		return vec[max] - vec[head];
	}
	else{ 
		max = head;
		head++;
		while(head < tail){ 
			if(vec[max] < vec[head]){ 
				max = head;
			}
			head++;
		}
		return vec[max] - vec[tail];
	}
}

int main(void){ 
	return 0;
}