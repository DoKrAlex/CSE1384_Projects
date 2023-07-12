#include "person.h"

Person::Person()
{
    firstName = "";
    lastName = "";
    phone = "";
    email = "";
}

// getters
string Person::getFirstName()
{
    return firstName;
}

string Person::getLastName()
{
    return lastName;
}

string Person::getPhone()
{
    return phone;
}

string Person::getEmail()
{
    return email;
}

// setters
void Person::setFirstName(string first)
{
    firstName = first;
}

void Person::setLastName(string last)
{
    lastName = last;
}

void Person::setPhone(string phone)
{
    this->phone = phone;
}

void Person::setEmail(string email)
{
    this->email = email;
}
