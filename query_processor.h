/*
 * query_processor.h
 *
 *  Created on: 26-Mar-2018
 *      Author: charan_gotham
 */

#ifndef QUERY_PROCESSOR_H_
#define QUERY_PROCESSOR_H_

#include <iostream>

#include "b+_trees.h"

using namespace std;

void ProcessQuery(BTree *b_tree, string query);

int GetNumber(string query);

void GetRange(vector<int> &range, string query);

#endif /* QUERY_PROCESSOR_H_ */
