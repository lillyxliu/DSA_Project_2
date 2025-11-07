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
    

    bool listening = true;
    // string data_set_loaded = "dataset.csv";
    while(listening){
        cout << "Menu:" << endl;
        cout << "0. Choose Data Set" << endl;
        cout << "1. Graph Functions" << endl;
        cout << "2. Add Person" << endl;
        cout << "3. Lookup Person" << endl;
        cout << "4. View Person Information" << endl;
        cout << "5. Exit" << endl;
        cout << "[Currently Loaded Data Set: dataset.csv]" << endl;
        cout << "[Number of newly added people: ]" << endl;
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        string dataSetLoaded = "../data/dataset.csv";


        if(choice == 0){ //MENU CHOICE: CHANGE DATA SET
            // need to cin data set name
            // match to format: ../data/dataset.csv with "dataset" being replaced
            cout << "Enter data set name (without path or .csv): ";
            string dataSetName;
            cin >> dataSetName;
            dataSetLoaded = "../data/" + dataSetName + ".csv";
            cout << "Data set path changed to: " << dataSetLoaded << endl;

        }

    ifstream data(dataSetLoaded);
    
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


        if(choice == 1){ //MENU CHOICE: GRAPH FUNCTIONS
            int choice_1;
            cout << "-----" << endl;
            cout << "> Graph Functions:" << endl;
            cout << ">> 1. Print Graph" << endl;
            cout << ">> 2. Vertex Count" << endl;
            cout << ">> 3. Edge Count" << endl;
            cout << ">> 4. Check Edge Existence" << endl;
            cout << ">> 5. Checkout Node" << endl;

            cin >> choice_1;

            if(choice_1 == 1){
                calc_graph.printGraph(a_map);
            }
            else if (choice_1 == 2){
                cout << "Vertex Count: " << calc_graph.vertex_count() << endl;
            }
            else if (choice_1 == 3){
                cout << "Edge Count: " << calc_graph.edge_count() << endl;
            }
            else if (choice_1 == 4){
                string from_id, to_id;
                cout << "Enter first ID: ";
                cin >> from_id;
                cout << "Enter second ID: ";
                cin >> to_id;
                int from_index = calc_graph.find_node_index(from_id);
                int to_index = calc_graph.find_node_index(to_id);
                
                if(calc_graph.isEdge(from_index, to_index)){
                    cout << "Edge exists between " << from_id << " and " << to_id << endl;
                }
                else{
                    cout << "No edge exists between " << from_id << " and " << to_id << endl;
                }
            }else if (choice_1 == 5){
                string id;
                cout << "Enter node ID to checkout: ";
                cin >> id;

                int index = calc_graph.find_node_index(id);
                if (index == -1) {
                    cout << "Node not found." << endl;
                }else{
                    cout << "[" << a_map[id].getFirstName() << "]:" << endl;
                    for (auto neighbor : calc_graph.nodes[index].neighbors){
                        cout << a_map[neighbor.first].getFirstName() << " (weight: " << neighbor.second << ")" << endl;
                    }
                }
            }
        }

        else if(choice == 2){ //MENU CHOICE: ADD PERSON
            Questions newPerson;
            newPerson.runTest();
        }
        else if(choice == 3){ //MENU CHOICE: LOOKUP PERSON
            lookupPerson(a_map);
        }
        else if(choice == 4){ //MENU CHOICE: VIEW PERSON INFORMATION
            viewPersonInfo(a_map);
        }
        else{
            listening = false;
            break;
        } 
    }   

    

    
    
    return 0;

}