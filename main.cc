/*
 * main.cc
 *
 *  Created on: 26-Mar-2018
 *      Author: charan_gotham
 */

#include <string>
#include <fstream>

#include "b+_trees.h"
#include "query_processor.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << argc - 1 << endl;

	for (int i = 1; i < argc; ++i) {
		cout << argv[i] << endl;
	}
	cout << endl;

	int block_size;
	cout << "block size = ";
	cin >> block_size;
	cout << endl;
	BTree *b_tree = new BTree(block_size);
	ifstream input_file(argv[1]);
	string query;
	while (getline(input_file, query)) {
		cout << query << endl;
		ProcessQuery(b_tree, query);
//		cout << endl;
		(b_tree->AccessRoot())->Traverse();
		cout << endl;
		cout << endl;
	}
	(b_tree->AccessRoot())->Traverse();
	cout << endl;
	return 0;
}
