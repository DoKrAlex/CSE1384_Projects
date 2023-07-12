#ifndef POTATO_H_
#define POTATO_H_

#include "inventory.h"

// derived Potato class
class Potato: public Inventory
{
private:
   string type;

public:
   Potato();
   Potato(string type, string itemID, int stock, float price, int flag);
   string getType();
   void setType(string type);
   float getPotatoTotal(float weight);
};

#endif

//end of potato.h

// potato.cpp

#include "potato.h"

Potato::Potato()
{
   type = "";
   itemID = "";
   itemName = "Potatoes";
   stock = 0;
   price = 0;
   organic = false;
}

Potato::Potato(string type, string itemID, int stock, float price, int flag)
{
   setType(type);
   setItemID(itemID);
   itemName = "Potatoes";
   setStock(stock);
   setPrice(price);
   setOrganic(flag);
}

string Potato::getType()
{
   return type;
}

void Potato::setType(string type)
{
   this->type = type;
}

float Potato::getPotatoTotal(float weight)
{
   return getPrice()*weight;
}