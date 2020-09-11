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
    double getAverage();
    void display();
    double getStrikeRate();
    double stringTODouble(string);
};