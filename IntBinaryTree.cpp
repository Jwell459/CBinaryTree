/*
James Stockwell

Programming Assignment Chapter 21

November 2021
*/

#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

/*----------------------------------------------------------------------------------------------------------------
class name:		IntBinaryTree

attributes:		stuct TreeNode { int value, struct TreeNode left, struct TreeNode right}, TreeNode *root
methods:		IntBinaryTree, ~IntBinaryTree,
				deleteNodes, insertNode, insert, displayInOrderRoot, displayInOrder, leafCountRoot, leafCount,
				heightRoot, height, widthRoot, width

A binary tree for the Binary Tree Game.
----------------------------------------------------------------------------------------------------------------*/

/************************************************************************************
name:		IntBinaryTree
called by:	main
passed:		none
returns:	none
calls:		none

Default constructor. Initializes root to a nullptr.
************************************************************************************/
IntBinaryTree::IntBinaryTree() {
	root = nullptr;
}

/************************************************************************************
name:		~IntBinaryTree
called by:	main
passed:		none
returns:	none
calls:		deleteNodes

Default deconstructor. Calls deleteNodes and passes it the root of the tree.
************************************************************************************/
IntBinaryTree::~IntBinaryTree() {
	if (root)		//Only deletes nodes if there is root node
		deleteNodes(root);
}

/************************************************************************************
name:		deleteNodes
called by:	~IntBinaryTree
passed:		TreeNode *nodePtr
returns:	none
calls:		none

Using recursive logic, deletes every node in the left subtree of the passed node, then the
right subtree, then deletes the passed node.
************************************************************************************/
void IntBinaryTree::deleteNodes(TreeNode *nodePtr) {
	if (nodePtr->left)			//If there is a left node, call left's deleteNodes method
		deleteNodes(nodePtr->left);
	if (nodePtr->right)			//If there is a right node, call right's deleteNodes method
		deleteNodes(nodePtr->right);
	delete nodePtr;				//Delete the current node
}

/************************************************************************************
name:		insertNode
called by:	main
passed:		int num
returns:	none
calls:		insert

Takes integer input and then creates a tree node to hold it. Then passes it to insert.
************************************************************************************/
void IntBinaryTree::insertNode(int num) {
	TreeNode *newNode = new TreeNode;		//New node to store the num value

	newNode->value = num;		//Initializes value to num
	newNode->left = nullptr;	//Initializes left pointer to nullptr
	newNode->right = nullptr;	//Initializes rihgt pointer to nullptr

	insert(root, newNode);		//Pass the created node to insert
}

/************************************************************************************
name:		insert
called by:	insertNode
passed:		TreeNode *&nodePtr, TreeNode *&newNode
returns:	none
calls:		insert

Takes a tree node and then traverses the list until it finds an appropriate spot to
place it in.
************************************************************************************/
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
	if (!root)			//If there is no root node, the passed node becomes the new node
		root = newNode;
	else {				//Otherwise traverse the tree until it finds a spot to place it in
		if (nodePtr == nullptr)		//If at an empty pointer, place newNode there
			nodePtr = newNode;
		else if (newNode->value < nodePtr->value)	//If the value of newNode is less than that of nodePtr, call insert->left
			insert(nodePtr->left, newNode);
		else										//Otherwise call insert->right
			insert(nodePtr->right, newNode);
	}
}

/************************************************************************************
name:		displayInOrderRoot
called by:	main
passed:		none
returns:	none
calls:		displayInOrder

Calls displayInOrder and passes it the root node of the tree, if there is a root node.
************************************************************************************/
void IntBinaryTree::displayInOrderRoot() {
	if (!root)
		cout << "The tree is empty.\n";
	else {
		cout << "There are the nodes inorder: \n";
		displayInOrder(root);
	}
}

/************************************************************************************
name:		displayInOrder
called by:	displayInOrderRoot, displayInOrder
passed:		TreeNode *nodePtr
returns:	none
calls:		displayInOrder

Using recursive logic, displays the nodes of the tree inorder.
************************************************************************************/
void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
	if (nodePtr != nullptr) {
		displayInOrder(nodePtr->left);	//Display all the nodes left of the current node
		cout << nodePtr->value << ' ';	//Display current node
		displayInOrder(nodePtr->right);	//Display all the nodes right of the current node
	}
}

