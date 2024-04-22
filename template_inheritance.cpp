#include <iostream>
using namespace std;
template <class X>
class Base
{
    protected:
    X dat;
    public:
    Base(X a)
    {
        dat=a;
        cout<<dat<<'\n';
    }
};
template<class X>
class Derived:public Base<X>
{
    X val;
    public:
    Derived(X a,X b):Base<X>(a)
    {
        val=b;
        this->dat=this->dat+val;
        cout<<this->dat<<'\n';
    }
};
int main()
{
    Derived<int>ob(2,5);
    return 0;
}