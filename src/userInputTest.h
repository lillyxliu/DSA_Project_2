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
    
    int answer;

    /* data */
};

class Questions{
    public: 
        void ask_question();
        void getValues();

    private:
        vector<vector<questionData>> matrix_vector;
    
};





//test case so u cant take in an int

//a question and what a yes/no implies for each quesion