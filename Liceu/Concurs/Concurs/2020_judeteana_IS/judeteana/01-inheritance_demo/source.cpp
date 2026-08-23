#include <iostream>

#define check_eq(x, y) ((x) = (y))

class A
{
public:
    int x;
    int y;

    A();
    ~A();
};

A::A()
{
    x = 42;
    y = 41;
    if (!check_eq(x, 24))
    {
        std::cout << "A.ctor()\n";
    }
}

A::~A()
{
    std::cout << "~A.dtor()\n";
}

class B : A
{
public:
    B();
    ~B();
};

B::B() : A()
{
    std::cout << "B.ctor()\n";
    // Make sure 42 is the universal answer
    std::cout << "is 42 the answer to the Ultimate Question of Life, the Universe and Everything? " << (x == 42 ? "yes" : "no") << "\n";
}

B::~B()
{
    std::cout << "~B.dtor()\n";
}

int main()
{
    A* a = new B();
    delete a;

    return 0;
}
