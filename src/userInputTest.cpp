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


void Questions::runTest(){
    getValues();
    askQuestions();
    calculatePersonality();
}

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

      bank.push_back(dataPoint);


}
  
}

void Questions::updateScore(string& category, int answer, bool flipped) {
    if (flipped) {
        answer = 6 - answer;
    }
    int value = answer - 3; // Normalize to -2 to +2 scale

    if (category == "Social") {
        setSocialScore(getSocialScore() + value);
    } else if (category == "Processing") {
        setProcessingScore(getProcessingScore() + value);
    } else if (category == "Decision") {
        setDecisionScore(getDecisionScore() + value);
    } else if (category == "Tactics") {
        setTacticsScore(getTacticsScore() + value);
    }
}



void Questions::askQuestions(){

  cout << "We will now begin the questionnaire. Please answer the following questions on a scale from 1 to 5, where 1 means 'Strongly Disagree' and 5 means 'Strongly Agree'." << endl;

  for (int i = 0; i < bank.size(); i++){
    cout << i + 1 << ". " << bank[i].question << ": ";
    cin >> bank[i].answer;

    updateScore(bank[i].category, bank[i].answer, bank[i].flipped);
    
    // FOR TESTING
    // if(bank[i].flipped) cout << "(This question is flipped)" << endl;
    // cout << "You answered: " << bank[i].answer << endl;
   
    // cout << bank[i].category << " score is now: ";
   
    // if (bank[i].category == "Social" && socialScore != 0) {
    //     cout << getSocialScore() << endl;
    // } else if (bank[i].category == "Processing" && processingScore != 0) {
    //     cout << getProcessingScore() << endl;
    // } else if (bank[i].category == "Decision" && decisionScore != 0) {
    //     cout << getDecisionScore() << endl;
    // } else if (bank[i].category == "Tactics" && tacticsScore != 0) {
    //     cout << getTacticsScore() << endl;
    // } else { cout << "0" << endl; }
    // cout << endl;
  }
}


void Questions::calculatePersonality(){
    string personalityType = "";

    cout << socialScore << " " << processingScore << " " << decisionScore << " " << tacticsScore << endl;


    personalityType += (getSocialScore() >= 0) ? "E" : "I";
    personalityType += (getProcessingScore() >= 0) ? "N" : "S";
    personalityType += (getDecisionScore() >= 0) ? "T" : "F";
    personalityType += (getTacticsScore() >= 0) ? "P" : "J";

    cout << "Your personality type is: " << personalityType << endl;
}