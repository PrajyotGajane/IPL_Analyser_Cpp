#include "UserInputAndOutput.h"
using namespace std;

int UserInputAndOutput::selectField()
{
    int choice;
    cout << "\nSort" << endl;
    cout << "\n1: Average";  
    cout << "\n2: Strike Rate";
    cout << "\n3: 4's and 6's";
    cout << "\n4: Strike Rate and 4's and 6's";  
    cout << "\n5: Average with strike rate";
    cout << "\n6: Max Runs with Average";
    cout << "\n7: Bowlers Average";  
    cout << "\n8: Bowlers Strike Rate";
    cout << "\n9: Bowlers Economy Rate";
    cout << "\n10: Bowlers Strike rate and 4 and 5 Wkts";
    cout << "\n11: Bowlers Striker rate and average";
    cout << "\n12: Bowlers Wickets and average";
    cout << "\n13: Player Batting and Bowling average";
    cout << "\n14: Player Runs and Wickets average";
    cout << "\n15: Player Hundred's and Batting average";
    cout << "\n16: Player Zero Hundred's / Fifties but best batting average";
    cout << "\n20:Exit"
         << endl;
    cout << "Your input : ";     
    cin >> choice;
    system("clear");
    cout << "\n================================================================================================";
    return choice;
}

void UserInputAndOutput::displayBatsmanData(vector<Batsman *> ipl_data, string message)
{
    cout << message;
    for (auto iterator = ipl_data.begin() + 1; iterator != ipl_data.begin() + 2; iterator++)
    {
        cout << "\n";
        (*iterator)->display();
        cout << "\n================================================================================================";
    }
}

void UserInputAndOutput::displayBowlerData(vector<Bowler *> ipl_data, string message)
{
    cout << message;
    for (auto iterator = ipl_data.begin() + 1; iterator != ipl_data.begin() + 2; iterator++)
    {
        cout << "\n";
        (*iterator)->display();
        cout << "\n================================================================================================";
    }
}

void UserInputAndOutput::displayAllRounderData(vector<AllRounder *> ipl_data, string message)
{
    cout << message;
    for (auto iterator = ipl_data.begin() + 1; iterator != ipl_data.begin() + 2; iterator++)
    {
        cout << "\n";
        (*iterator)->display();
        cout << "\n================================================================================================";
    }
}

void UserInputAndOutput::displayWelcomeMessage()
{
    system("clear");
    cout << "Welcome to IPL Analyser"
         << "\n";
}