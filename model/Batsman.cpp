#include "Batsman.h"

//POS,PLAYER,Mat,Inns,NO,Runs,HS,Avg,BF,SR,100,50,4s,6s

double Batsman::getAverage()
{
    return stringTODouble(this->average);
}

void Batsman::display()
{
    cout << "Name : " << this->player << "\t";
    cout << "   Average : " << this->average << "\t";
    cout << "   Strike Rate : " << this->SR << "\t";
    cout << "   4's : " << this->fours << "\t";
    cout << "   6's : " << this->sixes << "\t";
    cout << "   Runs : " << this->runs << "\n";
}

string *Batsman::getPosition()
{
    return &this->POS;
}

string Batsman::getPlayer()
{
    return this->player;
}

double Batsman::getStrikeRate()
{
    return stringTODouble(this->SR);
}

int Batsman::getFours()
{
    return stringToInteger(this->fours);
}

int Batsman::getHundreds()
{
    return stringToInteger(this->hundreds);
}

int Batsman::getSixes()
{
    return stringToInteger(this->sixes);
}

double Batsman::getHundredsAndWicket()
{
    return getHundreds() * getAverage();
}

int Batsman::getFoursAndSixes()
{
    return getFours() + getSixes();
}

int Batsman::getRuns()
{
    return stringToInteger(this->runs);
}

double Batsman::stringTODouble(string value_to_convert)
{
    std::stringstream ss;
    ss << value_to_convert;
    double convert_to_double = 0.0;
    ss >> convert_to_double;
    return convert_to_double;
}

int Batsman::getFifties()
{
    return stringToInteger(this->fifties);
}

int Batsman::stringToInteger(string value_to_convert)
{
    std::stringstream ss;
    ss << value_to_convert;
    double convert_to_int = 0;
    ss >> convert_to_int;
    return convert_to_int;
}
