#ifndef DATASTRUCTUREONE_H
#define DATASTRUCTUREONE_H
using namespace std;
#include <map>
#include <vector>
#include <string>
#include "dataStructureTwo.h"


void quickSort(vector<string>& vector_id, Person& p_source, int high, int low, map<string,Person>& a_map, int type) {

}


int partition(vector<string>& vector_id, int low, int high ) {
    // select pivot element

    int pivot = vector_id.low;
    int up = low, down =  high;

    while(up < down) {
        for (int j = up ; j < high; j++){
            if(vector_id.up > pivot) {
                break;
            }
            up++;
        }
        for (int j = high; j > low; j--) {
            if(vector_id.down < pivot) {
                break;
            }    
            down --;
        }
        if(up < down) {
            swap(&vector_id.up, &vector_id.down);
        }
        swap(&vector_id.)
    }


}