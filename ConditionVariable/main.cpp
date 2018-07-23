#include <mutex>
#include <iostream>


bool ready = false;
std::mutex mtx;
std::condition_variable cv;

int main()
{
	std::thread t1([] {
		std::lock_guard<std::mutex> g(mtx);
		ready = true;
		cv.notify_one();
	});

	std::thread t2([] {
		std::unique_lock<std::mutex> ul(mtx);
		cv.wait(ul, [] {return ready; }); //The ul.unlock maybe called by wait to save cpu time slice.
		//cv.wait_for(ul, std::chrono::second(5)); // Poor expression without pred as there are mistake-notifications from os in sometimes.
		//cv.wait_for(ul, std::chrono::second(5), [] {return ready}); // good
		std::cout << " ready: " << std::boolalpha << ready << std::endl;
	});

	t1.join();
	t2.join();
	return 0;
}

