/*
 * node.h by Pascal Odijk 2/5/2021
 * P0 CS4280 Professor Hauschild
 *
 * This file contains the structure for the tree nodes.
 */

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

using namespace std;

struct treeNode {
	string key;
	string cKey;
	int level;
	vector<string> strings;
	treeNode *head;
	treeNode *left;
	treeNode *right;
};

#endif
