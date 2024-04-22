#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num,i;

    vector<int>::iterator it;//creates an iterator for vectors of integers

    vector<int>v;//creates a null vector
    cout<<v.size()<<'\n';//return the size of the vector
    if(v.empty())//checking for empty
        cout<<"Empty Vector\n";
    
    vector<int>v1(5);//creates a vector of size 5

    vector<int>v2(5,2);//creates a vector of size 5 and initialize each element to 2
    for(i=0;i<v2.size();i++)
        cout<<v2[i]<<'\n';//accessing the vector through index
    v2.clear();//delete all  elments of vector i.e now size of v2 is 0 OR use v2.erase()
    
    vector<int>v3(v1);//creates a vector v3 using exisiting vector v1
    it=v3.begin();//returns an iterator to the beginning of the vector v3
    
    while(it!=v3.end())//returns an iterator to the end of the vector
    {
        cout<<"Enter integer.\n";
        cin>>num;
        *it=num;//simply assign values to elements
        
        it++;
    }
    it=v3.begin();
    v3.insert(it,num+1);//adding extra elements to the vector now size of v3 is 6
    it=v3.begin();
    while(it!=v3.end())
    {
        cout<<*it<<'\n';
        it++;
    }
    cout<<v3.size()<<'\n';
    v3.erase(it);//all element pointed to by it will be deleted if any hence size is also reduced
    v3.push_back(3);//to add element to end,size increases by 1
    v3.pop_back();//to delete the last element,size decreases by one
    return 0;
}