#include <iostream>

using namespace std;

class Link;
class LinkAllocator
{
	enum {BlockLinks = 16};
	class Block
	{
	public:
		Block* Next() {return _next;}
		void SetNext(Block* next) {_next = next;}
	private:
		Block* _next;
	};
public:
	LinkAllocator():_p(0), _blocks(0){}
	~LinkAllocator();
	void Purge();
	void* NextLink();
	void Recycle(void* link);
private:
	Link* _p;
	Block* _blocks;
};

void* LinkAllocator::NewLink()
{
	if(_p == 0)
	{
		char* p = ::new char[sizeof (Block) + BlockLinks * 
				sizeof(Link)];
		Block* block = reinterpret_cast<Block*>(p);
		_blocks = block;

		p += sizeof(Block);
		for(int i = 0; i < BlockLinks; ++i)
		{
			Link* link = reinterpret_cast<Link*>(p);
			link->_pNext = _p;
			_p = link;
			p += sizeof(Link);
		}
	}
	void* mem = _p;
	_p = _p->_pNext;
	return mem;
}

void LinkAllocator::Purge()
{
	while(_blocks != 0)
	{
		char* mem = reinterpret_cast<char *>(_blocks);
		_blocks = _blocks->Next();
		::delete [] mem;
	}
}
