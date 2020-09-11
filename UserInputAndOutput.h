#pragma once
#include <iostream>
#include <vector>
#include "Batsman.h"
#include "Bowler.h"

class UserInputAndOutput
{
public:
    int selectField();
    void displayBatsmanData(vector<Batsman *>);
    void displayBowlerData(vector<Bowler *>);
};