/*
Name: Alex Do                       NetID: akd306
Date: 3/14/2022                    Due Date: 3/14/2022
Description: I am given a driver file (main.cpp) and two text files (potatoList.txt and
appleList.txt) that will be testing classes that you should create
*/

#include "inventory.h"


string Inventory::getItemID()
{
   return itemID;
}

string Inventory::getItemName()
{
   return itemName;
}

int Inventory:: getStock()
{
   return stock;
}

float Inventory:: getPrice()
{
   return price;
}

bool Inventory:: isOrganic()
{
   return organic;
}

void Inventory:: setItemID(string itemID)
{
   this->itemID = itemID;
}

void Inventory:: setStock(int stock)
{
   this->stock = stock;
}

void Inventory:: setPrice(float price)
{
   this->price = price;
}

void Inventory:: setOrganic(int flag)
{
   if(flag == 1)
       organic = true;
   else
       organic = false;
}

float Inventory:: getItemTotal(int quantity)
{
   return(getPrice()*quantity);
}