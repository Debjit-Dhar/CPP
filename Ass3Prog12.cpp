#include <iostream>
#include <string>
using namespace std;
class Item
{
    long int icode;
    string iname;
    float irate;
    int qty;
    public:
    friend class ItemList;
    Item()
    {
        icode=0;
        iname="\0";
        irate=0;
        qty=0;
    }
    void setdet(long int a,string b,float c)
    {
        icode=a;
        iname=b;
        irate=c;
        qty=1;
    }
    void update_rate(float r)
    {
        irate=r;
    }
    void update_qty(int ch)
    {
        if(ch==0)
            qty++;
        else
            qty--;
    }
    void display()
    {
        cout<<icode<<"\t\t"<<iname<<"\t\t"<<irate<<"\t\t"<<qty<<"\n";
    }
};
class ItemList
{
    int max;//max number of distinct items
    Item *list;
    public:
    ItemList(int m)
    {
        max=m;
        long int a;
        string b;
        float c;
        int flag;
        list=new Item[max];
        for(int i=0;i<max;i++)
        {
            flag=1;
            cout<<"Enter item code\n";
            cin>>a;
            cout<<"Enter item name\n";
            cin>>b;
            cout<<"Enter item price\n";
            cin>>c;
            for(int j=0;j<i;j++)
                if(list[j].iname==b)
                {
                    list[j].update_qty(0);
                    flag=0;
                    i-=1;
                }
            if(flag==0)
                continue;
            list[i].setdet(a,b,c);
        }
    }
    void issue(string n)
    {
        int flag=0;
        for(int i=0;i<max;i++)
            if(list[i].iname==n && list[i].qty!=0)
            {
                list[i].update_qty(1);
                flag=1;
            }
        if(!flag)
            cout<<"Item not currently in stock.\n";
    }
    void receive(string n)
    {
        for(int i=0;i<max;i++)
            if(list[i].iname==n)
                list[i].update_qty(0);
    }
    void display_list()
    {
        cout<<"Item Code "<<"Item Name "<<"Item Rate "<<"Quantity\n";
        for(int i=0;i<max;i++)
            list[i].display();
    }
};
class Menu
{
    public:
    Menu()
    {
        int maxSize;
        cout << "Enter the maximum number of items: ";
        cin >> maxSize;
        ItemList itemList(maxSize);
        int choice;
        string itemName;
        do
        {
            cout << "\nMenu:\n";
            cout << "1. Display item list\n";
            cout << "2. Issue an item\n";
            cout << "3. Receive an item\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
                case 1:
                    itemList.display_list();
                    break;
                case 2:
                    cout << "Enter the item name to issue: ";
                    cin >> itemName;
                    itemList.issue(itemName);
                    break;
                case 3:
                    cout << "Enter the item name to receive: ";
                    cin >> itemName;
                    itemList.receive(itemName);
                    break;
                case 4:
                    cout << "Exiting the program.\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                    break;
            }
        } while (choice != 4);
    }
};
int main()
{   
    Menu menu;
    return 0;
}
