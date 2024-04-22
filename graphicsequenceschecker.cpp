#include <iostream>
#include <queue>
using namespace std;
void display(priority_queue<int>pq)
{
    priority_queue<int>pq1;
    while(!pq.empty())
    {
        cout<<pq.top()<<'\t';
        pq1.push(pq.top());
        pq.pop();
    }
    cout<<endl;
}
bool isgraphic()
{
    priority_queue<int> pq;
    priority_queue<int>pq1;
    cout<<"Enter negative or zero to exit.\n";
    int n=1;
    while(n>0)
    {
        cin>>n;
        if(n<=0)
            break;
        pq.push(n);
    }
    bool graphic=false;
    int d=0,x=0;
    while(true)
    {
        display(pq);
        if(pq.empty())
            return true;
        d=pq.top();
        pq.pop();
        
        while(d>0)
        {
            if(pq.empty())                                
                return false;
            x=pq.top()-1;
            if(x<0)
                return false;
            pq.pop();
            pq1.push(x);
            d--;
        } 
        while(!pq1.empty())
        {
            pq.push(pq1.top());
            pq1.pop();
        }
              
    }
}
int main()
{
    if(isgraphic())
        cout<<"Sequence is graphic"<<endl;
    else
        cout<<"Sequence is not graphic"<<endl;
    return 0;
}