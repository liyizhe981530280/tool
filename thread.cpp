/*************************************************************************
	> File Name: thread.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2018年12月13日 星期四 09时02分40秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
using namespace std;

namespace threadguard
{
class ThreadGuard
{
  private:
	thread &m_thread;

  public:
	ThreadGuard(thread &);
	~ThreadGuard();
	ThreadGuard(const ThreadGuard &) = delete;
	ThreadGuard &operator=(const ThreadGuard &) = delete;
};
ThreadGuard::ThreadGuard(thread &t) : m_thread(t)
{
}
ThreadGuard::~ThreadGuard()
{
	if (m_thread.joinable())
	{
		m_thread.join();
	}
}
} // namespace threadguard
class SelfException
{
  public:
	SelfException()
	{
		cout << "a self defined exception " << endl;
	}
};

void func()
{
	while (1)
	{
		cout << "hello world ;...!" << endl;
	}
}
#include <queue>
#include <mutex>
#include <condition_variable>
#include <initializer_list>

namespace gdface
{
inline namespace mt
{
template <typename T>
class threadsafe_queue
{
  private:
	mutable std::mutex mut;
	mutable std::condition_variable data_cond;
	using queue_type = std::queue<T>;
	queue_type data_queue;

  public:
	using value_type = typename queue_type::value_type;
	using container_type = typename queue_type::condition_variable;
	threadsafe_queue() = default;
	threadsafe_queue(const threadsafe_queue &) = delete;
	threadsafe_queue &operator=(const threadsafe_queue &) = delete;

	template <typename _InputIterator>
	threadsafe_queue(_InputIterator first, _InputIterator last)
	{
		for (auto itor = first; itor != last; ++itor)
		{
			data_queue.push(*itor);
		}
	}

	explicit threadsafe_queue(const container_type &c) : data_queue(c) {}

	threadsafe_queue(std::initializer_list<value_type> list) : threadsafe_queue(list.begin(), list.end())
	{
	}

	void push(const value_type &new_value)
	{
		std::lock_guard<std::mutex> lk(mut);
		data_cond.wait(lk, [this] {
			return !this->data_queue.empty();
		});

		auto value = std::move(data_queue.front());
		data_queue.pop();
		return value;
	}

	bool type_pop(value_type &value)
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
		{
			return false;
		}

		value = std::move(data_queue.front());
		data_queue.pop();
		return true;
	}

	auto empty() const -> decltype(data_queue.empty())
	{
		std::lock_guard<std::mutex> lk(mut);
		return data_queue.empty();
	}
	auto size() const -> decltype(data_queue.empty())
	{
		std::lock_guard<std::mutex> lk(mut);
		return data_queue.size();
	}

	bool type_pop_front(value_type &value)
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
		{
			return false;
		}

		value = data_queue.front();
		return true;
	}

	bool try_pop_pop()
	{
		std::lock_guard<std::mutex> lt(mut);
		if (data_queue.empty())
		{
			return false;
		}
		data_queue.pop();
		return true;
	}

	void clear()
	{
		std::lock_guard<std::mutex> lk(mut);
		queue_type empty;
		swap(empty, data_queue);
	}
};
} // namespace mt
} // namespace gdface
using namespace threadguard;
int main()
{
	thread t(func);
	ThreadGuard tg(t);
	try
	{
		throw SelfException();
	}
	catch (...)
	{
	}

	return 0;
}
