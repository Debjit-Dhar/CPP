#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Student
{
    long int roll;
    string name;
    public:
    Student()
    {
        roll=0;
        name="";
    }
    void accept(long int r,string s)
    {
        roll=r;
        name=s;
    }
    long int get_roll()
    {
        return roll;
    }
    void display()
    {
        cout<<roll<<'\t'<<name<<'\n';
    }
};
class Subject
{
    long int scode;
    string sname;
    public:    
    Subject()
    {
        scode=0;
        sname="";
    }
    void accept(long int r,string s)
    {
        scode=r;
        sname=s;
    }
    long int get_scode()
    {
        return scode;
    }
    void display()
    {
        cout<<scode<<'\t'<<sname<<'\n';
    }
};
class StudentList
{
    int size;
    Student *stuar;
    public:
    StudentList(int s=0)
    {
        size=s;
        stuar=new Student[size];
        int r;
        string str;
        for(int i=0;i<s;i++)
        {
            cout<<"Enter roll.\n";
            cin>>r;
            for(int j=0;j<=i;j++)
            {
                if(r!=stuar[j].get_roll())
                {
                    cout<<"Enter student name\n";
                    cin>>str;
                    //getline(cin,str,'\n');
                    stuar[i].accept(r,str);
                    break;
                }
            }
        }
    }
    ~StudentList()
    {
        delete[]stuar;
    }
    int get_size()
    {
        return size;
    }
    long int getl_roll(int i)
    {
        return stuar[i].get_roll();
    }
    void displayl(int i)
    {
        stuar[i].display();
    }
    void print()
    {
        cout<<"Subject List:\n";
        for(int i=0;i<size;i++)
            stuar[i].display();
    }
};
class SubjectList
{
    int size;
    Subject *subar;
    public:
    SubjectList(int s=0)
    {
        size=s;
        subar=new Subject[size];
        int r;
        string str;
        for(int i=0;i<s;i++)
        {
            cout<<"Enter subject code\n";
            cin>>r;
            for(int j=0;j<=i;j++)
            {
                if(r!=subar[j].get_scode())
                {
                    cout<<"Enter subject name\n";
                    cin>>str;
                    //getline(cin,str,'\n');
                    subar[i].accept(r,str);
                    break;
                }
            }
        }
    }
    ~SubjectList()
    {
        delete[]subar;
    }
    int get_size()
    {
        return size;
    }
    long int getl_scode(int i)
    {
        return subar[i].get_scode();
    }
    void displayl(int i)
    {
        subar[i].display();
    }
    void print()
    {
        cout<<"Subject List:\n";
        for(int i=0;i<size;i++)
            subar[i].display();
    }
};
class Selection
{
    public:
    Selection()
    {
        int s1,s2;
        cout<<"Total number of student.\n";
        cin>>s1;
        cout<<"Total number of subject.\n";
        cin>>s2;
        StudentList ob1(s1);
        SubjectList ob2(s2);
        int stus=ob1.get_size();
        int subs=ob2.get_size();
        int select[stus][subs];
        int i,j;
        long int opt;
        int ch;
        for(i=0;i<stus;i++)
        {
            for(j=0;j<subs;j++)
            {
                select[i][j]=0;
            }
        }
        for(int i=0;i<stus;i++)
        {
            for(j=0;j<subs;j++)
            {
                cout<<"Enter 1 to select 0 to deselect\n";
                cin>>select[i][j];
            }
        }
        while(1)
        {
            cout<<"Enter 1 to display students for a subject, 2 to display subjects for a student any other to exit.\n";
            cin>>ch;
            switch(ch)
            {
                case 1:
                cout<<"Enter scode.\n";
                cin>>opt;
                for(i=0;i<subs;i++)
                {
                    if(ob2.getl_scode(i)==opt)
                    opt=i;
                }
                for(i=0;i<stus;i++)
                if(select[i][opt]==1)
                    ob1.displayl(i);
                break;
                case 2:
                cout<<"Enter roll.\n";
                cin>>opt;
                for(i=0;i<stus;i++)
                {
                    if(ob1.getl_roll(i)==opt)
                    opt=i;
                }
                for(i=0;i<subs;i++)
                if(select[opt][i]==1)
                    ob2.displayl(i);
                break;
                default:
                exit(0);
            }
        }
    }
};
int main()
{
    Selection();
    return 0;
}