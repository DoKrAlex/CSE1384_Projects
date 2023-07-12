/*
Name: Alex Do                      NetID: akd306
Date: 4/23/2022                    Due Date: 4/24/2022
Description: My job will be to complete the LinkedList class to make the driver (main.cpp) fully functional. The linked list will be a list of integers.
The header file (linkedlist.h) has definitions for the functions you should be adding tothe code (in the linkedlist.cpp).
The return values and parameters are listed appropriately there.
*/

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList(){
    if(head != nullptr) {
        Node *temp;
        while(head != nullptr) {
            temp = head->next;
            // deletes head
            delete head;
            // goes to next element
            head = temp;
        }
    }
}

void LinkedList::display() {
    Node *temp = head;

    for(int i = 0; i < size; i++) {
        cout << temp->data << "\t";
        temp = temp->next;
    }

    cout << endl;
}

void LinkedList::append(int num) {
    // list is empty
    if(head == nullptr) {
        head = new Node;
        head->data = num;
        head->next = nullptr;
        // sets tail to head
        tail = head;
    }

    else {
        // creates new node
        Node *temp = new Node;
        // sets new node data
        temp->data = num;
        temp->next = nullptr;
        // sets previous tail link to new node
        tail->next = temp;
        // sets this node to new tail
        tail = temp;
    }

    // increments size
    size++;
}

void LinkedList::pop() {
    if(size > 1) {
        Node *temp = head;

        // loops to node before tail
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }

        // deletes tail
        delete tail;
        // sets new tail
        tail = temp;
        tail->next = nullptr;
    }

    // if there's only one item
    else if(size == 1) {
        Node *temp = tail;

        // head and tail are now null
        head = nullptr;
        tail = nullptr;

        // deletes node
        delete temp;
    }

    size--;
}

void LinkedList::insert(int num,int pos) {
   // optional code for validity
   if(pos < 0 || pos > size+1) {
       cout<<"Invalid Position"<<endl;
       return;
   }
   // create node
   Node *temp = new Node;
   temp->data = num;
   temp->next = nullptr;
   if(pos==0) { // check if 0th index
       temp->next = head; // change next to head
       head =temp; // create node as head
   }
   else if(pos==size) { // check for last
       tail->next = temp; // add after tail
       tail = temp;
   }
   else {
       Node *curr = head;
       int i = 0;
       while(i < (pos-1)) { // find prev position
           curr = curr->next;
           i++;
       }
       // save instance at postion after position to change
       Node *p = curr->next;
       curr->next = temp; // change prev->next to node
       temp->next = p; // change node next pos node next
  
   }
   size++; // increment size
}

int LinkedList::linearSearch(int key) {
   Node *curr = head; // save address of first node
   int index = 0; // to return index
   while(curr!=nullptr) { // run till traverse all
       if(curr->data == key) {
           return index; // return index
       }
       curr = curr->next; // increment next
       index++; // increase index
   }
   return -1; // if not found return -1
}

int LinkedList::min() {
   Node *curr = head->next; // assign second node as curr
   int minValue = head->data; // assign data of first node as min
   while(curr!=nullptr) {
       if(minValue > curr->data){ // check if min greater
           minValue = curr->data; // assign min value
       }
       curr = curr ->next;
   }
   return minValue; // return min
}

int LinkedList::max() {
   Node *curr = head->next; // assign second node as curr
   int maxValue = head->data; // assign data of first node as max
   while(curr!=nullptr) {
       if(maxValue < curr->data) { // check if max small
           maxValue = curr->data; // assign max value
       }
       curr = curr ->next;
   }
   return maxValue; // return max
}

int LinkedList::mean() {
   Node *curr = head;
   int sum = 0; // sum all node
   while(curr!=nullptr) {
       sum += curr->data;
       curr = curr->next; // point to next node
   }
   return sum/size; // return mean
}

void LinkedList::reverse() {
    // Initialize current tail, previous and
    // next pointers
    Node* current = head;
    tail = head;
    Node *prev = NULL, *next = NULL;

    while (current != nullptr) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}

void LinkedList::sort() {
   // use bubble sort
   for(Node *i = head ; i != nullptr; i = i->next) {
       for(Node *j = head; j->next !=nullptr; j=j->next) {
           if(j->data > j->next->data){
               int temp = j->data;
               j->data = j->next->data;
               j->next->data = temp;
           }
       }
   }
}

void LinkedList::remove(int pos) {
   // optional validity check
   if(pos < 0 || pos > size+1) {
       cout<<"Invalid Position"<<endl;
       return;
   }
   if(pos==0) { // check if first node
       head = head->next; // change head to next node
   }
   else { // otherwise find prev node and skip that node
       Node *curr = head;
       int i = 0;
       while(i < (pos-1)){
           curr = curr->next;
           i++;
       }
       Node *p = curr->next;
       curr->next = curr->next->next;
       delete p; // delete that node
   }
   size--;
}
