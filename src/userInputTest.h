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

    // Default constructor
    personQuestionData() : question(""), category(""), flipped(true), 
                          yesIndicates(""), noIndicates(""), answer(0) {}
    
    // Parameterized constructor
    personQuestionData(const string& q, const string& c, bool f, 
                      const string& yes, const string& no, int a = 0)
        : question(q), category(c), flipped(f), 
          yesIndicates(yes), noIndicates(no), answer(a) {}
    
    // Copy constructor
    personQuestionData(const personQuestionData& other) = default;
    
    // Destructor
    ~personQuestionData() = default;
};

struct PhysicalQuestion
{
    string question;
    vector<string> options;
    char user_answer = '-';

    // Default constructor
    PhysicalQuestion() : question(""), options(), user_answer('-') {}
    
    // Parameterized constructor
    PhysicalQuestion(const string& q, const vector<string>& opts, char ans = '-')
        : question(q), options(opts), user_answer(ans) {}
    
    // Copy constructor
    PhysicalQuestion(const PhysicalQuestion& other) = default;
    
    // Destructor
    ~PhysicalQuestion() = default;
};



class Questions {
    public:
        // Default constructor
        Questions() : socialScore(0), processingScore(0), 
                     decisionScore(0), tacticsScore(0) {}
        
        // Copy constructor
        Questions(const Questions& other) 
            : personalityBank(other.personalityBank),
              physicalBank(other.physicalBank),
              physical_questions(other.physical_questions),
              socialScore(other.socialScore),
              processingScore(other.processingScore),
              decisionScore(other.decisionScore),
              tacticsScore(other.tacticsScore) {}
        
        // Assignment operator
        Questions& operator=(const Questions& other) {
            if (this != &other) {
                personalityBank = other.personalityBank;
                physicalBank = other.physicalBank;
                physical_questions = other.physical_questions;
                socialScore = other.socialScore;
                processingScore = other.processingScore;
                decisionScore = other.decisionScore;
                tacticsScore = other.tacticsScore;
            }
            return *this;
        }
        
        // Destructor
        ~Questions() = default;

        void runTest();

        // PERSONALITY FUNCTIONS
        void getPersonalityValues();
        void askPersonalityQuestions();
        void updateScore(string& category, int answer, bool flipped);
        void calculatePersonality();
        void convertPersonalityScale();

        // PHYSICAL FUNCTIONS
        void getPhysicalValues();
        void askPhysicalQuestions();
        

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
        
        vector<PhysicalQuestion> physical_questions; //this stores the questions, its options and the user input 

        int socialScore = 0;
        int processingScore = 0;
        int decisionScore = 0;
        int tacticsScore = 0;
    
};





//test case so u cant take in an int

//a question and what a yes/no implies for each quesion