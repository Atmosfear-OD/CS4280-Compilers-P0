/*
 * tree.cpp by Pascal Odijk 2/5/2021
 * P0 CS4280 Professor Hauschild
 *
 * This file contains the functions to build the Binary Search Tree (BST), insert/create nodes, and search the BST to avoid inserting duplicate stings. A toLower funtion was created to make node key comparisons
 * easier should one key be uppercase and the other be lower case. One the BST has been created, the three traversals are called from main and print the traversals to appropriate output files. 
 * Note: Only strings are considered acceptable input for building the BST, if anything else is encountered, an error message will display
 * 	 Another error message will display should there be some error with the input file
 */

#include <iostream>
#include <fstream>
#include "tree.h"
using namespace std;

treeNode *root = NULL;

// Function to build tree from keyboard, redirection, or file input
// Only strings are accepted, anything else will output tree building error
treeNode *buildTree(string fileName){
	string key;
	string input;
	ifstream file(fileName.c_str());

	if(file.is_open()){
		while(file >> input) {
			for(int i = 0 ; i < input.size() ; i++){
				if(!isalpha(input.at((unsigned int)i))){
					cout << "ERROR: Invalid character -- " << input.at((unsigned int)i) << "\n";
					return NULL;
				}
			}

			key = input.substr(0, 2);
			insert(root, key, input);
		}

		file.close();
	} else { // Error if file is not found
		cout << "ERROR: " << fileName << " not found, please try again\n";
		return NULL;
	}
	
	return root;
}

// Function to build new tree node
treeNode *constructor(int level, string key, string s){
	treeNode *node = new treeNode;

	node->left = NULL;
	node->right = NULL;
	node->head = NULL;

	node->key = key;
	node->cKey = key; 
	
	node->strings.push_back(s);
	node->level = level;
	return node;
}

// Function to convert node keys to lower case
string toLower(string key){
	for(int i = 0 ; i < key.length() ; i++){
		if(key[i] >= 'A' && key[i] <= 'Z'){
			key[i] = key[i] + 32;
		}
	}

	return key;
}

// Function to insert new nodes or strings into existing nodes into the BST
void insert(treeNode *node, string key, string s){
	string keyCopy = key;
	for(int i = 0 ; i < keyCopy.length() ; i++){
		if(keyCopy[i] >= 'A' && keyCopy[i] <= 'Z'){
			keyCopy[i] = keyCopy[i] + 32;
		}
	}

	if(root == NULL){
		root = constructor(0, key, s);
		root->head = root;
	} else if(keyCopy < toLower(node->cKey)){
		if(node->left == NULL){
			node->left = constructor((node->level+1), key, s);
			node->left->head = node;
		} else if(keyCopy == toLower(node->left->cKey)) {
			if(searchTree(node->left, s) != 0){
				node->left->strings.push_back(s);
			}
		} else{
			insert(node->left, key, s);
		}
	
	} else if(keyCopy == toLower(node->cKey)){
		if(searchTree(node, s) != 0){
			node->strings.push_back(s);
		}
	} else if(keyCopy > toLower(node->cKey)) {
		if(node->right == NULL){
			node->right = constructor((node->level+1), key, s);
			node->right->head = node;
		} else if(keyCopy == toLower(node->right->cKey)){
			if(searchTree(node->right, s) != 0){
				node->right->strings.push_back(s);
			}
		} else {
			insert(node->right, key, s);
		}
	}
} 

// Function to search node strings within BST to avoid duplicates
int searchTree(treeNode *node, string s){
	if(node->strings.size() > 0){
		for(int i = 0 ; i < node->strings.size() ; i++){
			if(node->strings[i].compare(s) == 0){
				 return 0; 
			} 
		}
	}

	return 1;			
}

// Funtion to print BST preorder traversal to output file
void printPreorder(treeNode *root, ofstream& ofile){
	if(root != NULL){
		for(int i = 0 ; i < root->level ; i++){ ofile << "\t"; }

		for(int i = 0 ; i < (int)root->strings.size() ; i++){
			ofile << root->strings[i] << " ";
		}

		ofile << "\n";

		printPreorder(root->left, ofile);
		printPreorder(root->right, ofile);
	}
}

// Function to print BST inorder traversal to output file
void printInorder(treeNode *root, ofstream& ofile){
	if(root != NULL){
		printInorder(root->left, ofile);

		for(int i = 0 ; i < root->level ; i++){ ofile << "\t"; }

		for(int i = 0 ; i < (int)root->strings.size() ; i++){
			ofile << root->strings[i] << " ";
		}
		
		ofile << "\n";

		printInorder(root->right, ofile);
	}
}

// Function to print BST postorder traversal to output file
void printPostorder(treeNode *root, ofstream& ofile){
	if(root != NULL){
		printPostorder(root->left, ofile);
		printPostorder(root->right, ofile);

		for(int i = 0 ; i < root->level ; i++){ ofile << "\t"; }

		for(int i = 0 ; i < (int)root->strings.size() ; i++){
			ofile << root->strings[i] << " ";
		}

		ofile << "\n";
	}
}
