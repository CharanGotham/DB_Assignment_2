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
		this->root->keys.push_back(element_to_insert);
		this->root->current_degree = 1;
	} else {
		if (root->current_degree == degree) {
			TreeNode* new_root = new TreeNode(degree, false);
			new_root->child_pointers.push_back(root);
			new_root->SplitChildNode(0, root);
			new_root->Traverse();
			cout << endl;

			int i = 0;
			if (new_root->keys[i] < element_to_insert) i++;
			new_root->child_pointers[i]->InsertNonFull(element_to_insert);

			root = new_root;
		} else {
			root->InsertNonFull(element_to_insert);
		}
	}
}

void TreeNode::SplitChildNode(int split_position, TreeNode* child) {
	int child_size = child_pointers[split_position]->current_degree;
	TreeNode* new_child_node = new TreeNode(child->degree, child->leaf);
	new_child_node->current_degree = 0;
	for (int i = (child_size / 2) + 1; i < child_size; ++i) {
		new_child_node->keys.push_back(child->keys[i]);
		child->keys.pop_back();
		child->current_degree--;
		new_child_node->current_degree++;
	}
	if (!child->leaf) {
		for (int i = 0; i <= child_size / 2; ++i) {
			new_child_node->
			child_pointers.push_back(child->
					child_pointers[i + (child_size / 2)]);
			child->child_pointers.pop_back();
		}
	}
	child_pointers.push_back(NULL);
	for (int i = current_degree; i >= split_position + 1; i--){
		child_pointers[i + 1] = child_pointers[i];
	}
	child_pointers[split_position + 1] = new_child_node;
	keys.push_back(INT_MIN);
	for (int i = current_degree - 1; i >= split_position; i--)
		keys[i + 1] = keys[i];
	keys[split_position] = child->keys[child_size / 2];
	child->keys.pop_back();
	child->current_degree--;
	current_degree++;

}

void TreeNode::InsertNonFull(int element_to_insert) {
	int i = current_degree - 1;
	if (leaf == true) {
		keys.push_back(INT_MIN);
		while (i >= 0 && keys[i] > element_to_insert) {
			keys[i + 1] = keys[i];
			i--;
		}
		keys[i + 1] = element_to_insert;
		current_degree++;
	} else {
		while (i >= 0 && keys[i] > element_to_insert) i--;
		if (child_pointers[i + 1]->current_degree == degree) {
			SplitChildNode(i + 1, child_pointers[i + 1]);
			if (keys[i + 1] < element_to_insert) i++;
		}
		child_pointers[i + 1]->InsertNonFull(element_to_insert);
	}
}

bool TreeNode::Find(int element_to_find) {
	int i = current_degree - 1;
	while (i >= 0 && keys[i] >= element_to_find) i--;
	if (keys[i + 1] == element_to_find) return true;
	if (leaf) return false;
	return false || child_pointers[i + 1]->Find(element_to_find);
}

int TreeNode::Count(int count_element) {
	int element_count = 0;
	int i = current_degree - 1;
	while (i >=0 && keys[i] > count_element) i--;
	while (i >= 0 && keys[i] == count_element) {
		element_count++;
		if (!leaf) element_count += child_pointers[i + 1]->Count(count_element);
		i--;
	}
	if (!leaf) element_count += child_pointers[i + 1]->Count(count_element);
	return element_count;
}

// future : update Range function.
void TreeNode::Range(int start, int end) {
	int i;
	for (i = 0; i < keys.size(); ++i) {
		if (IsInRange(keys[i], start, end)) {
			if (!leaf) child_pointers[i]->Range(start, end);
			cout << keys[i] << endl;
		}
	}
	if (!leaf) child_pointers[i]->Range(start, end);
}

bool IsInRange(int x, int start, int end) {
	return (x >= start && x <= end) ? true : false;
}


