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
        Person() = default; // default constructor
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
        float calcPhysicalDif_euclidean(const Person& other);
        float calcPersDif_euclidean(const Person& other);

        // // Getters
        // Getters
        string getID() { return id; }
        string getFirstName(){return firstName;}
        string getLasttName(){return lastName;}
        float getSocialS() { return socialS; }
        float getProcessS() { return processS; }
        float getDecisionS() { return decisionS; }
        float getTactics() { return tacticsS; }

        float getHeightS() { return heightS; }
        float getEyeS() { return eyeS; }
        float getHairS() { return hairS; }
        float getGenderS() { return genderS; }
        float getSkinS() { return skinS; }

    
};

#endif // PERSON_H