#include <iostream>
#include <string>
using namespace std;
class APPLICANT
{
    long int baseid;
    long int id;
    string name;
    float score;
    public:
    static int count;
    APPLICANT()
    {
        baseid=10192;
        count+=1;
        id=baseid+count-1;
        name="";
        score=0;
    }
    void accept(string n,float s)
    {
        name=n;
        score=s;
    }   
    void display()
    {
        cout<<id<<'\t'<<name<<'\t'<<score<<'\n';
    }
};
int APPLICANT::count;
class SYSTEM
{
    int size;
    APPLICANT *ob;
    public:
    SYSTEM(int s=0)
    {
        string n;
        float sc;
        size=s;
        ob=new APPLICANT[size];
        for(int i=0;i<size;i++)
        {
            cout<<"Enter name.\n";
            cin>>n;
            cout<<"Enter score.\n";
            cin>>sc;
            ob[i].accept(n,sc);
            ob[i].display();
        }
        cout<<"Count= "<<APPLICANT::count<<'\n';
    }
};
int main()
{
    SYSTEM sob(5);
    return 0;
}