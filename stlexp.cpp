#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
class Student
{
    public:
    long int roll;
    string name;
    float score;
    public:
    Student(long int a,string b,float c)
    {
        roll=a;
        name=b;
        score=c;
    }
    void display() 
    {
        cout<<"Roll= "<<roll<<",Name= "<<name<<",Score= "<<score<<'\n';
    }
    friend bool operator>(Student&,Student&);
    friend bool operator<(Student&,Student&);    
    friend bool operator==(Student&,Student&);
};
bool operator>(Student&t1,Student &t2)
{
    return t1.score>t2.score;
}
bool operator<(Student&t1,Student &t2)
{
    return t1.score<t2.score;
}
bool operator==(Student&t1,Student &t2)
{
    return t1.score==t2.score;
}
int main()
{
    list<Student> l;
    list<Student>::iterator it;
    int r;string n;float s;
    cout<<"Enter roll\n";
                cin>>r;
                cout<<"Enter name\n";
                cin>>n;
                cout<<"Enter score\n";
                cin>>s;
                Student ob(r,n,s);
                l.push_back(ob);
    cout<<"Enter roll\n";
                cin>>r;
                cout<<"Enter name\n";
                cin>>n;
                cout<<"Enter score\n";
                cin>>s;
                Student ob1(r,n,s);
                l.push_back(ob1);
    l.sort();
    it=l.begin();
    (*it).display();
    return 0;
}
