/*
 * b+_trees.h
 *
 *  Created on: 24-Mar-2018
 *      Author: charan_gotham
 */

#ifndef B__TREES_H_
#define B__TREES_H_

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {

	std::vector<int> keys;
	std::vector<TreeNode*> child_pointers;
	int degree; // number of keys can be filled
	int curent_degree; // Number of keys filled == keys.size()

public:
	TreeNode(int val, bool leaf);
	void SplitNode(TreeNode* child);

};

class BTree {

	TreeNode* root;
	int degree; // number of keys can be filled

public:
	BTree(int _degree) {
		root = NULL;
		degree = _degree;
	}

	void Insert(int x);
	void Find(int x);
	int Count(int x);
	int Range(int x, int y);
	void Delete(int x);

};

#endif /* B__TREES_H_ */
