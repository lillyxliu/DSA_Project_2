//
// Created by lilly on 10/14/2025.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include "person.h"
#include "dataStructureOne.h"
#include "dataStructureTwo.h"
#include "graph.h"
#include "functions.h"
using namespace std;

int main(){ 

    ifstream data("../data/dataset.csv");
    if(!data.is_open()){
        cout << "Error opening file" << endl;
        return 1;
    }
    string headers;
    getline(data,headers,'\n'); // 1st line
    
    string row_str;
    map<string, Person> lookupMap;
    vector<string> vector_id;
    
    while(getline(data, row_str, '\n')){
      Person p(row_str);
      lookupMap.insert({p.getID(),p});
      vector_id.push_back(p.getID());
      
    }
    
    //Person source_p("Halia,Ahny,00000008,0.87,0.30,0.36,0.4,0.28,0.70,0.62,0.33,0.64");
    //Person source_p("Ana,Chatter,00000009,0.81,0.99,0.99,0.00,0.61,0.98,0.82,0.61,0.31");
    Person source_p("An,jee,00000005,0.80,1.00,1.00,0.00,0.60,0.99,0.80,0.60,0.35");
    vector<string> vector_id_personality = vector_id;
    vector<string> vector_id_physical = vector_id;
    heapSort(vector_id_personality,source_p, lookupMap, 0); // by personality
    heapSort(vector_id_physical,source_p, lookupMap, 1); // by physical
    
    // print vector print
    for(int i =0 ; i<vector_id.size();i++){
        cout << lookupMap[vector_id_personality[i]].getFirstName() << " "; 
        
    }
cout << endl;
    for(int i =0 ; i<vector_id.size();i++){
        cout << lookupMap[vector_id_physical[i]].getFirstName() << " "; 
        
    }


    /// testing graph
    cout << "Testing Graph Implementation" << endl << endl; 
    Graph g;
    g.add_edge("Anny", "Bobby", 5);
    g.add_edge("Anny", "Cathy", 3);
    g.add_edge("Bobby", "Cathy", 2);
    g.add_edge("Cathy", "David", 4);
    g.printGraph();

    cout << "Vertices: " << g.vertex_count() << endl;
    cout << "Edges: " << g.edge_count() << endl;
    cout << "Is Edge between Anny and Bobby: " << g.isEdge(0, 1) << endl;
    cout << "Weight Anny-Bobby" << g.getWeight(0, 1) << endl;
    vector<int> adj = g.getAdjacent("Cathy");
    cout << "Adjacent to Cathy: ";
    for(int index : adj){
        cout << g.nodes[index].id << " ";
    }
    cout << endl;
    return 0;
}
