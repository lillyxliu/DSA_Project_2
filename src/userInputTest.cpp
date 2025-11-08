#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
#include "person.h"
#include "userInputTest.h"
#include <limits>



Person user;

personQuestionData personalityDataPoint;
Questions personalityQuestionsObj;


void Questions::runTest(){
    getPersonalityValues();
    askPersonalityQuestions();
    calculatePersonality();
    convertPersonalityScale();
    getPhysicalValues();
    askPhysicalQuestions();
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

cout << "\n---------------------------------------- \nPersonality Test" << endl;

  cout << " \nWe will now begin the questionnaire.\nPlease answer the following questions on a scale from 1 to 5\nWhere 1 means 'Strongly Disagree' and 5 means 'Strongly Agree'." << endl;

  //cin fail method from: https://www.geeksforgeeks.org/cpp/how-to-use-cin-fail-method-in-cpp/ 


    int questionCount = personalityBank.size();

  for (int i = 0; i < questionCount; i++){
    int answer;
    bool valid_input = false;
    while (!valid_input) {
        cout << "\n----------------------------------------" << endl;
        cout << "Question " << i + 1 << " of " << questionCount << endl;
        cout << personalityBank[i].question << ": ";
        cin >> answer;
        if (cin.fail() || answer < 1 || answer > 5) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
        } else {
            valid_input = true;
        }
    }
    personalityBank[i].answer = answer;
    

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
    cout << "\n----------------------------------------" << endl;
    cout << "End of Personality Test" << endl;

    string personalityType = "";


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
    if (!data.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    string headers;
    getline(data, headers); // Skip header line

    string line;
    while (getline(data, line)) {
        if (line.empty()) continue;

        // remove quotes
        if (line.front() == '"') line.erase(0, 1);
        if (!line.empty() && line.back() == '"') line.pop_back();

        PhysicalQuestion pq;
        string curr_question = line;

        size_t pos = curr_question.find(" a)");
        if (pos != string::npos) {
            pq.question = curr_question.substr(0, pos);

            string options = curr_question.substr(pos + 1);
            char current_label = 'a';

            while (true) {
                string label = string(1, current_label) + ")";
                size_t start = options.find(label);
                if (start == string::npos) break;


                size_t next = options.find(" " + string(1, current_label + 1) + ")");
                string choice;
                if (next == string::npos) {
                    choice = options.substr(start + 2);
                } else {
                    choice = options.substr(start + 2, next - (start + 2));
                }


                pq.options.push_back(choice);
                current_label++;
            }
        } else {
            pq.question = curr_question;
        }

        physicalBank.push_back(curr_question);
        physical_questions.push_back(pq);
    }
}


// Helper function for validating height input in format like 5'9
string getValidHeight() {
    string height;

    while (true) {
        cout << "Enter your height (example: 5'9): ";
        getline(cin >> ws, height);

        // remove spaces
        height.erase(remove(height.begin(), height.end(), ' '), height.end());

        // find apostrophe
        size_t apostrophePos = height.find('\'');

        // check for valid structure
        if (apostrophePos == string::npos || apostrophePos == 0 || apostrophePos == height.length() - 1) {
            cout << "Invalid format. Please use the correct format.\n";
            continue;
        }

        // extract feet and inches
        string feet = height.substr(0, apostrophePos);
        string inches = height.substr(apostrophePos + 1);

        bool valid = true;

        // ensure both are numeric
        for (char c : feet)
            if (!isdigit(c)) valid = false;
        for (char c : inches)
            if (!isdigit(c)) valid = false;

        if (!valid) {
            cout << "Invalid format. Please use numbers only, like 5'9.\n";
            continue;
        }

        return height; // valid input
    }
}



void Questions::askPhysicalQuestions() {
    cout << "\n----------------------------------------" << endl;
    cout << "Physical Test" << endl;
    cout << "\nWe will now ask a few physical-related questions." << endl;

    for (int i = 0; i < physical_questions.size(); i++) {
        PhysicalQuestion& pq = physical_questions[i];
        cout << "\n----------------------------------------" << endl;
        cout << "Question " << i + 1 << ": " << pq.question << endl;

        if (!pq.options.empty()) {
            char current_label = 'a';
            for (const auto& option : pq.options) {
                cout << "  " << current_label << ") " << option << endl;
                current_label++;
            }

            char user_choice;
            bool valid = false;
            while (!valid) {
                cout << "Enter your choice (a-" << char('a' + pq.options.size() - 1) << "): ";
                cin >> user_choice;
                if (user_choice >= 'a' && user_choice < 'a' + pq.options.size()) {
                    valid = true;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            pq.user_answer = user_choice;
        } 
        else {
    // Special handling for height question
    if (pq.question.find("tall") != string::npos || pq.question.find("height") != string::npos) {
        string validHeight = getValidHeight();
        pq.options.push_back(validHeight);
        pq.user_answer = '-';
    } else {
        cout << "Your answer: ";
        string user_input;
        getline(cin >> ws, user_input);
        pq.options.push_back(user_input);
        pq.user_answer = '-';
    }
}

    }

    cout << "\nHere are your responses:\n";
    for (const auto& pq : physical_questions) {
        cout << pq.question << endl;
        if (pq.user_answer != '-') {
            int index = pq.user_answer - 'a';
            cout << "  You chose: " << pq.user_answer << ") " << pq.options[index] << endl;
        } else {
            cout << "  Your answer: " << pq.options[0] << endl;
        }
        cout << endl;
    }

    cout << "----------------------------------------" << endl;
    cout << "End of Physical Test" << endl;
}

