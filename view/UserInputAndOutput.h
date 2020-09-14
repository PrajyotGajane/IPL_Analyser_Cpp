#pragma once
#include <iostream>
#include <vector>
#include "../model/Batsman.h"
#include "../model/Bowler.h"
#include "../model/AllRounder.h"

class UserInputAndOutput
{
public:
    int selectField();
    void displayBatsmanData(vector<Batsman *>, string message);
    void displayBowlerData(vector<Bowler *>, string message);
    void displayAllRounderData(vector<AllRounder *>, string message);
    void displayWelcomeMessage();
};