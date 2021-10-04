/*
 * tree.h by Pascal Odijk 2/5/2021
 * P0 CS4280 Professor Hauschild
 * 
 * This file contains the function prototypes for the functions located in tree.cpp.
 */

#ifndef TREE_H
#define TREE_H

#include <string>
#include <fstream>
#include <iostream>
#include "node.h"

// Prototypes for buidling tree, inserting nodes, and searching tree
treeNode *buildTree(string fileName);
treeNode *constructor(int level, string key, string s);
void insert(treeNode *node, string key, string s);
int searchTree(treeNode *node, string s);

// Prototypes for traversing tree
void printPreorder(treeNode *root, ofstream& ofile);
void printInorder(treeNode *root, ofstream& ofile);
void printPostorder(treeNode *root, ofstream& ofile);

#endif
