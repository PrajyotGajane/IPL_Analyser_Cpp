#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//POS,PLAYER,Mat,Inns,NO,Runs,HS,Avg,BF,SR,100,50,4s,6s
class Batsman
{
    string POS;
    string player;
    string matches;
    string innings;
    string NO;
    string runs;
    string high_score;
    string average;
    string balls_faced;
    string SR;
    string hundreds;
    string fifties;
    string fours;
    string sixes;

public:
    string *getPosition();
    string getPlayer();
    double getAverage();
    void display();
    double stringTODouble(string);
    int stringToInteger(string);
    int getFours();
    int getSixes();
    int getHundreds();
    double getStrikeRate();
    double getHundredsAndWicket();
    int getFoursAndSixes();
    int getFifties();
    int getRuns();
};
