#include <iostream>

#include "linkedlist.h"

using namespace std;

int main()
{
    LinkedList nums;

    // adding through append
    nums.append(8);
    nums.append(6);
    nums.append(7);
    nums.append(8);
    nums.append(0);
    nums.append(9);

    // displays list
    cout << "List after append: " << endl;
    nums.display();
    cout << endl;

    // adding through insert
    nums.insert(1, 0);
    nums.insert(5, 4);
    nums.insert(3, 7);

    // displays list
    cout << "List after inserting: " << endl;
    nums.display();
    cout << endl;

    // testing searching
    cout << "Testing linear search:" << endl;

    int pres = nums.linearSearch(7);

    if(pres < 0)
    {
        cout << "7 is not present in the list." << endl;
    }

    else
    {
        cout << "7 can be found at location " << pres << endl;
    }

    pres = nums.linearSearch(5);

    if(pres < 0)
    {
        cout << "5 is not present in the list." << endl;
    }

    else
    {
        cout << "5 can be found at location " << pres << endl;
    }

    cout << endl;

    // does math
    cout << "Minimum, maximum, and average before removing any items: " << endl;
    cout << "Min: " << nums.min() << endl;
    cout << "Max: " << nums.max() << endl;
    cout << "Mean: " << nums.mean() << endl << endl;

    // displays items reversed
    cout << "Items reversed: " << endl;
    nums.reverse();
    nums.display();
    cout << endl;

    // removing through pop
    nums.pop();
    nums.pop();

    // displays list
    cout << "List after popping: " << endl;
    nums.display();
    cout << endl;

    // removing through remove
    nums.remove(0);
    nums.remove(2);
    nums.remove(4);

    // displays list
    cout << "List after removing: " << endl;
    nums.display();
    cout << endl;

    // displays items sorted
    cout << "Items sorted: " << endl;
    nums.sort();
    nums.display();
    cout << endl;

    // does math
    cout << "Minimum, maximum, and average after removing items: " << endl;
    cout << "Min: " << nums.min() << endl;
    cout << "Max: " << nums.max() << endl;
    cout << "Mean: " << nums.mean() << endl << endl;

    // testing searching
    cout << "Testing linear search:" << endl;

    pres = nums.linearSearch(7);

    if(pres < 0)
    {
        cout << "7 is not present in the list." << endl;
    }

    else
    {
        cout << "7 can be found at location " << pres << endl;
    }

    pres = nums.linearSearch(5);

    if(pres < 0)
    {
        cout << "5 is not present in the list." << endl;
    }

    else
    {
        cout << "5 can be found at location " << pres << endl;
    }

    return 0;
}
