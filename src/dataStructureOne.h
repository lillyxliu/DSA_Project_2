#ifndef DATASTRUCTUREONE_H
#define DATASTRUCTUREONE_H
using namespace std;
#include <map>
#include <vector>
#include <string>
#include "person.h"

//#include "main.cpp"



Person lookup_id_get_obj(string id, map<string,Person>& a_map);
float id_to_value_personality(string& id, Person& p_source,  map<string,Person>& a_map);

void heapify(vector<string>& vector_id, Person& p_source, int n, int i , map<string,Person>& a_map);

void heapSort(vector<string>& vector_id, Person& source_p, map<string,Person>& a_map);


#endif 