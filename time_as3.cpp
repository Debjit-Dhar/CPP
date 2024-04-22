#include <iostream>
using namespace std;
class TIME
{
    int hour;
    int minute;
    int second;
    char ampm;
    public:
    TIME(int h,int m,int s)
    {
        hour=h;
        minute=m;
        second=s;
    }
    TIME(int h,int m,int s,char a)
    {
        hour=h;
        minute=m;second=s;
        ampm=a;
    }
    void display24()
    {
        cout<<hour<<':'<<minute<<':'<<second<<'\n';
    }
    void displayampm()
    {
        cout<<hour<<':'<<minute<<':'<<second;
        if(ampm=='p')
            cout<<"PM\n";
        else
            cout<<"AM\n";
    }
    void update(int n)
    {
        minute+=n;
        if(minute>60)
        {
            hour+=minute/60;
            minute-=(minute/60)*60;
        }
        
    }
};
int main()
{
    TIME ob1(16,21,30);
    TIME ob2(4,21,30,'p');
    ob1.display24();
    ob2.displayampm();
    ob1.update(40);
    ob2.update(40);
    ob1.display24();
    ob2.displayampm();
}