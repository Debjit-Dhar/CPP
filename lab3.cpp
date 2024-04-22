#include <iostream>
using namespace std;
class Base
{
    private:
    void f1()
    {
        cout<<"Private\n";
    }
    public:
    void f2()
    {
        cout<<"Public\n";
    }
    protected:
    void f3()
    {
        cout<<"Protected\n";
    }
};
class D1:protected Base
{
    public:
    void access()
    {        
        //f1();
        f2();
        f3();        
    }
};
class D2:public D1
{
    public:
    void access()
    {
        //f1();
        f2();
        f3();        
    }
};
int main()
{
    D1 ob1;
    D2 ob2;
    cout<<"In D1\n";
    ob1.access();
    cout<<"In D2\n";
    ob2.access();
    cout<<"In Main()\n";
    //ob1.f1();
    //ob1.f2();
    //ob1.f3();  
    return 0;
}