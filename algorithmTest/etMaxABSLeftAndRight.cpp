#include <iostream>
#include <string>

using namespace std;

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