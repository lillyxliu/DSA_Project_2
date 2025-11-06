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




// Generic heapify function
template <typename T>
void heapify_generic(vector<T>& vector_gen, int n, int i, bool ascending){
    // Initialize extreme as root
    int extreme = i;
    // left index = 2*i + 1
    int l = 2 * i + 1;
    // right index = 2*i + 2
    int r = 2 * i + 2;

    if(ascending){ // for max heap
        if (l <n && vector_gen[l].second > vector_gen[extreme].second){
            extreme = l;
        } if (r < n && vector_gen[r].second > vector_gen[extreme].second){
            extreme = r;
        }
    }else{ // for min heap
        if(l<n && vector_gen[l].second < vector_gen[extreme].second){
            extreme = l;
        } if(r<n &&  vector_gen[r].second < vector_gen[extreme].second){
            extreme = r;    
        }
    }
    

    // If largest is not root
    if (extreme != i) {
        swap(vector_gen[i], vector_gen[extreme]);
        // Recursively heapify the affected sub-tree
        heapify_generic(vector_gen, n, extreme, ascending);
    }
}
// Generic heap sort function
// citation: heap sort algorithinm: https://www.geeksforgeeks.org/dsa/cpp-program-for-heap-sort/
template <typename T>
void heapSort_generic(vector<T>& vector_gen , bool ascending){
// ascending = true: max heap, ascending = false: min heap
    int n = vector_gen.size();

    // Build heap (rearrange vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_generic(vector_gen, n, i, ascending);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(vector_gen[0], vector_gen[i]);

        // Call max heapify on the reduced heap
        heapify_generic(vector_gen, i, 0, ascending);
    }
}

// template doesn't work in cpp files; needs to be in header
/*
// // Generic heapify function
// template <typename T>
// void heapify_generic(vector<T>& vector_gen, int n, int i , bool ascending);
// // Generic heap sort function
// // citation: heap sort algorithinm: https://www.geeksforgeeks.org/dsa/cpp-program-for-heap-sort/
// template <typename T>
// void heapSort_generic(vector<T>& vector_gen , bool ascending);
*/

#endif 