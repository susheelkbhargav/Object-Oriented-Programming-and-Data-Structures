/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include <string>
#include "MergeSort.h"

/**
 * Default constructor.
 */
MergeSort::MergeSort() : ListSorter() {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string MergeSort::name() const { return "Mergesort"; }

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{
	//source::http://algorithms.tutorialhorizon.com/merge-or-combine-two-sorted-linked-lists//

    /***** Complete this member function. *****/
	Node head1 = list;
		int mid = getLength(a) / 2;
		if (list.next == null)
			return list;
		while (mid - 1 > 0) {
			head1 = head1.next;
			mid--;
		}
		Node head2 = head1.next;
		head1.next = null;
		head1 = a;
		Node t1 = mergesort(head1);
		Node t2 = mergesort(head2);
		return merge(LinkedList& list,
                      LinkedList& t1, LinkedList& t2)

	}


/**
 * Merge two sublists back into sublist1 single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
    /***** Complete this member function. *****/
	if(sublist1==NULL)
	{
		list=sublist2;
		return list;
	}
	if(sublist2==NULL)
	{
		list=sublist1;
		return list;
	}
	if(sublist1.data>sublist2.data)
	{
		result = sublist2;
			result.next = merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2.next);
	}
	else
	{
		result = a;
			result.next = merge(LinkedList& list,
                      LinkedList& sublist1.next, LinkedList& sublist2);
	}
	return result;
}
/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }
