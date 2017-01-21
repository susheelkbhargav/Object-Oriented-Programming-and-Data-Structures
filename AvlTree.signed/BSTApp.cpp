/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */
#include <iostream>
#include <vector>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <chrono>

#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "BinaryTreeChecker.h"
#include "BinaryTreePrinter.h"


using namespace std;
using namespace std::chrono;

const bool DUMP = false;

void testBST();
void testAVL();

void makeTree(BinarySearchTree<int>& tree,
              BinaryTreeChecker<int>& checker,
              BinaryTreePrinter<int>& printer,
              string kind);

void testTree(BinarySearchTree<int>& tree,
              BinaryTreeChecker<int>& checker,
              BinaryTreePrinter<int>& printer);

/**
 * Main.
 */
 //static  int VALUES[10000];
int main( )
{
	/*;
	for(int i=0;i<10000;i++)
  {
    int n= (rand()%10000)+1;
	VALUES[i]=n;
  
  }*/
    testBST();
    testAVL();
	/**/
    return 0;
  
}

/**
 * Run the test with a binary search tree.
 */
void testBST()
{
    cout << endl;
    cout << "**********************" << endl;
    cout << "* BINARY SEARCH TREE *" << endl;
    cout << "**********************" << endl;

   BinarySearchTree<int>  tree;
   BinaryTreeChecker<int> checker(tree);
   BinaryTreePrinter<int> printer(tree);
   makeTree(tree, checker, printer, "BST");
 //   testTree(tree, checker, printer);
}

/**
 * Run the test with an AVL tree.
 */
void testAVL()
{
    cout << endl;
    cout << "************" << endl;
    cout << "* AVL TREE *" << endl;
    cout << "************" << endl;

    AvlTree<int> tree;
    BinaryTreeChecker<int> checker(tree);
    BinaryTreePrinter<int> printer(tree);
   makeTree(tree, checker, printer, "AVL");
    //testTree(tree, checker, printer);
}

/*static const int VALUES[] = {
    62,71,29,88,11,41,21,66,57,27,39,40,77,20,51,49,82,37,
    94,63,76,91,70,64,60,90,12,80,23,10,52,35,96,75,28
};*/

/**
 * Make a binary search tree containing unique random integer data items.
 * @param tree the tree to make.
 * @param maxNodes the maximum number of nodes to generate.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 * @param insertPrint true iff print a message after each node insertion
 */
void makeTree(BinarySearchTree<int>& tree,
              BinaryTreeChecker<int>& checker,
              BinaryTreePrinter<int>& printer,
              string kind)
{
    steady_clock::time_point start_time = steady_clock::now();

    srand(time(NULL));
    int iterations=10000;
	int j,i;
while(iterations <=100000)
{
for(i=0;i<iterations;i++ )
{
  j= (rand()%iterations)+1;
 i++;
}
 steady_clock::time_point end_time = steady_clock::now();
    long elapsed = duration_cast<microseconds>(end_time - start_time).count();
    cout << endl << "Done! Total time:for " << iterations<<"iterations"<<elapsed << " microseconds" << endl;
iterations= iterations+10000;


        //cout << endl << "Inserted node " << n << ":" << endl;

        tree.insert(j);  // insert into tree
        //checker.add(n);  // store with the tree checker

        //cout << endl;
        //printer.print();
	}
    

    cout << endl;
    cout << "***" << endl;
    cout << "*** COMPLETED " << kind << " TREE:" << endl;
    cout << "***" << endl << endl;
    //printer.print();
   
   
 steady_clock::time_point starttime = steady_clock::now();
  int count=10000;
   while(count<=100000){
	   for(int j=0;j<count;j++)
		{
        int f=rand()%(count);
		j++;
		bool x=tree.contains(f);
		}
		steady_clock::time_point endtime = steady_clock::now();
    long elap_sed = duration_cast<microseconds>(endtime - starttime).count();
    cout << endl << "Done! Total time: for searching" << count<<"iterations"<<elap_sed << " microseconds" << endl;
		count+=10000;
		  
   }

}

/**
 * Test a binary tree.
 * @param tree the tree to test.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 */
void testTree(BinarySearchTree<int>& tree,
              BinaryTreeChecker<int>& checker,
              BinaryTreePrinter<int>& printer)
{
    int status = BinaryTreeChecker<int>::NO_ERROR;

     //Delete the root node each time through the loop.
     //Print the tree after each deletion.
    while (!tree.isEmpty())
    {
        BinaryNode<int> *root = tree.getRoot();
        int data = root->data;
       cout << endl << "Deleted root node " << data << ":" << endl;

        tree.contains(data);
        checker.remove(data);

        cout << endl;
        printer.print();

        status = checker.check(DUMP);
        if (status != BinaryTreeChecker<int>::NO_ERROR) break;
    }

    // What was the status?
    string msg;
    switch (status)
    {
        case BinaryTreeChecker<int>::NO_ERROR:
        {
            msg = ">>>>> The tree is now empty.";
            break;
        }
        case BinaryTreeChecker<int>::DATA_MISMATCH:
        {
            msg =  ">>>>> Data mismatch.";
            break;
        }
        case BinaryTreeChecker<int>::INSUFFICIENT_DATA:
        {
            msg =  ">>>>> Data missing from tree.";
            break;
        }
        case BinaryTreeChecker<int>::REMAINING_DATA:
        {
            msg =  ">>>>> Data remaining in tree.";
            break;
        }
    }
    cout << msg << endl;
}