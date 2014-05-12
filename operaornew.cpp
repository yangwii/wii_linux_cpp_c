#include <iostream>
#include <assert.h>

using namespace std;

class Link;
class FreeList
{
public:
	FreeList(): _p(0){}	
	~FreeList();
	void Purge();
	void * NewLink();
	void Recycle(void * link);
private:
	Link * _p;
};

/*
void* FreeList::NewLink()
{
	if(_p != 0)
	{
		void *mem = _p;
		_p = _p->_pNext;
		return mem;
	}
	else
	{
		return ::new char[sizeof Link];
	}
}
*/

class Link
{
	friend class FreeList;
public:
	Link(Link *pNext, int id):_pNext(pNext), _id(id){}
	Link* Next() const {return _pNext;}
	int Id() const {return _id;};

	void* operator new(size_t size)
	{
		assert(size == sizeof(Link));
		return _freeList.NewLink();
	}
	void operator delete(void *mem)
	{
		if(mem)
			_freeList.Recycle(mem);
	}
	static void Purge()
	{
		_freeList.Purge();
	}
private:
	static FreeList _freeList;
	Link* _pNext;
	int _id;
};

class List
{
public:
	List();
	~List()
	{
		while(_pHead != 0)
		{
			Link *pLink = _pHead;
			_pHead = _pHead->Next();
			delete pLink;
		}
	}

	void Add(int id)
	{
		Link *pLink = new Link(_pHead, id);
		_pHead = pLink;
	}

	Link const* GetHead()const
	{
		return _pHead;
	}
private:
	Link *_pHead;
};

class HTable
{
public:
	explicit HTable(int size):_size(size)
	{
		_aList = new List[size];
	}

	~HTable()
	{
		delete [] _aList;
		Link::Purge();
	}
private:
	List *_aList;
	int _size;
};

void* FreeList::NewLink()
{
	if(_p != 0)
	{
		void *mem = _p;
		_p = _p->_pNext;
		return mem;
	}
	else
	{
		return ::new char[sizeof (Link)];
	}
}

void FreeList::Recycle(void *mem)
{
	Link* link = static_cast<Link *>(mem);
	link->_pNext = _p;
	_p = link;
}

FreeList::~FreeList()
{
	Purge();
}

void FreeList::Purge()
{
	while(_p != 0)
	{
		char* mem = reinterpret_cast<char *>(_p);
		_p = _p->Next();
		::delete [] mem;
	}
}
FreeList Link::_freeList;
int main()
{
	return 0;
}
