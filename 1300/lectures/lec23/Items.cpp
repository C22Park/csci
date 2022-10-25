#include "Item.h"

Item::Item()
{
    price = 0;
    upc = "";
    description = "";
}

Item::Item(double price_in, string upc_in, string description_in)
{
    price = price_in;
    upc = upc_in;
    description = description_in;
}

//getters and setters
double Item::getPrice()
{
    return price;
}

// need to modify this to not allow a negative price
void Item::setPrice(double price_in)
{
    price = price_in;
}

string Item::getUpc()
{
    return upc;
}

void Item::setUpc(string upc_in)
{
    upc = upc_in;
}

string Item::getDescription()
{
    return description;
}

void Item::setDescription(string description_in)
{
    description = description_in;
}