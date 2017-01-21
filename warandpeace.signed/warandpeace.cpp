#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){

	bool foundInLastLine=false;
	size_t found=0;
	size_t foundLast=0,foundLastTemp;
	size_t foundNext=0;
	int lineNum=1;
	int tempIndex;
	string tempStr;

	vector<string> firstName; //storimg first name as a vector
	vector<string> lastName; // storing second name as another vector

	firstName.push_back("Makar"); 
	firstName.push_back("Joseph");
	firstName.push_back("Boris");	

	lastName.push_back("Alexeevich");
	lastName.push_back("Bazdeev");
	lastName.push_back("Drubetskoy");
	

/**Reading the file*/

    ifstream file("WarAndPeace.txt");
    string str;

/** Print Header for output*/
    cout << "LINE\t"  << "POSITION\t"<<"NAME" << endl;

    
    while (getline(file, str))
    {
		if(foundInLastLine)
				{
					tempStr = str.substr(0,12); /** taking a length of 12 characters*/
					foundNext=tempStr.find(lastName[tempIndex]);

					if (foundNext!=string::npos) /**if found*/
                	{
						cout << lineNum-1<<"\t"<< foundLastTemp+1 << "\t" << firstName[tempIndex]+' '+lastName[tempIndex] << endl;
						foundInLastLine=false;
					}
					foundInLastLine=false;
				}
				
		
		for(int i=0;i<firstName.size();i++)
		{

				found=str.find(firstName[i]+' '+lastName[i]); 

                if (found!=string::npos) 
                    cout << lineNum<<"\t"<< found+1 << "\t" << firstName[i]+' '+lastName[i] << endl;
                else 
                {
					foundLast=str.find(firstName[i]);  
                	if(foundLast!=string::npos)
                	{
                		foundInLastLine=true;
                		foundLastTemp = foundLast;
                		tempIndex = i;

                	}
                }	
		}
		lineNum++; /** to print line number*/
	}
}