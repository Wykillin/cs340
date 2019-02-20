/******************************************************************************************
 * 		Name: 			Adam Wykle
 *      Section: 		02
 *		Instructor:     Jie Zhou
 *      TA: 			Aditya Sabbineni
 *      Due Date: 		11/09/2016
 *      Assignment#: 	8
 *		Purpose: 		write a C++ program to sort items in several input files,
 *                      using the heapsort technique. For each input file, your program 
 *                      first reads the items from the input file and builds a heap structure for these items. 
 *                      Then, it retrieves these items from the heap structure in a given order and prints 
 *     					them out on stdout.
 *******************************************************************************************/



#include "prog8.h"






int main ( )
{
    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings

    // print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";

    // first heap

    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int > print1 ( v1.size ( ), INT_SZ, INT_LN );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    cout << "first heap - descending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    // second heap

    cout << "second heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float > print2 ( v2.size ( ), FLT_SZ, FLT_LN );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    cout << "second heap - descending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    // third heap

    cout << "third heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string > print3 ( v3.size ( ), STR_SZ, STR_LN );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    cout << "third heap - descending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
    return 0;
}


/****************************************************************

   CLASS:   Template for get_list(vector, char*)

   NOTES:   Opens an input file for reading, then reads the items from the file 
			and inserts them in a vector
****************************************************************/
template < class T > void get_list ( vector < T >& v, const char* path )
{
	v.clear();
	T num;
	ifstream fd;
	fd.open(path);
	if (!fd)
	{
		cout << "Data file does not exist" << endl;
		exit(1);
	}
	fd >> num;
	while (!fd.eof()){
		v.push_back(num);
		fd >> num;
		}
	fd.close();
}


/****************************************************************

   CLASS:   Template for construct_heap(vector<T>, P pred)

   NOTES:   This uses the STL to construct a heap using a predicate
   * 		The main function in this case will pass either greater
   * 		or less and then sort accordingly
****************************************************************/
template < class T, class P > void construct_heap ( vector < T >& v, P pred ){
	
	make_heap(v.begin(), v.end(), pred);
	sort_heap(v.begin(), v.end(), pred);
}

/****************************************************************

   CLASS:   Default constructor for print_list

   NOTES:    s is the heap size, w is the minimum number of chars 
   * 		 written in printout, l is the maximum number of items 
   * 		 printed in a single line, and c is used as a counter
****************************************************************/
template < class T > print_list < T > :: print_list ( const unsigned& s, const unsigned& w,
const unsigned& l, const unsigned& c )
{
		sz = s;
		wid = w;
		len = l;
		cnt = c;
	
}
/****************************************************************

   CLASS:   Operator for print_list

   NOTES:   Object can be used to print out the item x of a heap on stdou
****************************************************************/
template < class T > 
void print_list < T > :: operator ( ) ( const T& x )
{
	cout.width ( wid ); cout.precision ( 2 );
	cout << fixed << showpoint;
	if ( cnt <= sz )
	{
		if (cnt % len == 0)
		{
			cout << endl;
		}
		cout << x << " ";
		cnt++;
		if (cnt == sz)
			cout << endl << endl;
	}
}
