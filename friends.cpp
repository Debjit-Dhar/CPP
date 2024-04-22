#include <iostream>
class C1
{
    int a,b;
    public:
        C1(int a,int b){this->a=a;    this->b=b;};
        friend int sum(C1);
        void print();
};
int sum(C1 x)
{
    return x.a+x.b;
}
void C1::print()
{
    std::cout<<a<<'\t'<<b<<'\n';
}
int main()
{
    std::cout<<"Hello World.\n";
    C1 x(2,3);
    int s=sum(x);
    x.print();
    std::cout<<"Sum= "<<s<<'\n';
    return 0;
}
