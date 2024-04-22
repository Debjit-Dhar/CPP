#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int>v(5);
    vector<int>::iterator it;
    it=v.begin();
    for(int i=0;i<5;i++)
    {
        cout<<"Enter elements.\n";
        cin>>v[i];
    }
    cout<<v.size()<<'\n';
    cout<<v.empty()<<'\n';
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<'\t';
    cout<<'\n';
    cout<<v.capacity()<<'\n';
    v.push_back(3);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<'\t';
    cout<<'\n';
    v.pop_back();
    v.pop_back();
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<'\t';
    cout<<'\n';
    it=v.begin();
    while(it!=v.end())
    {
        cout<<(*it)<<'\t';
        it++;
    }
    cout<<'\n';
    cout<<v.size()<<'\n';
    return 0;
}