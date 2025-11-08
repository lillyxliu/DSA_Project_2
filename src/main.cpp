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
    string dataSetLoaded = "../data/dataset.csv";
    map<string, Person> a_map;
    vector<string> vector_id;
    Graph calc_graph;

    while (listening) {
        cout << "----------------------------------" << endl;
        cout << "Menu:" << endl;
        cout << "0. Choose Data Set" << endl;
        cout << "1. Graph Functions" << endl;
        cout << "2. Add Person" << endl;
        cout << "3. Lookup Person" << endl;
        cout << "4. View Person Information" << endl;
        cout << "5. Exit" << endl;
        cout << "[Currently Loaded Data Set: " << dataSetLoaded << "]" << endl;
        cout << "[Number of newly added people: " << 0 << "]" << endl;
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 0) { // CHANGE DATASET
            cout << "Enter data set name (without path or .csv): ";
            string dataSetName;
            cin >> dataSetName;
            dataSetLoaded = "../data/" + dataSetName + ".csv";

            ifstream data(dataSetLoaded);
            if (!data.is_open()) {
                cout << "Error opening file. Reverting to previous dataset." << endl;
                continue;
            }

            string headers;
            getline(data, headers, '\n'); // skip header
            a_map.clear();
            vector_id.clear();

            load_people_data(data, a_map, vector_id);
            data.close();

            cout << "Data set loaded successfully: " << dataSetLoaded << endl;
            cout << "Loaded " << a_map.size() << " people." << endl;

            // rebuild graph
            calc_graph = build_graph(a_map, vector_id);
        } 
        else if (choice == 1) { // GRAPH FUNCTIONS
            if (a_map.empty()) {
                cout << "No dataset loaded. Please load a dataset first." << endl;
                continue;
            }

            int choice_1;
            cout << "-----" << endl;
            cout << "> Graph Functions:" << endl;
            cout << ">> 1. Print Graph" << endl;
            cout << ">> 2. Vertex Count" << endl;
            cout << ">> 3. Edge Count" << endl;
            cout << ">> 4. Check Edge Existence" << endl;
            cout << ">> 5. Checkout Node" << endl;
            cout << "Enter choice: ";
            cin >> choice_1;

            if (choice_1 == 1) {
                calc_graph.printGraph(a_map);
            }
            else if (choice_1 == 2) {
                cout << "Vertex Count: " << calc_graph.vertex_count() << endl;
            }
            else if (choice_1 == 3) {
                cout << "Edge Count: " << calc_graph.edge_count() << endl;
            }
            else if (choice_1 == 4) {
                string from_id, to_id;
                cout << "Enter first ID: ";
                cin >> from_id;
                cout << "Enter second ID: ";
                cin >> to_id;
                int from_index = calc_graph.find_node_index(from_id);
                int to_index = calc_graph.find_node_index(to_id);

                if (calc_graph.isEdge(from_index, to_index)) {
                    cout << "Edge exists between " << from_id << " and " << to_id << endl;
                } else {
                    cout << "No edge exists between " << from_id << " and " << to_id << endl;
                }
            }
            else if (choice_1 == 5) {
                string id;
                cout << "Enter node ID to checkout: ";
                cin >> id;

                int index = calc_graph.find_node_index(id);
                if (index == -1) {
                    cout << "Node not found." << endl;
                } else {
                    cout << "[" << a_map[id].getFirstName() << "]:" << endl;
                    for (auto neighbor : calc_graph.nodes[index].neighbors) {
                        cout << a_map[neighbor.first].getFirstName()
                             << " (weight: " << neighbor.second << ")" << endl;
                    }
                }
            }
        } 
        else if (choice == 2) { // ADD PERSON
            Questions newPerson;
            newPerson.runTest();
        } 
        else if (choice == 3) { // LOOKUP PERSON
            if (a_map.empty()) {
                cout << "No dataset loaded. Please load a dataset first." << endl;
                continue;
            }
            lookupPerson(a_map);
        } 
        else if (choice == 4) { // VIEW PERSON INFO
            if (a_map.empty()) {
                cout << "No dataset loaded. Please load a dataset first." << endl;
                continue;
            }
            viewPersonInfo(a_map);
        } 
        else if (choice == 5) { // EXIT
            cout << "Exiting program..." << endl;
            listening = false;
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
