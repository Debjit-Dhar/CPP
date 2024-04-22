#include <iostream>
using namespace std;
template<class X>
class A 
{
    public:
    void f()
    {
        cout<<"Hello.\n";
    }
};
template<class X>
class B 
{
    public:
    void g(){cout<<"No Hello.\n";}
};
int main()
{
    A<B<int>>x;
    x.f();
    return 0;
}