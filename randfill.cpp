#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define DAY 5
#define PERIOD 6

class RoutineItem
{
public:
    RoutineItem() : mCode(""), mCredit(0) {}
    RoutineItem(string code, int credit)
    {
        mCode = code;
        mCredit = credit;
    }

    RoutineItem(const RoutineItem &another)
    {
        mCode = another.mCode;
        mCredit= another.mCredit;
    }

    const string& getCode() { return mCode; }
    const int& getCredit() { return mCredit; }

private:
    string mCode;
    //string mTitle;
    int mCredit;
};

class Routine
{
    typedef struct
    {
        int day;
        int period;
    } pos;

    vector<RoutineItem> data;
    vector<vector<RoutineItem>> routine;

public:

    Routine() : routine(DAY, vector<RoutineItem>(PERIOD, RoutineItem()))
    {
        data.push_back(RoutineItem("CSE3101", 3));
        data.push_back(RoutineItem("CSE3102", 1));
        data.push_back(RoutineItem("CSE3103", 3));
        data.push_back(RoutineItem("CSE3104", 1));
        data.push_back(RoutineItem("CSE3105", 3));
        data.push_back(RoutineItem("CSE3107", 3));
        data.push_back(RoutineItem("CSE3109", 3));
        data.push_back(RoutineItem("CSE3110", 1));
        data.push_back(RoutineItem("CSE3112", 1));
        data.push_back(RoutineItem("CSE3111", 4));

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

        labs.clear();

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

    void print_routine()
    {
        for(int d=0; d<DAY; d++)
        {
            for(uint p=0; p<routine[d].size(); p++)
            {
                printf("%d%d %7s ", d, p, routine[d][p].getCode().c_str());
                //cout << d << p << " " << routine[d][p].getCode() << " ";
            }

            cout << endl;
        }
    }

    void shuffle()
    {
        for(int d=0; d<DAY; d++)
        {
            random_shuffle(routine[d].begin(), routine[d].begin()+3);
            random_shuffle(routine[d].begin()+4, routine[d].begin()+6);
        }

        random_shuffle(routine.begin(), routine.end());
    }
};

int main()
{
    Routine r;
    r.shuffle();
    r.print_routine();

    r.shuffle();
    r.print_routine();

    return 0;
}
