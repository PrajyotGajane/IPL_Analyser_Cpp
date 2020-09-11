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
    double getAverage();
    void display();
};
