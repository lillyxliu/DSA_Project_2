#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {
    private:
        string firstName, lastName, id;
        string inputString;

        // Personality Attributes
        float socialS, processS, decisionS, tacticsS;

        // Physical Attributes
        float heightS, eyeS, hairS, genderS, skinS;
        
        void setAttributes(); // Function to initialize attributes from inputString
        
    public:
     
       Person(string input){
            // Default constructor
            this->inputString = input;
           
            // Initialize all attributes to zero
            this->socialS =  this->processS = this->decisionS = this->tacticsS = 0.0;
            this->heightS = this->eyeS = this->hairS = this->genderS = this->skinS = 0.0;
         
            setAttributes();
        } 
        Person(const Person& other) = default; // Copy constructor

        ~Person() = default; // Destructor
        
        float calcPhysicalDif(const Person& other);
        float calcPersDif(const Person& other);

        // // Getters
        // float getSocialS() const;
        // float getProcessS() const;
        // float getDecisionS() const;
        // float getTactics() const;

        // float getHeightS() const;
        // float getEyeS() const;
        // float getHairS() const;
        // float getGenderS() const;
        // float getSkinS() const;

    
};

#endif // PERSON_H