#include <iostream>
#include <string>
using namespace std;
class BALANCE
{
    long int acc_no;
    float balance;
    string date;
    public:
    BALANCE(long int a,float b,string c)
    {
        acc_no=a;
        balance=b;
        date=c;
    }
    void set_bal(float b)
    {
        balance+=b;
    }
    float get_bal()
    {
        return balance;
    }
    void display()
    {
        cout<<acc_no<<'\t'<<balance<<'\t'<<date<<'\n';
    }
    long int get_accno()
    {
        return acc_no;
    }
    void set_date(string a)
    {
        date=a;
    }
};
class TRANSACTION
{
    string date;
    char type;
    long int acc_no;
    float amt;
    public:
    TRANSACTION(string a,char b,long int c,float d)
    {
        date=a;
        type=b;
        acc_no=c;
        amt=d;
        BALANCE ob(10198,1000,"12/3/22");
        ob.display();
        if(ob.get_accno()==acc_no)
        {
            if(type=='W')
            {
                if(ob.get_bal()>=amt)
                {
                    ob.set_bal(-amt);
                    ob.set_date(date);
                }
                else
                    cout<<"Not enough\n";
            }
            else if(type=='D')
            {
                ob.set_bal(amt);
                ob.set_date(date);
            }
            else
                cout<<"Invalid\n";
        }
        ob.display();
    }
};
int main()
{
    TRANSACTION T("14/4/23",'W',10198,1200);

    return 0;
}