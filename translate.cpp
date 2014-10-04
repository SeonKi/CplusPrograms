/*
 * translate.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: skim
 */

#include <string>
#include "translate.h"

using namespace std;

int start = 0;
unsigned int position = 0;
string result="";
string word="";

void translateLineToPig(string entry){
	while (start<entry.length())
	{
		if(((entry[position] >= 'A') && (entry[position]<='Z')) || ((entry[position] >='a') && (entry[position] <= 'z')) || (entry[position] == '\'') || (entry[position] == '\,'))
		{
			position++;
		}
		else
		{

			word = entry.substr(start, (position-start));
			translateWordToPig(word);
			start = position;
			position++; //I am moving two pointers to create a substring without creating an actual buffer
		}

	}

}

void translateLineFromPig(string entry)
{
	while (start<entry.length())
	{
		if(((entry[position] >= 'A') && (entry[position]<='Z')) || ((entry[position] >='a') && (entry[position] <= 'z')))
		{
			position++;
		}
		else
		{
			word = entry.substr(start, position);
			start = position+1;
			translateWordFromPig(word);
			position++;
		}
	}

}

string translateWordToPig(string word) {
	string trans = "";
	string prefix = "";
	string punc = "";

	if (((word[0] == '\,') || (word[0] == '\-'))&& (word[0] != ' '))
		{
			punc+=word[0];
			word.erase(0,1);

		}

		if (word[0]==('a')||word.at(0)=='e'||word.at(0)=='i'||word.at(0)=='o'||word.at(0)=='u'||word.at(0)=='A'||word.at(0)=='E'||word.at(0)=='I'||word.at(0)=='O'||word.at(0)=='U')
		{
			result += (word + "way");
			cout << result;
			result = "";

		}
		else
		{
			for (unsigned int k=0; k<word.length();k++)
			{
				if ((word[k]!=' ')){
					int x = 0;
				}
				else {

				if ((word[k]!='a')&&(word[k]!='e')&&(word[k]!='i')&&(word[k]!='o')&&(word[k]!='u')&&(word[k]!='A')&&(word[k]!='E')&&(word[k]!='I')&&(word[k]!='O')&&(word[k]!='U'))
				{
					prefix+=word[k];
				}
				else
				{
					break;

				}
				}
			}

			trans = word.substr(prefix.length());
			result += (punc + trans + prefix + "ay" +" ");
			cout << "prefix=" << prefix << "=prefix" << endl;
			cout << result;
			result = "";
			trans = "";
			prefix = "";
			word = "";
		}

}

string translateWordFromPig(string entry) {
	char pref;
	if ((word[word.length()-3]=='w')&&(word[word.length()-2]=='a')&&(word[word.length()]=='y'))
	{
		word.erase(word.length()-3,3);
		result = word;
		cout << result;
	}
	else
	{
		if ((word[word.length()-2]=='a')&&(word[word.length()]=='y'))
				{
		word[word.length()-3] = pref;
		word.erase(word.length()-3,3);
		result += pref + word;
				}
		else
		{
			cout << entry;
		}
	}

	return result;
}
