#ifndef  ROMANNUMERAL_H
#define ROMANNUMERAL_H


#include <iostream>
#include <string>

using namespace std;

class RomanNumeral
{
	public:
		
	/* Default Constructor*/
	RomanNumeral();
	/* Construct a RomanNumeral with given string*/	
	RomanNumeral(string s);
	
	/* Construct a RomanNumeral with given decimal*/	
	RomanNumeral(int value);
	
	/* Gets the Roman value of a RomanNumeral*/
	string getRomanValue();
	
	/* Gets the Decimal value of a RomanNumeral*/
	int getDecimalValue();

	/* * * *
	 *  All arthematic operators(+,-,*,/)overloading 
	 *  These fuctions are automatically invoke when arthematic opeations
	 *  are performed between two RomanNumericals object
	 */
	RomanNumeral operator+(const RomanNumeral& rn);
	RomanNumeral operator-(const RomanNumeral& rn);
	RomanNumeral operator*(const RomanNumeral& rn);
	RomanNumeral operator/(const RomanNumeral& rn);
	
	/* * * *
	 *  Equality comparision operators overloading( == , !=)
	 *  These fuctions are automatically called when comparing two RomanNumericals object
	 */
	int operator==(const RomanNumeral& rn);
	int operator!=(const RomanNumeral& rn);
	
	/* * * *
	 * Send this RomanNumeral value in [integer value:roman string] format to given output stream.
	 * Returns 'out' for chaining.
	 */
	friend ostream& operator<<(ostream& out,const RomanNumeral& rn);
	
	/* * * *
	 * Gets the Roman value string format to given input put stream.
	 * Returns 'in' for chaining.
	 */
	friend istream& operator>>(istream& in, RomanNumeral& rn);
	
	private:
	
	/* Converts decimal to roman */
	string toRoman(int n);
	
	/* Converts roman to decimal*/
	int toDecimal(string s);
	
	/*
	 *	Gets the decimal value of a Roman symbol(I,V,...M)
	 */
	int getRomanSymbolValue(char c);
	
	private:
	
	/*yelds the roman number value*/
	string roman;
	
	/*yeilds decimal number value*/
	int decimal;	
};

#endif  // ROMANNUMERAL_H
