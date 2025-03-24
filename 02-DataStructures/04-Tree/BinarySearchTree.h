//============================================================================
// Name        : BinarySearchTree.cpp
// Date        : July 11, 2024
// Author      : Alsayed_Ali_Aldkhakhni
// Copyright   : Nothing to be mentioned yet.
// Description : Binary search tree implementation.
//============================================================================
#include <iostream> // for cin, cout declaration.
using namespace std;// for their definition.

template <class T>
class BinarySearchTree // class definition.
{
	class Node     // the basic element of the tree.
	{
	public:
		T data;
		Node* left;
		Node* right;
		Node(T dt, Node* lft = NULL, Node* rgt = NULL) : data(dt), left(lft), right(rgt) {}
	};

private:
	// the tree's head, starting point.
	Node* root;
	
	// insertion functions, both private and public.
	Node*  insert(Node* rootOfTree, T data)
	{
		if(rootOfTree == NULL)           // base case.
			rootOfTree = new Node(data);

		else if(data < rootOfTree->data) // if the position of this node is in the left side.
			rootOfTree->left = insert(rootOfTree->left, data);

		else if(data >= rootOfTree->data) // if the position of this node is in the right side.
			rootOfTree->right = insert(rootOfTree->right, data);

		return rootOfTree;                // the new tree after those changes.
	}
	
	// find the minimum element in the tree.
	Node*  findMin(Node* rootOfTree)
	{
		// base case.
		if(rootOfTree == NULL)
			return NULL;
		// if the tree has only the right side, so the root is the minimum.
		else if(rootOfTree->left == NULL)
			return rootOfTree;
		// if the tree has both sides, so we search in the left since it has the lower values.
		else
			return findMin(rootOfTree->left);
	}

	// find the maximum element in the tree.
	Node*  findMax(Node* rootOfTree)
	{
		// base case.
		if(rootOfTree == NULL)
			return NULL;
		// if the tree has only the left side, so the root is the maximum.
		else if(rootOfTree->right == NULL)
			return rootOfTree;
		// if the tree is full of items in both sides, search in the right.
		else
			return findMax(rootOfTree->right);
	}

	// print the tree in left-right-root order.
	void  displayPostOrder(Node* rootOfTree)
	{
		if(rootOfTree == NULL) return;	    // base case.
		displayPostOrder(rootOfTree->left); // left.
		displayPostOrder(rootOfTree->right);// right.
		cout << rootOfTree->data << ",  ";  // root.
	}
	
       	// print the tree in root-left-right order.
	// complex one.
	void displayPreOrder(Node* rootOfTree)
	{
		if(rootOfTree == NULL) return;     // base case.
		cout << rootOfTree->data << ",  "; // root.
		displayPreOrder(rootOfTree->left); // left.
		displayPreOrder(rootOfTree->right);// right.
	}

	 // print the tree in left-root-right order.
	void displayInOrder(Node* rootOfTree)
	{
		if(rootOfTree == NULL) return;    // base case.
		displayInOrder(rootOfTree->left); // left.
		cout << rootOfTree->data << ",  ";// root.
		displayInOrder(rootOfTree->right);// right.
	}

	// Search.
	Node* searchFor(Node* rootOfTree, T target)
	{
		if(rootOfTree == NULL || rootOfTree->data == target) // base case, and if the target is the root.
			return rootOfTree;
		else if(target < rootOfTree->data)
			return searchFor(rootOfTree->left, target);  // the target is in the left side.
		else
			return searchFor(rootOfTree->right, target); // the target is in the right side.
	
	}

	// remove the nodes totally from the memory since they are scattered.
	void  releaseMemory(Node* rootOfTree)
	{
		if(rootOfTree == NULL) // base case.
			return;
		else
		{
			// display a message to inform.
			//cout << rootOfTree->data << " is destroyed.\n";

			// call the method again for both sides.
			releaseMemory(rootOfTree->left);
			releaseMemory(rootOfTree->right);
		}

		// delete the node from the memory.
		delete rootOfTree;
	}


