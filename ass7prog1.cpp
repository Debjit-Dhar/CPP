#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Student
{
    
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
    long int get_roll()const
    {
        return roll;
    }
    int checksub(string n)
    {
        if(name.find(n)!=string::npos)
            return 1;
        else
            return -1;
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

class StudentVector
{
    vector<Student>::iterator it;
    vector<Student> v;
    public:
    void add()
    {
        int r;string n;float s;
        cout<<"Enter roll\n";
        cin>>r;
        cout<<"Enter name\n";
        cin>>n;
        cout<<"Enter score\n";
        cin>>s;
        Student ob(r,n,s);
        v.push_back(ob);
    }
    void remove()
    {
        int r;
        cout<<"Enter roll of student to be removed.\n";
        cin>>r;
        it = find_if(v.begin(), v.end(),[r](Student &t) { return t.get_roll() == r;});
        (*it).display();
        v.erase(it);
    }
    void randaccess()
    {
        int i;
        cout<<"Enter index to access\n";
        cin>>i;
        (v.at(i)).display();
    }
    void count()
    {
        cout<<"No of students= "<<v.size()<<'\n';        
    }
    void max()
    {
        it=max_element(v.begin(),v.end());
        (*it).display();
    }
    void findsubnames(int i)
    {   
        string n;
        cout<<"Enter substring.\n";
        cin>>n;
        it=v.begin();
        while(it!=v.end())
        {
            if(i==((*it).checksub(n)))
                (*it).display();
            it++;
        }
    }
    void sortvector()
    {
        sort(v.begin(),v.end());
    }
    void display()
    {
        it=v.begin();
        while(it!=v.end())
        {
            (*it).display();
            cout<<'\n';
            it++;
        }
    }
};
class System
{
    StudentVector sv;
    public:
    System()
    {
        int ch;
        while(1)
        {
            cout<<"Enter choice\n1 to add\n2 to remove\n3 to access\n4to count\n5 to find the highest score\n6 to find student with substring in name\n7 to find students without substring in name\n8 to sort\n9 to display all\n any other to exit\n";
            cin>>ch;
            switch(ch)
            {
                case 1:
                sv.add();
                break;
                case 2:
                sv.remove();
                break;
                case 3:
                sv.randaccess();
                break;
                case 4:
                sv.count();
                break;
                case 5:
                sv.max();
                break;
                case 6:
                sv.findsubnames(1);
                break;
                case 7:
                sv.findsubnames(-1);
                break;
                case 8:
                sv.sortvector();
                break;
                case 9:
                sv.display();
                break;
                default:
                return;
            }
        }
    }
};
int main()
{
    System system;
    return 0;
}