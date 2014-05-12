#include <iostream>
#include <stack>

using namespace std;
void reverse(stack<int> & s, int tmp)
{
	if(!s.empty())
	{
		tmp = s.top();
		s.pop();
		reverse(s, tmp);
	}
	cout<<tmp<<"\n";
	s.push(tmp);
}
void printstack(stack<int> s)
{
	while(!s.empty())
	{
		cout<<s.top()<<"\t";
		s.pop();
	}
	cout<<"\n";
}
int main(int argc, char *argv[])
{
	int arr[5] = {1, 2, 3, 4, 5};
	stack<int> ist; //(arr, arr + 5);
	ist.push(1);	
	ist.push(2);	
	ist.push(3);	
	ist.push(4);	
	ist.push(5);	
	//cout<<ist.top();	
	printstack(ist);	
	reverse(ist, 1);
	printstack(ist);	
	//ist.pop();
	//cout<<ist.top();	
	return 0;
}
