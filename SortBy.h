#pragma once
#include "Batsman.h"

using namespace std;

bool compareByAverage(Batsman *avg1, Batsman *avg2)
{
    return avg1->getAverage() > avg2->getAverage();
}
