//============================================================================
// Name        : BinarySearchTree.cpp
// Date	       : July 13, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned yet.
// Description : Create our own tree data structure.
//============================================================================

#include "BinarySearchTree.h" // reference to the 'BinaaySearchTree' class.
#include <iostream>           // for cin, cout declaration.
using namespace std;          // for the definition of cin, cout.

int main()
{
	// Instantiate an object of our homemade binary tree.
	BinarySearchTree<int> tree1;

	try
	{
		// inserting some items.
		tree1.insert(45);
		tree1.insert(15);
		tree1.insert(79);
		tree1.insert(90);
		
		tree1.insert(10);
		tree1.insert(55);
		tree1.insert(12);
		tree1.insert(20);
		tree1.insert(50);

		// show the data in what manner.
		short ans;
		cout << "Choose the digit.\n[1.pre, 2.post, 3.in]: ";
		cin >> ans;

		// display the data in one of the 3 ways we made.
		switch(ans)
		{
		case 1:
			tree1.displayPreOrder(); break;
		case 2:
			tree1.displayPostOrder(); break;
		case 3:
			tree1.displayInOrder(); break;
		default:
			cout << "Not available.\n";
			exit(1);
		}

		// search for an item in the tree.
		int target;
		cout << "Enter an item to search for: ";
		cin >> target;
		cout << target << " is " << (tree1.searchFor(target) == true ? "Found." : "Not found.") << "\n\n";

		// get the minimum of maximum number in the tree.
		char minMax;
		cout << "Find min/max, hit a sign of(-, +): ";
		cin >> minMax;

		switch(minMax)
		{
		case '-':
			cout << "The minimum item in the tree: ";
			cout << tree1.findMin() << "\n\n";
			break;
		case '+':
			cout << "The maxmum item in the tree: ";
			cout << tree1.findMax() << "\n\n";
			break;
		default:
			cout << "Invalid input.\n";
			exit(1);
		}
		
		// delete a node from the tree.
		int delNode;
		cout << "Enter a node to be deleted: ";
		cin >> delNode;

		tree1.deleteAt(delNode);

		// display in the same way before deleting.
		switch(ans)
		{
		case 1:
			tree1.displayPreOrder(); break;
		case 2:
			tree1.displayPostOrder(); break;
		case 3:
			tree1.displayInOrder(); break;
		default:
			cout << "Not available.\n";
		}

	}catch(const BinarySearchTree<int>::Exception&)
	{}
	
	// indicates a successful execution.
	return 0;
}





