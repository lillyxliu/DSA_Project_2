//
// Created by lilly on 10/14/2025.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    // cout << "hello world, meow meow Abby's test meow meow meow meow adoras test meow meow" << endl;
    // cout << "hello lilly meow meow meow" << endl;
    // for (int i = 0; i < 5; i++) {
    //     cout << "This is line " << i + 1 << endl;
    // }
    // return 0;
    
    vector<vector<string>> data2d;
    ifstream data("../data/dataset.csv");
    if(!data.is_open()){
        cout << "Error opening file" << endl;
        return 1;
    }
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
    
}

