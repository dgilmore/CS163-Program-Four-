//David Gilmore CS163 May 25, 2016
// Header File: This file has the struct node decleration
// as well as the binary search tree class declaration. The
// program lets a user add entrys to a bst, then the user
// can decide to diplay the entries in order, display a range
// of entries in alphabetical order, remove and entry, edit
// and entry or retrieve a entries data in a node. 
#include <cstdlib>
struct node
{
   int key; 
   char * title;
   char * notes;
   char * chpNum;
   char * pgNum;
   char needMoreStudy;
   
   node * right;
   node * left;
};

class table
{

   public:
   table();
   int hash(char * keyword); 
   int insert(node * to_add);
   int remove(char * keyword);
   int retreive(char * keyword, node * & to_retreive);
   int edit(char * keyword, char * newNotes);
   int display_order();
   int display_range(char * start, char * end);
   int remove_all();
   int height();
   
   private:
   int insert(node * & root, node * to_add);
   int remove(node * & root, char * keyword); 
   int remove_all(node * & root);
   int display_order(node * root);
   int retreive(node * root, char * keyword, node * & retreive);  
   int display_range(node * root, int start, int end); 
   int edit(node * & root, char * keyword, char * newNotes);
   int height(node * root);   
   node * root;
}; 
