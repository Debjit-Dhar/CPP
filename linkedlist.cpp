#include <iostream>
using namespace std;
class Node;
typedef Node* NodePointer;
class Node
{
    public:
    int data;
    NodePointer link;
    Node(int d)
    {
        data=d;
        link=NULL;
    }
    void display()
    {
        cout<<data;
    }
};
class list
{
    public:
    NodePointer head;
    list(int dat)
    {
        head=new Node(dat);
        head->data=dat;
    }
    ~list(){delete head;}
    int is_empty(NodePointer head)
    {
        return(head==NULL);
    }
    int atend_l(NodePointer cur)
    {
        if(cur==NULL)
            return 0;
        else
            return((cur->link)==NULL);
    }
    void insert_front(NodePointer *head,NodePointer target)
    {
        target->link=(*head);
        *head=target;
    }
    void insert_after(NodePointer prev,NodePointer target)
    {
        target->link=prev->link;
        prev->link=target;
    }
    void delete_front(NodePointer*head)
    {
        NodePointer cur=*head;
        *head=(*head)->link;
        delete cur;
    }
    void delete_after(NodePointer prev)
    {
        NodePointer cur=prev->link;
        prev->link=cur->link;
        delete cur;
    }
    void printlist()
    {
        NodePointer cur=head;
        while(!atend_l(cur))
        {
            cout<<(cur->data)<<"->";
            cur=cur->link;
        }
        cout<<(cur->data)<<'\n';
    }
    
};
int main()
{
    list ob(5);
    NodePointer target=new Node(3);
    target->link=NULL;
    ob.insert_after(ob.head,target);
    ob.printlist();
    delete target;
    return 0;
}