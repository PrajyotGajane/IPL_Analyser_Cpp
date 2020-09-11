#include <iostream>
#include "IPLAnalyser.cpp"
#include "UserInputAndOutput.h"
#include "SortBy.h"
#include <vector>

using namespace std;

string BATSMAN_FILE_PATH = "MostRuns.csv";
string BOWLER_FILE_PATH = "MostWkts.csv";

enum SortChoice
{
    AVERAGE = 1,
    STRIKE_RATE,
    FOURS_AND_SIXES,
    STRIKE_RATE_WITH_FOURS_SIXES,
    AVERAGE_WITH_STRIKE_RATE,
    RUNS_WITH_AVERAGE,
    AVERAGE_BOWLER,
    STRIKE_RATE_BOWLER,
    ECONOMY_RATE,
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
    IPLAnalyser<Batsman> ipl_batsman_analyser;
    IPLAnalyser<Bowler> ipl_bowler_analyser;
    UserInputAndOutput user_input_output;
    vector<Batsman *> sorted_batsman_list;
    vector<Bowler *> sorted_bowler_list;
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
                    ipl_batsman_analyser.loadIPLData(BATSMAN_FILE_PATH);
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByAverage);
                    cout << "\nPlayer with highest average \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);
                    break;

                case STRIKE_RATE:
                    ipl_batsman_analyser.loadIPLData(BATSMAN_FILE_PATH);
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByStrikeRate);
                    cout << "\nPlayer with highest strike rate \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);
                    break;

                case FOURS_AND_SIXES:
                    ipl_batsman_analyser.loadIPLData(BATSMAN_FILE_PATH);
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByFoursAndSixes);
                    cout << "\nPlayer with highest Fours and Sixes \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);
                    break;

                case STRIKE_RATE_WITH_FOURS_SIXES:
                    ipl_batsman_analyser.loadIPLData(BATSMAN_FILE_PATH);
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByStrikeRateWithFourAndSix);
                    cout << "\nPlayer with highest Strike rate along with Fours and Sixes \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);   
                    break;

                case AVERAGE_WITH_STRIKE_RATE:
                    ipl_batsman_analyser.loadIPLData(BATSMAN_FILE_PATH);
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByAverageWithStrikeRate);
                    cout << "\nPlayer with highest Average along with Strike rate \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);   
                    break;   

                case RUNS_WITH_AVERAGE:
                    ipl_batsman_analyser.loadIPLData(BATSMAN_FILE_PATH);
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareRunsWithAverage);
                    cout << "\nPlayer with highest Runs along with average \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);   
                    break;  

                case AVERAGE_BOWLER:
                    ipl_bowler_analyser.loadIPLData(BOWLER_FILE_PATH);
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareBowlerByAverage);
                    cout << "\nBowler with highest average \n";
                    user_input_output.displayBowlerData(sorted_bowler_list); 
                    break;

                case STRIKE_RATE_BOWLER:
                    ipl_bowler_analyser.loadIPLData(BOWLER_FILE_PATH);
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByStrikeRate);
                    cout << "\nBowler with highest strike rate \n";
                    user_input_output.displayBowlerData(sorted_bowler_list); 
                    break;

                case ECONOMY_RATE:
                    ipl_bowler_analyser.loadIPLData(BOWLER_FILE_PATH);
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByEconRate);
                    cout << "\nBowler with highest economy rate \n";
                    user_input_output.displayBowlerData(sorted_bowler_list); 
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