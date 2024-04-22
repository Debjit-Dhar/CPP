#include <iostream>
using namespace std;

class ACCOUNT
{
    private:
    long int accountid;
    double balance;

    public:
    ACCOUNT(long int aid=0,double b=0.0)
    {

        accountid=aid;
        balance=b;
    }
    long int getaccountid()
    {
        return accountid;
    }
    double getbalance()
    {
        return balance;
    }
    void update(double b=0.0,double w=0.0)
    {
        balance+=b-w;
    }
    void displayAccountInfo() 
    {
        cout << "Account ID: " << accountid << ", Balance: " << balance << endl;
    }

};

class WITHDRAW
{
    private:
    long int accountid;
    double withdraw;

    public:
    WITHDRAW(long int aid=0,double w=0.0)
    {

        accountid=aid;
        withdraw=w;
    }
    long int getaccountid()
    {
        return accountid;
    }
    double getwithdraw()
    {
        return withdraw;
    }
};

class BANK
{
    private:
    ACCOUNT data[100];
    int num;

    public:
    BANK()
    { 
        num=0;
    }
    void addAccount(ACCOUNT b)
    {
        if(num>=100)
            return;
        for(int i=0;i<num;i++)
        {
            if(b.getaccountid()==data[i].getaccountid())
            {
                cout<<"Account ID exists."<<endl;
                return;
            }
        }
        data[num]=b;
        num++;
    }

    void withdrawbal(WITHDRAW b)
    {
        for(int i=0;i<num;i++)
        {
            if(b.getaccountid()==data[i].getaccountid())
            {
                if(data[i].getbalance()<b.getwithdraw())
                {
                    cout<<"Withdraw greater than balance.";
                    return;
                }
                data[i].update(0.0,b.getwithdraw());
                return;
            }
        }
        cout<<"Account ID not found"<<endl;
    }
    void displayAllAccounts()
    {
        for (int i = 0; i < num; i++) {
            data[i].displayAccountInfo();
        }
    }
    void searchAccount(long int accid)
    {
        for(int i=0;i<num;i++)
        {
            if(data[i].getaccountid()==accid)
            {
                cout<<"Account Found. Balance = "<<data[i].getbalance()<<endl;
                return;
            }
        }
        cout<<"Account does not exist"<<endl;
        return;
    }
};

class SYSTEM
{
    public:
    SYSTEM()
{
    BANK a;
    int opt;
    long int accid;
    double bal;
    
    while(1)
    {
    cout << "Enter 1 to add account/Enter 2 to search and view account/Enter 3 to withdraw/4 to display all accounts/Any other to exit: ";
    cin >> opt;
    switch (opt)
    {
        case 1:
        {
            cout << "Enter Account ID: ";
            cin >> accid;
            cout << "Enter Balance: ";
            cin >> bal;
            ACCOUNT b(accid, bal);
            a.addAccount(b);
            break;
        }

        case 2:
        {
            cout << "Enter Account ID: ";
            cin >> accid;
            a.searchAccount(accid);
            break;
        }

        case 3:
        {
            cout << "Enter Account ID: ";
            cin >> accid;
            cout << "Enter Withdrawl balance: ";
            cin >> bal;
            WITHDRAW c(accid, bal);
            a.withdrawbal(c);
            break;
        }

        case 4:
            a.displayAllAccounts();
            break;

        default:
            cout << "Exiting the program." << endl;
            break;
    }
    }
}
};

int main()
{
    SYSTEM systemInstance; 
    return 0; 
}