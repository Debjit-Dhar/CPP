#include <iostream>
using namespace std;

class data
{
    int dat;
    public:
    data()
    {
        dat=0;
    }
    void accept(int n)
    {
        dat=n;
    }
    void print()
    {
        cout<<dat<<'\t';
    }
};
class STACK
{
    int top;
    int max;
    data *stck;
    public:
    STACK(int l)//initialization
    {
        max=l;
        stck=new data[max];
        top=-1;
    }
    ~STACK()
    {
        delete[]stck;
    }
    void push(int n)//push
    {
        if(top==max-1)
            cout<<"Overflow.\n";
        else
            stck[++top].accept(n);
    }
    void pop()//pop
    {
        if(top==-1)
            cout<<"Underflow.\n";
        else
            top--;
    }
    void display()
    {
        if(top==-1)
            cout<<"Stack Empty.\n";
        else
        {
            for(int i=0;i<=top;i++)
                stck[i].print();
            cout<<'\n';
        }
    }
};
int main()
{
    int maxSize;
    cout << "Enter the maximum size of the stack: ";
    cin >> maxSize;

    STACK stack(maxSize);
    int choice;
    int value;

    do
    {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            stack.display();
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
