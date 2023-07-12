/*
Name: Alex Do                      NetID: akd306
Date: 2/19/2022                  Due Date: 2/19/2022 
Description: This program utilizes vectors to allow the user to create and edit their own class schedule.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int addClass (std::vector <string> &courseCode, std::vector <string> &className) {				//Function for adding a class
    string course;
    string clasn;
    cout << "What course code would you like to add?(4 characters long): ";	//Prompts the user to enter a course number
    cin >> course;
    if (course.length () == 4) {				//If statement that allows the user to progress in adding a class if the course code is 4 characters long
        cout << "What is the course name?: ";	//Prompts the user to enter the course name
        cin.ignore ();
        getline (cin, clasn, '\n');
        courseCode.push_back (course);
        className.push_back (clasn);
    }
    else {				//Else statement that stops the user from adding a class name if the course code is not 4 characters long
        return 1;
    }
    return 0;
}

void viewSchedule (std::vector <string> &courseCode, std::vector <string> &className) {				//Function for viewing the class schedule
    int size = courseCode.size ();
    
    for (int i = 0; i < size; i++) {				//Displays all classes present
      cout << i + 1 << ". " << courseCode[i] << " " << className[i] << endl;
    }
    cout << endl;
}

int removeClass (std::vector <string> &courseCode, std::vector <string> &className) {				//Function for removing a class
    int n;
    cout << "Which course would you like to delete?: ";	//Prompts the user to select a class to remove
    cin >> n;

    if (n >= 1 && n <= courseCode.size ()) {				//If statement that allows the user to remove a class if they select a valid number
      courseCode.erase (courseCode.begin () + n - 1);
      className.erase (className.begin () + n - 1);
    }
    else {				//Else statement that stops the user from removing a class if they do not select a valid number
        return 1;
    }
  return 0;
}

int editClass (std::vector <string> &courseCode, std::vector <string> &className) {				//Function for editing a class
    int n;
    string clasn;
    cout << "Which course would you like to edit?: ";	//Prompts the user to select a class to edit
    cin >> n;

    if (n >= 1 && n <= courseCode.size ()) {				//If statement that allows the user to edit a class if they select a valid number
        className.erase (className.begin () + n - 1);
        cout << "What would you like the new name to be?: ";	//Prompts the user to enter the new class name
        cin.ignore ();
        getline (cin, clasn, '\n');
        className.push_back (clasn);
    }
    else {				//Else statement that stops the user from editing a class if they do not select a valid number
        return 1;
    }
    return 0;
}


int main () {				//Main function

    int n;
    vector < string > courseCode;
    vector < string > className;

    while (1) {				//Displays menu
        cout << "0. Exit\n";
        cout << "1. View Schedule\n";
        cout << "2. Add Class\n";
        cout << "3. Remove Class\n";
        cout << "4. Edit Class\n";
        cout << "Which option would you like? ";
        cin >> n;			//User inputs which option they would like

        cout << "\n\n";
        if (n == 0) {			//Exits the program if 0 is chosen
            cout << "Good-bye!\n";
	        break;
        }
    
        else if (n == 1) {			//Option to view class schedule
	        if (courseCode.size () == 0) {
                cout << "You have to add classes first!\n\n";
	        }
	        else {
	            viewSchedule (courseCode, className);
	        }
	    }
	
        else if (n == 2) {			//Option to add a class
            if (!addClass (courseCode, className)) {			//Displays after successful input from user
	            cout << "Course added!\n\n";
	        }
            else {			//Displays after unsuccessful input from user, prompts user to input a proper 4 number class code
	            cout << "Error in adding course. Please try again.\n\n";
	        }
        }
	    
        else if (n == 3) {			//Option to remove a class
            if (courseCode.size () == 0) {			//Displays if there are no classes present, checking the vector
	            cout << "You have to add classes first!\n\n";
	        }
	        else {			//Displays if classes are present, and after the user selects a class to remove
                viewSchedule (courseCode, className);
                if (!removeClass (courseCode, className)) {
		            cout << "Course removed!\n\n";
                }
	            else {		//Displays if the user inputs an invalid class number
		            cout << "Error in removing course. Please try again.\n\n";
		        }
            }
        }
    
        else if (n == 4) {			//Option to edit a class
            if (courseCode.size () == 0) {			//Displays if there are no classes present, checking the vector
	        cout << "You have to add classes first!\n\n";
	        }
	        else {			//Displays if classes are present, and after the user selects a class to edit
	            viewSchedule (courseCode, className);
	            if (!editClass (courseCode, className)) {
                    cout << "Course edited!\n\n";
    		    }
	            else {		//Displays if the user inputs an invalid class number
		            cout << "Error in editing course. Please try again.\n\n";
                }
	        }
	    }
	
        else {			//Displays if the user chooses an invalid option
            cout << "That is not a valid menu option.Try again.\n\n";
	    }
    }
    return 0;
  
}
