#include <iostream>
#include <algorithm>
#include <iterator>
#include <ostream>
#include <stack>

using namespace std;

template <class T>
class  StackQueue
{
public:
	 StackQueue(){}
	~ StackQueue(){}
	void enQueue(T t){ 
		while(!s1.empty()){ 
			T t1 = s1.top();
			s1.pop();
			s2.push(t1);
		}
		s1.push(t);
		while(!s2.empty()){ 
			T t2 = s2.top();
			s2.pop();
			s1.push(t2);
		}
	}
	T deQueue(){ 
		if(!s1.empty()){ 
			T t3 = s1.top();
			s1.pop();
			return t3;
		}
		else{ 
			return NULL;
		}
	}
private:
	stack<T> s1;
	stack<T> s2; 	
};

int main(){ 
	StackQueue<int> sq;
	sq.enQueue(1);
	sq.enQueue(2);
	sq.enQueue(3);

	cout<<sq.deQueue()<<endl;
	return 0;
}