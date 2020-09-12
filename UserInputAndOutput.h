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
    void displayBatsmanData(vector<Batsman *>);
    void displayBowlerData(vector<Bowler *>);
    void displayAllRounderData(vector<AllRounder *>);
};