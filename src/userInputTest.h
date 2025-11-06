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


struct questionData
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
        void askQuestions();
        void getValues();
        void updateScore(string& category, int answer, bool flipped);
        void calculatePersonality();

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

        vector<questionData> bank;

        int socialScore = 0;
        int processingScore = 0;
        int decisionScore = 0;
        int tacticsScore = 0;
    
};





//test case so u cant take in an int

//a question and what a yes/no implies for each quesion