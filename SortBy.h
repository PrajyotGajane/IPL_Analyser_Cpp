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

bool compareByFoursAndSixes(Batsman *four_and_sixes_1, Batsman *four_and_sixes_2)
{
    return four_and_sixes_1->getFoursAndSixes() > four_and_sixes_2->getFoursAndSixes();
}

bool compareByStrikeRateWithFourAndSix(Batsman *sr_fours_sixes_1, Batsman *sr_fours_sixes_2) 
{ 
    return (sr_fours_sixes_1->getFoursAndSixes() > sr_fours_sixes_2->getFoursAndSixes()) && (sr_fours_sixes_1->getStrikeRate() > sr_fours_sixes_2->getStrikeRate());
}
