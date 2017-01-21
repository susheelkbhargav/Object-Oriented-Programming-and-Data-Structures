/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "QuickSorter.h"

/**
 * Default constructor.
 */
QuickSorter::QuickSorter() : VectorSorter() {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
 
 
void QuickSorter::quicksort(const int left, const int right)
{
    /***** Complete this member function. *****/
	
	//source:http://algorithms.tutorialhorizon.com/quick-sort-implementation/
	int mid = (left+right) / 2;
	int low =left, high=right;
		int pivot = data[mid]; // select middle element as pivot
		while (left <= right) {
			while (data[left] < pivot)
				left++;// find element which is greater than pivot
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

		if (low < right)
			quicksort(low, right);
		if (left < high)
			quicksort(left, high);
	
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
int QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const int pivot)
{
    /***** Complete this member function. *****/
    struct node *pivot = end;
    struct node *prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
 
 
//here the sorting happens exclusive of the end node
struct node *quickSortRecur(struct node *head, struct node *end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    node *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    struct node *pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        struct node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(struct node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
}
