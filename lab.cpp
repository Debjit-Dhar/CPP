#include <iostream>
using namespace std;
class String
{
    char *str;
    int size;
    public:
    String(int s=0)
    {
        size=s;
        str=new char[size+1];        
    }
    ~String()
    {
        delete[]str;
    }
    String(String &s)//s is the string object from which the 'this' object is copying
    {
        size=s.size;
        str=new char[size+1];
        for(int i=0;i<size;i++)
            *(str+i)=*(s.str+i);
    }
    istream &operator>>(istream &cin)//overloading the extraction operator
    {
        char ch;
        for(int i=0;i<size;i++)
        {
            cin>>ch;
            if(ch=='\n')
                break;
            *(str+i)=ch;
        }
        return cin;
    }
    ostream &operator<<(ostream &cout)//overloading the insertion operator
    {
        for(int i=0;i<size;i++)
            cout<<*(str+i);
        cout<<'\n';
        return cout;
    }
};
int main()
{
    int n;
    cout<<"Enter size\n";
    cin>>n;
    String ob(n),obc;
    cout<<"Enter string.\n";
    ob>>cin;
    ob<<cout;
    obc=ob;
    obc<<cout;
    return 0;
}