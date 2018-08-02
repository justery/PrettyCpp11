#include <memory>
#include <iostream>


class Obj
{
public:
    Obj() {
        std::cout << "Obj" << std::endl;
    }

    ~Obj() {
        std::cout << "~Obj" << std::endl;
    }
};

int main()
{
    //case 1: common usecase.
    {
        std::unique_ptr<Obj> up = std::make_unique<Obj>();
        //auto temp = up; // Point *: error, no copy constructor.

        // Point ***** Why line 22 failed but 'operation =' at line 21 succeed?
        //As C++ recognize anonymous object from construct as r-value object,
        //and the copy constructor 'Obj(const Obj&&)' is offerred by default.
        //It is the same for some other classes in C++11, e.g. std::thread.
    }
    std::cout << "--------------------" << std::endl;

    //case 2: manage object array.
    {
        // Point *** clean version for using unique_ptr.
        std::unique_ptr<Obj[]> up = std::make_unique<Obj[]>(3);
        // Point *** deleter is offerred by std::default_delete<Obj []>.
        auto objects = new Obj[5]();
        using DeleteFunc = std::default_delete<Obj[]>;
        auto deleter = DeleteFunc();
        deleter(objects);//or ' DeleteFunc()(objects);'
    }

    return 0;
}
