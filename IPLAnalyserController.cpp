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
    RUNS_WICKETS,
    HUNDRED_AVERAGE,
    ZERO_HUN_FIF,
    EXIT = 20
};

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
        user_input_output.displayWelcomeMessage();
        ipl_batsman_analyser.loadIPLData(BATSMAN_FILE_PATH);
        ipl_bowler_analyser.loadIPLData(BOWLER_FILE_PATH);
        sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByAverage);
        sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareBowlerByAverage);
        all_rounder_list = getAllRounderData(sorted_batsman_list,sorted_bowler_list);
        bool break_loop = true;
        string message;
        while (break_loop)
        {
            choice = user_input_output.selectField();
            switch (choice)
            {
                case AVERAGE:
                    message = "\nPlayer with highest average \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list, message);
                    break;

                case STRIKE_RATE:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByStrikeRate);
                    message = "\nPlayer with highest strike rate \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list, message);
                    break;

                case FOURS_AND_SIXES:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByFoursAndSixes);
                    message = "\nPlayer with highest Fours and Sixes \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list, message);
                    break;

                case STRIKE_RATE_WITH_FOURS_SIXES:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByStrikeRateWithFourAndSix);
                    message = "\nPlayer with highest Strike rate along with Fours and Sixes \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list, message);   
                    break;

                case AVERAGE_WITH_STRIKE_RATE:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByAverageWithStrikeRate);
                    message = "\nPlayer with highest Average along with Strike rate \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list, message);   
                    break;   

                case RUNS_WITH_AVERAGE:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareRunsWithAverage);
                    message = "\nPlayer with highest Runs along with average \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list, message);   
                    break;  

                case ZERO_HUN_FIF:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareZeroHunFiftiesWithAverage);
                    message = "\nPlayer with Zero Hundreds and Fifties along with average \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list, message);   
                    break;

                case AVERAGE_BOWLER:
                    message = "\nBowler with highest average \n";
                    user_input_output.displayBowlerData(sorted_bowler_list, message); 
                    break;

                case STRIKE_RATE_BOWLER:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByStrikeRate);
                    message = "\nBowler with highest strike rate \n";
                    user_input_output.displayBowlerData(sorted_bowler_list, message); 
                    break;

                case ECONOMY_RATE:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByEconRate);
                    message = "\nBowler with highest economy rate \n";
                    user_input_output.displayBowlerData(sorted_bowler_list, message); 
                    break;

                case STRIKE_RATE_WITH_FOURS_FIVE_WKT:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByStrikeRateWithFourAndFiveWickets);
                    message = "\nBowler with highest strike rate and wickets\n";
                    user_input_output.displayBowlerData(sorted_bowler_list, message); 
                    break;

                case AVERAGE_WITH_STRIKE_RATE_BOWLER:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByStrikeRateAndAverageBowler);
                    message = "\nBowler with highest strike rate and average\n";
                    user_input_output.displayBowlerData(sorted_bowler_list, message); 
                    break;

                case AVERAGE_WITH_WICKET:
                    sorted_bowler_list = ipl_bowler_analyser.getSortedData(&compareByAverageAndWickets);
                    message = "\nBowler with highest strike rate and average\n";
                    user_input_output.displayBowlerData(sorted_bowler_list, message); 
                    break;    

                case BATIING_AND_BOWLING_AVG:
                    ipl_all_rounder.loadData(all_rounder_list);
                    all_rounder_list_2 = ipl_all_rounder.getSortedData(&compareByBattingBowlingAverage);
                    message = "\nPlayer with highest batting and bowling average\n";
                    user_input_output.displayAllRounderData(all_rounder_list, message);
                    break;

                case RUNS_WICKETS:
                    ipl_all_rounder.loadData(all_rounder_list);
                    all_rounder_list_2 = ipl_all_rounder.getSortedData(&compareByRunsAndWickets);
                    message = "\nPlayer with highest Runs and wickets\n";
                    user_input_output.displayAllRounderData(all_rounder_list_2, message);
                    break;

                case HUNDRED_AVERAGE:
                    sorted_batsman_list = ipl_batsman_analyser.getSortedData(&compareByHundredAndAverage);
                    message = "\nPlayer with highest average \n";
                    user_input_output.displayBatsmanData(sorted_batsman_list, message);
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
    IPLAnalyserController controller;
    controller.performTask();
}