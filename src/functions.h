#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <map>
#include <vector>
#include <string>
#include "person.h"
#pragma once
using namespace std;

//Look up object
Person lookup_id_get_obj(string id, map<string,Person>& a_map);

float id_to_value_physical(string& id, Person& p_source,  map<string,Person>& a_map);

float id_to_value_personality(string& id, Person& p_source,  map<string,Person>& a_map);

float id_to_value_type(string& id, Person& p_source,  map<string,Person>& a_map,int type);

#endif 
