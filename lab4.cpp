#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1="makakund",s2="bappa",s3="djkund";
    string sub="kund";
    if(s1.find(sub)!=string::npos)
        cout<<"1\n";
    else
        cout<<"-1\n";
    if(s2.find(sub)!=string::npos)
        cout<<"1\n";
    else
        cout<<"-1\n";
    if(s3.find(sub)!=string::npos)
        cout<<"1\n";
    else
        cout<<"-1\n";
    
    /*int m,n,i,j;
    cout<<"Rows\n";
    cin>>m;
    cout<<"Cols\n";
    cin>>n;
    int **a=new int*[m];
    for(i=0;i<m;i++)
      a[i]=new int[n];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            a[i][j]=1;
    for(i=0;i<m;i++)
        {for(j=0;j<n;j++)
            cout<<a[i][j]<<'\t';
        cout<<'\n';
        }
    for(i=0;i<m;i++)
        delete[] a[i];
    delete[] a;*/
    return 0;
}
