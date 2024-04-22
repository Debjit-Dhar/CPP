#include <iostream>
using namespace std;
void f()throw(float)
{
    int x;
    throw x;
}
int main()
{
    int x;
    try
    {
        f();
        /*x=2;
        if(x==2)
            throw x;*/
    }
    catch(float)
    {
        cout<<"Float";
    }
    /*catch(int)
    {
        throw x;
    }*/
    
    return 0;
}