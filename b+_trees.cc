/*
 * b+_trees.cc
 *
 *  Created on: 24-Mar-2018
 *      Author: charan_gotham
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	cout << argc - 1 << endl;
	for (int i = 1; i < argc; ++i) {
		cout << argv[i] << endl;
	}
	ifstream input_file(argv[1]);
	string query;
	while (getline(input_file, query)) {
		cout << query << endl;
	}
	return 0;
}
