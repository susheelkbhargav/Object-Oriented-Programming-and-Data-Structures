/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "InsertionSort.h"

/**
 * Default constructor.
 */
InsertionSort::InsertionSort() : VectorSorter() {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string InsertionSort::name() const { return "Insertion sort"; }

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
	int n =size;
	 for(int i=1; i<=n-1;i++)
	 {
		 int value = a[i];
		 int hole =i;
		 while(hole>0&& data[hole-1]>value)
		 {
			 data[hole]=data[hole-1];
			 hole=hole-1;
		 }
		 data[hole]=value;
	 }
	 
	 

}
