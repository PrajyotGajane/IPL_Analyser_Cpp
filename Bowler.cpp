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

void Bowler::display()
{
    cout << "Name : " << this->player << "\t";
    cout << "   Average : " << this->average << "\n";
}

double Bowler::stringTODouble(string value_to_convert)
{
    std::stringstream ss;
    ss << value_to_convert;
    double convert_to_double = 0.0;
    ss >> convert_to_double;
    return convert_to_double;
}