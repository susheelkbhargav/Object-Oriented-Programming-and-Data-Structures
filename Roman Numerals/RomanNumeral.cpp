#include"RomanNumeral.h"

/*
 *  Constructor.
 *  Initializes all data with zeros and empty strings
 */
RomanNumeral::RomanNumeral():roman(""),decimal(0)
{
	
}
RomanNumeral::RomanNumeral(string s)
{
	roman = s;
	decimal = toDecimal(roman);  // Getting decimal information fom roman value
}
	
RomanNumeral::RomanNumeral(int value)
{
	decimal = value;
	roman = toRoman(decimal); // Getting roman information fom decimal value
}
	
string RomanNumeral::getRomanValue()
{
	// returns roman string value
	return roman;
}
	
int RomanNumeral::getDecimalValue()
{
	// returns integer value
	return decimal;
}
	
RomanNumeral RomanNumeral::operator+(const RomanNumeral& rn)
{	
    // which invokes single argument constuctor and return a RomanNumeal object
	return RomanNumeral(decimal + rn.decimal);
}

RomanNumeral RomanNumeral::operator-(const RomanNumeral& rn)
{
	// which invokes single argument constuctor and return a RomanNumeal object
	return RomanNumeral(decimal - rn.decimal);
}

RomanNumeral RomanNumeral::operator*(const RomanNumeral& rn)
{
	// which invokes single argument constuctor and return a RomanNumeal object
	return RomanNumeral(decimal * rn.decimal);
}

RomanNumeral RomanNumeral::operator/(const RomanNumeral& rn)
{
	// which invokes single argument constuctor and return a RomanNumeal object
	return RomanNumeral(decimal / rn.decimal);
}
	
int RomanNumeral::operator==(const RomanNumeral& rn)
{
	return (decimal == rn.decimal);  //  return 1 if both objects has same value else return 0
}

int RomanNumeral::operator!=(const RomanNumeral& rn)
{
	return (decimal != rn.decimal);  //  return 1 if both objects are not equal else return 0
}

ostream& operator<<(ostream& out,const RomanNumeral& rn)
{
	// output in [integer value : roman string]
	out<<"["<<rn.decimal<<":"<<rn.roman<<"]";
	return out;
}
	
istream& operator>>(istream& in, RomanNumeral& rn)
{
	string input; // To hold roman number given by user
	
	cout<<"enter roman value : ";
	in>> input;  // Gets the input from the user 	
	// Assiagning an object which created from the input roman string 
	//to input RomanNumeral object 
	rn = RomanNumeral(input);  
	return in;
}

string RomanNumeral::toRoman(int value)
{
  string result;  // Yeilds the Roman number 
  // define a structure to contain decimal and roman number
  struct romannumeral_data_t { int value; char const* roman; }; 
  // Created array of structure to hold roman number and its decimal value
  romannumeral_data_t rd[]=	{{1000, "M"},{900, "CM"},{500, "D"},{400, "CD"},
					 {100, "C"},{90, "XC"},{50, "L"},{40, "XL"},
					 {10, "X"},{9, "IX"},{5, "V"},{4, "IV"},{1, "I"},{0,NULL}}; 
	
	//Travesing structure				 
	for (romannumeral_data_t const* current = rd; current->value; current++)
	{
		/* Checking decimal value is less than or equal to the current elemet value */
		while(value >= current->value)
		{
			result = result + current->roman; // adding string to roman string
			value  = value - current->value; // decreasing decimal value 
		}
	}
  return result;
}

int RomanNumeral::getRomanSymbolValue(char c)
{
	int value = 0;  // Initialziing value , holds roman symbol value
	
	/* Checking roman symbol */
	switch(c)
	{
		case 'I':
				  value = 1;
				  break;
		case 'V':
				  value = 5;
				  break;
		case 'X': 
				  value = 10;
				  break;
		case 'L':
		 		  value = 50;
				  break;
		case 'C': 
				  value = 100;
				  break;
		case 'D': 
				  value = 500;
				  break;
		case 'M': 
		 		  value = 1000;
				  break;
	}
	
	return value;  
}

int RomanNumeral::toDecimal(string s)
{
	int value = 0;  // Yeilds the total integer number value 
	int prev  = 0;  // Holds prev Roman integer symbol value
	
	// Traverse given roman number
	for(int i = 0; s[i]; i++)
	{
		int romansymbol_value = getRomanSymbolValue(s[i]);  //  Getting Roman symbol value of current index
		
		value += romansymbol_value;  // Adding every roman symbol value 		
		if(prev < romansymbol_value)  // comparing previous roman symbol value with current
		{
			value = value - (2 * prev);  // if current roman symbol value is greater than previous . modify the total decimal value
		}
		prev = romansymbol_value;  // update prev value with current  roman symbol value
	}
	return value;
}
	
	

