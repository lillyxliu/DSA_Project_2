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

personQuestionData personalityDataPoint;
Questions personalityQuestionsObj;


void Questions::runTest(){
    // getPersonalityValues();
    // askPersonalityQuestions();
    // calculatePersonality();
    // convertPersonalityScale();
    getPhysicalValues();
}

void Questions::getPersonalityValues() {
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
      
      personalityDataPoint.question = question;
      personalityDataPoint.category = category;
      personalityDataPoint.flipped = true;  // Reset flipped to true for each new question
      personalityDataPoint.yesIndicates = first_column;
      personalityDataPoint.noIndicates = second_column;
      
      if (first_column == "Extraversion" || first_column == "Intuition" || first_column == "Thinking" || first_column == "Perceiving"){
        personalityDataPoint.flipped = false;
      }

      personalityBank.push_back(personalityDataPoint);

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

void Questions::askPersonalityQuestions(){

  cout << "We will now begin the questionnaire. Please answer the following questions on a scale from 1 to 5, where 1 means 'Strongly Disagree' and 5 means 'Strongly Agree'." << endl;

  for (int i = 0; i < personalityBank.size(); i++){
    cout << i + 1 << ". " << personalityBank[i].question << ": ";
    cin >> personalityBank[i].answer;

    updateScore(personalityBank[i].category, personalityBank[i].answer, personalityBank[i].flipped);
    
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

void Questions::convertPersonalityScale(){ 
    // Convert scores from -10 to +10 scale to 0 to 1 scale
    user.setSocialS((socialScore + 10) / 20.0 * 1.0);
    user.setProcessS((processingScore + 10) / 20.0 * 1.0);
    user.setDecisionS((decisionScore + 10) / 20.0 * 1.0);
    user.setTactics((tacticsScore + 10) / 20.0 * 1.0);

    // cout << user.getSocialS() << " " << user.getProcessS() << " " << user.getDecisionS() << " " << user.getTactics() << endl;
}


void Questions::getPhysicalValues() {
    ifstream data("../data/QuestionsPhysical.csv");
    if(!data.is_open()){
        cout << "Error opening file" << endl;
        return;
    }
    string headers;
    getline(data, headers); // 1st line
    
    string line;
    while(getline(data, line)){
      
      if (line.empty()) continue; 

    if(line.front() == '"') {
        line.erase(0, 1);
    }
    if(!line.empty() && line.back() == '"') {
        line.pop_back();  
    }  
    physicalBank.push_back(line);
    }
   for (int i = 0; i < physicalBank.size(); i++) {
        PhysicalQuestion pq;

        string curr_question = physicalBank[i];
        
        // find where options start " a)"
        size_t pos = curr_question.find(" a)");
        if (pos != string::npos) {
            pq.question = curr_question.substr(0, pos);
            cout << "Question " << i + 1 << ": " << pq.question << endl;
            
            // extract the rest of the string (the options)
            string options = curr_question.substr(pos + 1); //  skips the initial space before 'a)'
            

            // split by patterns like "a)" "b)" "c)"
            char current_label = 'a';
            while (true){

                string label = string(1, current_label) + ")";
                size_t start = options.find(label);

                if (start == string::npos){ 
                break;
                }

                size_t next = options.find(" " + string(1, current_label + 1) + ")", start + 2);
                string choice;

                if (next == string::npos)
                    choice = options.substr(start + 2);
                else
                    choice = options.substr(start + 2, next - (start + 2));

                pq.options.push_back(choice);
                cout << "  " << label << " " << choice << endl;
                current_label++;
            }

            //prompting user input

            cout << "Enter your choice (a-" << char(current_label - 1) << "): ";
            char user_choice;
            cin >> user_choice;
            while (user_choice < 'a' || user_choice >= current_label) {
                cout << "Invalid choice. Please enter a valid option (a-" << char(current_label - 1) << "): ";
                cin >> user_choice;
            }

            pq.user_answer = user_choice;
            cout << "You selected option " << pq.user_answer << endl;

        } 
        else{
            
            pq.question = curr_question;
            cout << "Question " << i + 1 << ": " << pq.question << endl;
            cout << "Your answer:" << endl;
            string user_input_height;
            getline(cin >> ws, user_input_height);
            pq.options.push_back(user_input_height);
            pq.user_answer = '-'; //the dash indicates that this is the height answer and not "a)" or smthing else
            cout << endl;

        }

        
        physical_questions.push_back(pq);
        cout << endl;
    }  

    //test to check whether it stored correctly

    cout << "Here are your responses:\n";

    for (const auto &pq : physical_questions) {
        cout << pq.question << endl;
        if (pq.user_answer != '-') {
            int index = pq.user_answer - 'a';
            if (index >= 0 && index < pq.options.size())
                cout << "  You chose: " << pq.user_answer << ") " << pq.options[index] << endl;
        } else {
            cout << "  Your answer: " << pq.options[0] << endl;
        }
        cout << endl;
    }

}
