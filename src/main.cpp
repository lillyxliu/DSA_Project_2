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
using namespace std;

int main(){

    // cout << "hello world, meow meow Abby's test meow meow meow meow adoras test meow meow" << endl;
    // cout << "hello lilly meow meow meow" << endl;
    // for (int i = 0; i < 5; i++) {
    //     cout << "This is line " << i + 1 << endl;
    // }
    // return 0;
    

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
    heapSort(vector_id,source_p, lookupMap); // by personality
    
    // print vector print
    for(int i =0 ; i<vector_id.size();i++){
        cout << lookupMap[vector_id[i]].getFirstName();
    }
    return 0;

    
}
/*  */


/* vector<vector<string>> data2d;
    string cell_str;
    string row_str;
    while(getline(data, row_str, '\n')){
        vector<string> row_vect;
        stringstream ss(row_str);
        while(getline(ss, cell_str, ',' )){
            row_vect.push_back(cell_str);

        }
        data2d.push_back(row_vect); // push back vector: row
    }
    
    for(int i = 0; i < data2d.size(); i++){
        for(int j = 0; j < data2d[i].size(); j++){
            cout << data2d[i][j] << " ";
        }
        cout << endl;
    }
    
}*/

