#include "Bowler.h"

string *Bowler::getPosition()
{
    return &this->POS;
}

double Bowler::getAverage()
{
    return stringTODouble(this->average);
}

double Bowler::getStrikeRate()
{
    return stringTODouble(this->strike_rate);
}

double Bowler::getEconRate()
{
    return stringTODouble(this->Econ);
}

int Bowler::getFourWickets()
{
    return stringToInteger(this->four_wickets);
}

int Bowler::getFiveWickets()
{
    return stringToInteger(this->five_wickets);
}

int Bowler::getFourAndFiveWickets()
{
    return getFourWickets() + getFiveWickets();
}

int Bowler::getWickets()
{
    return stringToInteger(this->wickets);
}

void Bowler::display()
{
    cout << "Name : " << this->player << "\t";
    cout << "   Average : " << this->average << "\t";
    cout << "   Strike Rate: " << this->strike_rate << "\t";
    cout << "   Economy : " << this->Econ << "\t";
    cout << "   4 Wkts: " << this->four_wickets << "\t";
    cout << "   5 Wkts: " << this->five_wickets << "\t";
    cout << "   Total Wickets : " << this->wickets << "\n";
}

double Bowler::stringTODouble(string value_to_convert)
{
    std::stringstream ss;
    ss << value_to_convert;
    double convert_to_double = 0.0;
    ss >> convert_to_double;
    return convert_to_double;
}

string Bowler::getPlayer(){
    return this->player;
}

int Bowler::stringToInteger(string value_to_convert)
{
    std::stringstream ss;
    ss << value_to_convert;
    double convert_to_int = 0;
    ss >> convert_to_int;
    return convert_to_int;
}