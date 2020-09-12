
#pragma once
#include <iostream>
#include "Batsman.h"
#include "Bowler.h"

using namespace std;

class AllRounder
{
    string player_name;
    double battingAverage, bowlingAverage;

public:
    AllRounder(Batsman *batsman, Bowler *bowler)
    {
        this->player_name = batsman->getPlayer();
        this->battingAverage = batsman->getAverage();
        this->bowlingAverage = bowler->getAverage();
    }
    void display()
    {
        cout << "Name : " << this->player_name << "\t";
        cout << "   Batting Average : " << this->battingAverage << "\t";
        cout << "   Bowling Average : " << this->bowlingAverage << "\t";
        cout << "\n";
    }

    double getBattingAverage()
    {
        return this->battingAverage;
    }

    double getBallingAverage()
    {
        return this->bowlingAverage;
    }
};