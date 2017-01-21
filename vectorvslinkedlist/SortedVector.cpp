#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
}

SortedVector::~SortedVector()
{
}


/***** Complete this file. *****/

bool SortedVector::check()
{
    if (data.size() == 0) return true;

    vector<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}

 void SortedVector::prepend(int value)
 {
	 vector<int>::iterator it=data.begin();
	 it = data.insert(it,value);
 }
 void SortedVector::append(int value)
 {
	 data.push_back(value);
 }
    bool SortedVector::find(int value) const
	{
		vector<int>::const_iterator it=data.begin();
		for(it;it!=data.end();it++)
		{
			if(*it==value)
			{
				//int k=value;
				return true;
			}
			
		}
		return false;
	}
    int SortedVector::get_value(int i) const
	{
		return data[i];
		
	}
    void SortedVector::clear()
	{
		for(vector<int> :: iterator it=data.begin(); it != data.end(); ++it)
    {
      data.pop_back();
        
    }
		
	}
