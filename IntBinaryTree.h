/*
James Stockwell

Programming Assignment Chapter 21

November 2021
*/

/*----------------------------------------------------------------------------------------------------------------
class name:		IntBinaryTree

attributes:		stuct TreeNode { int value, struct TreeNode left, struct TreeNode right}, TreeNode *root
methods:		IntBinaryTree, ~IntBinaryTree,
				deleteNodes, insertNode, insert, displayInOrderRoot, displayInOrder, leafCountRoot, leafCount,
				heightRoot, height, widthRoot, width

A binary tree for the Binary Tree Game.
----------------------------------------------------------------------------------------------------------------*/

#pragma once
class IntBinaryTree {

	private:
		struct TreeNode {		//A node for the binary tree
			int value;			//Integer value of the node
			TreeNode *left;		//Pointer to the next node with less value
			TreeNode *right;	//Pointer to the next node with more value
		};
		TreeNode *root;			//The beginning of the tree

		void deleteNodes(TreeNode *nodePtr);					//Deletes the subtree that begins with the given node
		void insert(TreeNode *&nodePtr, TreeNode *&newNode);	//Traverses the tree and inserts a given node into it
		void displayInOrder(TreeNode *nodePtr) const;			//Displays the subtree that begins with the given node inorder
		int leafCount(TreeNode *nodePtr) const;					//Returns the number of leaf nodes in the subtree beginning with the given node
		int height(TreeNode *nodePtr) const;					//Returns the height of the subtree starting with the given node
		int width(TreeNode *nodePtr, int layer) const;			//Returns the width of the given layer of the tree


	public:
		IntBinaryTree();		//Default constructor
		~IntBinaryTree();		//Defauly deconstructor

		void insertNode(int num);	//Creates a node and passes it to insert
		void displayInOrderRoot();	//Passes the root of the tree to displayInOrder
		int leafCountRoot();		//Passes the root of the tree to leafCount
		int heightRoot();			//Passes the root of the tree to height
		int widthRoot();			//Calls width for every layer of the tree

};

