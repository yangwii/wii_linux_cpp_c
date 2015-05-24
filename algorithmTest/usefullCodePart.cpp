/*
If I have a vector of pairs
std::vector<std::pair<int, int> > vec;
is there and easy way to sort the list in increasing order based on the second element of the pair
*/

struct sort_pred{
	bool operator()(const pair(int, int) &left, const pair(int, int) &right){
		return left.second > right.second;
	}
}

sort(v.begin(), v.end(), sort_pred());

// temlate
template <class T1, class T2, class Pred = less<T1>() >
struct sort_pred{
	bool operator()(const pair(T1, T2) &left, const pair(T1, T2) &right){
		Pred p;
		return p(left.second, right.second);
	}
}
sort(v.begin(), v.end(), sort_pred<int, int>());