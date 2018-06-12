#include <thread>


class ThreadGuard
{
public:
	ThreadGuard(std::thread& _t):t(_t){}
    

    ~ThreadGuard(){
        if (t.joinable())
                t.join();
    }

    ThreadGuard(const ThreadGuard&) = delete;
    
    ThreadGuard& operator = (const ThreadGuard&) = delete;

private:  
    std::thread & t;
};

void do_some_thing_may_occur_exception(){}

int main()
{
    std::thread t([](){});
    ThreadGuard g(t);
    
    do_some_thing_may_occur_exception();

	return 0;
}
