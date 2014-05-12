#ifndef __STRING__H
#define __STRING__H
#include <stddef.h>
#include <stdint.h>

namespace muduo
{
class StringEager
{
public:
	typedef char value_type;
	typedef uint32_t size_type;
	typedef int32_t difference_type;
	typedef value_type& reference;
	typedef const char& const_reference;
	typedef value_type* pointer;
	typedef const char* const_pointer;
	typedef pointer iterator;
	typedef const_pointer const_iterator;

	static const size_type npos = static_cast<size_type>(-1);
	const_pointer c_str() const {return start_;};
	const_pointer data() const {return start_;};

	iterator begin() {return start_;};
	const_iterator cbegin() {return start_;};
	const_iterator begin() {return start_;};
	
	size_type size() const {return size_;};
	size_type length() const {return size_;};
	size_type cpacity() const {return capacity_;};

	size_type max_size() const {return 1<<30;};
	bool empty() const {return size_ == 0;};

	StringEager():start_(kEmpty_), size_(0), capacity_(0){}

	StringEager(const StringEager&);
	StringEager& operator=(const StringEager&);

	~StringEager()
	{
		if(start_ != kEmpty_)
		{
			delete [] start_;
		}
	}

	StringEager(const char* str);
	StringEager(const char* str, size_t);
	StringEager& operator=(const char*);

	bool operator<(const StringEager&) const;
	bool operator<(const char*) const;
	bool operator==(const StringEager&) const;
	bool operator==(const char*) const;
	StringEager& operator+=(const StringEager&);
	StringEager& operator+=(const char* );


	void push_back(char c);
	void append(const char* str);
	void append(const char* str, size_t);

	void assign(const char* str, size_t);

	void reverse(size_type);
	void clear() throw();
	void swap(StringEager& rhs) throw();
private:
	struct NoAlloc{};

	void init(const char* str);
	StringEager(char* str, uint32_t, uint32_t, NoAlloc);
	void expandAndAppend(const char* str, size_t len);
	uint32_t nextCapacity(uint32_t) const;
	bool equals(const char* str, size_t len) const;
	bool lessThan(const char* str, size_t len) const;

	char* start_;
	size_type size_;
	size_type capacity_;

	static char kEmpty_;
	static const size_type kMinCapacity_ = 15;
};
template <typename Stream>
Stream& operator << (Stream&, const StringEager&);
}
#endif 
