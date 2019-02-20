/******************************************************************************************
 * 		Name: 			Adam Wykle
 *      Section: 		02
 *      TA: 			Aditya Sabbineni
 *      Due Date: 		10/28/2016
 *      Assignment#: 	7
 *		Purpose: 		Binary Search Tree Class, write a the class for binTree that can handle just about any type of data
 *     					the class relies on Node.h for the class Node and is called by the driver program to do all the heavy
 *						printing and stdout structuring.
 *******************************************************************************************/
#include "binTree.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;


#ifndef H_BINTREES
#define H_BINTREES



/****************************************************************

   CLASS:   Class definition for binSTree

   NOTES:   refers to binTree.h and is a friend of Node.h
   * 		builds on what assignment 7 was.
			
****************************************************************/

template < class T >
class binSTree : public binTree < T > {
public:
void insert ( const T&  ); // inserts node with value x
void remove ( const T&  ); // removes node with value x
private:
void insert ( Node < T >*&, const T& ); // private version of insert
void remove ( Node < T >*&, const T& ); // private version of remove
Node < T >* pred ( Node < T >* ); // returns predecessor of node
};

// insert node with value x
template <class T>
void binSTree<T>::insert ( const T& x )
{
	insert( this->root, x );
}

// remove node with value x
template <class T>
void binSTree<T>::remove ( const T& x )
{
	remove( this->root, x );
}
  
/****************************************************************

   FUNCTION:   private version of remove()

   ARGUMENTS:  Node *&p, const x

   RETURNS:    none

   NOTES:       Deletes node if it matches x
****************************************************************/

template <class T>
void binSTree<T>::remove ( Node <T>*& p, const T& x )
{
    Node<T> *tmp;

     if (p == NULL) return;
      
 


                if(x>p->data) remove(p->right,x);

                else if(x<p->data) remove(p->left,x);
                
                if (p->data == x)
                 {
           
                if( p->left == 0 && p->right == 0)
                {
                        delete p;
                        p=NULL;
                        return;
                } //if it is a leaf node

                else if (p->left != 0 && p->right == 0)
                {

                        p= p->left; //if left node is not empty and right is not make p point to left node
                        remove(p->left, p->data);
                         return;
                }


                else if (p->left == 0 && p->right != 0)
                {
                        p = p->right;
                         //if left node is not empty and right is not make p point to left node
                        remove(p->right, p->data);
                      return;
                }

                else 
                {
						
                        tmp = pred(p); /* if none of those is true p is equal to the predocessor*/
                        p->data = tmp->data; // copy the predecessor to the original node
						
                       
                        remove(p->left, p->data);
                       
                }
                
			
	}
	
}

// private version of insert
/****************************************************************

   FUNCTION:   private version of insert()

   ARGUMENTS:  Node *&p, const x

   RETURNS:    none

   NOTES:       Inserts into tree on left if smaller and right if bigger
   * 			than root.
****************************************************************/
template <class T>
void binSTree<T>::insert ( Node <T>*& p, const T& x )
{
	

	if(p == NULL)
	{
        p = new Node<T>( x );
	}
    else if( x < p->data)
	{
        insert( p->left, x );
	}
    else if( x > p->data )
	{
        insert(p->right, x );
	}
    else
	{
        return; // duplicate 
	}
}
/****************************************************************

   FUNCTION:   pred

   ARGUMENTS:  Node

   RETURNS:    predecessor

   NOTES:       
****************************************************************/

template <class T>
Node<T>* binSTree<T>::pred(Node<T> *node)
{
	
	node = node->left;
	
	
	while (node->right != 0) node = node->right;
	
	return node;
	
		
	
}


#endif
