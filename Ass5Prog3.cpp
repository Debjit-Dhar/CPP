#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Employee//Abstract Class 
{
    long int emp_id;
    string name;
    string designation;
    float basic;
    public:
    Employee(long int eid,string n,string d,float b)
    {
        emp_id=eid;
        name=n;
        designation=d;
        basic=b;
    }
    float get_basic()
    {
        return basic;
    }
    virtual float calsal()=0;//pure virtual function.
};
class Contractual:public Employee
{
    float allow;
    public:
    Contractual(long int a,string b,string c,float d,float e):Employee(a,b,c,d)
    {
        allow=e;
    }
    float calsal()
    {
        float b=get_basic();
        return b+allow;
    }
};
class Permanent:public Employee
{
    public:
    Permanent(long int a,string b,string c,float d):Employee(a,b,c,d){}
    float calsal()
    {
        float b=get_basic();
        return b+0.3*b+0.8*b;
    }
};
class System
{
    public:
    System()
    {
        int ch,t;
        long int a;
        string b,c;
        float d;
        float e;
        Employee *emp;
        while(1)
        {
            cout<<"Enter choice 1 to calculate salary any other to exit\n";
            cin>>ch;
            switch(ch)
            {
                case 1:
                {
                    cout<<"Enter Employee id\n";
                    cin>>a;
                    cout<<"Enter name\n";
                    cin>>b;
                    cout<<"Enter Designation\n";
                    cin>>c;
                    cout<<"Enter Basic salary\n";
                    cin>>d;
                    cout<<"Enter 0 for contractual or 1 for permanent\n";
                    cin>>t;
                    if(t==0)
                    {
                        cout<<"Enter allowance\n";
                        cin>>e;
                        Contractual cont(a,b,c,d,e);
                        emp=&cont;
                        cout<<emp->calsal()<<'\n';
                    }
                    else
                    {
                        Permanent perm(a,b,c,d);
                        emp=&perm;
                        cout<<emp->calsal()<<'\n';
                    }
                }
                break;
                default:
                exit(0);
            }
        }
    }
};
int main()
{
    System s;
    return 0;
}