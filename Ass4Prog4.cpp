#include <iostream>
#include <new>
using namespace std;
class STRING
{
    char *str;
    int size;
    public:
    STRING(int sz=0)//initializing with space
    {   
        size=sz;
        str=new char[sz+1];
        int i;
        for(i=0;i<sz;i++)
            str[i]=' ';
        str[i]='\0';
    }
    STRING(STRING &s)//copy constructor
    {
        size=s.size;
        str=new char[size];
        for(int i=0;i<size;i++)
            str[i]=s.str[i];
    }
    STRING(char s[],int sz)
    {
        size=sz;
        str=new char[size+1];
        int i;
        for(i=0;i<size;i++)
            str[i]=s[i];
        str[i]='\0';
    }
    ~STRING(){delete[]str;}
    
    STRING operator=(STRING s)
    {
        for(int i=0;i<s.size;i++)
            str[i]=s.str[i];
        return *this;
    }
    STRING operator+(STRING s)
    {
        STRING temp(size+s.size);
        int i;
        for(i=0;i<size;i++)
            temp.str[i]=str[i];
        for(i=0;i<s.size;i++)
            temp.str[size+i]=s.str[i];
    }
    int operator<(STRING s)
    {
        int min=size<s.size?size:s.size;
        for(int i=0;i<min;i++)
            if(str[i]<s.str[i])
                return 1;
        if(min==s.size)
            return 0;
        return 1;
    }
    int operator>(STRING s)
    {
        int min=size<s.size?size:s.size;
        for(int i=0;i<min;i++)
            if(str[i]<s.str[i])
                return 0;
        if(min==size)
            return 0;
        return 1;
    }
    int operator==(STRING s)
    {
        if(size!=s.size)
            return 0;
        for(int i=0;i<size;i++)
            if(str[i]!=s.str[i])
                return 0;
        return 1;
    }
};

int main()
{
    STRING str1(10);
    char s1[6]={'D','e','b','j','i','t'};
    char s2[6]={'D','h','a','r'};
    STRING str2(s1,6);
    STRING str3(s1,6);
    cout<<(str2>str3)<<'\n';
    cout<<(str2<str3)<<'\n';
    cout<<(str2==str3)<<'\n';
    str1=str2;    
    return 0;
}