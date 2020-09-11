#pragma once
#include "Batsman.h"

using namespace std;

bool compareByAverage(Batsman *avg1, Batsman *avg2)
{
    return avg1->getAverage() > avg2->getAverage();
}

bool compareByStrikeRate(Batsman *strike_rate_1, Batsman *strike_rate_2) 
{ 
    return strike_rate_1->getStrikeRate() > strike_rate_2->getStrikeRate();
}
