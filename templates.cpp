#include <iostream>
using namespace std;

class A
{
    int num;
    public:
    A(int x)
    {
        num=x;
    }
    operator int()
    {
        return num;
    }
    A operator+(int i)
    {
        A sum(0);
        sum.num=num+i;
        return sum;
    }
    A operator+(A ob)
    {
        A sum(0);
        sum.num=num+ob.num;
        return sum;
    }
    void display()
    {
        cout<<num<<'\n';
    }
};
int main()
{
    A x(2),y(3),z(4);int i=5;
    x.display();
    y.display();
    z.display();
    cout<<i<<'\n';
    x=i;
    x.display();
    i=x;
    cout<<i<<'\n';
    z=x+y;
    z.display();
    x=y+i;
    x.display();
    i=x+y;
    cout<<i<<'\n';
    return 0;
}
