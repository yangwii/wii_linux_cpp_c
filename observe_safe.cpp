#include <algorithm>
#include <vector>
#include <vector>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <pthread.h>
#include <stdio.h>

using namespace std;

pthread_mutex_t mutex;
class Observable;

class Observer : public boost::enable_shared_from_this<Observer>
{
public:
	virtual ~Observer();
	virtual void update() = 0;

	void observe(Observable *s);
protected:
	Observable *subject_;
};

class Observable
{
public:
	void register_(boost::weak_ptr<Observer> x);

	void notifyObservers()
	{
		pthread_mutex_lock(&mutex);	
		Iterator it = observers_.begin();
		while(it != observers_.end())
		{
			boost::shared_ptr<Observer> obj(it->lock());
			if(obj)
			{
				obj->update();
				++it;
			}
			else
			{
				printf("notify erase()\n");
				it = observers_.erase(it);
			}
		}
		pthread_mutex_unlock(&mutex);
	}
private:
	vector<boost::weak_ptr<Observer> > observers_;
	typedef vector<boost::weak_ptr<Observer> >::iterator Iterator;
};

Observer::~Observer()
{

}

void Observer::observe(Observable *s)
{
	s->register_(shared_from_this());
	subject_ = s;
}

void Observable::register_(boost::weak_ptr<Observer> x)
{
	observers_.push_back(x);
}

class Foo : public Observer
{
public:
	virtual void update()
	{
		printf("Foo: update() %p\n", this);
	}
};

int main(void)
{
	if(pthread_mutex_init(&mutex, NULL))
	{
		printf("mutex init failed\n");
		return 1;
	}

	Observable subject;
	boost::shared_ptr<Foo> p(new Foo);
	/*
	subject.register_(p);
	*/
	boost::shared_ptr<Foo> pp(new Foo);
	p->observe(&subject);
	pp->observe(&subject);
	subject.notifyObservers();
	pthread_mutex_destroy(&mutex);
	return 0;
}
