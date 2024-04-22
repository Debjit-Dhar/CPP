#include <iostream>
using namespace std;

class Node;
typedef Node* Nodepointer;

class Node
{
    int data;
    Nodepointer link;
    public: 
    friend class LinkedList; 
    friend class Menu;     
    Node(int n=0)
    {
        data=n;
        link=NULL;
    }
    void printdata()
    {
        cout<<data<<"->";
    }
};

class LinkedList
{
    Nodepointer head;
    public:    
    friend class Menu;
    LinkedList()
    {
        head = NULL;
    }

    void init_l(int n)
    {
        if (!head) {
            head = new Node(n);
        } else {
            head->data = n;
        }
    }

    ~LinkedList()
    {
        delete head;
    }

    int empty_l()
    {
        return (head == NULL);
    }

    int atend_l(Nodepointer cur)
    {
        if(cur == NULL)
            return 0;
        else
            return ((cur->link) == NULL);
    }

    void insert_front(Nodepointer *head, Nodepointer target)
    {
        if (!empty_l())
        {
            target->link = *head;
            *head = target;
        }
        else
            *head = target;     
    }

    void insert_after(Nodepointer prev, Nodepointer target)
{
    if (prev == NULL)
    {
        cout << "Invalid previous node. Cannot insert.\n";
        return;
    }

    target->link = prev->link;
    prev->link = target;
}


    void delete_front(Nodepointer *head)
    {
        if (*head == NULL)
            return;

        Nodepointer temp = *head;
        *head = (*head)->link;
        delete temp;
    }

    void delete_after(Nodepointer prev)
    {
        if (prev == NULL || prev->link == NULL)
            return;

        Nodepointer temp = prev->link;
        prev->link = temp->link;
        delete temp;
    }

    void print_l()
    {
        Nodepointer cur = head;
        while (!atend_l(cur))
        {
            cur->printdata();
            cur = cur->link;
        }

        if (cur)
            cur->printdata();
        
        cout << '\n';
    }
};

class Menu
{
    public:
    Menu()
    {
        LinkedList ob;
        int ch, c = 0, num;
        while (1)
        {
            cout << "Enter 1 to insert, 2 to delete, 3 to print, any other to exit\n";
            cin >> ch;
            switch(ch)
            {
               case 1:
                {
                    cout << "Enter data.\n";
                    cin >> num;
                    Nodepointer target = new Node(num);
                    Nodepointer cur;
                    if (c == 0)
                    {
                        ob.insert_front(&(ob.head), target);
                        cur = ob.head;  // Declaration of cur for the first insertion
                    }
                    else
                    {
                        cout << "Enter the position after which to insert (1-" << c << "): ";
                        int pos;
                        cin >> pos;
                        if (pos < 1 || pos > c)
                        {
                            cout << "Invalid position. Cannot insert.\n";
                            break;
                        }
                        Nodepointer prev = ob.head;
                        for (int i = 1; i < pos; ++i)
                            prev = prev->link;
                        ob.insert_after(prev, target);
                        cur = prev->link;  // Update cur after insertion
                    }
                    c++;
                }
                break;
                case 2:
                if (c == 0) 
                    cout << "List is empty. Cannot delete.\n";
                else
                {
                    int pos;
                    cout << "Enter the position to delete (1-" << c << "): ";
                    cin >> pos;
                    if (pos < 1 || pos > c) 
                        cout << "Invalid position. Cannot delete.\n";
                    else 
                    {
                        Nodepointer prev = ob.head;
                        for (int i = 1; i < pos - 1; ++i) 
                            prev = prev->link;
                        if (pos == 1) 
                            ob.delete_front(&(ob.head));
                        else 
                            ob.delete_after(prev);
                        cout << "Node at position " << pos << " deleted.\n";
                        c--;
                    }
                }
                break;
                case 3:
                ob.print_l();
                break;

                default:
                exit(0);
            }
        }
    }
};

int main()
{
    Menu menu;
    return 0;
}
