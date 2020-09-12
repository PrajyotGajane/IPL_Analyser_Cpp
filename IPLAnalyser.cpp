#include <iostream>
#include <vector>
#include "IPLAdaptorFactory.cpp"
#include <algorithm>
#include "ALLRounder.h"

using namespace std;

template <class T>
class IPLAnalyser
{
private:
    vector<T *> ipl_data;

public:
    void loadIPLData(string csv_file_path)
    {
        IPLAdaptorFactory<T> adaptor;
        ipl_data = adaptor.getIPLList(csv_file_path);
    }

    vector<T *> getSortedData(bool (*sortFunc)(T *, T *))
    {
        vector<T *> sorted_list = ipl_data;
        sort(sorted_list.begin() + 1, sorted_list.end(), sortFunc);
        return sorted_list;
    }

    void loadAllRouderData(vector<AllRounder *> data) {
        ipl_data = data;
    }

    vector<AllRounder *> getSortedDataR(bool (*sortFunc)(AllRounder *, AllRounder *))
    {
        vector<AllRounder *> sorted_list = ipl_data;
        sort(sorted_list.begin() + 1, sorted_list.end(), sortFunc);
        return sorted_list;
    }
};