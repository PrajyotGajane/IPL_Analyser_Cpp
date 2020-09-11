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
    cout << "   Strike Rate : " << this->SR << "\n";
}

string *Batsman::getPosition()
{
    return &this->POS;
}

double Batsman::getStrikeRate() {
    return stringTODouble(this->SR);
}

double Batsman::stringTODouble(string value_to_convert) {
    std::stringstream ss;
    ss << value_to_convert;
    double convert_to_double = 0.0;
    ss >> convert_to_double;
    return convert_to_double;
}
