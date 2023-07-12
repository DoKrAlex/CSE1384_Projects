/*  Intermediate Computer Programming
 *  Spring 2022 - Lab 5
 *
 *  Driver program
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

// user made classes
#include "apple.h"
#include "potato.h"

// using statements
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ifstream;
using std::exit;
using std::string;

// user defined functions
int processPotatoFile(vector<Potato> &potatoes);
int processAppleFile(vector<Apple> &apples);
void displayStock(vector<Potato> &potatoes, vector<Apple> &apples);
void displayPotatoStock(vector<Potato> &potatoes);
void displayAppleStock(vector<Apple> &apples);


int main()
{
    // initial vectors
    vector<Potato> potatoes;
    vector<Apple> apples;

    // function to process file
    processPotatoFile(potatoes);
    processAppleFile(apples);
    cout << endl;

    // display stock list before...
    cout << "***STOCK BEFORE CHANGES***" << endl;
    displayStock(potatoes, apples);

    // testing functions...
    // potatoes
    potatoes[0].setStock(456);
    potatoes[1].setPrice(1.99);
    potatoes[2].setType("Purple");
    potatoes[2].setOrganic(1);

    // apples
    apples[0].setOrchardLocation("New York, NY");
    apples[0].setType("Granny Smith");
    apples[2].setPrice(0.45);

    // display stock list after...
    cout << endl << "***STOCK AFTER CHANGES***" << endl;
    displayStock(potatoes, apples);


    // testing other functions...
    cout << endl << "***MISCELLANEOUS***" << endl;
    cout << "Buying 44 " << apples[1].getType() << " " << apples[1].getItemName();
    cout << " will cost $" << apples[1].getItemTotal(44) << endl;

    cout << "Buying 134lbs worth of " << potatoes[0].getType() << " " << potatoes[0].getItemName();
    cout << " will cost $" << potatoes[0].getPotatoTotal(134) << endl;

    return 0;
}

// processing potato file
int processPotatoFile(vector<Potato> &potatoes)
{
    ifstream infile;
    string line;

    // initial variables
    string type, itemID;
    int quantity, flag;
    float price;

    // static potatoList file
    infile.open("potatoList.txt");

    // checking for file success
    if(infile.is_open())
    {
        cout << "Successful potato file opening." << endl;
    }

    // exits program otherwise
    else
    {
        cout << "Couldn't locate potato file. Program closing." << endl;
        exit(EXIT_FAILURE);
    }

    // loop to read file
    while(getline(infile, line))
    {
        if(line == "potato")
        {
            // initial object
            // constructor: no parameters
            Potato temp;

            // get potato data...
            getline(infile, type);
            getline(infile, itemID);
            infile >> quantity;
            infile >> price;
            infile >> flag;

            // ignore newline for next getline...
            infile.ignore();

            // set potato data
            temp.setType(type);
            temp.setItemID(itemID);
            temp.setStock(quantity);
            temp.setPrice(price);
            temp.setOrganic(flag);

            // add to appropriate vector
            potatoes.push_back(temp);
        }

    }

    return 0;
}

int processAppleFile(vector<Apple> &apples)
{
    ifstream infile;
    string line;

    // initial variables
    string type, itemID, location;
    int quantity, flag;
    float price;

    // static appleList file
    infile.open("appleList.txt");

    // checking for file success
    if(infile.is_open())
    {
        cout << "Successful apple file opening." << endl;
    }

    // exits program otherwise
    else
    {
        cout << "Couldn't locate apple file. Program closing." << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(infile, line))
    {
        if(line == "apple")
        {
            // get apple data...
            getline(infile, type);
            getline(infile, itemID);
            infile >> quantity;
            infile >> price;
            infile >> flag;

            // ignore newline...
            infile.ignore();

            // final line...
            getline(infile, location);

            // create object
            // constructor: with parameters
            Apple temp(type, location, itemID, quantity, price, flag);

            // add to appropriate vector
            apples.push_back(temp);
        }

    }
}

// function to actually display the stock
void displayStock(vector<Potato> &potatoes, vector<Apple> &apples)
{
    cout << "We have the following items in stock: " << endl << endl;

    displayPotatoStock(potatoes);
    displayAppleStock(apples);
}

void displayPotatoStock(vector<Potato> &potatoes)
{
    // display potatoes
    for(int i = 0; i < potatoes.size(); i++)
    {
        cout << "Item: " << potatoes[i].getItemID() << endl;
        cout << potatoes[i].getStock() << " ";
        cout << potatoes[i].getType() << " " << potatoes[i].getItemName();
        cout << " at " << potatoes[i].getPrice() << " per lb" << endl;
        cout << "Organic: ";

        if(potatoes[i].isOrganic())
        {
            cout << "yes" << endl << endl;
        }

        else
        {
            cout << "no" << endl << endl;
        }
    }
}

void displayAppleStock(vector<Apple> &apples)
{
    // display apples
    for(int i = 0; i < apples.size(); i++)
    {
        cout << "Item: " << apples[i].getItemID() << endl;
        cout << apples[i].getStock() << " ";
        cout << apples[i].getType() << " " << apples[i].getItemName();
        cout << " at $" << apples[i].getPrice() << " per item" << endl;
        cout << "Sourced from: " << apples[i].getOrchardLocation() << endl;
        cout << "Organic: ";

        if(apples[i].isOrganic())
        {
            cout << "yes" << endl << endl;
        }

        else
        {
            cout << "no" << endl << endl;
        }
    }
}