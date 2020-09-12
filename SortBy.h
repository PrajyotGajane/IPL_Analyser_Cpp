#pragma once
#include "Batsman.h"
#include "Bowler.h"

using namespace std;

bool compareByAverage(Batsman *avg1, Batsman *avg2)
{
    return avg1->getAverage() > avg2->getAverage();
}

template <class T>
bool compareByStrikeRate(T *strike_rate_1, T *strike_rate_2)
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

bool compareByAverageWithStrikeRate(Batsman *sr_with_avg_1, Batsman *sr_with_avg_2)
{
    return (sr_with_avg_1->getAverage() > sr_with_avg_2->getAverage()) && (sr_with_avg_1->getStrikeRate() > sr_with_avg_2->getStrikeRate());
}

bool compareRunsWithAverage(Batsman *runs_with_avg_1, Batsman *runs_with_avg_2)
{
    return (runs_with_avg_1->getRuns() > runs_with_avg_2->getRuns()) && (runs_with_avg_1->getAverage() > runs_with_avg_2->getAverage());
}

bool compareBowlerByAverage(Bowler *avg_1, Bowler *avg_2)
{
    return avg_1->getAverage() > avg_2->getAverage();
}

bool compareByEconRate(Bowler *econ_1, Bowler *econ_2)
{
    return econ_1->getEconRate() > econ_2->getEconRate();
}

bool compareByStrikeRateWithFourAndFiveWickets(Bowler *sr_four_five_1, Bowler *sr_four_five_2)
{
    return (sr_four_five_1->getFourAndFiveWickets() > sr_four_five_2->getFourAndFiveWickets()) && (sr_four_five_1->getStrikeRate() < sr_four_five_2->getStrikeRate());
}

bool compareByStrikeRateAndAverageBowler(Bowler *sr_avg_1, Bowler *sr_avg_2)
{
    return (sr_avg_1->getAverage() > sr_avg_2->getAverage()) && (sr_avg_1->getStrikeRate() > sr_avg_2->getStrikeRate());
}

bool compareByAverageAndWickets(Bowler *avg_wkts_1, Bowler *avg_wkts_2)
{
    return (avg_wkts_1->getAverage() > avg_wkts_2->getAverage()) && (avg_wkts_1->getWickets() > avg_wkts_2->getWickets());
}

bool compareByBattingBowlingAverage(AllRounder *bat_ball_avg_1, AllRounder *bat_ball_avg_2)
{
    return (bat_ball_avg_1->getBallingAverage() > bat_ball_avg_2->getBallingAverage()) && (bat_ball_avg_1->getBattingAverage() > bat_ball_avg_2->getBattingAverage());
}