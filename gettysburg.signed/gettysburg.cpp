#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const string INPUT_FILE_NAME = "GettysburgAddress.txt";

int main()
{
    string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;
    int lower_count = 0;
    int upper_count = 0;
    int space_count = 0;
    int punctuation_count = 0;

    char currentCharacter;
    char prevCharacter = ' ';


    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }





    while (true)
    {

        input.get(currentCharacter);
        //cout<<currentCharacter<<"\t";



        if (input.eof())
        {
            break;
        }
        else if (currentCharacter == '\n')
        {
            ++line_count;

            //++word_count;
        }
        else if(currentCharacter == ' ')
        {
        	++space_count;
        	++character_count;

        	//++word_count;
        }
        else if(islower(currentCharacter))
        {
        	++lower_count;
        	++character_count;
        }
        else if(isupper(currentCharacter))
        {
        	++upper_count;
        	++character_count;
        }
        else if(ispunct(currentCharacter))
        {
        	++punctuation_count;
        	++character_count;

        	//if(currentCharacter == '.'||currentCharacter == ',')
        	//{

        	//++word_count;
        	//}
        }


        if(((islower(prevCharacter)||isupper(prevCharacter))&& isspace(currentCharacter)))
        {
            ++word_count;
        }
         if(((islower(prevCharacter)||isupper(prevCharacter))&& ispunct(currentCharacter)))
        {
            ++word_count;
        }


        prevCharacter=currentCharacter;

    }


    cout <<"Statistics for file " << INPUT_FILE_NAME << ":" << endl;
    cout << endl;

    /***** Complete this program. *****/

    cout << "Lines: " << line_count << endl;
    cout << "Characters: " << character_count << endl;
    cout << "Words: " << word_count << endl;
    cout << "Lower-case letters: " << lower_count << endl;
    cout << "Upper-case letters: " << upper_count << endl;
    cout << "Spaces: " << space_count << endl;
    cout << "Punctuation marks: " << punctuation_count << endl;
}
