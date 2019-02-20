#ifndef H_BINTREE
#define H_BINTREE

/******************************************************************************************
 * 		Name: 			Adam Wykle
 *      Section: 		03
 *      TA: 			Aditya Sabbineni
 *      Due Date: 		10/6/2016
 *      Assignment#: 	6
 *		Purpose: 		Binary Tree Class, write a the class for binTree that can handle just about any type of data
 *     					the class relies on Node.h for the class Node and is called by the driver program to do all the heavy
 *						printing and stdout structuring.
 *******************************************************************************************/


#include "/home/cs340/progs/16f/p7/Node.h" // for creating and maintaining Node<T>
using namespace std;
//creates an enumerator to choose between left and right node randomly
typedef enum { left_side, right_side } SIDE;
SIDE rnd () { return rand () % 2 ? right_side : left_side; };


/****************************************************************

   CLASS:   Class definition for binTree

   NOTES:      calls all public functoins recursively inside of
				private functions
****************************************************************/

template < class T > class binTree {
	public:
		binTree ( ); // default constructor
		unsigned height ( ) const; // returns height of tree
		virtual void insert ( const T& ); // inserts a node in tree
		void inorder ( void ( * ) ( const T& ) ); // inorder traversal of tree
		unsigned size ( ) const; // public version of size
	protected:
		Node < T >* root; // root of tree
	private:
		unsigned size( Node < T >* ) const; //private version of size ( )
		unsigned height ( Node < T >* ) const; // private version of height ( )
		void insert ( Node < T >*&, const T& ); // private version of insert ( )
		void inorder ( Node < T >*, void ( * ) ( const T& ) ); // private version of inorder ( )
};

/****************************************************************

   FUNCTION:   default constructor for binTree()

   ARGUMENTS:  none

   RETURNS:    root = 0

   NOTES:      default constructor for binTree with root = 0 
****************************************************************/

//Default constructor for binTree()

template<class T>
binTree<T>::binTree()
{
	root = 0; //initialize root
}

template <class T>
unsigned binTree <T>::size( ) const
{
    return size( root ); // call recursive
}

/****************************************************************

   FUNCTION:   public version of insert


   ARGUMENTS:  takes x as an unsigned value

   RETURNS:    the node location and the value in the node

   NOTES:      public version for taking just one argument
****************************************************************/

template <class T>
void binTree<T>::insert( const T& x)
{
	insert(root, x);
}

/****************************************************************

   FUNCTION:   height() const

   ARGUMENTS:  none

   RETURNS:    returns height of passed value, root by default

   NOTES:      returns the greater of the two left and right heights
****************************************************************/

//public height
template <class T>
unsigned binTree <T>::height( ) const
{
    return height( root );
}

/****************************************************************

   FUNCTION:  inorder (( * ) T&))

   ARGUMENTS:  *p (const T& x)

   RETURNS:    a value and a function

   NOTES:      gets x and then calls function recursively
****************************************************************/

//public inorder
template <class T>
void binTree<T>::inorder(void ( *p ) ( const T& x ) )
{
	inorder( root, p ); 
}

// private version of size
template <class T>
unsigned binTree <T>::size( Node <T>* p ) const
{
	if( ptr != 0 ) // if not empty
	{
		return 1 + size( p->left ) + size( p->right );
	}
	else
	{
		return 0; // emtpy tree
	}
} 
//private insert
/****************************************************************

   FUNCTION:   private version of inorder()

   ARGUMENTS:  Node *&p, const x

   RETURNS:    const x

   NOTES:       Takes the value passed and determs if the root is empty. 
				If root is empty, create a new node, else,
				randomly select left or right node
****************************************************************/

template <class T>
void binTree<T>::insert(Node<T>*& p, const T& x)
{

	if (p == 0) 
	{ 
		p = new Node<T>(x);// create new node if root is empty
	}

	else 
	{
		 auto side = rnd(); //create variable equal to rnd() to get side
		
		if ( side == right_side) // select the right side if rnd is equal to right_side
		{
			insert(p->right, x); //insert x into right
		}
		else//( rnd() == left_side ) //insert x into left
		{
			insert(p->left, x);
		}
	}
}

/****************************************************************

   FUNCTION:   private version of inorder()

   ARGUMENTS:  Node *&p, const x

   RETURNS:    const x

   NOTES:      takes the height of both sides of tree and returns the bigger of the two
****************************************************************/

template <class T>
unsigned binTree<T>::height( Node<T>* p) const
{ 
	if ( p == 0) return 0; //tree is empty
	
	else
	{
		int lHeight = height( p->left ); // left side
		int rHeight = height( p->right ); // right side
	  
		if( lHeight > rHeight ) // which is greater
		{
			return 1 + lHeight; // return left
		}
		else
		{
			return 1 + rHeight; // return right 
		}   
	}
}
	
/****************************************************************

   FUNCTION:   private version of inorder()

   ARGUMENTS:  Node *&p, *fn (const x)

   RETURNS:    data to *fn, as well as right and left nodes

   NOTES:      takes the data being passed by main and calls the 
			   function called (usually print).
****************************************************************/

//private inorder 
template <class T>
void binTree<T>::inorder(Node<T>* p, void (*fn) (const T&) )
{
	if( p != NULL )
	{
		inorder( p->left, fn );
		fn( p->data );
		inorder( p->right, fn );
	}
} 
	
#endif
