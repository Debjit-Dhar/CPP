#include <iostream>  
#include<string>  
using namespace std;
int main()
{
    string str;     
    cout << "Enter the string as an input:";
    getline(cin, str,'\n');
    cout<<"Name is "<<str<<'\n';
}  