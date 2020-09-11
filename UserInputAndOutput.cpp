#include "UserInputAndOutput.h"

using namespace std;

int UserInputAndOutput::selectField()
{
    int choice;
    cout << "\nSort" << endl;
    cout << "\n1: Average  2: Strike Rate  3: 4's and 6's  \n4: Strike Rate and 4's and 6's  5: Average with strike rate  6: Max Runs with Average   20: Exit"
         << endl;
    cout << "Your input : ";     
    cin >> choice;
    cout << "\n================================================================================================";
    return choice;
}

void UserInputAndOutput::displayData(vector<Batsman *> ipl_data)
{
    for (auto iterator = ipl_data.begin() + 1; iterator != ipl_data.begin() + 2; iterator++)
    {
        cout << "\n";
        (*iterator)->display();
        cout << "\n================================================================================================";
    }
}