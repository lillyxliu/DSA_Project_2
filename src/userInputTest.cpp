#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;
#include "person.h"
#include "userInputTest.h"


Person user;

questionData dataPoint;
Questions questionsObj;

void Questions::getValues() {
    //read from csv file and populate 2d_vector
    ifstream data("../data/Questions.csv");
    if(!data.is_open()){
        cout << "Error opening file" << endl;
        return;
    }
    string headers;
    getline(data, headers,'\n'); // 1st line
    
    string row_str;
    
    while(getline(data, row_str, '\n')){
      stringstream ss(row_str);
      string question, category, flipped_str, first_column, second_column;
    
      getline(ss, question, ',');
      getline(ss, category, ',');
      getline(ss, flipped_str, ',');   
      getline(ss, first_column, ',');
      getline(ss, second_column, ',');
      
      dataPoint.question = question;
      dataPoint.category = category;
      dataPoint.flipped = true;  // Reset flipped to true for each new question
      dataPoint.yesIndicates = first_column;
      dataPoint.noIndicates = second_column;
      
      if (first_column == "Extraversion" || first_column == "Intuition" || first_column == "Thinking" || first_column == "Perceiving"){
        dataPoint.flipped = false;
      }

      cout << "Question: " << dataPoint.question << ", Category: " << dataPoint.category << ", Flipped?: " << dataPoint.flipped << endl;
      
    }
    

}

