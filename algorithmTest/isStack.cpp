#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s, string t);

int main(){
	string s = "123";
	string t = "123";
	if(isValid(s, t)){ 
		cout<<"is valid"<<endl;
	}
	else{ 
		cout<<"is no valid"<<endl;
	}

	return 0;
}

bool isValid(string s, string t){ 
	stack<char> cs;
	int i = 0;
	int j = 0;
	bool flag = false;
	int size = s.size();
	cs.push(s[i++]);
	while(true){ 
		if(cs.empty() && i == j && i == size){ 
			flag = true;
			break;
		}
		if(cs.top() == t[j]){ 
			j++;
			cs.pop();
			if(cs.empty() && i < size){ 
				cs.push(s[i++]);
			}
		}
		else{ 
			if(i == size){ 
				flag = false;
				break;
			}
			cs.push(s[i++]);
		}
	}

	return flag;
}