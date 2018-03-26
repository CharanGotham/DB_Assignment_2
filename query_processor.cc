/*
 * query_processor.cc
 *
 *  Created on: 26-Mar-2018
 *      Author: charan_gotham
 */

#include <iostream>
#include <string>

#include "query_processor.h"
#include "b+_trees.h"
//#include "b+_trees.cc"

using namespace std;

void ProcessQuery(BTree b_tree, string query) {
	if (query[0] == 'I') {
		query.erase(query.begin(), query.begin() + 7);
		cout << query << endl;
		int element_to_insert = GetNumber(query);
//		b_tree.Insert(element_to_insert);
	} else if (query[0] == 'F') {
		query.erase(query.begin(), query.begin() + 5);
		cout << query << endl;
		int element_to_find = GetNumber(query);
//		b_tree.Find(element_to_find);
	} else if (query[0] == 'C') {
		query.erase(query.begin(), query.begin() + 6);
		cout << query << endl;
		int element_count = GetNumber(query);
//		b_tree.Count(element_count);
	} else if (query[0] == 'R') {
		query.erase(query.begin(), query.begin() + 6);
		cout << query << endl;
		vector<int> range;
		GetRange(range, query);
//		b_tree.Range(range[0], range[1]);
	}
}

int GetNumber(string query) {
	int number = 0;
	for (int i = 0; i < query.length(); ++i) {
		if (int(query[i]) > 47 && int(query[i]) <= 57) {
			number = (number * 10) + (query[i] - '0');
		}
	}
	return number;
}

void GetRange(vector<int> &range, string query) {
	int flag = 0, number = 0;
	for (int i = 0; i < query.length(); ++i) {
		if (int(query[i]) > 47 && int(query[i]) <= 57) {
			number = (number * 10) + (query[i] - '0');
		} else if (flag == 0) {
			range.push_back(number);
			number = 0;
			flag = 1;
		}
	}
	range.push_back(number);
}

