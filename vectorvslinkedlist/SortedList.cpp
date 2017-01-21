#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
}

SortedList::~SortedList()
{
}

/***** Complete this file. *****/

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}

void SortedList::prepend(int value)
{
	 
	list<int>::iterator it = data.begin();
		 it= data.insert(it,value);

	/*For each data structure, use an iterator to append an integer value at the beginning. You
may assume that the data arrives in sorted order, largest to smallest. Therefore, you do
not need to sort the data into smallest to largest order.
*/
}
    void SortedList::append(int value)
	{
		data.push_back(value);
		
		/*For each data structure, append an integer value to the end. You may assume that the
data arrives in sorted order, smallest to largest. Therefore, you do not need to sort the
data.*/
	}
    bool SortedList::find(int value) const
	{
		list<int>::const_iterator it=data.begin();
		for(it;it!=data.end();it++)
		{
			if(*it==value)
			{
				//int k=value;
				return true;
			}
			
		}
		return false;
	
		/*For each data structure, use a constant iterator to search for the given value. Return true
if the value is found, else return false.*/
	}
	
    int SortedList::get_value(int i) const
	{
		/*For each data structure, return the value at the given index i. You do not need to checkthe range of the index.For the data, use a constant iterator to access the ith element. Since you can walk adoubly linked data in both directions starting from its beginning or the end, also use a reverse constant iterator and start from the end whenever that is advantageous.*/
		int k = 0;
		if(i>=0&&i<data.size())
		{
  for(list <int> ::const_iterator it=data.begin(); it != data.end(); ++it)
    {
        if(k==i)
        {
             return *it;
        }
        
      k++;
    }
		
		}
		
	}
    void SortedList::clear()
	{
		/*For each data structure, use an iterator to repeatedly erase (remove) the head element
until the all the elements are gone.*/
  for(list<int> :: iterator it=data.begin(); it != data.end(); ++it)
    {
      data.pop_back();
    }

	}
   /* bool SortedList::check()
	{
		int prev=NULL;
  for(data <int> :: iterator it=lst.begin(); it != lst.end(); ++it)
    {
       if(prev>*it)
	   {
		   return FALSE;
	   }
       
    }
		return TRUE;
	}*/