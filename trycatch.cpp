#include <iostream>
#include <string>
using namespace std;
int main()
{
    int age;
    float salary;
    try
    {
        cin>>age;
        cin>>salary;
        if(age<=18)
            throw -1;
        if(salary<=0)
            throw -1.0f;
        if(age>100)
            throw "exception";
    }  
    catch(int)
    {
        cout<<"Age is to low.\n";
    }
    catch(float)
    {
        cout<<"Invalid salary.\n";
    }
    catch(...)
    {
        cout<<"an error has occurred.\n";
    }
    cout<<"END\n";
    return 0;
}