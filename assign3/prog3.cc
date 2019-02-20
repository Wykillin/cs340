/* Programmer: Adam Wykle
 * Section: 03
 * TA: Aditya Sabbineni
 * Due Date: 9/8/2016
 *
 * Purpose: Sieve of Eratosthenes. This program is meant to prompt the user
 *          to input a number as the upperbound of a set. Then the algorithm
 *          will eliminate each number in the set that is not a prime number
 *          by using sieve() and then printing the numbers remainging with
 *	    print_primes() formated.
*/



#include "prog3.h"
using namespace std;



int main()
{
	int n;//n is the number input by user for upperbound
	cout << "upper limit for the set of primes: ";
	cin >> n;
	cout << endl;
	set<int> s; //create empty set
	sieve(s, n);//to the sieve!
	print_primes(s); //print prime numbers
}

void sieve(set<int>& s, int n)
{
	for(int i = 2; i <= n; i++) //set i to 2 and increment
	{
		s.insert(i); //insert 2, 3, 4, ..n
	}
	
	for(int m = 2; m * m <= n; m++)//initialize m as 2 as long as m^2 <=n
	{
		if(s.find(m) != s.end()) //see if at end of set
		{
			int k = 2 * m; //initialize k as double m
				while(k <= n) //check if k is in set
				{
					s.erase(k); //erase double of m
					k += m;	//take k and add m, to move one up iteration by m
						//ie 2*m = 4 then k+=m = k=6
				}
		}

	}
}

void print_primes(const set<int>& s) //prints prime numbers from 2 to n
{
	set<int>::const_iterator it; //create iterator for set
	int i = 0;
	for(it = s.begin(); it != s.end(); it++) //make sure it's still in set
	{
		cout << setw(ITEM_W) << *it << " ";//print primes at it with  setw(ITEM_W)
		i++;
		if(i == NO_ITEMS) //if NO_ITEMS per line start a new line and reset i
		{
			cout << endl;
			i = 0; //reset i
		}
	}
	cout << endl;
}
