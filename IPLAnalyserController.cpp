#include <iostream>
#include "IPLAnalyser.cpp"
#include "UserInputAndOutput.h"
#include "SortBy.h"
#include <vector>

using namespace std;

string BATSMAN_FILE_PATH = "MostRuns.csv";

enum SortChoice
{
    AVERAGE = 1,
    STRIKE_RATE,
    EXIT = 20
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
        bool break_loop = true;
        while (break_loop)
        {
            choice = user_input_output.selectField();
            switch (choice)
            {
                case AVERAGE:
                    ipl_analyser.loadIPLData(BATSMAN_FILE_PATH);
                    sorted_list = ipl_analyser.getSortedData(&compareByAverage);
                    cout << "\nPlayer with highest average \n";
                    user_input_output.displayData(sorted_list);
                    break;

                case STRIKE_RATE:
                    ipl_analyser.loadIPLData(BATSMAN_FILE_PATH);
                    sorted_list = ipl_analyser.getSortedData(&compareByStrikeRate);
                    cout << "\nPlayer with highest strike rate \n";
                    user_input_output.displayData(sorted_list);
                    break;

                case EXIT:
                    break_loop = false;
                    break;

                default:
                    cout << "Invalid Input" << endl;
                    break;
            }
        }
    }
};

int main()
{
    displayWelcomeMessage();
    IPLAnalyserController controller;
    controller.performTask();
}