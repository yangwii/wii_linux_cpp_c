#include <iostream>
#include <vector>


/*
一个递增数组如【1，2，3，4，5】可以右移 例如【3，4，5，1，2】
请设计一个函数int indexofArray(int []array, int target)，如果target在数字中返回数组下标否则返回-1
*/

using namespace std;

int indexOfArray(int arr[], int len, int target){ 
	int l = 0;
	int r = len - 1;
	while(l <= r){ 

		if(arr[l] < arr[r] && (target > arr[r] || arr[l] > target)){ 
			return -1;
		}

		int mid = (l + r) / 2;
		if(arr[mid] == target){ 
			return mid;
		}

		if(arr[l] < arr[mid] && target >= arr[l] && target < arr[mid]){ 
			r = mid - 1;
			continue;
		}

		if(arr[mid] < arr[r] && target > arr[mid] && target <= arr[r]){ 
			l = mid + 1;
			continue;
		}

		if(arr[l] > arr[mid]){ 
			r = mid - 1;
			continue;
		}

		if(arr[r] < arr[mid]){ 
			l = mid + 1;
			continue;
		}
	}

	return -1;
}
int main(void){
	/* code */
	return 0;
}