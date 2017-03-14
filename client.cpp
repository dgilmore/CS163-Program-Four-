//David Gilmore CS163 May 25, 2016
//Client File: Program builds a binary search
//tree from a users input, then gives the user
// the option to display, display range, edit,
// remove, display the height of a tree. 
#include "table.h"
#include <iostream>
#include <cctype>
#include <cstring> 
using namespace std;

void input_user(node * & to_add); //fills node with user input
void print_retreive(node * to_print); //prints a single nodes data

int main()
{
   char user;//control var
   char userInput;//control var
   char intake[100];//user input string
   char intake2[100];//user input string
   table tree;  // class instance
   node * to_add; //node to be filled
  cout << "Add You Notes to you notebook. " << endl;   
  do
  { // builds a bst from user input
     input_user(to_add);
     tree.insert(to_add);
     cout << "Would you like to add another entry: " << endl;
     cin >> user;
     cin.ignore(100, '\n');
     delete [] to_add->title;
     delete [] to_add->notes;
     delete [] to_add->chpNum;
     delete [] to_add->pgNum;
     delete to_add; 
  }
  while(user == 'y' || user == 'Y');  
  
  do// user menu of all options
  {
    cout << "********************************" << endl;
    cout << "Display all notes in order:   D "  << endl;
    cout << "Display all notes in a range: R " << endl;
    cout << "Remove a note entry:          X " << endl;
    cout << "Edit a note:                  E " << endl;
    cout << "Retreive a entry by title:    G " << endl;
    cout << "Find the Height of a Tree:    H " << endl;
    cout << "********************************" << endl;  
    cin >> userInput;
    cin.ignore(100, '\n'); 

    if(userInput == 'D' || userInput == 'd')//if user wants to display
    {
      if(tree.display_order())
         cout << "Error: List could not be printed: " << endl;
    }

    if(userInput == 'G' || userInput == 'g')// if user wants to retreive
    {
      cout << "What entry would you like to retreive? " << endl;
      cin.get(intake, 100, '\n');
      cin.ignore(100, '\n');
      node * to_retreive;
      if(!tree.retreive(intake, to_retreive))
        cout << "Error: Entry could not be found" << endl; 
      print_retreive(to_retreive); 
    }

    if(userInput == 'R' || userInput == 'r')//if user wants to display in a range
    {
      cout << "Enter the start range for displaly: " << endl;
      cin.get(intake, 100, '\n');
      cin.ignore(100, '\n');
      cout << "Enter the end range for the display: " << endl;
      cin.get(intake2, 100, '\n');
      cin.ignore(100, '\n');
      if(!tree.display_range(intake, intake2))
          cout << "Error: Could not Print" << endl;
    } 

    if(userInput == 'E' || userInput == 'e')//if user wants to edit a entry
    {
      cout << "What entry do you want to edit? " << endl;
      cin.get(intake, 100, '\n');
      cin.ignore(100, '\n');
      cout << "What are the new notes you'd like to add to the Entry: " << endl;
      cin.get(intake2, 100, '\n');
      cin.ignore(100, '\n');
      if(tree.edit(intake, intake2))
        cout << "Entry was edited: " << endl;
      else
        cout << "Error: Entry was not edited: " << endl; 
    } 
    
    if(userInput == 'x' || userInput == 'X') //if user wants to remove a entry
    {
      cout << "What Entry would you like to remove? Enter the Title: " << endl;
      cin.get(intake, 100, '\n');
      cin.ignore(100, '\n');
      if(tree.remove(intake))
         cout << "Node was removed: " << endl;
      else
         cout << "Error: Node was not removed: " << endl;
    }

    if(userInput == 'h' || userInput == 'H')//if user wants to display the height of a tree
    {
      cout << "Height of the Tree:    " << tree.height() << endl;
    }
 
    cout << "Would you Like to see the Menu again?" << endl;
    cin >> userInput;
    cin.ignore(100, '\n'); 
 }
 while(userInput == 'y' || userInput == 'Y');
 tree.remove_all();// delete the bst
}

void input_user(node * & to_add)//node gets filled with user data
{
   to_add = new node; 
   char input[200];
   cout << "Enter the title of the entry: " << endl;
   cin.get(input, 200, '\n');
   cin.ignore(100, '\n');
   to_add->title = new char[strlen(input) + 1];
   strcpy(to_add->title, input); 
   cout << "Enter the notes for this entry: " << endl;
   cin.get(input, 200, '\n');
   cin.ignore(100, '\n');
   to_add->notes = new char[strlen(input) + 1];
   strcpy(to_add->notes, input); 
   cout << "Enter the chapter numbers for this entry: " << endl;
   cin.get(input, 200, '\n');
   cin.ignore(100, '\n');
   to_add->chpNum = new char[strlen(input) + 1];
   strcpy(to_add->chpNum, input); 
   cout << "Enter the page numbers for this entry: " << endl;
   cin.get(input, 200, '\n');
   cin.ignore(100, '\n');
   to_add->pgNum = new char[strlen(input) + 1];
   strcpy(to_add->pgNum, input);
   cout << "Do you need more study of the subject of this entry? T-true/ F-false: " << endl;
   cin >> to_add->needMoreStudy; 
   cin.ignore(100, '\n');  
}

void print_retreive(node * to_print)// prints a single nodes data
{
   cout << "Title:              " << to_print->title << endl;
   cout << "Notes:              " << to_print->notes << endl;
   cout << "Chapter Number:     " << to_print->chpNum << endl;
   cout << "Page Numbers:       " << to_print->pgNum << endl;
   cout << "Need more studying? " << to_print->needMoreStudy << endl;
} 

