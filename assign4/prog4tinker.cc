/*	
 *	Name: Adam Wykle
 *	Section: 03
 * 	TA: Aditya Sabbineni
 * 	Due Date: 9/8/2016
 *
 *	Purpose: Create a program that starts with an empty list of words then read
 *		a file and look for punctuation marks and spaces to seperate words.
 * 		After inserting the words into a map the words and their frequency should
 *		be printed on the ostream.
*/
#include "prog4.h"
using namespace std;
//main calls get_words()
//bool isalnum(char c) { return true;}
int main()
{
	map<string, int> m;
	get_words(m);
	print_words(m);
	
	return 0;	
}

//get_words scans prog4.d for punctuation marks and takes what isn't punctuation as words
//then it inserts the words into the map

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
		



void print_words(const map<string, int>& m)
{

	int count;
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
	string::iterator i = find_if(f.begin(), f.end(), isalnum);	
	string::iterator j = find_if(f.end(), f.begin(), isalnum);	
	int i=0, j=0; //must be equal to zero to be an index
	for(i=0;i<f.length();i++)
	{
		if(isalnum(f[i]) )	break;
	}
	for(j=i+1;j<f.length();j++)
	{	
		if(isalnum(f[j]) == false)	break;
	}
	l =  f.substr(i, (j-i));	
	
	for(i=0;i<l.length();++i)
		l[i]= tolower(l[i]);	

}
