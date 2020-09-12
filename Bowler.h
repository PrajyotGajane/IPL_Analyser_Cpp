#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// POS,PLAYER,Mat,Inns,Ov,Runs,Wkts,BBI,Avg,Econ,SR,4w,5w
class Bowler
{
    string POS;
    string player;
    string matches;
    string innings;
    string overs;
    string runs;
    string wickets;
    string BBI;
    string average;
    string Econ;
    string strike_rate;
    string four_wickets;
    string five_wickets;

public:
    string *getPosition();
    string getPlayer();
    double getAverage();
    void display();
    int getFourWickets();
    int getFiveWickets();
    int getFourAndFiveWickets();
    double getStrikeRate();
    double stringTODouble(string);
    double getEconRate();
    int getWickets();
    double getStrikeRateAndFoursFives();
    int stringToInteger(string);
};
