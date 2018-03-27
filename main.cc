/*
 * main.cc
 *
 *  Created on: 26-Mar-2018
 *      Author: charan_gotham
 */

#include <string>
#include <fstream>

#include "b+_trees.h"
#include "b+_tree_node.h"
#include "query_processor.h"
#include "query_processor.cc"

using namespace std;

int main(int argc, char* argv[]) {
	cout << argc - 1 << endl;

	for (int i = 1; i < argc; ++i) {
		cout << argv[i] << endl;
	}
	cout << endl;

	int block_size = 5;
	BTree b_tree(block_size);
	ifstream input_file(argv[1]);
	string query;
	while (getline(input_file, query)) {
		cout << query << endl;
		ProcessQuery(b_tree, query);
		cout << endl;
	}
	return 0;
}
