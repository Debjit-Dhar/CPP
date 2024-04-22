#include <iostream>
#include <limits>

using namespace std;
class Item
{
    long int item_code;
    char item_name[100];
    float base_price;
    int qty;
    friend void get_details(Item a);
};
class Stock_List
{
    char type;
    

};
int main()
{
    size_t maxvalue = std::numeric_limits<size_t>::max();
    cout<<maxvalue;
    return 0;
}