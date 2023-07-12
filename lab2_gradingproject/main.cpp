/*
Name: Alex Do                       NetID: akd306
Date: 2/13/2022                   Due Date: 2/12/2022
Description: This program handles grading and presents the users with many options, such as displaying an average, display all grades stored, and inserting a new grade.
*/

#include <fstream>
#include<iostream>
#include<vector>
using namespace std;
int main() {
   cout << "Welcome to quiz grade averaging!\n";  //welcome message
   int error = 1, choice = 1, size;     //variable initializations
   string file_name;        //stores the file name
   vector<float> grades;    //vector to store the grades
   float element, sum, average, new_grade; //variable declarations
   while(error == 1)        //loop repeats until valid file name is entered
   {
       cout << "\nEnter the file name: ";  //prompts for file_name
       cin >> file_name;
       ifstream ifile;  //file pointer 
       ifile.open(file_name);   //tries to open the file to read
       if(! ifile)      //if file can't open, msg is displayed
            cout << "Error opening. Try again.\n";
        else
            {
                error = 0;  //if file opens, error is made zero
                while(ifile >> element) //reads each value from file to element
                {
                    grades.push_back(element);  //added to grades vector
                }
                ifile.close();   //file is closed
            }
   }
   while(choice != 0)   //loop repeats until wants to exit
   {
       cout << "\nMenu:";       //displays the menu to the user
       cout << "\n0. Exit" << "\n1. Display average";
       cout << "\n2. Display grades" << "\n3. Add new grade";
       cout << "\nEnter choice: ";
       cin >> choice;       //reads into choice
       if (choice == 0)      //if choice is zero, Good-bye msg is displayed
       {
           if (average <= 100 && average >= 90) {
               cout << "\nWith the average of " << average << " you'd have a grade of A.";
           }
           if (average <= 89 && average >= 80) {
               cout << "\nWith the average of " << average << " you'd have a grade of B.";
           }
           if (average <= 79 && average >= 70) {
               cout << "\nWith the average of " << average << " you'd have a grade of C.";
           }
           if (average <= 69 && average >= 60) {
               cout << "\nWith the average of " << average << " you'd have a grade of D.";
           }
           if (average <= 59 && average >= 0) {
               cout << "\nWith the average of " << average << " you'd have a grade of F.";
           }
           if (average <= 100 && average >= 0) {
               cout << "\nGood-bye!";
           }
       }
       else if (choice == 1)     //if choice is 1
       {
           size = grades.size();    //vector size is stored in size variable
           for(int i = 0; i < size; i++)
               sum += grades[i];    //each element is added to the sum
            average = sum/size;    //average is sum divided by size
            cout << "\nYour average quiz score is: " << average; //displays the average
            cout << "\n";
       }
       else if (choice == 2)     //if choice is 2
       {
           size = grades.size();
           for(int i = 0; i < size; i++)
                cout << "\nGrade " << i+1 << ": " << grades[i];  //displays all the grades
            cout << "\n";
       }
       else if (choice == 3)   //if choice is 3
       {
            cout << "\nEnter a grade to add (0.0-100.0): "; //prompts for the grade
            cin >> new_grade;       //reads into new_grade
            while(!(new_grade >= 0.0 && new_grade <= 100.0)) //if grade is not in range, loop is repeated
            {
                cout << "Invalid grade. Please try again.\n";
                cout << "Enter a grade to add (0.0-100.0): ";
                cin >> new_grade;
            }
            grades.push_back(new_grade);  //new_grade is added to grades vector
       }
       else {
           cout << "\nInvalid choice. Please try again.\n";
       }
   }
}