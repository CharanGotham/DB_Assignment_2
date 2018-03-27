/*
 * b+_tree_node.h
 *
 *  Created on: 27-Mar-2018
 *      Author: charan_gotham
 */

#ifndef B__TREE_NODE_H_
#define B__TREE_NODE_H_

#include <iostream>
#include <vector>
#include <climits>

#include "b+_trees.h"

using namespace std;

class TreeNode {

	std::vector<int> keys;
	std::vector<TreeNode*> child_pointers;
	int degree; // number of keys can be filled
	int curent_degree; // Number of keys filled == keys.size()
	bool leaf;

public:
	TreeNode(int _degree, bool _leaf) {
		degree = _degree;
		curent_degree = 0;
		leaf = _leaf;
	}
	void SplitNode(TreeNode* parent, TreeNode* child);
	void InsertNonFull(int k);

	friend class BTree;
};

void TreeNode::SplitNode(TreeNode* parent, TreeNode* child) {
	int child_size = child->child_pointers.size();

	TreeNode* left_child = new TreeNode(degree, child->leaf);
	TreeNode* right_child = new TreeNode(degree, child->leaf);

	parent->child_pointers.push_back(left_child);
	parent->child_pointers.push_back(right_child);

	left_child->curent_degree = 0;
	for (int i = 0; i <= (child_size / 2) - 1; ++i) {
		left_child->keys.push_back(child->keys[i]);
		left_child->curent_degree++;
	}

	right_child->curent_degree = 0;
	for (int i = (child_size / 2) - 1; i < child_size; ++i) {
		right_child->keys.push_back(child->keys[i]);
		right_child->curent_degree++;
	}

	if (child->leaf == false) {
		for (int i = 0; i <= (child_size / 2) - 1; ++i)
			left_child->child_pointers.push_back(child->child_pointers[i]);
		for (int i = (child_size / 2) + 1; i < child_size; ++i)
			right_child->child_pointers.push_back(child->child_pointers[i]);
	}
}

void TreeNode::InsertNonFull(int element_to_insert) {
	int i = curent_degree - 1;
	keys.push_back(INT_MIN);
	if (leaf == true) {
		while (i >= 0 && keys[i] > element_to_insert) {
			keys[i + 1] = keys[i];
			i--;
		}
		cout << "element " << element_to_insert << " pushed" << endl;
		keys[i + 1] = element_to_insert;
		curent_degree++;
	} else {
		while (i >= 0 && keys[i] > element_to_insert) i--;
		if (child_pointers[i + 1]->curent_degree == degree) {
			TreeNode* new_child = new TreeNode(degree, false);
			new_child->keys[0] = child_pointers[i + 1]->keys[degree / 2];
			new_child->curent_degree = 1;
			new_child->SplitNode(child_pointers[i + 1], new_child);
			if (element_to_insert <= new_child->keys[0])
				new_child->child_pointers[0]->InsertNonFull(element_to_insert);
			else
				new_child->child_pointers[1]->InsertNonFull(element_to_insert);
			child_pointers[i + 1] = new_child;
		}
	}
}

#endif /* B__TREE_NODE_H_ */
