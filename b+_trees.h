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

#include "b+_tree_node.h"

using namespace std;


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
	if (root == NULL) {
		root = new TreeNode(degree, true); // new node creation.
		cout << "element " << element_to_insert << " pushed" << endl;
		root->keys.push_back(element_to_insert);
		root->curent_degree = 1;
	} else if (root->curent_degree == degree) {
		TreeNode* new_root = new TreeNode(degree, false);
		new_root->child_pointers.push_back(root);
		new_root->keys[0] = root->keys[degree / 2];
		new_root->curent_degree = 1;
		new_root->SplitNode(new_root, root);
		if (element_to_insert <= new_root->keys[0])
			new_root->child_pointers[0]->InsertNonFull(element_to_insert);
		else
			new_root->child_pointers[1]->InsertNonFull(element_to_insert);
		root = new_root;
	} else {
		root->InsertNonFull(element_to_insert);
	}
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
