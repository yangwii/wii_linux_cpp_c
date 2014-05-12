#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class WriteString
{
public:
	WriteString(istream& i = cin):is(i){}
	bool operator()(string &s)
	{
		return getline(is, s);
	}
private:
	istream& is;
};


class PrintString
{
public:
	PrintString(ostream &o = cout, char c = ' '):
			os(o), sep(c) {}
	void operator()(const string& str) const { os << str << sep; }
private:
	ostream &os;
	char sep;
};


struct absInt
{
	int operator()(int val) const
	{
		return val < 0? -val: val;
	}
};
int main(void)
{
	vector<string> vstr;
	WriteString wstr(cin);
	string s;
	while(wstr(s))
	{
		vstr.push_back(s);
	}
	for_each(vstr.begin(), vstr.end(), PrintString(cout, '\t'));
	return 0;
}
