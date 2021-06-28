#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
class DataManager
{
public:
    static int giveTodayData();
    static int insertData();
    static void changeDateFormat(int date);
    static int showCurrentMonth();
    static int showPreviousMonth();
    static int selectedDate();
    static string convertToFile(int date);
    static int convertToVector(string stringDate);

};
#endif
