//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned yet.
// Description : Create our own tree data structure.
//============================================================================
#include <iostream> // for cin, cout declaration.
using namespace std;// for their definition.
#include "BinarySearchTree.h" // reference to the 'BinaaySearchTree' class.

int main()
{
	// Instantiate an object of our homemade binary tree.
	BinarySearchTree tree1;

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
		cout << "Choose display method...\n\t[1.pre, 2.post, 3.in]: ";
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
		}

		// search for an item in the tree.
		int target;
		cout << "Enter an item to search for: ";
		cin >> target;
		cout << target << " is " << (tree1.searchFor(target) == true ? "Found." : "Not found.") << "\n\n";

		// get the minimum of maximum number in the tree.
		char minMax;
		cout << "Search for the minimum or the maximum value(-, +): ";
		cin >> minMax;

		if(minMax == '-')
			cout << tree1.findMin() << "\n\n";
		else if(minMax == '+')
				cout << tree1.findMax() << "\n\n";
		else
			cout << "Invalid input.\n";

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

	}catch(BinarySearchTree::Exception&)
	{}
	
	// indicates a successful execution.
	return 0;
}
