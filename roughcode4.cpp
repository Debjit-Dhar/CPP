#include <iostream>
using namespace std;
class A 
{
    public:
    void f1(double)
    {
        cout<<"Inside void f1(double) of A\n";
    }
    virtual void f1(int)
    {
        cout<<"Inside virtual void f1(int) of A\n";
    }
    virtual void f1(int,int)
    {
        cout<<"Inside virtual void f1(int,int) of A\n";
    }
    void f1(char)
    {
        cout<<"Inside void f1(char) of A\n";
    }
    void f2(char,char)
    {
        cout<<"Inside void f2(char,char) of A\n";
    }
};
class B:public A
{
    public:
    void f1(int)
    {
        cout<<"Inside void f1(int) of B\n";
    }  
    void f1(char)
    {
        cout<<"Inside void f1(char) of B\n";
    }  
    void f1(float)
    {
        cout<<"Inside void f1(float) of B\n";
    }
    void f1(int,float)
    {
        cout<<"Inside void f1(int,float) of B\n";
    }
};
int main()
{
    int i,j;char c1,c2;float fx;double dx;
    A*p;B b;
    p=&b;
    b.f1(i,j);b.f2(i,j);p->f1(i,j);p->f1(c1);p->f1(i);p->f1(fx);
    return 0;
}