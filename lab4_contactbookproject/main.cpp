/*
Name: Alex Do                     NetID: akd306
Date: 3/8/2022                 Due Date: 3/8/2022
Description: The program uses the Person class to aid in creating an address book to manage the user’s
contacts.
*/

#include "person.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// function declarations
void readContacts(vector<Person> &contacts, ifstream &infile);
void addContacts(vector<Person> &contacts, string filename);
void displayContacts(vector<Person> &contacts);

int main() {
    vector <Person> contacts;
    string filename;

    // ask user for file name
    cout << "Welcome to your address book manager!\n";
    cout << "Please enter a file to read your contacts from (include extension): "; 
    cin >> filename;
    ifstream infile(filename);
    // loop until valid file name is entered
    while(!infile) {
        cout << "That file doesn't exist. Try again.\n\n";
        cout << "Please enter a file to read your contacts from (include extension): ";
        cin >> filename;
        infile.open(filename);
    }
    
    // call function to read contacts in vector
    cout << "\nFile opening ...\n";
    readContacts(contacts, infile);
    infile.close();
    cout << "File read. Closing the file from read mode.\n";

    // loop until user wants to use the program
    while (true) {
        cout << "\nMenu\n";
        cout << "1. Display Contacts\n";
        cout << "2. Add Contacts\n";
        cout << "3. Remove Contacts\n";
        cout << "0. Exit\n";
        int ch;
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch) {
            case 1: displayContacts(contacts);
                break;
            case 2: addContacts(contacts, filename);
                break;
            case 0: exit(0);
            default: cout << "Error. Invalid choice! Try again.\n";
        }
    }
    return 0;
}

// function definitions

/* Purpose: read the contents of file in a loop */

void readContacts(vector<Person> &contacts, ifstream &infile) {
    Person p;
    string fname, lname, pno, email;
    while(infile >> fname >> lname >> pno >> email) {
        p.setFirstName(fname);
        p.setLastName(lname);
        p.setPhone(pno);
        p.setEmail(email);
        contacts.push_back(p);
    }
}

/* Purpose: get input from user and append in file */
void addContacts(vector<Person> &contacts, string filename) {
    Person p;
    string fname, lname, pno, email;
    cout << "\nWhat is the first name? ";
    cin >> fname;
    cout << "What is the last name? ";
    cin >> lname;
    cout << "What is the phone number (no spaces)? ";
    cin >> pno;
    cout << "What is the email address? ";
    cin >> email;
    p.setFirstName(fname);
    p.setLastName(lname);
    p.setPhone(pno);
    p.setEmail(email);
    contacts.push_back(p);

    ofstream outfile;
    outfile.open(filename, ofstream::app);
    outfile << fname << " " << lname << " " << pno << " " << email << "\n";
    outfile.close();
}

/* void deleteContact(vector<Person> &contacts, string filename) {
    Person p;
    string fname, lname, pno, email;
    cout << "\nWhich contact would you like to remove? ";
    contacts.push_back(p);

    ofstream outfile;
    outfile.open(filename, ofstream::app);
    outfile << fname << " " << lname << " " << pno << " " << email << "\n";
    outfile.close();
} /*

/* Purpose: display the contents of vector */
void displayContacts(vector<Person> &contacts) {
    for (int i = 0; i < contacts.size(); i++) {
        cout << "\nContact " << (i + 1) << ": \n";
        cout << "Name: " << contacts[i].getFirstName() << " " << contacts[i].getLastName() << "\n" << "Phone number: " << contacts[i].getPhone() << "\n" << "Email address: " << contacts[i].getEmail() << "\n";
    }
}