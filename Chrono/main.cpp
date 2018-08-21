#include <chrono>
#include <cstdint>
#include <memory>

struct DataHolder
{
    std::chrono::system_clock::time_point
        getTimestamp()
    {
        using namespace std::chrono;
        return system_clock::time_point{ milliseconds{ 1437520382241 } };
    }
};

int main()
{
    using namespace std;
    using namespace std::chrono;
    auto data_holder = std::unique_ptr<DataHolder>(new DataHolder);

    auto now = system_clock::now();
    bool is_old = minutes{ 2 } < now - data_holder->getTimestamp();
    return 0;
}