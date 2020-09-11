#include <iostream>
#include "IPLAnalyser.cpp"
#include "UserInputAndOutput.h"
#include "SortBy.h"
#include <vector>

using namespace std;

string BATSMAN_FILE_PATH = "MostRuns.csv";

enum SortChoice
{
    AVERAGE = 1
};

void displayWelcomeMessage()
{
    system("clear");
    cout << "Welcome to IPL Analyser"
         << "\n";
}

class IPLAnalyserController
{
    IPLAnalyser ipl_analyser;
    UserInputAndOutput user_input_output;
    vector<Batsman *> sorted_list;
    int choice;

public:
    void performTask()
    {
        choice = user_input_output.selectField();
        switch (choice)
        {
            case AVERAGE:
                ipl_analyser.loadIPLData(BATSMAN_FILE_PATH);
                sorted_list = ipl_analyser.getSortedData(&compareByAverage);
                break;

            default:
                cout << "Invalid Input" << endl;
                break;
        }
        user_input_output.displayData(sorted_list);
    }
};

int main()
{
    displayWelcomeMessage();
    IPLAnalyserController controller;
    controller.performTask();
}