#ifndef DATASTRUCTURETWO_H
#define DATASTRUCTURETWO_H
using namespace std;
#include <map>
#include <vector>
#include <string>
#include "dataStructureTwo.h"


void quickSort(vector<string>& vector_id, int low, int high, Person& source_p, map<string, Person>& a_map, int type) {
    if (low < high) {
        int pivot = partition(vector_id, low, high, source_p, a_map, type);
        quickSort(vector_id, low, pivot - 1, source_p, a_map, type);
        quickSort(vector_id, pivot + 1, high, source_p, a_map, type);
    }
}


int partition(vector<string>& vector_id, int low, int high, Person& source_p, map<string, Person>& a_map, int type) {
    string pivot_id = vector_id[low];
    float pivot_value = id_to_value_type(pivot_id, source_p, a_map, type);


    int up = low;
    int down = high;


    while (up < down) {
        while (up < high && id_to_value_type(vector_id[up], source_p, a_map, type) >= pivot_value)
            up++;


        while (id_to_value_type(vector_id[down], source_p, a_map, type) < pivot_value)
            down--;


        if (up < down)
            swap(vector_id[up], vector_id[down]);
    }


    swap(vector_id[low], vector_id[down]);
    return down;
}