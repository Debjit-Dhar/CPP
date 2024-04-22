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
            cout<<"Enter number of copies\n";
            cin>>b;
            cout<<"Enter price\n";
            cin>>f;     
            blist[i].accept(a,b,c,d,e,f);
        }
    }
    ~BookList()
    {
        delete[] blist;
    }
    long int get_bid(int i)
    {
        blist[i].get_bid();
    }
    int get_srno(int i)
    {
        blist[i].get_copy();
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
class BookAvailability
{
    long int bid;
    int avail;
    public:
    BookAvailability()
    {
        bid=0;
        avail=0;
    }
    void accept(long int a,int b)
    {
        bid=a;
        avail=b;
    }
    void set_avail(int set)
    {
        avail+=set;
    }
    int get_avail()
    {
        return avail;
    }
    long int get_bid()
    {
        return bid;
    }
};
class BookAvailabilityList
{
    int size;
    BookAvailability *availlist;
    public:
    BookAvailabilityList(BookList &ob,int max)
    {
        size=max;
        availlist=new BookAvailability[max];
        for(int i=0;i<max;i++)
            availlist[i].accept(ob.get_bid(i),ob.get_srno(i));
    }
    int get_avail(long int bid)
    {
        for(int i=0;i<size;i++)
            if(availlist[i].get_bid()==bid)
                return availlist[i].get_avail();
        return -1;
    }
    void set_avail(long int bid,int set)
    {
        for(int i=0;i<size;i++)
            if(availlist[i].get_bid()==bid)
                availlist[i].set_avail(set);
    }
};
class Transaction
{
    string date;
    long int mid;
    long int bid;
    int serial_no;
    int nob;//number of books borrowed
    public:
    Transaction()
    {
        date="";
        mid=0;
        bid=0;
        serial_no=0;
        nob=0;
    }
    void accept(string a,long int b,long int c,int d)
    {
        date=a;
        mid=b;
        bid=c;
        serial_no=d;
    }
    long int get_nob()
    {
        return nob;
    }
    void set_nob(int set)//set is either +1 or -1
    {
        nob+=set;
    }
    void display()
    {
        cout<<date<<'\t'<<mid<<'\t'<<bid<<'\t',serial_no<<'\n';
    }
    long int get_mid()
    {
        return mid;
    }
    long int get_bid()
    {
        return bid;
    }
    long int get_srno()
    {
        return serial_no;
    }
};
class TransactionList
{
    int size;
    Transaction **Tlist;
    public:
    TransactionList(int max)
    {
        size=max;
        Tlist=new Transaction*[size];
        for(int i=0;i<size;i++)
            Tlist[i]=new Transaction[10];
    }
    int search(long int n)//search for a member in transaction list
    {
        for(int i=0;i<size;i++)
            if(Tlist[i][0].get_mid()==n)
                return i;
        return -1;
    }
    int search(int pos,long int n,int x)//search for a book borrowed by a member in transaction list
    {
        for(int i=0;i<10;i++)
            if(Tlist[pos][i].get_bid()==n && Tlist[pos][i].get_srno()==x)
                return i;
        return -1;
    }
    void borrow(BookAvailabilityList &ob,int pos,int type)//for borrow,srno is serial number of book
    {
        string a;long int b,c;
        cout<<"Enter date\n";
        cin>>a;
        cout<<"Enter member id\n";
        cin>>b;
        cout<<"Enter book id\n";
        cin>>c;
        int avail=ob.get_avail(c);
        if(avail==0)
        {
            cout<<"No available copies.\n";
            return;
        }
        int n=Tlist[pos][0].get_nob();
        if(type==0 && n>=2)
        {
            cout<<"Student cannot borrow any more books\n";
            return;
        }
        if(type==1 && n>=10)
        {
            cout<<"Faculty cannot borrow any more books\n";
            return;
        }
        int i=0;
        for(i=0;i<n;i++)     
            Tlist[pos][i].set_nob(1);
        n=Tlist[pos][0].get_nob();
        Tlist[pos][i].accept(a,b,c,avail);        
        ob.set_avail(c,1);
    }
    void submit(BookAvailabilityList &ob,int pos,long int bid,int srno)//for return
    {
        int posj=search(pos,bid,srno);
        if(posj==-1)
        {
            cout<<"Invalid Book Returned.\n";
            return;
        }
        ob.set_avail(bid,-1);   
        for(int i=posj;i<9;i++)
            Tlist[pos][i]=Tlist[pos][i+1];                    
    }
    void printlist()
    {
        cout<<"Date\tMember Id\tBook Id\tSerial Number\n";
        for(int i=0;i<size;i++)
        {
            if(Tlist[0][0].get_mid()==0)
                continue;
            for(int j=0;j<10;j++)
            {
                if(Tlist[i][j].get_mid()==0)
                    continue;
                Tlist[i][j].display();
            }
        }
    }
};
class Library {
public:
    Library() {
        int lastpos = 0;
        int bmax, mmax;
        cout << "Enter total number of books\n";
        cin >> bmax;
        BookList blob(bmax);
        cout << "Enter total number of members\n";
        cin >> mmax;
        MemberList mlob(mmax);
        TransactionList tlob(mmax);
        BookAvailabilityList balob(blob, bmax);
        int ch;

        while (true) {
            cout << "Enter choice\n 1 to borrow\n 2 to return\n 3 to display\n any other to exit.\n";
            cin >> ch;

            switch (ch) {
                case 1: {
                    int type, pos;
                    long int mid;
                    cout << "Enter type of member\n";
                    cin >> type;
                    cout << "Enter member id\n";
                    cin >> mid;
                    pos = tlob.search(mid);
                    if (pos == -1) {
                        lastpos += 1;
                        pos = lastpos;
                    }
                    tlob.borrow(balob, pos, type);
                    break;
                }
                case 2: {
                    long int bid, mid;
                    int srno;
                    cout << "Enter book id\n";
                    cin >> bid;
                    cout << "Enter serial number\n";
                    cin >> srno;
                    cout << "Enter member id\n";
                    cin >> mid;
                    int pos = tlob.search(mid);
                    tlob.submit(balob, pos, bid, srno);
                    break;
                }
                case 3:
                {
                    cout<<"Member List\n";
                    mlob.printlist();
                    cout<<"Book List\n";
                    blob.printList();
                    cout<<"Transaction List\n";
                    tlob.printlist();
                    break;
                }
                default:
                    cout << "Exiting.\n";
                    return;
            }
        }
    }
};
int main()
{
    Library ob;
    return 0;
}