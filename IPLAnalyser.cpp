#include <iostream>
#include <vector>
#include "Batsman.h"
#include "CSVParser.cpp"
#include <algorithm>
using namespace std;

class IPLAnalyser
{
private:
    vector<Batsman *> ipl_batsman_data;

public:
    void loadIPLData(string csv_file_path)
    {
        CSVParser<Batsman> csv_parser_obj;
        ipl_batsman_data = csv_parser_obj.readDataFromFile(csv_file_path);
    }

    vector<Batsman *> getSortedData(bool (*sortFunc)(Batsman *, Batsman *))
    {
        vector<Batsman *> sorted_list = ipl_batsman_data;
        sort(sorted_list.begin() + 1, sorted_list.end(), sortFunc);
        return sorted_list;
    }
};