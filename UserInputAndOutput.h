#pragma once
#include <iostream>
#include <vector>
#include "Batsman.h"

class UserInputAndOutput
{
public:
    int selectField();
    void displayData(vector<Batsman *>);
};