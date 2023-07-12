/*
Name: Alex Do                      NetID: akd306
Date: 4/2/2022                    Due Date: 4/2/2022
Description: This a program that will recursively build an equation based on user input. The equation will be a string of
parentheses, numbers, and operations.
*/
#include <iostream>
#include <string>
using namespace std;

string buildEq(bool nested, string tab);

int main() {
    cout << "Welcome to the equation builder!" << endl << endl;

    cout << "Instructions: Each step can only have one operation between two numbers." << endl;
    cout << "So the equation (3 + 4) + 6 would have one 'nested' operation." << endl << endl;

    string equation = buildEq(false, "");

    cout << endl << "The equation you have built is... " << equation << endl;
    cout << endl << "Thanks for coming!" << endl;

    return 0;
}

string buildEq(bool nested, string tab) {
    string equation = "";

    // Adding open parenthesis only if nested
    if (nested) {
    equation += "(";
    }

    char nestInput;

    /*
    * Left Operand
    */
    // Looping to determine a valid answer (y/n)
    while (nestInput != 'y' && nestInput != 'n') {
        cout << tab << "For this step, is there nesting? (y/n) ";
        cin >> nestInput;
        if(nestInput != 'y' && nestInput != 'n') {
            cout << tab << "Error: only 'y' and 'n' are valid inputs. Please try again." << endl;
        }
    }
    // Recursion if response is yes (nested)
    if (nestInput == 'y') {
        equation += buildEq(true, tab + "\t");
    }
    // Prompting user for number, if response is no
    else if (nestInput == 'n') {
        int number;
        cout << tab << "What number would you like to enter: ";
        cin >> number;
        equation += (number + '0');
    }

    /*
    * Operator
    */
    char operation;

    // Looping to ensure a valid answer is entered (+, -, * or /)
    while (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
        cout << endl << tab << "What operation would you like to perform? (+, -, *, /) ";
        cin >> operation;
        if (operation != '+' && operation != '-' && operation != '*' &&operation != '/') {
            cout << tab << "Error: only '+', '-', '*' and '/' are valid inputs. Please try again." << endl;
        }
    }
    
    // Updating the equation with the operation and spaces
    equation += " ";
    equation += operation;
    equation += " ";

    /*
    * Right Operand
    */
    nestInput = '\0'; // Making the character empty.
    
    // Looping to determine a valid answer (y/n)
    while(nestInput != 'y' && nestInput != 'n') {
        cout << endl << tab << "For this step, is there nesting? (y/n) ";
        cin >> nestInput;
        if(nestInput != 'y' && nestInput != 'n') {
            cout << tab << "Error: only 'y' and 'n' are valid inputs. Please try again." << endl;
        }
    }
    
    // Recursion if response is yes (nested)
    if(nestInput == 'y') {
        equation += buildEq(true, tab + "\t");
    }
    
    // Prompting user for number, if response is no
    else if(nestInput == 'n') {
        int number;
        cout << tab << "What number would you like to enter: ";
        cin >> number;
        equation += (number + '0');
    }

    // Adding closed parenthesis only if nested
    if(nested) {
        equation += ")";
    }

    return equation;
}