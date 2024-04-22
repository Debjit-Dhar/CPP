#include <iostream>
#include <map>
using namespace std;
class Student
{
    int roll;
    float score;
    public:
    Student(int a,float b)
    {
        roll=a;
        score=b;
    }
    int get_roll()const{return roll;}
    float get_score()const{return score;}
    friend bool operator<(Student&,Student&);
};
bool operator<(Student &a,Student &b)
{
    return a.roll<b.roll;
}
class StudentMap
{
    map<int,float> smap;
    map<int,float>::iterator it;
    public:
    void accept()
    {
        int r;float s;
        cout<<"Enter roll\n";
        cin>>r;
        cout<<"Enter score";
        cin>>s;
        Student a(r,s);
        smap.insert(pair<int,float>(a.get_roll(),a.get_score()));
    }
    void displayall()
    {
        it=smap.begin();
        while(it!=smap.end())
        {
            cout<<"Roll= "<<it->first<<" Score= "<<it->second<<'\n';
            it++;
        }
    }
    void search()
    {        
        int r;
        cout<<"Enter roll.\n";
        cin>>r;
        it=smap.find(r);
        if(it!=smap.end())
            cout<<"Roll= "<<it->first<<" Score= "<<it->second<<'\n';
        else
            cout<<"Student does not exist.\n";
    }
};
class System
{
    StudentMap studentMap;
    public:
    System()
    {
        int choice;
        while(true)
        {
            cout << "1. Accept\n2. Search\n3. Display all\nany other to exit\n";
            cin >> choice;
            switch (choice) 
            {
                case 1:
                    studentMap.accept();
                break;
                case 2:
                    studentMap.search();
                break;
                case 3:
                    studentMap.displayall();
                break;
                default:
                    cout << "Exiting.\n";
                return;
            }
        }
    }
};
int main()
{
    System sys;
    return 0;
}