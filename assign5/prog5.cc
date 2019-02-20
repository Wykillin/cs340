/*	
 *	Name: Adam Wykle
 *	Section: 03
 * 	TA: Aditya Sabbineni
 * 	Due Date: 10/6/2016
 *	Assignment#: 5
 *
 *	Purpose: The Josephus problem is a puzzle about an army whom is out numbered by
 *	enemy forces. They only have one horse left for one soldier to go get reinforcements
 *	and they put their names in the hat at a frequency of K, M names are eliminated from the
 *	group size of N soldiers.
 */
#include "prog5.h"
#include <iterator>
using namespace std;

int main()
{
	in_args p;               //p is ptr->in_args struct, i is the index of M, k is when to print group
	int cnt = 0;
	int i = 0;
	int k = 0;
	vector<string> v;
	init_vals(v, p);
	
	cout << endl << "Initial group of soldiers:" << endl;
	cout << "Number of people? " << p.N << endl;
	cout << "Index for elimination? " << p.M << endl;
	cout << "Index for printing? " << p.K << endl;

	cout << "--------------------------" << endl;
		print_vector(v,cnt);
		
	while ( v.size() != 1 ) // loop until only one soldier remaims ( the one who is getting on the horse)
	{
		i = (i + p.M -1 ) % v.size(); //the soldier getting eliminated is M away from the starting soldier
			v.erase(v.begin() + i);	//remove that soldier from the vector
			

			if ( k == p.K) // print because it's hit the frequency input by user
			{
				cout << "Group of soldiers after " << cnt << " runs:" << endl;
				cout << "--------------------------------" << endl;
				print_vector(v, cnt);
				k = 0; // reset k and start counting towards K again
			}
			cnt++; k++; //iterate
		
	}

		cout << "Group of soldiers after " << cnt << " runs:" << endl;
		cout << "--------------------------------" << endl;
			print_vector(v, cnt); //all done, print header and lucky soldier
}

void init_vals(vector<string> &v, in_args& in) //initializes the vector for the input data
{
	cin >> in.N;  //get input from user/unix pipe
	cin >> in.M;
	cin >> in.K;
	
	v.resize(in.N); //set vector to M, which is given by user.
	generate(v.begin(), v.end(), SEQ(in.N)); //generate N vectors
	
}

void print_vector(const vector<string>& v, const unsigned& cnt)
{
	vector<string>::const_iterator it; //iterator for vector
	int items = 0;

	
		for (it = v.begin(); it != v.end(); it++ )
		{
					cout << *it << " ";
			items++;	
			if( items == 12 ){ cout << endl; items = 0;}
				
		} // just a simple print function
	cout << endl << endl;
}
