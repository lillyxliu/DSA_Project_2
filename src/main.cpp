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
using namespace std;


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
    vector<string> vector_id_personality = vector_id;
    vector<string> vector_id_physical = vector_id;
    heapSort(vector_id_personality,source_p, a_map, 0); // by personality
    heapSort(vector_id_physical,source_p, a_map, 1); // by physical
    
    // quickSort(vector_id_personality, 0, vector_id_personality.size() - 1, source_p, a_map, 0); // by personality
    // quickSort(vector_id_physical, 0, vector_id_physical.size() - 1, source_p, a_map, 1); // by physical


    // // print vector print
    // for(int i =0 ; i<vector_id.size();i++){
    //     cout << a_map[vector_id_personality[i]].getFirstName() << " "; 
        
    // }
    // cout << endl;
    // for(int i =0 ; i<vector_id.size();i++){
    //     cout << a_map[vector_id_physical[i]].getFirstName() << " "; 
        
    // }
    // cout << endl;

    cout << "Loaded " << a_map.size() << " people." << endl;


    /// testing graph
    Graph g;
    g.add_edge("Anny", "Bobby", 5);
    g.add_edge("Anny", "Cathy", 3);
    g.add_edge("Bobby", "Cathy", 2);
    g.add_edge("Cathy", "David", 4);

    cout << "Testing Graph Implementation" << endl;
    g.printGraph();

    cout << "Reached graph calculation" << endl;

//Calc Graph Implementaion
    Graph calc_graph;
    for(int i =0; i< vector_id.size();i++){
        for(int j = i+1; j< vector_id.size(); j++){
            Person& person_one = a_map[vector_id[i]];
            Person& person_two = a_map[vector_id[j]];   

            float weight_perosnality_eculidean = person_one.calcPersDif_euclidean(person_two);
            float weight_physical_eculidean = person_one.calcPhysicalDif_euclidean(person_two);
            float total_weight = (weight_perosnality_eculidean + weight_physical_eculidean)/2.0;

        
            calc_graph.add_edge(person_one.getID(), person_two.getID(), total_weight);
            calc_graph.add_edge(person_two.getID(), person_one.getID(), total_weight);
        }
    }
    cout << "Calculated Graph Implementation" << endl;
    // calc_graph.printGraph(a_map);


    return 0;
}
