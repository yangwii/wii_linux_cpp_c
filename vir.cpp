#include <iostream>

using namespace std;

class awov
{
public:
		virtual ~awov() = 0;
};

awov::~awov()//纯虚也可以有是实现
{
	cout<<"Base"<<endl;
}

class drived : public awov
{
public:
	~drived()
	{
		cout<<"Drived"<<endl;
	}
};

int main(void)
{
	drived d;
	awov* pa = &d;
	return 0;
}