/************************************************************************************
name:		leafCountRoot
called by:	main
passed:		none
returns:	int
calls:		leafCount

Calls leafCount and passes it the root of the tree.
************************************************************************************/
int IntBinaryTree::leafCountRoot() {
	if (!root)	//If there is no root, return 0
		return 0;
	else		//Otherwise return leafCount and pass it root
		return leafCount(root);
}

/************************************************************************************
name:		leafCount
called by:	leafCountRoot
passed:		TreeNode *nodePtr
returns:	int
calls:		leafCount

Using recursive logic, finds and returns the total number of leaf nodes in the tree.
************************************************************************************/
int IntBinaryTree::leafCount(TreeNode *nodePtr) const {

	if (nodePtr != nullptr) {
		if (nodePtr->left == nullptr && nodePtr->right == nullptr)		//If at a leaf node, return 1
			return 1;
		else if (nodePtr->left != nullptr && nodePtr->right != nullptr)		//If at a internal node with both a left and right node, return left->leafCount + right->leafCount
			return leafCount(nodePtr->left) + leafCount(nodePtr->right);
		else if (nodePtr->left != nullptr)									//If at a internal node with only a left node, return left->leafCount
			return leafCount(nodePtr->left);
		else if (nodePtr->right != nullptr)									//If at a internal node with only a right node, return right->leafCount				
			return leafCount(nodePtr->right);
	}
	return 0;
}

/************************************************************************************
name:		heightRoot
called by:	main
passed:		none
returns:	int
calls:		height

Calls height and passes it the root of the tree.
************************************************************************************/
int IntBinaryTree::heightRoot() {
	if (!root)		//If there is no root, return 0
		return 0;
	else			//Otheriwse call height, pass it root, and subtract 1 from its return value
		return height(root) -1 ;
}

/************************************************************************************
name:		height
called by:	heightRoot, width
passed:		TreeNode *nodePtr
returns:	int
calls:		heightRoot, height

Using recursive logic, finds and returns the height of the tree.
************************************************************************************/
int IntBinaryTree::height(TreeNode *nodePtr) const {

	if (nodePtr == nullptr)												//If an nullptr, return 0
		return 0;
	else if (nodePtr->left == nullptr && nodePtr->right == nullptr)		//If at a leaf node, return 1
		return 1;
	else {																//Otherwise return either the height of the leftsubstree + 1 or right substree + 1, whichever is greater
		int leftHeight = height(nodePtr->left);
		int rightHeight = height(nodePtr->right);
		if (leftHeight > rightHeight)
			return 1 + leftHeight;
		else
			return 1 + rightHeight;

	}

}

/************************************************************************************
name:		widthRoot
called by:	main
passed:		none
returns:	int
calls:		width

Calls width for every layer of the tree, then returns the width of the widest layer.
************************************************************************************/
int IntBinaryTree::widthRoot() {
	int maxWidth = 0;	//Stores the width of the widest layer
	int widthCurrent;	//Stores width of called layer
	for (int i = 0; i < height(root); i++) {		//call width for every layer in the tree
		widthCurrent = width(root, i);
		if (widthCurrent > maxWidth)				//If the width of the called layer is greater than the current maxWidth value, replace it
			maxWidth = widthCurrent;
	}

	return maxWidth;
}

/************************************************************************************
name:		width
called by:	widthRoot
passed:		TreeNode *nodePtr, int layer
returns:	int
calls:		width

Using recursive logic, finds and returns the width of the given layer in the tree.
************************************************************************************/
int IntBinaryTree::width(TreeNode *nodePtr, int layer) const {

	if (nodePtr == nullptr)		//If a nullptr is reached, return 0
		return 0;
	else if (layer == 0 && nodePtr != nullptr)	//If a node of the desired layer is reached, return 1
		return 1;
	else					//Otherwise, return the sum of the width calls for the left and right nodes on the next layer
		return width(nodePtr->left, layer - 1) + width(nodePtr->right, layer - 1);
}