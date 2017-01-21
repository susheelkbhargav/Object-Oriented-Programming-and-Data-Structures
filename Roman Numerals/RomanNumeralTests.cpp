#include <iostream>
#include <fstream>
#include "RomanNumeral.h"

#define INPUT_FILE "RomanNumeral.txt"

int main(int argc, char** argv)
{
	ifstream inputfile(INPUT_FILE);  // Input file stream
	string line;  //  It will use to hold the file line by line arithmetic data.
	RomanNumeral r1("XVI"),r2("MMDXLIV"),r3("XCIII"),r4("XIV"); // RomanNumeral objects initialization
//	RomanNumeral r1(2),r2(46),r3(2),r4(234);
// 	cout<<r1<<r2<<r3<<r4;	

	cout<< (r1 + r2 / r3)<<endl; //  arithmetic operations
	
	if(r2 == r4)  // compaing two RomanNumeral
	{
		cout<< "r2 and r4 are equal\n";
	}
	else
	{
		cout<< "r2 and r4 are not equal \n";
	}
	if(r1 == r3)    // compaing two RomanNumeral
	{
		cout<< "r1 and r3 are equal \n";
	}
	else
	{
		cout<< "r1 and r3 are not equal\n";
	}
	
	
	if(inputfile.is_open())  // Checking if a file stream was successfully opened or not
	{
		while(getline(inputfile,line))  // reading the file line by line
		{
			string::size_type pos = line.find_first_of(" ");
			RomanNumeral r(line.substr(0,pos)); // Getting the rightside Roman value 
			string::size_type  pos1 = line.find_first_of(" ",pos+1);
			string operation=line.substr(pos+1,1); // Getting the arithmetic operation information
			pos = line.find_first_of(" ",pos1+1);
			RomanNumeral l(line.substr(pos1+1,pos));  //Getting the leftside Roman value 
			
			/*Performing arithmetic operation provide in line*/
			switch(operation[0])
			{
				case '+':
					  cout<<r<<" + "<<l<< " = " << r + l<<endl;
					  break;
				case '-':
					  cout<<r<<" - "<<l<< " = " << r - l<<endl;
					  break;
				case '*':
					  cout<<r<<" * "<<l<< " = " << r * l<<endl;
					  break;
				case '/':
					  cout<<r<<" / "<<l<< " = " << r / l<<endl;
					  break;

			}
		}
		inputfile.close(); //  closing the opended inputfile
	}
	else
	{
		cout<<"Unable to open input file";
	}
	
	
	return 0;
}

