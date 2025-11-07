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
#include "userInputTest.h"
using namespace std::chrono;
using namespace std;



int main(){ 
    ifstream data("../data/dataset.csv");
    
    if(!data.is_open()){
        cout << "Error opening file" << endl;
        return 1;
    }

    string headers;
    getline(data,headers,'\n'); // 1st line: skip header

    map<string, Person> a_map;
    vector<string> vector_id;
    
    load_people_data(data,a_map,vector_id);
    data.close();
    
    Person source_p("An,jee,00000005,0.80,1.00,1.00,0.00,0.60,0.99,0.80,0.60,0.35");
   

    /////////////////////////////////////////////////
    /// Measuring Sorting Algorithims
    /////////////////////////////////////////////////

    // Create copies of vector_id for each sorting algorithm and type
    
    measure_sorting_algos(a_map,vector_id,source_p);

    print_loaded_first_names(a_map,vector_id);

    cout << "Loaded " << a_map.size() << " people." << endl;
    cout << "Loaded vector " << vector_id.size() << " people." << endl;
   
    /////////////////////////////////////////////////////
    cout << "---------------------------" << endl;
    cout << "Reached graph calculation" << endl;
    
    Graph calc_graph = build_graph(a_map, vector_id);

    cout << "Calculated Graph Implementation" << endl;
    calc_graph.printGraph(a_map);

    bool listening = true;
    string data_set_loaded = "dataset.csv";
    while(listening){
        cout << "Menu:" << endl;
        cout << "0. Choose Data Set" << endl;
        cout << "1. Graph Functions" << endl;
        cout << "2. Add Person" << endl;
        cout << "3. Lookup Person" << endl;
        cout << "4. View Person Information" << endl;
        cout << "5. Exit" << endl;
        cout << "[Currently Loaded Data Set: dataset.csv]" << endl;
        cout << "[Number of newly added people: " << endl;

        int choice;
        cin >> choice;
        if(choice == 1){
            int choice_1;
            cout << "-----" << endl;
            cout << "> Graph Functions:" << endl;
            cout << ">> 1. Print Graph" << endl;
            cout << ">> 2. Vertex Count" << endl;
            cout << ">> 3. Edge Count" << endl;
            cout << ">> 4. Check Edge Existence" << endl;
            cout << ">> 5. Checkout Node" << endl;

        }else{
            listening = false;
            break;
        }
    }   

//     return 0;
Questions qst;
qst.runTest();

}