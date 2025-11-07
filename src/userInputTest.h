    /*    needs to store: 
    - a string for the question answer and more
    public:
        ask_question(){
            cout<< the question
        }
*/
#include <string>
#include <vector>
using namespace std;


struct personQuestionData
{
    string question;
    string category;
    bool flipped = true;
    string yesIndicates;
    string noIndicates;
    
    int answer = 0;

    /* data */
};



class Questions{
    public: 
        void runTest();

        // PERSONALITY FUNCTIONS
        void askPersonalityQuestions();
        void getPersonalityValues();
        void updateScore(string& category, int answer, bool flipped);
        void calculatePersonality();
        void convertPersonalityScale();

        // PHYSICAL FUNCTIONS
        void askPhysicalQuestions();
        void getPhysicalValues();
        

        // GETTERS
        int getSocialScore(){
            return socialScore;
        }
        int getProcessingScore(){
            return processingScore;
        }
        int getDecisionScore(){
            return decisionScore;
        }
        int getTacticsScore(){
            return tacticsScore;
        }

        // SETTERS
        void setSocialScore(int score){
            socialScore = score;
        }
        void setProcessingScore(int score){
            processingScore = score;
        }
        void setDecisionScore(int score){
            decisionScore = score;
        }
        void setTacticsScore(int score){
            tacticsScore = score;
        }

    private:

        vector<personQuestionData> personalityBank;
        vector<string> physicalBank;

        int socialScore = 0;
        int processingScore = 0;
        int decisionScore = 0;
        int tacticsScore = 0;
    
};





//test case so u cant take in an int

//a question and what a yes/no implies for each quesion