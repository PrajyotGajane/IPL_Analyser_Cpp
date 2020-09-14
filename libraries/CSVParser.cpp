#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
class CSVParser
{
public:
    vector<T *> readDataFromFile(string filePath)
    {
        vector<T *> List;
        ifstream theFile;
        theFile.open(filePath, ios::in);
        string line;
        while (getline(theFile, line))
        {
            string column_value;
            T *t = new T();
            int index = 0;
            string *position = t->getPosition();
            stringstream ss(line);
            while (getline(ss, column_value, ','))
            {
                position[index++] = column_value;
            }
            List.emplace_back(t);
        }
        return List;
    }
};