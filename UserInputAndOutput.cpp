#include "UserInputAndOutput.h"

using namespace std;

int UserInputAndOutput::selectField()
{
    int choice;
    cout << "\nSort" << endl;
    cout << "\n1: Average  2: Strike Rate  3: 4's and 6's";
    cout << "\n4: Strike Rate and 4's and 6's  5: Average with strike rate  6: Max Runs with Average";
    cout << "\n7: Bowlers Average  8: Bowlers Strike Rate   9: Bowlers Economy Rate";
    cout << "\n10: Bowlers Strike rate and 4 and 5 Wkts";
    cout << "\n11: Bowlers Striker rate and average";
    cout << "\n12: Bowlers Wickets and average";
    cout << "\n20:Exit"
         << endl;
    cout << "Your input : ";     
    cin >> choice;
    system("clear");
    cout << "\n================================================================================================";
    return choice;
}

void UserInputAndOutput::displayBatsmanData(vector<Batsman *> ipl_data)
{
    for (auto iterator = ipl_data.begin() + 1; iterator != ipl_data.begin() + 2; iterator++)
    {
        cout << "\n";
        (*iterator)->display();
        cout << "\n================================================================================================";
    }
}

void UserInputAndOutput::displayBowlerData(vector<Bowler *> ipl_data)
{
    for (auto iterator = ipl_data.begin() + 1; iterator != ipl_data.begin() + 2; iterator++)
    {
        cout << "\n";
        (*iterator)->display();
        cout << "\n================================================================================================";
    }
}