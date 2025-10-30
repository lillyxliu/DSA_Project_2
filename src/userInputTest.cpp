#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
#include "person.h"


Person user;

void personalityTest(){
    
    float answer; 
    string EI;
    string NS;
    string TF;
    string PJ;

    cout << "We will being with the personality test" << endl;

    
    cout << "Are you more introverted (0.0) or extrover0.ted (1.0)?" << endl;
    cin >> answer;
    user.setSocialS(answer);
    cout << "Great! you are an ";
    
    if(answer > 0.5) {
        cout << "introvert" << endl;
        EI = "I";
    }

    else {
        cout << "extrovert!" << endl;
        EI = "E";
    }

    cout << "When you process information, do you think in hard facts (0.0) or abstract concepts (1.0)?";
    cin >> answer;
    user.setProcessS(answer);

    cout << "Do you make decisions based on more logic (0.0) or personal values (1.0)?";
    cin >> answer;
    user.setDecisionS(answer);

    cout << "Are you more structured (0.0) or flexible (1.0)?";
    cin >> answer;
    user.setTactics(answer);


    /*Do you make decisions based on more logic (0.0) or personal values (1.0)?
Are you more structured (0.0) or flexible (1.0)?
Are you below (0.0) or above (1.0) the average height for your gender? (5’9 for men, 5’4 for women)
Are your eyes light (0.0) or dark (1.0)?
Is your hair light (0.0) or dark (1.0)?

*/









    
}

void physicalTest(){
    cout << "We will now move on to the physical test" << endl;
}