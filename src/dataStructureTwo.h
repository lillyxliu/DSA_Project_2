#ifndef DATASTRUCTURETWO_H
#define DATASTRUCTURETWO_H

using namespace std;
#include <map>
#include <vector>
#include <string>
#include "person.h"
#pragma once

void quick_sort(vector<string>& vector_id, int low, int high, Person& source_p, map<string, Person>& a_map, int type);
int partition(vector<string>& vector_id, int low, int high, Person& source_p, map<string, Person>& a_map, int type);

#endif 