#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class WidgetImpl 
{
public:
	WidgetImpl(const WidgetImpl& rhs)
	{
		
	}
private:
	int a;
	int b;
	int c;
	vector<double> v;
};

class Widget
{
public:
	Widget(const Widget& rhs)
	{
		//this.pImpl = rhs.pImpl;	
		pImpl = new WidgetImpl(*(rhs.pImpl));
	}
	Widget& operator=(const Widget& rhs)
	{
		WidgetImpl* pOrig = pImpl;
		pImpl = new WidgetImpl(*(rhs.pImpl));
		delete pOrig;
		return *this;
	}
	void swap(Widget& other)
	{
		using std::swap;
		swap(pImpl, other.pImpl);
	}
private:
	WidgetImpl* pImpl;
};

namespace std
{
	template<>
	void swap<Widget>(Widget& a, Widget &b)
	{
		a.swap(b);
	}
}
int main(void)
{
	return 0;
}
