#include <iostream>
#include <queue>
using namespace std;
class Marksheet
{
    float sub1,sub2,sub3,sub4,sub5;
    float sgpa;
    public:
    Marksheet(float a,float b,float c,float d,float e,float f)    
    {
        sub1=a;
        sub2=b;
        sub3=c;
        sub4=d;
        sub5=e;
        sgpa=f;
    }
    void display()
    {
        cout<<"Subject 1\tSubject 2\tSubject 3\tSubject 4\tSubject 5\tSGPA\n";
        cout<<sub1<<'\t'<<sub2<<'\t'<<sub3<<'\t'<<sub4<<'\t'<<sub5<<'\t'<<sgpa<<'\n';
    }
};
class Report
{
    Marksheet marks;
    int date;
    public:
    Report(float a,float b,float c,float d,float e,float f,int g):marks(a,b,c,d,e,f)
    {
        date=g;
    }
    void display()
    {
        marks.display();
        cout<<"Date= "<<date<<'\n';
    }
    friend bool operator<(Report,Report);
};
bool operator<(Report r1,Report r2)
{
    return r1.date>r2.date;
}
class ReportQueue
{
    priority_queue<Report> rq;
    public:
    void push_report()
    {
        float a,b,c,d,e,f;int g;
        cout<<"Enter subject 1 marks.\n";
        cin>>a;
        cout<<"Enter subject 2 marks.\n";
        cin>>b;
        cout<<"Enter subject 3 marks.\n";
        cin>>c;
        cout<<"Enter subject 4 marks.\n";
        cin>>d;
        cout<<"Enter subject 5 marks.\n";
        cin>>e;
        cout<<"Enter sgpa\n";
        cin>>f;
        cout<<"Enter date.\n";
        cin>>g;
        Report ob(a,b,c,d,e,f,g);
        rq.push(ob);
    } 
    void pop_report()
    {
        rq.pop();
    }
    void display_top()
    {
        Report ob=rq.top();
        ob.display();
    }
};
class System
{
    ReportQueue repq;
    public:
    System()
    {
        int ch;
        while(1)
        {
            cout<<"Enter choice\n1. to push\n2. to pop\n3.to display top element\nany other to exit.\n";
            cin>>ch;
            switch(ch)
            {
                case 1:
                repq.push_report();
                break;
                case 2:
                repq.pop_report();
                break;
                case 3:
                repq.display_top();
                break;
                default:
                return ;
            }
        }
    }
};
int main()
{
    System sys;
    return 0;
}