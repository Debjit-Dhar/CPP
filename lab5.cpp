#include <iostream>
using namespace std;
void f(int,float)
{
    cout<<"f(int,float)\n";
}
void f(double,double)
{
    cout<<"f(double,double)\n";
}
int main()
{
    int x,y;
    int *a=new int(5);
    f(x,y);
    return 0;
}