//inventory.h

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream>
using namespace std;

// base Inventory class
class Inventory
{
protected:
   string itemID;
   string itemName;
   int stock;
   float price;
   bool organic;

public:
   string getItemID();
   string getItemName();
   int getStock();
   float getPrice();
   bool isOrganic();
   void setItemID(string itemID);
   void setStock(int stock);
   void setPrice(float price);
   void setOrganic(int flag);
   float getItemTotal(int quantity);
};

#endif