#include <iostream>
#include <string>
using namespace std;
class Book
{
    long int bid;
    int serial_no;//denotes copy of a book
    string title;
    string author;
    string publisher;
    float price;
    public:
    Book()
    {
        bid=0;
        serial_no=1;
        title="";
        author="";
        publisher="";
        price=0;
    }
    void accept(long int a,int b,string c,string d,string e,float f)
    {
        bid=a;
        serial_no=b;
        title=c;
        author=d;
        publisher=e;
        price=f;
    }
    void display()
    {
        cout<<bid<<'\t'<<serial_no<<"\t\t"<<title<<'\t'<<author<<'\t'<<publisher<<'\t'<<price<<'\n';
    }
    long int get_bid()
    {
        return bid;
    }
    int get_copy()
    {
        return serial_no;
    }
    void set_count()
    {
        serial_no+=1;
    }
    string get_name()
    {
        return title;
    }
    string get_aut()
    {
        return author;
    }
    string get_pub()
    {
        return publisher;
    }
    float get_price()
    {
        return price;
    }
};
class BookList
{
    int max;
    Book *blist;
    public:
    BookList(int m)
    {
        long int a;int b=1;string c,d,e;float f;
        max=m;
        blist=new Book[max];
        for(int i=0;i<max;i++)
        {
            cout<<"Enter Book Id\n";
            cin>>a;
            for(int j=0;j<i;j++)
                if(blist[j].get_bid()==a)
                    continue;
            cout<<"Enter Book Name\n";
            cin>>c;
            cout<<"Enter author\n";
            cin>>d;       
            cout<<"Enter publisher\n";     
            cin>>e;            
            for(int j=0;j<i;j++)
                if(blist[j].get_name()==c && blist[j].get_aut()==d && blist[j].get_pub()==e)
                    {
                        blist[j].set_count();          
                        b=blist[j].get_copy();
                    } 
            cout<<"Enter price\n";
            cin>>f;     
            blist[i].accept(a,b,c,d,e,f);
        }
    }
    ~BookList()
    {
        delete[] blist;
    }
    void printList()
    {
        cout<<"Book Id\tCopy Number\tBook Name\tAuthor\tPublisher\tPrice\n";
        for(int i=0;i<max;i++)
            blist[i].display();
    }
};
class Member
{
    long int mid;
    int type;//0 for student and 1 for faculty
    string email;
    string address;
    string name;
    public:
    Member()
    {
        mid=0;
        type=0;
        email="";
        address="";
    }
    void accept(long int a,int b,string c,string d,string e)
    {
        mid=a;
        type=b;
        email=c;
        address=d;
        name=e;
    }
    void display()
    {
        cout<<mid<<'\t'<<name<<'\t'<<type<<"\t\t"<<email<<'\t'<<address<<'\n';
    }
    long int get_mid()
    {
        return mid;
    }
};
class MemberList
{
    int max;
    Member *mlist;
    public:
    MemberList(int m)
    {
        max=m;
        mlist=new Member[max];
        long int a;
        int b;
        string c,d,e;
        for(int i=0;i<max;i++)
        {
            cout<<"Enter member id.\n";
            cin>>a;
            cout<<"Enter type.\n";
            cin>>b;
            cout<<"Enter name.\n";
            cin>>c;
            cout<<"Enter email.\n";
            cin>>d;
            cout<<"Enter address.\n";
            cin>>e;
            for(int j=0;j<i;j++)
                if(mlist[j].get_mid()==a)
                    return;
            mlist[i].accept(a,b,c,d,e);
        }
    };
    ~MemberList()
    {
        delete[] mlist;
    } 
    void printlist()
    {
        cout<<"Member ID\tName\tType\tEmail\tAddress\t\n";
        for(int i=0;i<max;i++)
            mlist[i].display();
    }   
    int search_member(long int n)
    {
        for(int i=0;i<max;i++)
            if(mlist[i].get_mid()==n)
                return 1;
        return 0;
    }
    int get_max()
    {
        return max;
    }
    long int get_mid(int i)
    {
        return mlist[i].get_mid();
    }
};
class Transaction
{
    string date;
    long int mid;
    long int bid;
    int serial_no;
    public:
};
class TransactionList
{
    int isret;//1 for returned 0 for not yet returned
    long int **all_transactions;
    int size;
    public:
    TransactionList(MemberList &ob)
    {
        size=ob.get_max();
        all_transactions[ob.get_max()][10];
        for(int i=0;i<ob.get_max();i++)
            for(int j=0;j<10;j++)
                if(j==0)
                    all_transactions[i][j]=ob.get_mid(i);
                else
                    all_transactions[i][j]=0;
    }
    int search(long int n)
    {
        for(int i=0;i<size;i++)
            if(all_transactions[i][0]==n)
                return i;
        return -1;
    }
    void borrow(string a,long int b,long int c,int d,MemberList &ob,int type)//for borrow
    {
        date=a;
        mid=b;
        bid=c;
        serial_no=d;
        isret=0;
        if(search(mid)!=-1)
        {
            if(type==0)
            {
                
            }
            else
            {

            }
        }
    }
    void submit(string a,long int b,long int c,int d,MemberList &ob)//for return
    {
        date=a;
        mid=b;
        bid=c;
        serial_no=d;
        isret=1;
        if(ob.search_member(mid))
    }

};
class Library
{
    public:
};
int main()
{
    BookList ob(4);
    ob.printList();
    return 0;
}