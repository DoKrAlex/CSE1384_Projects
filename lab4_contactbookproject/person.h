#include <string>

using std::string;

#ifndef PERSON_H
#define PERSON_H

class Person
{
    private:
        string firstName;
        string lastName;
        string phone;
        string email;

    public:
        Person();

        // getters
        string getFirstName();
        string getLastName();
        string getPhone();
        string getEmail();

        // setters
        void setFirstName(string first);
        void setLastName(string last);
        void setPhone(string phone);
        void setEmail(string email);
};

#endif // PERSON_H
