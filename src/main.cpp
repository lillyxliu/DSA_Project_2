//
// Created by lilly on 10/14/2025.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cfloat>  
#include "person.h"
#include "dataStructureOne.h"
#include "dataStructureTwo.h"
#include "graph.h"
#include "functions.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

// https://www.geeksforgeeks.org/cpp/passing-a-function-as-a-parameter-in-cpp/
template<typename T>
auto measure_time(T funct){
    auto start_funct = high_resolution_clock::now();
    funct();
    auto end_funct= high_resolution_clock::now();
    return duration_cast<microseconds>(end_funct - start_funct);
}


int main(){ 
    
    ifstream data("../data/LargerDataset.csv");
    if(!data.is_open()){
        cout << "Error opening file" << endl;
        return 1;
    }
    string headers;
    getline(data,headers,'\n'); // 1st line
    
    string row_str;
    map<string, Person> a_map;
    vector<string> vector_id;
    
    while(getline(data, row_str, '\n')){
      Person p(row_str);
      a_map.insert({p.getID(),p});
      vector_id.push_back(p.getID());
      
    }
    
    //Person source_p("Halia,Ahny,00000008,0.87,0.30,0.36,0.4,0.28,0.70,0.62,0.33,0.64");
    //Person source_p("Ana,Chatter,00000009,0.81,0.99,0.99,0.00,0.61,0.98,0.82,0.61,0.31");
    Person source_p("An,jee,00000005,0.80,1.00,1.00,0.00,0.60,0.99,0.80,0.60,0.35");
    // vector<string> vector_id_personality = vector_id;
    // vector<string> vector_id_physical = vector_id;

    

    /////////////////////////////////////////////////
    /// Measuring Sorting Algorithims
    /////////////////////////////////////////////////

    // Create copies of vector_id for each sorting algorithm and type
    vector<string> vector_id_personality_heap = vector_id;
    vector<string> vector_id_physical_heap = vector_id;
    vector<string> vector_id_personality_quick = vector_id;
    vector<string> vector_id_physical_quick = vector_id;
 

    // Measure heapSort time
    auto heap_pers_time = measure_time([&](){
        heapSort(vector_id_personality_heap, source_p, a_map, 0); // by personality
    });

    auto heap_phys_time = measure_time([&](){
        heapSort(vector_id_physical_heap, source_p, a_map, 1); // by physical
    });

    cout << "heapSort took " << (heap_pers_time + heap_phys_time).count() << " microseconds." << endl;

    // Measure quickSort time
    auto quick_pers_time = measure_time([&](){
        quickSort(vector_id_personality_quick, 0, vector_id_personality_quick.size() - 1, source_p, a_map, 0); // by personality
    });

    auto quick_phys_time = measure_time([&](){
        quickSort(vector_id_physical_quick, 0, vector_id_physical_quick.size() - 1, source_p, a_map, 1); // by physical
    });

    cout << "quickSort took " << (quick_pers_time + quick_phys_time).count() << " microseconds." << endl;


    // // print vector print
    // for(int i =0 ; i<vector_id.size();i++){
    //     cout << a_map[vector_id_personality_heap[i]].getFirstName() << " "; 
        
    // }
    // cout << endl;
    // for(int i =0 ; i<vector_id.size();i++){
    //     cout << a_map[vector_id_physical_heap[i]].getFirstName() << " "; 
        
    // }
    cout << endl;
    /////////////////////////////////////////////////////

    cout << "Loaded " << a_map.size() << " people." << endl;

/*
    // /// testing graph
    // Graph g;
    // g.add_edge("Anny", "Bobby", 5);
    // g.add_edge("Anny", "Cathy", 3);
    // g.add_edge("Bobby", "Cathy", 2);
    // g.add_edge("Cathy", "David", 4);

    // cout << "Testing Graph Implementation" << endl;
    // g.printGraph();
*/
    cout << "Reached graph calculation" << endl;

    // int connections_max = 10;
    // //Calc Graph Implementaion
    // Graph calc_graph;
    // for(int i =0; i< vector_id.size();i++){
    //     Person& person_one = a_map[vector_id[i]]; // create a copy of person one
    //   //  vector<pair<string,float>> similar_neighbors; // to store potential neighbors and their weights
    //     vector<string> ids_copy = vector_id; // copy of vector_id to modify

    //     heapSort(ids_copy, person_one, a_map, 3); // sort by total weight

    //     int neighbors_added = 0;

    //     for(int j = 0; j< ids_copy.size(); j++){
    //         if(person_one.getID()== ids_copy[j]) continue; // if index of same person, skip

    //         Person& person_two = a_map[ids_copy[j]];    // create a copy of person two

    //         float weight_personality_euclidean = person_one.calcPersDif_euclidean(person_two); // calculate personality weight
    //         float weight_physical_eculidean = person_one.calcPhysicalDif_euclidean(person_two); // calculate physical weight
          
    //         float total_weight = (weight_personality_euclidean + weight_personality_euclidean)/2.0f; // average weight

    //       //  similar_neighbors.push_back({person_two.getID(), total_weight});    // push back the id and weight of neighbors
            
    //       if(calc_graph.isEdge(calc_graph.find_node_index(person_one.getID()), 
    //                            calc_graph.find_node_index(person_two.getID()))){
    //             continue; // skip if edge already exists
    //         }

    //         calc_graph.add_edge(person_one.getID(), person_two.getID(), total_weight);
    //         neighbors_added++;
            
    //         if(neighbors_added >= connections_max){
    //             break; // if number of neighbors added reaches max allowed, stop so only top n neighbors connected
    //         }
    //     }
    // }


    // cout << "Calculated Graph Implementation" << endl;
    // //calc_graph.printGraph(a_map);


    return 0;
}
