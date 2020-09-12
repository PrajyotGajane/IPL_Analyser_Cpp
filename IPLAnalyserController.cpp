#include <iostream>
#include "IPLAnalyser.cpp"
#include "UserInputAndOutput.h"
#include "ALLRounder.h"
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
    STRIKE_RATE_WITH_FOURS_FIVE_WKT,
    AVERAGE_WITH_STRIKE_RATE_BOWLER,
    AVERAGE_WITH_WICKET,
    BATIING_AND_BOWLING_AVG,
    EXIT = 20
};

void displayWelcomeMessage()
{
    system("clear");
    cout << "Welcome to IPL Analyser"
         << "\n";
}

vector<AllRounder* > getAllRounderData(vector<Batsman *> batsman, vector<Bowler *> bowler)
{
    vector<AllRounder*> data;
    for (auto iterator = batsman.begin() + 1; iterator != batsman.end(); iterator++)
    {
        for (auto itr = bowler.begin() + 1; itr != bowler.end(); itr++)
        {
            if ((*iterator)->getPlayer() == (*itr)->getPlayer()) {
                AllRounder* all_rounder = new AllRounder(*iterator, *itr); 
                data.push_back(all_rounder);
            }
        }
    }
    return data;
}

class IPLAnalyserController
{
    IPLAnalyser<Batsman> ipl_batsman_analyser;
    IPLAnalyser<Bowler> ipl_bowler_analyser;
    IPLAnalyser<AllRounder> ipl_all_rounder;
    
    UserInputAndOutput user_input_output;

    vector<Batsman *> sorted_batsman_list;
    vector<Bowler *> sorted_bowler_list;
    vector<AllRounder *> all_rounder_list;
    vector<AllRounder *> all_rounder_list_2;

    int choice;

public:
    IPLAnalyserController(){}
    void performTask()
    {  
        ipl_batsman_analyser.loadIPLData(BATSMAN_FILE_PATH);
        ipl_bowler_analyser.loadIPLData(BOWLER_FILE_PATH);
        bool break_loop = true;
        while (break_loop)
        {
            choice = user_input_output.selectField();
            switch (choice)
            {
                case AVERAGE:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByAverage);
                    cout << "\nPlayer with highest average \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);
                    break;

                case STRIKE_RATE:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByStrikeRate);
                    cout << "\nPlayer with highest strike rate \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);
                    break;

                case FOURS_AND_SIXES:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByFoursAndSixes);
                    cout << "\nPlayer with highest Fours and Sixes \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);
                    break;

                case STRIKE_RATE_WITH_FOURS_SIXES:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByStrikeRateWithFourAndSix);
                    cout << "\nPlayer with highest Strike rate along with Fours and Sixes \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);   
                    break;

                case AVERAGE_WITH_STRIKE_RATE:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByAverageWithStrikeRate);
                    cout << "\nPlayer with highest Average along with Strike rate \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);   
                    break;   

                case RUNS_WITH_AVERAGE:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareRunsWithAverage);
                    cout << "\nPlayer with highest Runs along with average \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list);   
                    break;  

                case AVERAGE_BOWLER:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareBowlerByAverage);
                    cout << "\nBowler with highest average \n";
                    user_input_output.displayBowlerData(sorted_bowler_list); 
                    break;

                case STRIKE_RATE_BOWLER:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByStrikeRate);
                    cout << "\nBowler with highest strike rate \n";
                    user_input_output.displayBowlerData(sorted_bowler_list); 
                    break;

                case ECONOMY_RATE:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByEconRate);
                    cout << "\nBowler with highest economy rate \n";
                    user_input_output.displayBowlerData(sorted_bowler_list); 
                    break;

                case STRIKE_RATE_WITH_FOURS_FIVE_WKT:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByStrikeRateWithFourAndFiveWickets);
                    cout << "\nBowler with highest strike rate and wickets\n";
                    user_input_output.displayBowlerData(sorted_bowler_list); 
                    break;

                case AVERAGE_WITH_STRIKE_RATE_BOWLER:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByStrikeRateAndAverageBowler);
                    cout << "\nBowler with highest strike rate and average\n";
                    user_input_output.displayBowlerData(sorted_bowler_list); 
                    break;

                case AVERAGE_WITH_WICKET:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByAverageAndWickets);
                    cout << "\nBowler with highest strike rate and average\n";
                    user_input_output.displayBowlerData(sorted_bowler_list); 
                    break;    

                case BATIING_AND_BOWLING_AVG:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByAverage);
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareBowlerByAverage);
                    all_rounder_list = getAllRounderData(sorted_batsman_list,sorted_bowler_list);
                    ipl_all_rounder.loadAllRouderData(all_rounder_list);
                    all_rounder_list_2 = ipl_all_rounder.getSortedDataR(&compareByBattingBowlingAverage);
                    user_input_output.displayAllRounderData(all_rounder_list);
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