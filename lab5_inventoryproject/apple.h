#include "apple.h"

Apple::Apple()
{
   type = "";
   orchardLocation = "";
   itemID = "";
   itemName = "Apples";
   stock = 0;
   price = 0;
   organic = false;
}

Apple::Apple(string type, string location, string itemID, int stock, float price, int flag)
{
   setType(type);
   setOrchardLocation(location);
   setItemID(itemID);
   itemName = "Apples";
   setStock(stock);
   setPrice(price);
   setOrganic(flag);
}

string Apple::getType()
{
   return type;
}

string Apple::getOrchardLocation()
{
   return orchardLocation;
}

void Apple::setType(string type)
{
   this->type = type;
}

void Apple::setOrchardLocation(string location)
{
   this->orchardLocation = location;
}