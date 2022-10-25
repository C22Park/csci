#include <iostream>

using namespace std;

class Item
{
private:
    double price;
    string upc;
    string description;

public:
    Item();

    Item(double price_in, string upc_in, string description_in);

    //getters and setters
    double getPrice();

    // need to modify this to not allow a negative price
    void setPrice(double price_in);

    string getUpc();

    void setUpc(string upc_in);

    string getDescription();

    void setDescription(string description_in);
};