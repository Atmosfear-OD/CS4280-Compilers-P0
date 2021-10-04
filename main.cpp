/*
 * main.cpp by Pascal Odijk 2/5/2021
 * P0 CS4280 Professor Hauschild
 *
 * This file contains the main function for P0. The project starts by taking input in three different ways: file specification, redirection, or through keyboard input followed by ctrl+d (simulated EOF). 
 * If the user starts the program with ./P0, this will trigger the keyboard input form, ./P0 < fileName.ext will trigger redirection, and ./P0 fileName will trigger file input. If more than one argument
 * is encountered, the program will output an error message. This function will then call the function to build the Binary Search Tree (BST) found within tree.cpp and then call the functions to traverse the BST
 * in three ways: inorder, postorder, and preorder. These traversals will then be printed to an output file.
 * Note: If the program is initiated with ./P0 or ./P0 < fileName.ext, the output files will be named output.preorder, output.inorder, and output.postorder
 * 	 If the program is initiated with ./P0 fileName, the output files will be named fileName.preorder, fileName.inorder, and fileName.postorder
 */

#include <iostream>
#include <fstream>
#include "tree.h"

using namespace std;

int main(int argc, char *argv[]) {
	string fileName;
	string outPreord, outInord, outPostord;
	ofstream printPreord, printInord, printPostord; 
	
	if(argc == 1){ // Handles program initialization of ./P0 (keyboard) or ./P0 < fileName.ext (redirection)
		try {
		string userInput;
		ofstream tempFile;

		fileName = "temp.sp2021";
		outPreord = "output.preorder";
		outInord = "output.inorder";
		outPostord = "output.postorder";
		tempFile.open(fileName.c_str());

		//cout << "Enter character strings and press ctrl+d when finished.\n";
		while(cin >> userInput){
			tempFile << userInput << " ";
		}

		tempFile.close();
		} catch(const ifstream::failure& e){
			cout << "Error file not found\n";
			return 1;
		}
	} else if(argc == 2){ // Handles program initialization of ./P0 fileName (read from file)	
		fileName = argv[1];
		outPreord = fileName;
		outPreord.append(".preorder");
		outInord = fileName;
		outInord.append(".inorder");
		outPostord = fileName;
		outPostord.append(".postorder");
		fileName.append(".sp2021");
	} else if(argc > 2){ // Error if more than one argument is entered
		cout << "ERROR: Too many arguments\n";
		cout << "USAGE: ./P0 [keyboard input], or ./P0 fileName, or ./P0 < fileName.ext\n";
		return 1;
	}
	
	// Call function to build tree with input from file/keyboard, will output message if error building tree
	treeNode *root = buildTree(fileName);
		
	if(root == NULL){
		cout << "Error building tree\n";
		return 1;
	}
	
	cout << "\nNow printing to file in preorder...\n";
	printPreord.open(outPreord.c_str());
	printPreorder(root, printPreord);
	printPreord.close();	

	cout << "Now printing to file in inorder...\n";
	printInord.open(outInord.c_str());
	printInorder(root, printInord);
	printInord.close();

	cout << "Now printing to file in postorder...\n";
	printPostord.open(outPostord.c_str());
	printPostorder(root, printPostord);

	cout << "Traversals finished, now closing file and terminating\n";
	printPostord.close();

	return 0;
}
