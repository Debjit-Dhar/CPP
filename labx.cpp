#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template <class X>
class A
{
    X a;
    public:
    A(X a)
    {
        this->a=a;
    }
};
template <class X,class Y>
class B:public A<X>
{
    Y b;
    public:
    B(X a,Y b):A<X>(a)
    {
        this->b=b;
    }
};
template <class X>
class C 
{
    public:
    C(X c)
    {
        cout<<"C constructor\n";
    }
};
int main()
{
    cout<<__cplusplus<<'\n';
    B<int,float>bob(12,3.5);
    C<A<int>> cob(3);
    return 0;
}