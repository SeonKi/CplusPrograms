//Seong Kim CS280 Section 03 Programming Assignment 1

#include <iostream>
#include <string>
#include "translate.h"
using namespace std;


int main(int argc, char *argv[])
{
	enum { TOPIG, FROMPIG } mode;
	if( argc == 1 ) {


		mode = TOPIG;
	}
	else if( argc != 2 ) {


		cout << "That was not a valid input" << endl;

		return 1;
	}
	else {


		string userArg(argv[1]);


		if( userArg == "topig" ) {



			mode = TOPIG;


		}


		else if( userArg == "frompig" ) {



			mode = FROMPIG;


		}


		else {



			cout << "That was not a valid input" << endl;



			return 1;


		}
	}


	string entry = "";
	while (true)
	{
		getline(cin, entry);
		if (!cin.good())
		{
			break;
		}
		if (mode == FROMPIG )
		{
			translateLineFromPig(entry);

		}
		else
		{
			translateLineToPig(entry);
		}
	}
return 0;
}

