#include <iostream>
#include <string.h>
using namespace std;
class Student
{
    static int nos;
    long int roll;
    char name[100];
    char course[100];
    char date[100];
    float marks[5];
    public:
    Student(long int r,char n[],char c[],char d[])
    {
        roll=r;
        strcpy(name,n);
        strcpy(course,c);
        strcpy(date,d);
        nos+=1;
    }
    void get_marks(float m[])
    {
        for(int i=0;i<5;i++)
            marks[i]=m[i];
    }
    void display()
    {
        cout<<nos<<'\n';
        cout<<roll<<name<<course<<date<<'\n';
        for(int i=0;i<5;i++)
            cout<<"Subject 1="<<marks[i]<<'\n';
    }
};
int Student::nos;
int main()
{
    Student ob1(1106,"Debjit Dhar","CSE","11/22/22");
    float m[5]={99.97,100,100,100,100};
    ob1.get_marks(m);
    ob1.display();
    Student ob2(1107,"Soham Lahiri","CSE","11/22/22");
    ob2.get_marks(m);
    ob2.display();
    return 0;
}