	// delete a specific node from the tree.
	Node*  deleteAt(Node* rootOfTree, T target)
	{
		// base case.
		if(rootOfTree == NULL)
			return NULL;
		// if the node is in the left side.
		if(target < rootOfTree->data)
			rootOfTree->left =  deleteAt(rootOfTree->left, target);
		// if the node is in the right side.
		else if(target > rootOfTree->data)
			rootOfTree->right =  deleteAt(rootOfTree->right, target);
		// the root of the tree or of the sub-tree.
		else
		{
			// leaf node has a child on its right.
			if(rootOfTree->left == NULL && rootOfTree->right != NULL)
			{
				// overwrite the value of the parent, as if i swapped it.
				rootOfTree->data =  (rootOfTree->right)->data;

				// delete the child.
				delete rootOfTree->right;

				// terminate the parent node.
				rootOfTree->right = NULL;
			}
			// leaf node that has a child on its left.
			else if(rootOfTree->left != NULL && rootOfTree->right == NULL)
			{
				// overwrite the value of the parent, as if i swapped it.
				rootOfTree->data =  rootOfTree->left->data;

				// delete the child.
				delete rootOfTree->left;

				// terminate the parent node.
				rootOfTree->left = NULL;
			}
			// leaf node has no children.
			else if(rootOfTree->left == NULL && rootOfTree->right == NULL)
			{
				delete rootOfTree; // delete.
				rootOfTree = NULL; // terminate the parent's pointer.
			}
			else // it the node has both sides.
			{
				// find the maximum node of the minimums.
				Node* maxOfMins = findMax(rootOfTree->left);

				// overwrite the values.
				rootOfTree->data = maxOfMins->data;

				// delete that node and update the changes in that side of the tree.
				rootOfTree->left =  deleteAt(rootOfTree->left, maxOfMins->data);
			}
		}

		// the tree after the changes.
		return rootOfTree;
	}


public:
	// no-arguments constructor.
	BinarySearchTree() : root(NULL) {}

	class Exception // exception handler class.
	{
	public:
		Exception(const char* msg) { cout << "\n" << msg << "\n"; }
	};

	// check if there are data in the tree or not.
	bool isEmpty() { return root == NULL; }

	// getter and setter of the root.
	Node* getRoot() { return root; }
	void  setRoot(Node* rt) { root = rt; }

	// a simple version of deleteAt() method.
	void deleteAt(T target)
	{
		Node* check = searchFor(getRoot(), target);

		if(check == NULL)
			cout << target << " doesn't exist in the tree.\n\n";
		else
			setRoot(deleteAt(getRoot(), target));
	}

	// simplified version.
	void insert(T data)
	{
		// insert and those changes will be made is the new tree.
		Node* newRoot = insert(getRoot(), data);
		setRoot(newRoot); // overwrite the old tree's pointer with the new one.
	}

	// Pre-Order.
	// user's simplified version.
	void displayPreOrder()
	{
		if(isEmpty())
			throw Exception("Tree's empty.");
		else
		{
			cout << "Pre-Order:  ";
			displayPreOrder(getRoot());
			cout << "\n\n";
		}
	}

	// Post-Order.
	void displayPostOrder()
	{
		if(isEmpty())
			throw Exception("Tree's empty.");
		else
		{
			cout << "Post-Order:   ";
			displayPostOrder(getRoot());
			cout << "\n\n";
		}
	}

	// In-Order.
	void displayInOrder()
	{
		if(isEmpty())
			throw Exception("Tree's empty.");
		else
		{
			cout << "In-Order: ";
			displayInOrder(getRoot());
			cout << "\n\n";
		}
	}

	// user's version.
	bool searchFor(T target)
	{
		return searchFor(getRoot(), target) != NULL;
	}

	// simplified versions.
	T findMin()
	{
		Node* rslt = findMin(getRoot());
		return rslt == NULL ? -1 : rslt->data;
	}

	T findMax()
	{
		Node* rslt = findMax(getRoot());
		return rslt == NULL ? -1 : rslt->data;
	}

	// clear the memory from our unaccessible data to avoid memory leaks.
	~BinarySearchTree() { releaseMemory(getRoot()); }
};




