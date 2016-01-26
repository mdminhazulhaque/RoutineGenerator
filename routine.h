#ifndef ROUTINE_H
#define ROUTINE_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QVariantMap>
#include <QDebug>

#include <map>
#include <vector>
#include <algorithm>

#include "routineitem.h"

#define DAY 5
#define PERIOD 6

using namespace std;

class Routine
{
public:
    Routine();
    void generate();
    void shuffleDays();
    void shufflePeriods();

    vector<vector<RoutineItem>> routine;

private:
    typedef struct
    {
        int day;
        int period;
    } pos;

    vector<RoutineItem> data;
};

#endif // ROUTINE_H
