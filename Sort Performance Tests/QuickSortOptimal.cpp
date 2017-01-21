/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "QuickSortOptimal.h"

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
QuickSortOptimal::QuickSortOptimal() {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string QuickSortOptimal::name() const { return "Quicksort optimal"; }

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
int QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    /***** Complete this member function. *****/
	  int center = (left + right) / 2;
    int pivot = (data [left] + data [right] + data [center])/3;
	/*Examine the two values at the ends of the list and the value at the middle position of the list.
Choose the value that’s in between the other two*/
//source:http://algorithms.tutorialhorizon.com/quick-sort-implementation/
    while (left <= right) {
			while (data[left] < pivot)
				left++;
			while (data[right] > pivot)
				right--;
			if (left <= right) {
				int temp = data[left];
				data[left] = data[right];
				data[right] = temp;
				left++;
				right--;
			}
		} 
   
    return pivot
	
}
