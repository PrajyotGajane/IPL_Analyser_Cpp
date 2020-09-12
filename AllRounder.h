
#pragma once
#include <iostream>
#include "Batsman.h"
#include "Bowler.h"

using namespace std;

class AllRounder
{
    string player_name;
    double battingAverage, bowlingAverage;
    int runs, wickets;

public:
    AllRounder(Batsman *batsman, Bowler *bowler)
    {
        this->player_name = batsman->getPlayer();
        this->battingAverage = batsman->getAverage();
        this->bowlingAverage = bowler->getAverage();
        this->runs = batsman->getRuns();
        this->wickets = bowler->getWickets();
    }
    void display()
    {
        cout << "Name : " << this->player_name << "\t";
        cout << "   Batting Average : " << this->battingAverage << "\t";
        cout << "   Bowling Average : " << this->bowlingAverage << "\t";
        cout << "   Runs : " << this->runs << "\t";
        cout << "   Wickets : " << this->wickets << "\t";
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

    int getRuns()
    {
        return this->runs;
    }

    int getWickets()
    {
        return this->wickets;
    }
};