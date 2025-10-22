#include "person.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


void Person::setAttributes(){
   // cout << inputString << endl; //tester
    vector<string> tokens;
    stringstream ss(inputString);
    string token; 
    
    while(getline(ss, token, ',')){
        tokens.push_back(token);
    }

    if(tokens.size() != 12){
        cerr << "Error: Invalid input string format." << endl;
        return;
    }   
    /* citation: 
    getline string: https://www.geeksforgeeks.org/cpp/getline-string-c/ 
    string to float: https://en.cppreference.com/w/cpp/string/basic_string/stof
    */
    firstName = tokens[0];
    lastName = tokens[1];
    id = stoi(tokens[2]);
    heightS = stof(tokens[3]);
    eyeS = stof(tokens[4]);
    hairS = stof(tokens[5]);
    genderS = stof(tokens[6]);
    skinS = stof(tokens[7]);
    socialS = stof(tokens[8]);
    processS = stof(tokens[9]);
    decisionS = stof(tokens[10]);
    tacticsS = stof(tokens[11]);

    cout << firstName << " " << lastName << endl;
}

float Person::calcPhysicalDif(const Person& other){
    float physicalDiff = 0.0;
    physicalDiff = abs(heightS - other.heightS) +
    abs(eyeS - other.eyeS); abs(hairS - other.hairS) +
    abs(genderS - other.genderS) + abs(skinS - other.skinS);
    return physicalDiff;
};

float Person::calcPersDif(const Person& other){
    float persDiff = 0.0;
    persDiff = abs(socialS - other.socialS) + abs(processS - other.processS) +
    abs(decisionS - other.decisionS) + abs(tacticsS - other.tacticsS);
    return persDiff;
};





// float Person::getSocialS() return socialS;
// float Person::getProcessS() return processS;
// float Person::getDecisionS() return decisionS;
// float Person::getTactics() return tacticsS;

// float Person::getHeightS() 
// float Person::getEyeS() 
// float Person::getHairS() 
// float Person::getGenderS() 
// float Person::getSkinS() 

