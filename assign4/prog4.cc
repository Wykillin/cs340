/*	
 *	Name: Adam Wykle
 *	Section: 03
 * 	TA: Aditya Sabbineni
 * 	Due Date: 9/8/2016
 *
 *	Purpose: Create a program that starts with an empty list of words then reads
 *		a file and looks for punctuation marks and spaces to seperate words.
 * 		After inserting the words into a map the words and their frequency should
 *		be printed on the ostream with setw 16 and 3 words per line.
*/
#include "prog4.h"
using namespace std;
//main calls get_words and then call print_words
int main()
{
	map<string, int> m;
	get_words(m);
	print_words(m);
	
	return 0;	
}

//get_words scans prog4.d for punctuation marks and takes what isn't punctuation as words
//then it inserts the words into the map if their length > 0.

void get_words(map <string, int>& m)
{

	string dirty, clean;
	while( cin >> dirty )
	{
			
		if( dirty.length() !=  0) 
		{		
			clean_entry( dirty, clean );
		}		
	if(clean.length()>0)	m[clean]++;	
	
	}
	
}		
		

//prints at ITEM_W spacing on each word in map followed by the no. times it occurs
//if there are 3 items in a row, create a new row

void print_words(const map<string, int>& m)
{

	int count; //the count is the values of the map added together
	map<string, int>::const_iterator it = m.begin(); 
	while( it != m.end())
	{
		int i = 0;	
		for(;it != m.end(); ++it)
		{
			cout << setw(ITEM_W) << left <<  it->first << ": " << it->second << '\t';
			i++; count += it->second;

			if(i == NO_ITEMS){ cout << endl; i = 0; }
	
		}
	
	cout << endl  << "no of words in input stream:  " <<  count << endl;
	cout << "no of words in output stream: " << m.size() << endl; 	
	
	}
}

void clean_entry(const string& f, string& l)
{
	
	int i=0, j=0; //must be equal to zero to be an index
	for(i=0;i<f.length();i++) //initialize i on first letter of string and iterate until it points at a nonalpha
	{
		if(isalnum(f[i]) )	break; //breaks if i != alnum
	}
	for(j=i+1;j<f.length();j++)//same as i but from behInd
	{	
		if(isalnum(f[j]) == false)	break;
	}
	l =  f.substr(i, (j-i));	//set non const string to l between i and j substr(first pos, char length)
	
	for(i=0;i<l.length();++i)
		l[i]= tolower(l[i]);	//loop i until it is at end of string and convert each to lowercase

}
