#include <algorithm>
#include <vector>
#include <stdio.h>
#include <boost/shared_ptr.hpp>

using namespace std;
class Observable;

class Observer
{
public:
   virtual ~Observer();
   virtual void update() = 0;
   void observe(Observable* s);
protected:
   Observable* subject_;
};

class Observable
{
public:
   void register_(Observer* x);
   void unregister(Observer* x);
   void notifyObservers()
   {
   		for (size_t i = 0; i < observers_.size(); ++i)
		{
	    	Observer* x = observers_[i];
			if (x)
			{
				x->update(); // (3)
			}
	    }
	}

private:
    std::vector<Observer*> observers_;
};

Observer::~Observer()
{
	subject_->unregister(this);
}

void Observer::observe(Observable* s)
{
	 s->register_(this);
	 subject_ = s;
}

void Observable::register_(Observer* x)
{
	 observers_.push_back(x);
}

void Observable::unregister(Observer* x)
{
	std::vector<Observer*>::iterator it = std::find(observers_.begin(), observers_.end(), x);
	if (it != observers_.end())
	{
	     std::swap(*it, observers_.back());
	     observers_.pop_back();
	}
}

// ---------------------

class Foo : public Observer
{
	virtual void update()
	{
		printf("Foo::update() %p\n", this);
	}
};


class Fooo : public Observer
{
	virtual void update()
	{
		printf("Fooo:update() %p\n", this);
	}
};

int main()
{
	//tr1::shared_ptr<Observer*> ptr(new Foo);
	//Foo* p = new Foo;
	boost::shared_ptr<Foo> p(new Foo);
	boost::shared_ptr<Fooo> pp(new Fooo);
	//Fooo* pp = new Fooo;
	Observable subject;
	//subject.register_(p);
	//subject.register_(pp);
	p->observe(&subject);
	pp->observe(&subject);
	subject.notifyObservers();
	//subject.unregister(p);
	//delete p;//此处delete产生dangling pointer，core dump
//	subject.notifyObservers();
}
