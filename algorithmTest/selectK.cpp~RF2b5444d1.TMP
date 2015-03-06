#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <ostream>
#include <iterator>

using namespace std;

struct Cmp{
  	bool operator()(vector<int> s, vector<int> t) const {
    	return s[0] > t[0];
	}
};

vector<int> selectK(vector<vector<int> > nmMatrix, int k);

int main(){ 
	srand(time(NULL));
	vector<vector<int> > nm;
	for(int i = 0; i < 10; i++){
		vector<int> n;
		for(int j = 0; j < 10; j++) {
			n.push_back(rand() % 100);
		}
		sort(n.begin(), n.end());
		nm.push_back(n);
	}

	vector<int> r = selectK(nm, 9);
	copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;
	return 0;
}

vector<int> selectK(vector<vector<int> > nmMatrix, int k){ 
	vector<int> sortK;

	vector<vector<int> > heap;
	vector<int> load;
	for(int i = 0; i < nmMatrix.size(); i++){ 
		heap.push_back(nmMatrix[i]);
	}

	make_heap(heap.begin(), heap.end(), Cmp());

	while(!heap.empty()){ 
		pop_heap(heap.begin(), heap.end(), Cmp());
		load = heap.back();
		sortK.push_back(load[0]);
		if(sortK.size() == k) break;
		if(load.size() == 1){ 
			heap.pop_back();
		}
		else{ 
			heap.pop_back();
			load.erase(load.begin());
			heap.push_back(load);
			push_heap(heap.begin(), heap.end(), Cmp());
		}
	}

	return sortK;
}