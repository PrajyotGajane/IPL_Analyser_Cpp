#include "UserInputAndOutput.h"

using namespace std;

int UserInputAndOutput::selectField()
{
    int choice;
    cout << "\nSort" << endl;
    cout << "\n1: Average\n"
         << endl;
    cout << "Your input : ";
    cin >> choice;
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