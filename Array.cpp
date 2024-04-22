#include <iostream>
#include <new>
using namespace std;
class Array
{
    int *p;
    int size;
    public:
    Array(int sz=0){size=sz;p=new int[sz];}
    ~Array(){delete[]p;}
    Array(const Array &a);
    void put(int,int);
    void get();
};
Array::Array(const Array &a)
{
    size=a.size;
    p=new int[a.size];
    for(int i=0;i<a.size;i++)
        p[i]=a.p[i];
}
void Array::put(int val,int i)
{
    p[i]=val;
}
void Array::get()
{
    for(int i=0;i<size;i++)
        cout<<p[i];
    cout<<'\n';
}
int main()
{
    Array a1(5);
    int val;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter val\n";
        cin>>val;
        a1.put(val,i);
    }
    a1.get();
    Array a2(a1);
    a2.put(2,0);
    a2.get();
    a1.get();
}