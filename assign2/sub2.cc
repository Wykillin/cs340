/*
 * CSCI 340 - Assignment 2 - Fall 2016
 * 
 * Programmer: Adam Wykle
 * Section: 02
 * TA: Aditya Sabbineni 
 * Due Date: 9/8/2016
 * 
 * Purpose: This computer assignment is meant to implement two search 
 *	    algorithms on randomly generated integers stored in vectors.
 * 	    The search algorithms are linear and binary. It will be using
 * 	    find() for linear searches and binary_search() for binary
 *  
*/

#include "prog2.h"
#include <algorithm>
using namespace std;

void Vectors(vector<int>& v1, vector<int>& v2, int s1, int s2) //fills vecs with rand() with seeds

{
	srand(s1);
	for( int it1 = 0; it1 != ARR_SIZE; it1++)// it1 for vector 1
	{
		int RND_NUM1;
		RND_NUM1 = (rand() % (HIGH - LOW + 1) + LOW);
		v1[it1] = RND_NUM1;
	}
	
	srand(s2);
	for( int it2 = 0; it2 != TEST_ARR_SIZE ; it2++)//it2 for vector 2
	{
		int RND_NUM2;
		RND_NUM2 = (rand() % (HIGH - LOW + 1) + LOW);
		v2[it2]= RND_NUM2;
	}
	sort(v2.begin(), v2.end());
}


void sortVector(vector<int>& v)
{
	sort(v.begin(), v.end());
	
} 


bool linearSearch(const vector<int>& v, int x)
{
	if ( find(v.begin(), v.end(), x) != v.end())//if x isn't the last item in vecotr return true
		return true;
	else
		return false;
		
		
}

bool binarySearch(const vector<int>& v, int x)//returns if x was found
{
	return binary_search(v.begin(), v.end(), x);
}

int search(const vector<int>& v1, const vector<int>& v2, bool (*p)(const vector<int>& , int ))//p points to lnearSearch or binarySearch and returns found to main
{
	
	int found;
		
	for ( int it = 0;it!= TEST_ARR_SIZE; ++it){
		if( p(v1, v2[it]))
			found = found + 1;
	}
	

	return found;
}

void printStat( int totalSucCnt, int vectorSz)// prints the number of successful finds as a float.
{
	float percent = ( ((float)totalSucCnt / vectorSz)*100);
	cout << right << fixed << setprecision(2);
	cout << "\t""Percent of Successful Searches = " << percent<<"%!" << endl;	
	/*Prints the percent of successful searches as right-aligned, floating-point numbers on stdout,
	 where totalSucCnt is the total number of successful comparisons and vectorSz is the size of
	 the test vector.*/
}


void printVector(const vector<int>& v) //prints vectors when called at setw(4) and 16 per row
{
	int i = 0;
	 for( int it = 0; it != TEST_ARR_SIZE; ++it)
		{
			cout  << setw(ITEM_W)  <<  v[it] <<" ";
			
			 i++;
			if( i == NO_ITEMS)
			{
				cout  << endl;
				i=0;
			}
		}
}
		
