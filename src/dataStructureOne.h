#ifndef DATASTRUCTUREONE_H
#define DATASTRUCTUREONE_H
using namespace std;
#include <map>
#include <vector>
#include <string>
#include "person.h"
#pragma once

//#include "main.cpp"


void heapify(vector<string>& vector_id, Person& p_source, int n, int i , map<string,Person>& a_map, int type);

void heapSort(vector<string>& vector_id, Person& source_p, map<string,Person>& a_map, int type);


#endif 