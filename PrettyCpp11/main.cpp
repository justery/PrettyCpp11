#include <mutex>
#include <iostream>


bool ready;
std::mutex mtx;

int main()
{
	std::thread t1([]{
		std::lock_guard<std::mutex> g(mtx);
		ready = true;
	});

	std::thread t2([] {
		std::lock_guard<std::mutex> g(mtx);
		std::cout << " ready: " << std::boolalpha<< ready << std::endl;
	});

	t1.join();
	t2.join();
	return 0;
}