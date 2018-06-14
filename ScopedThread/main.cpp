#include <thread>
#include <stdexcept>
#include <iostream>


class ScopedThread
{
public:
	explicit ScopedThread(std::thread _t)
		:t(std::move(_t)){
		if (!t.joinable())
			throw std::logic_error("No valid thread.");
	}

	~ScopedThread() {
		t.join();
	}

	ScopedThread(const ScopedThread&) = delete;

	ScopedThread operator = (const ScopedThread&) = delete;

	auto id()
	{
		return t.get_id();
	}

private:
	std::thread t;
};

void func()
{
	std::cout << "func is working on " 
		<< std::this_thread::get_id() << std::endl;
}

int main()
{
	std::cout << "main is working on "
		<< std::this_thread::get_id() << std::endl;

	try
	{
		ScopedThread t(std::thread(std::bind(func)));
		std::thread tt;
		ScopedThread t2((std::thread&&)(tt));
		//auto bb = t2.joinable();
		auto id1 = t.id();
		auto id2 = t2.id();
		int cc = 00;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	//ScopedThread t(std::thread(std::bind(func))); // avoiding '未调用原型函数(是否是有意用变量定义的?)'
	//ScopedThread t2(std::thread());
	//ScopedThread t(std::thread(static_cast<void(*)()>(func))); // ok too.

	return 0;
}
