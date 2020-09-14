#include <string>
#include <vector>
#include "../libraries/CSVParser.cpp"
#include "Batsman.h"
#include "Bowler.h"

using namespace std;
template <class T>
class IPLAdaptorFactory
{
private:
    vector<T *> ipl_csv_data;

public:
    vector<T *> getIPLList(string file_path)
    {
        if (file_path == "C:/Users/Home/Desktop/Visual Studio Projects/IPL_Analyser_Cpp/resources/MostRuns.csv")
        {
            CSVParser<T> csv_parser_obj;
            ipl_csv_data = csv_parser_obj.readDataFromFile(file_path);
        }
        else if ( file_path == "C:/Users/Home/Desktop/Visual Studio Projects/IPL_Analyser_Cpp/resources/MostWkts.csv")
        {
            CSVParser<T> csv_parser_obj;
            ipl_csv_data = csv_parser_obj.readDataFromFile(file_path);
        }
        return ipl_csv_data;
    }
};
