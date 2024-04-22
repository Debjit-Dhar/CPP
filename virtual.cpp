#include <iostream>
using namespace std;
class A
{
    public:
    virtual void f1(){cout<<"A f1\n";}
    virtual void f2(){cout<<"A f2\n";}
};
class B:public A
{
    public:
    void f1(int){cout<<"B f1\n";}
    void f2(){cout<<"B f2\n";}
};
int main()
{
    A *p;
    B b;
    p=&b;
    p->f2();
    p->f1(10);
    b.f1();
    return 0;
}