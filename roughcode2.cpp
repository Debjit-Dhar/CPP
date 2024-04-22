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
    vector<Student>v;
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
        v.push_back(t);
    }
    void display()
    {
        it=v.begin();
        while(it!=v.end())
        {
            (*it).display();
            it++;
        }
    }
    void fsort()
    {
        Compare comp;
        sort(v.begin(),v.end(),comp);        
    }
    void fsearch(int r)
    {
        Search s(r);
        it=find_if(v.begin(),v.end(),s/*[r](Student t){return t.get_roll()==r;}*/);
        if(it!=v.end())
            (*it).display();
        else
            cout<<"Not Found.\n";
    }
    void pass()
    {
        Condition cond;
        for_each(v.begin(),v.end(),cond);       
    }
     float avg() const {
        Sum sum;
        float total = accumulate(v.begin(), v.end(), 0.0f, sum);
        return (total/v.size());
    }
};
int main()
{
    StudentContainer sc;
    sc.accept();
    sc.accept();
    sc.accept();
    sc.display();
    cout<<"After sorting.\n";
    sc.fsort();
    sc.display();
    sc.fsearch(3);
    cout<<"Student who have passed.\n";
    sc.pass();
    cout << "Average= " << sc.avg() << endl;
    return 0;
}