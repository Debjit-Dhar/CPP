#include <iostream>
using namespace std;
template<class x>
class Array
{
    int size;
    x *arr;
    public:
    Array(int sz)
    {
        size=sz;
        arr=new x[size];
        for(int i=0;i<size;i++)
        {
            cout<<"Enter element\n";
            cin>>arr[i];
        }
    }
    x findmax()
    {
        x max=arr[0];
        for(int i=0;i<size;i++)
            if(arr[i]>max)
                max=arr[i];
        return max;
    }
    x findsum()
    {
        x sum=0;
        for(int i=0;i<size;i++)
            sum+=arr[i];
        return sum;
    }
};
int main()
{
    Array<int> a1(5);
    cout<<a1.findmax();
    cout<<a1.findsum();
    return 0;
}