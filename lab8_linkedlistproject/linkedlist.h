#include <iostream>

using std::cout;
using std::endl;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList
{
    private:

        struct Node
        {
            int data;
            Node *next;
        };

        int size;
        Node *head, *tail;

    public:
        LinkedList();
        ~LinkedList();

        // misc
        void display();

        // sorting and searching
        // reverse --> sorting in descending
        int linearSearch(int key);
        void sort();
        void reverse();

        // various math
        int min();
        int max();
        int mean();

        // adding
        void append(int num);
        void insert(int num, int pos);

        // removing
        void pop();
        void remove(int pos);
};

#endif // LINKEDLIST_H
