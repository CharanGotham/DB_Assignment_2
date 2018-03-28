/*
 * b+_trees.cc
 *
 *  Created on: 27-Mar-2018
 *      Author: charan_gotham
 */

#include <bits/stdc++.h>

#include "b+_trees.h"

using namespace std;

TreeNode::TreeNode(int _degree, bool _leaf){
	this->degree = _degree;
	this->current_degree = 0;
	this->leaf = _leaf;
}

void TreeNode::Traverse() {
	if (current_degree == 0) cout << "current node is empty" << endl;
	else {
		for (int i = 0; i < current_degree; ++i) {
			if (!leaf) child_pointers[i]->Traverse();
			cout << keys[i] << " ";
		}
		if (!leaf) child_pointers[current_degree]->Traverse();
	}
}

void BTree::Insert(int element_to_insert) {
	if (root == NULL) {
		this->root = new TreeNode(degree, true); // new node creation.
		cout << "element " << element_to_insert << " pushed" << endl;
		this->root->keys.push_back(element_to_insert);
		this->root->current_degree = 1;
	} else if (root->current_degree == degree) {
		TreeNode* new_root = new TreeNode(degree, false);
		new_root->keys.push_back(root->keys[degree / 2]);
		new_root->current_degree = 1;
		new_root->SplitNode(new_root, root);

		if (element_to_insert <= new_root->keys[0])
			new_root->child_pointers[0]->InsertNonFull(element_to_insert);
		else
			new_root->child_pointers[1]->InsertNonFull(element_to_insert);
		this->root = new_root;
	} else {
		root->InsertNonFull(element_to_insert);
	}
}

void TreeNode::SplitNode(TreeNode* parent, TreeNode* child) {
	int child_size = child->current_degree;

	TreeNode* left_child = new TreeNode(degree, child->leaf);
	TreeNode* right_child = new TreeNode(degree, child->leaf);

	parent->child_pointers.push_back(left_child);
	parent->child_pointers.push_back(right_child);

	left_child->current_degree = 0;
	for (int i = 0; i <= (child_size / 2) - 1; ++i) {
		left_child->keys.push_back(child->keys[i]);
		left_child->current_degree++;
	}

	right_child->current_degree = 0;
	for (int i = (child_size / 2) + 1; i < child_size; ++i) {
		right_child->keys.push_back(child->keys[i]);
		right_child->current_degree++;
	}

	if (child->leaf == false) {
		for (int i = 0; i <= (child_size / 2) - 1; ++i)
			left_child->child_pointers.push_back(child->child_pointers[i]);
		for (int i = (child_size / 2) + 1; i < child_size; ++i)
			right_child->child_pointers.push_back(child->child_pointers[i]);
	}
}

void TreeNode::InsertNonFull(int element_to_insert) {
	int i = current_degree - 1;
	this->keys.push_back(INT_MIN);

	if (leaf == true) {
		while (i >= 0 && keys[i] > element_to_insert) {
			keys[i + 1] = keys[i];
			i--;
		}
		cout << "element " << element_to_insert << " pushed" << endl;
		keys[i + 1] = element_to_insert;
		current_degree++;
	} else {
		while (i >= 0 && keys[i] > element_to_insert) i--;
		if (child_pointers[i + 1]->current_degree == degree) {
			TreeNode* new_child = new TreeNode(degree, false);
			new_child->keys[0] = child_pointers[i + 1]->keys[degree / 2];
			new_child->current_degree = 1;
			new_child->SplitNode(child_pointers[i + 1], new_child);
			if (element_to_insert <= new_child->keys[0])
				new_child->child_pointers[0]->InsertNonFull(element_to_insert);
			else
				new_child->child_pointers[1]->InsertNonFull(element_to_insert);
			child_pointers[i + 1] = new_child;
		} else {
			child_pointers[i + 1]->InsertNonFull(element_to_insert);
		}
	}
}

bool TreeNode::Find(int element_to_find) {
	int i = current_degree - 1;
	while (i >= 0 && keys[i] >= element_to_find) i--;
	if (keys[i + 1] == element_to_find) return true;
	if (leaf) return false;
	return false || child_pointers[i + 1]->Find(element_to_find);
}

int BTree::Count(int element_count) {
	cout << "count working" << endl;
	element_count = 0;
	return element_count;
}

void BTree::Range(int start, int end) {
	cout << "range working" << endl;
}
