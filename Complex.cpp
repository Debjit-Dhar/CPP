#include <iostream>
using namespace std;
class Complex
{
    
    float real,img;
    public:
    Complex(float a=0,float b=0)
    {
        real=a;
        img=b;
    }
    Complex(const Complex &c)
    {
        real=c.real;
        img=c.img;
    }
    void display()
    {
        img>0?cout<<real<<'+'<<img<<"i\n":cout<<real<<img<<"i\n";
    }
    /*friend Complex operator+(Complex ,Complex);//overloading binary +(same for -,*,/,%)
    friend Complex operator+=(Complex&,Complex);//overloading shorthand operator +=(same for -=,/=,*=,%=)
    friend Complex operator++(Complex&);//overloading pre-increment(same for pre-decrement)
    friend Complex operator++(Complex&,int);//overloading post-increment(same for post decrement)*/
    friend istream& operator>>(istream& cin,Complex &c);//overloading extraction operator
    friend ostream& operator<<(ostream& cout,Complex c);//overloading insertion operator
    friend Complex operator*(int,Complex&);
    Complex operator+(Complex c)//overloading binary +(same for -,*,/,%)
    {
        Complex sum;
        sum.real=real+c.real;
        sum.img=img+c.img;
        return sum;
    }
    Complex operator+=(Complex c)//overloading shorthand operator +=(same for -=,/=,*=,%=)
    {
        real+=c.real;
        img+=c.img;
        return *this;
    }
    Complex operator++()//overloading pre-increment(same for pre-decrement)
    {
        cout<<"Pre increment\n";
        ++real;
        ++img;
        return *this;
    }
    Complex operator++(int)//overloading post-increment(same for post decrement)
    {
        cout<<"Post increment\n";
        real++;
        img++;
        return *this;
    }
    /*istream& operator>>(istream&cin)//overloading extraction operator
    {
        cout<<"Enter real\n";
        cin>>real;
        cout<<"Enter imaginary\n";
        cin>>img;
        return cin;
    }
    ostream& operator<<(ostream& cout)//overloading insertion operator
    {
        img>0?cout<<real<<'+'<<img<<"i\n":cout<<real<<img<<"i\n";
        return cout;
    }*/
    //Below operators must be overloaded as non-static member functions
    Complex operator=(Complex c)//overloading =
    {
        real=c.real;
        img=c.img;
        return *this;
    }
    float operator[](int i)//overloading [] operator
    {
        if(i==0)
            return real;
        else
            return img;
    }
    Complex operator()(float a,float b)//overloading () operator
    {
        real=a;
        img=b;
        return *this;
    }
    Complex *operator->()//overloading -> operator
    {
        return this;
    }
    Complex operator*(int num)
    {
        real*=num;
        img*=num;
        return *this;
    }
};
void *operator new(size_t size)//overloading new operator
{
    void *p=malloc(size);
    return p;
}
void operator delete(void *p)//overloading delete operator
{
    free(p);
}
Complex operator*(int num,Complex& c)
{
    c.real*=num;
    c.img*=num;
    return c;
}
/*Complex operator+(Complex c1,Complex c2)//overloading binary +(same for -,*,/,%)
{
    Complex sum;
    sum.real=c1.real+c2.real;
    sum.img=c1.img+c2.img;
    return sum;
}
Complex operator+=(Complex &c1,Complex c2)//overloading shorthand operator +=(same for -=,/=,*=,%=)
{
    c1.real+=c2.real;
    c1.img+=c2.img;
    return c1;
}
Complex operator++(Complex &c)//overloading pre-increment(same for pre-decrement)
{
    cout<<"Pre increment\n";
    ++c.real;
    ++c.img;
    return c;
}
Complex operator++(Complex &c,int)//overloading post-increment(same for post decrement)
{
    cout<<"Post increment\n";
    c.real++;
    c.img++;
    return c;
}*/
istream& operator>>(istream& cin,Complex& c)
{
    cout<<"Enter real\n";
    cin>>c.real;
    cout<<"Enter imaginary\n";
    cin>>c.img;
    return cin;    
}
ostream& operator<<(ostream& cout,Complex c)
{
    c.img>0?cout<<c.real<<'+'<<c.img<<"i\n":cout<<c.real<<c.img<<"i\n";
    return cout;
}

int main()
{
    Complex c1(2.5,3.5),c2(2.6,-3.6);
    c1.display();
    c2.display();
    Complex sum=c1+c2;
    sum.display();
    c1++;
    ++c2;
    c1.display();
    c2.display();
    sum=c1=c2;
    sum.display();
    c1.display();
    c2.display();
    c1+=c2;
    c1.display();
    cout<<c1[0]<<'\n';
    cout<<c1[1]<<'\n';
    c1(3.5,4.6);
    c1.display();
    /*c1>>cin;//for member operator function
    c2<<(c1<<cout);//for member operator function*/
    cin>>c1;//for non-member operator function
    cout<<c1<<c2;//for non-member operator function
    cout<<c1*5;
    cout<<5*c1;
    return 0;
}