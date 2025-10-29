#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
#include "person.h"


void personalityTest(){
    
    float answer; 

    cout << "We will being with the personality test" << endl;
    cout << "Are you more introverted (0.0) or extrover0.ted (1.0)?" << endl;
    cin >> answer;
    cout << "Great! you are an ";
    if(answer > 0.5) cout << "introvert" << endl;
    else cout << "extrovert!" << endl;
    

    
    
}

void physicalTest(){
    cout << "We will now move on to the physical test" << endl;
}