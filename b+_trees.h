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
	int current_degree; // Number of keys filled == keys.size()
	bool leaf;

public:
	TreeNode(int _degree, bool _leaf);
	void Traverse();

	void SplitChildNode(int split_position, TreeNode* child);
	void InsertNonFull(int k);
	bool Find(int x);
	int Count(int x);
	void Range(int x, int y);

	friend class BTree;
};


class BTree {

	TreeNode* root;
	int degree; // number of keys can be filled

public:
	BTree(int _degree) {
		this->root = NULL;
		this->degree = _degree;
	}

	void PrintPrivateVariables() {
		if (this->root == NULL) cout << "root is NULL" << endl;
		else cout << "root is filled" << endl;
		cout << "degree = " << degree << endl;
	}

	TreeNode* AccessRoot() { return root; }

	int AccessDegree() { return degree; }

	void Traverse() { if (root != NULL) root->Traverse(); }

	void Insert(int x);
	void Delete(int x);
};

bool IsInRange(int x, int start, int end);


#endif /* B__TREES_H_ */
