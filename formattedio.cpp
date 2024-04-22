#include <iostream>
using namespace std;
void showflags()
{
    ios::fmtflags f;
    long i;
    f=cout.flags();
    for(i=0x4000;i;i=i>>1)
        if(i&f)
            cout<<"1\t";
        else
            cout<<"0\t";
    cout<<'\n';
}
int main()
{
    showflags();+
    cout.setf(ios::showpos|ios::showpoint);
    showflags();
    cout<<10.0<<'\n';
    return 0;
}