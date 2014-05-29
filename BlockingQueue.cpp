#include <stdio.h>
#include <pthread.h>
#include <boost/noncopyable.hpp>
#include <assert.h>
#include <deque>

class MutexLock : boost::noncopyable
{
private:
	pthread_mutex_t mutex_;
public:
	MutexLock()
	{
		pthread_mutex_init(&mutex_, NULL);	
	}

	~MutexLock()
	{
		pthread_mutex_destroy(&mutex_);
	}

	void lock()
	{
		pthread_mutex_lock(&mutex_);
	}

	void unlock()
	{
		pthread_mutex_unlock(&mutex_);
	}

	pthread_mutex_t* getPthreadMutex()
	{
		return &mutex_;
	}
};

class MutexLockGuard : boost::noncopyable
{
public:
	explicit MutexLockGuard(MutexLock& mutex):mutex_(mutex)
	{
		mutex_.lock();
	}
	~MutexLockGuard()
	{
		mutex_.unlock();
	}
private:
	MutexLock& mutex_;
};

class Condition : boost::noncopyable
{
private:
	MutexLock& mutex_;
	pthread_cond_t pcond_;
public:
	explicit Condition(MutexLock& mutex):mutex_(mutex)
	{
		pthread_cond_init(&pcond_, NULL);			
	}
	~Condition()
	{
		pthread_cond_destroy(&pcond_);
	}

	void wait()
	{
		pthread_cond_wait(&pcond_, mutex_.getPthreadMutex());
	}

	void notify()
	{
		pthread_cond_signal(&pcond_);
	}

	void notifyAll()
	{
		pthread_cond_broadcast(&pcond_);
	}
};

class CountDownLatch : boost::noncopyable
{
private:
	mutable MutexLock mutex_;
	Condition condition_;
	int count_;
public:
	explicit CountDownLatch(int count) : mutex_(), condition_(mutex_), count_(count)
	{
	}

	void wait()
	{
		MutexLockGuard lock(mutex_);
		while(count_ > 0)
		{
			condition_.wait();
		}
	}

	void countDown()
	{
		MutexLockGuard lock(mutex_);
		--count_;
		if(count_ == 0)
		{
			condition_.notifyAll();
		}
	}
};

template <typename T>
class BlockingQueue : boost::noncopyable
{
private:
	mutable MutexLock mutex_;
	Condition notEmpty;
	std::deque<T> queue_;
public:
	BlockingQueue():mutex_(), notEmpty(mutex_), queue_(){}

	void put(const T& x)
	{
		MutexLockGuard lock(mutex_);
		queue_.push_back(x);
		notEmpty.notify();
	}

	T take()
	{
		MutexLockGuard lock(mutex_);

		while(queue_.empty())
		{
			notEmpty.wait();
		}

		T front(queue_.front());
		queue_.pop_front();

		return front;
	}

	size_t size() const
	{
		MutexLockGuard lock(mutex_);
		return queue_.size();
	}
};
