#include "routine.h"

Routine::Routine()
{
    //QFile jsonFile("../RoutineGenerator/data/3.json");
    QFile jsonFile("/media/data/dev/qt/RoutineGenerator/data/3.json");
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonFile.readAll());
    jsonFile.close();

    QVariantList vl = jsonDoc.array().toVariantList();

    for(int i=0; i<vl.size(); i++)
    {
        QVariantMap map = vl.at(i).toMap();
        data.push_back(RoutineItem(
                           map["code"].toString().toStdString(),
                       (int)map["credit"].toDouble()
                ));
    }
}

void Routine::generate()
{
    routine.clear();
    routine = vector<vector<RoutineItem>>(DAY, vector<RoutineItem>(PERIOD, RoutineItem()));

    vector<pos> labs = {
        {0, 0},
        {0, 3},
        {1, 0},
        {1, 3},
        {2, 0},
        {2, 3},
        {3, 0},
        {3, 3},
        {4, 0},
        {4, 3}
    };

    random_shuffle(labs.begin(), labs.end());

    for(auto it = data.begin(); it != data.end(); it++)
    {
        int credit = it->getCredit();

        if(credit < 2)
        {
            pos t = labs.back();
            routine[t.day][t.period] = *it;
            routine[t.day][t.period+1] = *it;
            routine[t.day][t.period+2] = *it;
            labs.pop_back();
        }
    }

    pos p = {0, 0};

    for(auto it = data.begin(); it != data.end(); it++)
    {
        int credit = it->getCredit();

        if(credit >= 2)
        {
            while(credit > 1)
            {
                if(routine[p.day][p.period].getCode() == "")
                {
                    routine[p.day][p.period] = *it;
                    credit--;
                    p.day++;
                }
                else
                {
                    p.period++;
                }

                if(p.day == DAY)
                    p.day = 0;

                if(p.period == PERIOD)
                    p.period = 0;
            }
        }
    }
}

void Routine::shuffleDays()
{
    random_shuffle(routine.begin(), routine.end());
}

void Routine::shufflePeriods()
{
    for(int d=0; d<DAY; d++)
    {
        random_shuffle(routine[d].begin(), routine[d].begin()+3);
        random_shuffle(routine[d].begin()+4, routine[d].begin()+6);
    }
}
