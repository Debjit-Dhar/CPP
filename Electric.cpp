#include <iostream>
#include <string.h>
using namespace std;
class Electric
{
    long int consumer_id;
    char consumer_name[100];
    char consumer_address[100];
    long int meter_id;
    float last_reading;
    float current_reading;
    float meter_rent;
    float per_unit_rate;
    public:
    Electric(long int id,char name[],char address[],long int mid,float lr,float cr,float mr=10,float pur=10)
    {
        consumer_id=id;
        strcpy(consumer_name,name);
        strcpy(consumer_address,address);
        meter_id=mid;
        last_reading=lr;
        current_reading=cr;
        meter_rent=mr;
        per_unit_rate=pur;
    }
    ~Electric()
    {
        cout<<"Apocalypse has arrived\n";
    }
    float calculate_bill()
    {
        float r=current_reading-last_reading;
        return meter_rent+per_unit_rate*r;
    }
    void printer()
    {
        cout<<"Consumer Id="<<consumer_id<<'\n';
        cout<<"Consumer Name= "<<consumer_name<<'\n';
        cout<<"Consumer Address= "<<consumer_address<<'\n';
        cout<<"Bill ="<<calculate_bill()<<'\n';
    }
};
int main()
{
    return 0;
}