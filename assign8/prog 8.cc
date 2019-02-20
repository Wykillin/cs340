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

template < class T > void get_list ( vector < T >& v, const char* path )
{
	T num;
	ifstream fd;
	fd.open(path);
	if (!fd)
	{
		cout << "Data file does not exist" << endl;
	}
	fd >> num;
	while (!fd.eof()){
		v.push_back(num);
		fd >> num;
		}
	fd.close();
}

template < class T, class P > void construct_heap ( vector < T >& v, P pred ){
	
	make_heap(v.begin(), v.end(), pred);
	sort_heap(v.begin(), v.end(), pred);
}

// prints heaped vector

template < class T > print_list < T > :: print_list ( const unsigned& s, const unsigned& w,
const unsigned& l, const unsigned& c )
{
	if ( c <= s )
	{
		if (c % l == 0)
		{
			cout << endl;
		}
		cout << fixed << setprecision(2) << setw(w) << x << " ";
		cnt++;
	}
	if ( c == sz)
		cout << endl << endl;
}

template < class T > 
print_list < T > :: print_list ( const int& s, const int& c )
{
	cnt = c;
	sz = s;
}
