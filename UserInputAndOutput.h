#pragma once
#include <iostream>
#include <vector>
#include "Batsman.h"
#include "Bowler.h"
#include "AllRounder.h"

class UserInputAndOutput
{
public:
    int selectField();
    void displayBatsmanData(vector<Batsman *>, string message);
    void displayBowlerData(vector<Bowler *>, string message);
    void displayAllRounderData(vector<AllRounder *>, string message);
    void displayWelcomeMessage();
};