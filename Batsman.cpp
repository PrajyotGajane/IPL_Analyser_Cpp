#include "Batsman.h"

//POS,PLAYER,Mat,Inns,NO,Runs,HS,Avg,BF,SR,100,50,4s,6s

double Batsman::getAverage()
{
    std::stringstream ss;
    ss << this->average;

    double value = 0.0;
    ss >> value;
    return value;
}

void Batsman::display()
{
    cout << "Name : " << this->player << "\t";
    cout << "   Average : " << this->average << "\n";
}

string *Batsman::getPosition()
{
    return &this->POS;
}
