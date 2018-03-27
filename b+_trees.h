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
	bool Find(int x);
	int Count(int x);
	void Range(int x, int y);
	void Delete(int x);

};

void BTree::Insert(int element_to_insert) {
	return;
}

bool BTree::Find(int elelment_to_find) {
	return true;
}

int BTree::Count(int element_count) {
	cout << "count working" << endl;
	element_count = 0;
	return element_count;
}

void BTree::Range(int start, int end) {
	cout << "range working" << endl;
}

#endif /* B__TREES_H_ */
