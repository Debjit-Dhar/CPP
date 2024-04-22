#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1;
    list<int> l2(5);
    cout<<l2.size()<<'\n';
    list<int>::iterator it;
    it=l2.begin();
    while(it!=l2.end())
    {
        *it=3;
        it++;
    }
    it=l2.begin();
    while(it!=l2.end())
    {
        cout<<*it<<'\n';
        it++;
    }
    return 0;
}