/*
James Stockwell

Programming Assignment Chapter 21

November 2021
*/

#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

//Function Prototypes
void menu(IntBinaryTree *tree);
void callInsert(IntBinaryTree *tree);
void callDisplay(IntBinaryTree *tree);
void callLeafCount(IntBinaryTree *tree);
void callHeight(IntBinaryTree *tree);
void callWidth(IntBinaryTree *tree);
void exit(IntBinaryTree *tree);

/************************************************************************************
name:		main
called by:	none
passed:		none
returns:	none
calls:		tree->IntBinaryTree, menu

Starts the program. Initializes a pointer to an empty binary tree that is used for
the rest of the program and then passes it to menu.
************************************************************************************/
int main() {
	IntBinaryTree *tree = new IntBinaryTree;	//Binary tree to be manipulated for the rest of the program
	cout << "Welcome to the Binary Tree Game!\n";
	menu(tree);
};

/************************************************************************************
name:		menu
called by:	main, callInsert, callDisplay, callLeafCount, callHeight, callWidth
passed:		IntBinaryTree *tree
returns:	none
calls:		callInsert, callDisplay, callLeafCount, callHeight, callWidth, exit

Displays a choice menu for the user and asks the user to choose one of them. The user input
then goes into a switch statment to call the appropriate function.
************************************************************************************/
void menu(IntBinaryTree *tree) {
	int choice;		//Stores user's choice


	cout << "1. Insert an integer into the tree\n" <<	//Displayed choice menu
		"2. Display the tree\n" <<
		"3. Display Leaf Count\n" <<
		"4. Display Tree Height\n" <<
		"5. Display Tree Width\n" <<
		"6. Exit\n";

	cout << "Please choose a menu option: ";	//Asks for user input
	while (!(cin >> choice) || (choice < 1) || (choice > 6)) { //Validates that the input is an integer is from 1 to 6
		cout << "Invalid input, please try again: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	switch (choice) {			//Switch statment that calls a function based on user's choice
	case 1:
		callInsert(tree);
		break;
	case 2:
		callDisplay(tree);
		break;
	case 3:
		callLeafCount(tree);
		break;
	case 4:
		callHeight(tree);
		break;
	case 5:
		callWidth(tree);
		break;
	case 6:
		exit(tree);
		break;
	default:
		break;
	}

}

/************************************************************************************
name:		callInsert
called by:	none
passed:		IntBinaryTree *tree
returns:	none
calls:		tree->insertNode, menu

Choice 1
Asks the user to input an integer, validates the input, and passes the input to tree's
insertNode method to insert it into the binary tree. Then calls menu.
************************************************************************************/
void callInsert(IntBinaryTree *tree) {
	int input;	//Stores user input
	cout << "Please enter an integer: ";	//Asks for user input
	while (!(cin >> input)) { //Validates input
		cout << "Invalid input, please try again: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	tree->insertNode(input);	//Passes input to tree's insertNode method
	cout << endl;
	menu(tree);
}

/************************************************************************************
name:		callDisplay
called by:	none
passed:		IntBinaryTree *tree
returns:	none
calls:		tree->displayInOrderRoot, menu

Choice 2
Calls tree's displayInOrderRoot method to display all the integers in the binary
tree. Then calls menu.
************************************************************************************/
void callDisplay(IntBinaryTree *tree) {
	tree->displayInOrderRoot();	//Calls tree's displayInOrder method
	cout << endl << endl;
	menu(tree);
}

/************************************************************************************
name:		callLeafCount
called by:	none
passed:		IntBinaryTree *tree
returns:	none
calls:		tree->leafCountRoot, menu

Choice 3
Call's tree's leafCountRoot method and displays the number of leaf nodes the tree has.
Then calls menu.
************************************************************************************/
void callLeafCount(IntBinaryTree *tree) {
	cout << "The tree has " << tree->leafCountRoot() << " leaves\n";	//Displays tree's leaf count
	cout << endl;
	menu(tree);
}

/************************************************************************************
name:		callHeight
called by:	none
passed:		IntBinaryTree *tree
returns:	none
calls:		tree->heightRoot, menu

Choice 4
Call's tree's heightRoot method and displays the height of the tree. Then calls menu.
************************************************************************************/
void callHeight(IntBinaryTree *tree) {
	cout << "The tree is " << tree->heightRoot() << " levels tall\n";	//Displays tree's height
	cout << endl;
	menu(tree);
}

/************************************************************************************
name:		callWidth
called by:	none
passed:		IntBinaryTree *tree
returns:	none
calls:		tree->widthRoot, menu

Choice 5
Call's tree's widthRoot method and displays the width of the tree. Then calls menu.
************************************************************************************/
void callWidth(IntBinaryTree *tree) {
	cout << "The tree is " << tree->widthRoot() << " nodes wide\n";		//Displays tree's max width
	cout << endl;
	menu(tree);
}

/************************************************************************************
name:		exit
called by:	none
passed:		IntBinaryTree *tree
returns:	none
calls:		tree->~IntBinaryTree

Choice 6
Call's tree's deconstructor, dispays a goodbye message, then ends the program.
************************************************************************************/
void exit(IntBinaryTree *tree) {
	tree->~IntBinaryTree();		//Call's tree's deconstuctor
	cout << "Thanks for playing!";

}