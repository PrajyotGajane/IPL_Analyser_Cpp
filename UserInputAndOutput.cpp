#include "UserInputAndOutput.h"

using namespace std;

int UserInputAndOutput::selectField()
{
    int choice;
    cout << "\nSort" << endl;
    cout << "\n1: Average  2: Strike Rate  20: Exit"
         << endl;
    cout << "Your input : ";
    cin >> choice;
    cout << "\n========================================";
    return choice;
}

void UserInputAndOutput::displayData(vector<Batsman *> ipl_data)
{
    for (auto iterator = ipl_data.begin() + 1; iterator != ipl_data.begin() + 2; iterator++)
    {
        cout << "\n";
        (*iterator)->display();
    }
}