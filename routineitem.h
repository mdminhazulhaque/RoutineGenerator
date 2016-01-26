#ifndef ROUTINEITEM_H
#define ROUTINEITEM_H

#include <string>
#include <QColor>
#include <random>

using namespace std;

class RoutineItem
{
public:
    RoutineItem(string code = "", int credit = 0);
    RoutineItem(const RoutineItem &another);

    const string& getCode() { return mCode; }
    const int& getCredit() { return mCredit; }
    const QColor& getColor() { return mColor; }

private:
    string mCode;
    //string mTitle;
    int mCredit;
    QColor mColor;
};

#endif // ROUTINEITEM_H
