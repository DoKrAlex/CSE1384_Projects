/*
Name: Alex Do                      NetID: akd306
Date: 2/6/2022                    Due Date: 2/6/2022
Description: This program will take in two sets of coordinate points, specifically the upper left corner and the lower right corner of a square/rectangle, and display a coordinate grid corresponding with the
points given.
*/

#include <iostream>
#include <vector>
using namespace std;

int main () {
  int x1;
  int y1;
  int x2;
  int y2;
  int xOrig; //Declaring all values as integers

  cout << "Enter your starting x: "; //Asking user for inital X value (higher value)
  cin >> x1;
  cout << "Enter your starting y: "; //Asking user for inital Y value (higher value)
  cin >> y1;
  
  xOrig = x1; //Holds user-inputted starting X value to resetted for each time the loop is reset after y decreases in the grid

  cout << endl;

  cout << "Enter your ending x: "; //Asking user for ending X value (lower value)
  cin >> x2;
  if (x2 >= x1) { //Error message if user-inputted ending X is greater than or equal to starting X, will prompt user to re-enter ending X
      cout << "That's not a valid value. Try again" << endl;
      cout << "Enter your ending x: ";
      cin >> x2;
  }
  
  cout << "Enter your ending y: "; //Asking user for ending Y value (lower value)
  cin >> y2;
  if (y2 >= y1) { //Error message if user-inputted ending Y is greater than or equal to starting Y, will prompt user to re-enter ending Y
	  cout << "That's not a valid value. Try again" << endl;
	  cout << "Enter your ending y: ";
	  cin >> y2;
    }

  while (x1 >= x2) { //Loop for initiating the grid itself
    if (x1 >= x2) { //Conditional statement that loops displaying of coordinates on a line until X1 equals X2
        cout << "(" << x1 << ", " << y1 << ")"; //Displays the coordinates as (x, y)
	    x1 = x1 - 1; //Subtracts 1 from the inital X value as the coordinates go right
    }
	if (x1 < x2) { //Conditional statement that will activate once X1 goes below X2
	    y1 = y1 - 1; //Lowers Y value by 1 for the next line of coordinates
	    cout << endl;
	    x1 = xOrig; //Resets X value to the user-inputted inital X value for the next line of coordinates
	}
	if (y1 < y2) { //Conditional statement that stops the program once the inital Y value equals the ending Y value
	    break;
	}
    }

  return 0;

}
