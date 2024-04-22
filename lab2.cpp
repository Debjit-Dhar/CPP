#include <iostream>
using namespace std;
class Base
{
    public:
    virtual void vf()
    {
        cout<<"Base\n";
    }
};
class derived1:public Base
{
    public:
    void vf()
    {
        cout<<"Derived1\n";
    }
};
class derived2:public derived1
{
};
int main()
{
    Base *bp,b;
    derived1 d1;
    derived2 d2;
    bp=&b;
    bp->vf();
    bp=&d1;
    bp->vf();
    bp=&d2;
    bp->vf();
    Base obj;
    derived1 obj2;
    long** vtable = reinterpret_cast<long**>(&obj);
    long** vtable2=reinterpret_cast<long**>(&obj2);
    // Print the addresses of virtual functions in the vtable
    cout << "VTable for Base class:" << std::endl;
    cout << "Address of vf(): " << vtable[0][0] << std::endl;
    cout<<"VTable for Derived1 class:"<<std::endl;
    cout << "Address of vf(): " << vtable2[0][0] << std::endl;
    return 0;
}
