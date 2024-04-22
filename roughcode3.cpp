#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
class Student
{
    int roll;
    float score;
    public:
    Student(int r=0,float s=0)
    {
        roll=r;
        score=s;
    }
    int get_roll()const
    {
        return roll;
    }
    float get_score()const
    {
        return score;
    }
    void display()
    {
        cout<<"Roll= "<<roll<<'\n';
        cout<<"Score= "<<score<<'\n';
    }
    /*bool operator<(Student t)
    {
        return (roll<t.roll);
    }
    bool operator==(Student t)
    {
        return (roll==t.roll);
    }*/
};
class Compare
{
    public:
    bool operator()(Student t1,Student t2)
    {
        return (t1.get_roll()<t2.get_roll());
    }
};
class Search
{
    public:
    int roll;
    Search(int r)
    {
        roll=r;
    }
    bool operator()(Student t)
    {
        return (roll==t.get_roll());
    }
};
class Condition
{
    public:
    void operator()(Student t)
    {
        if(t.get_score()>50)
            t.display();
    }
};
class Sum {
public:
    float operator()(float s, const Student& t2) const {
        return s + t2.get_score();
    }
};

class StudentContainer
{
    priority_queue<Student,vector<Student>,Compare>v;
    vector<Student>::iterator it;
    public:
    void accept()
    {
        int r;float s;
        cout<<"Enter roll.\n";
        cin>>r;
        cout<<"Enter score.\n";
        cin>>s;
        Student t(r,s);
        v.push(t);
        
    }
    void showtop()
    {
        Student t=v.top();
        t.display();
    }
    
};
int main()
{
    StudentContainer sc;
    sc.accept();
    sc.accept();
    sc.accept();
    
    
    
    sc.showtop();
    
    return 0;
}