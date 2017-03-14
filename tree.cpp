//David Gilmore CS163 May 25, 2016
//Binary Search Tree CPP file: File contains the constructor
// destructor, a hash function, an insert function, a removal
// function, a retreive, display in order and display in range 
// function and edit function. 
#include "table.h"
#include <cctype>
#include <cstring>
#include <iostream> 

table::table()//constructor
{
  root = NULL;
}

int table::hash(char * keyword)//hash function, takes first letter in keyword
{                              //multiplies by 13 and returns. 
   int total = keyword[0];
   total = total * 13;
   return total;
}

int table::insert(node * to_add)//insert function wrapper
{
   return insert(root, to_add); 
}

int table::insert(node * & root, node * to_add)//insert function takes a filled nodes and saves it
{                                              //in position by value
  int total = hash(to_add->title);
  int test_total = 0; 
  if(root == NULL)
  {
     root = new node;
     root->key = total; 
     root->title = new char[strlen(to_add->title) + 1];
     root->notes = new char[strlen(to_add->notes) + 1];
     root->chpNum = new char[strlen(to_add->chpNum) + 1];
     root->pgNum = new char[strlen(to_add->pgNum) + 1];
     strcpy(root->title, to_add->title);
     strcpy(root->notes, to_add->notes);
     strcpy(root->chpNum, to_add->chpNum);
     strcpy(root->pgNum, to_add->pgNum);
     root->needMoreStudy = to_add->needMoreStudy; 
     root->left = NULL;
     root->right = NULL;
     return 1;  
  }
  
  if(root->key > total)
  {
     insert(root->right, to_add);
  }
  else
     insert(root->left, to_add); 
}

int table::display_order()//display function wrapper
{ 
   return display_order(root); 
}

int table::display_order(node * root)// display function prints in the order of first letter of title
{
   using namespace std; 
   if(!root) return 0; 
   display_order(root->right);
   cout << "Title: " << root->title << endl;
   cout << "NOTES: " << root->notes << endl; 
   display_order(root->left); 
} 

int table::retreive(char * keyword, node * & to_retreive)// retreive function wrapper
{
   return retreive(root, keyword, to_retreive); 
}  

int table::retreive(node * root, char * keyword, node * & to_retreive) //keyword used to find entry to copy and return by ref.
{
   if(!root) return 0;

   int total = hash(keyword);

   if(root->key == total)
   {
     if(strcmp(keyword, root->title) == 0)
     {
        to_retreive = new node;
        to_retreive->title = new char[strlen(root->title) + 1];
        to_retreive->notes = new char[strlen(root->notes) + 1];
        to_retreive->chpNum = new char[strlen(root->chpNum) + 1];
        to_retreive->pgNum = new char[strlen(root->pgNum) + 1];
        strcpy(to_retreive->title, root->title);
        strcpy(to_retreive->notes, root->notes);
        strcpy(to_retreive->chpNum, root->chpNum);
        strcpy(to_retreive->pgNum, root->pgNum);
        to_retreive->needMoreStudy = root->needMoreStudy;
        return 1;  
      }
   }

   if(total <  root->key)
        retreive(root->right, keyword, to_retreive);
   else
        retreive(root->left, keyword, to_retreive); 
}

int table::display_range(char * start, char * end)//display range wrapper
{
     int total = hash(start);//start of range key
     int total2 = hash(end);//end of range key
     return display_range(root, total, total2);
}

int table::display_range(node * root, int start, int  end)//displays entries by first letter of title
{
    using namespace std; 
    if(!root) return 0;
    
    display_range(root->right, start, end);
    if(root->key >= start && root->key <= end)
      cout << "Title: " << root->title << endl;
    display_range(root->left, start, end); 
}

    
int table::edit(char * keyword, char * newNotes)//edit function wrapper
{
   return edit(root, keyword, newNotes);
}

int table::edit(node * & root, char * keyword, char * newNotes)//edit function lets user add string to notes
{                                                              // return 1 for success. 

   if(!root) return 0;
   int total = hash(keyword);

   if(root->key == total)// if key matches
   {
     if(strcmp(keyword, root->title) == 0)//check title vs. keywrod to be certain
     {

        char * temp = new char[strlen(root->notes) + 1];
        strcpy(temp, root->notes); 
        delete [] root->notes;
        root->notes = new char[strlen(temp) + strlen(newNotes) + 2];
        strcpy(root->notes, temp); 
        strcat(root->notes, " "); 
        strcat(root->notes, newNotes);
        delete [] temp;
        return 1;
      }
   }
  
   if(total < root->key)
        edit(root->right, keyword, newNotes);
   else
        edit(root->left, keyword, newNotes); 
}


int table::remove(char * keyword)//remove function wrapper 
{
   return remove(root, keyword);
}

int table::remove(node * & root, char * keyword)//remove function searches for a key and removes entry from tree
{                                               
     if(!root) return 0;// emptry tree return failure
     int total = hash(keyword);
    
     if(total == root->key)
     {
      if(strcmp(keyword, root->title) == 0)
      {
    
        if(root->right == NULL && root->left == NULL) //if a leaf remove is easy
        {
           delete root;
           root = NULL;
           return 1;
        }
        if(root->right == NULL && root->left !=NULL)//if only one child, parent can adopt
        {
           node * ptr = root->left;
           delete root;
           root = ptr;
           return 1;
        }
        if(root->left == NULL && root->right != NULL)//if only one child, parent can adopt
        {
          node * ptr = root->right;
          delete root;
          root = ptr;
          return 1;
        }
        if(root->right != NULL && root->left != NULL)//two children, find in order successor
        {                                            //copy data into node to be removed.
          node * current = root->right;
          node * prev;
          delete [] root->title;
          delete [] root->notes;
          delete [] root->chpNum;
          delete [] root->pgNum;
          
          while(current->left != NULL)
          {
              prev = current;
              current = current->left;
          }
          root->title = new char[strlen(current->title) + 1];
          root->notes = new char[strlen(current->notes) + 1];
          root->chpNum = new char[strlen(current->chpNum) + 1];
          root->pgNum = new char[strlen(current->pgNum) + 1];
          strcpy(root->title, current->title);
          strcpy(root->notes, current->notes);
          strcpy(root->chpNum, current->chpNum);
          strcpy(root->pgNum, current->pgNum);
          root->needMoreStudy = current->needMoreStudy;
          root->key = current->key; 
         
          if(current->right != NULL)
          {
               prev->left = current->right;
          }     
          delete [] current->title;
          delete [] current->notes;
          delete [] current->chpNum;
          delete [] current->pgNum;
          delete current;
       }
     }
   }

}

int table::height()  
{
  return height(root);
}
 
int table::height (node * root)
{  using namespace std;
   if(!root) return 0;
   return max(height(root->right), height(root->left)) + 1;
}

int table::remove_all()
{
     return remove_all(root);
}

int table:: remove_all(node * & root)
{
   if(!root) return 0;

   remove_all(root->right);
   remove_all(root->left);
   
   delete root;
   root = NULL; 
}
 
