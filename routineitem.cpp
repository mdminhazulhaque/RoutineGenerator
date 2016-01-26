#include "routineitem.h"

RoutineItem::RoutineItem(string code, int credit)
{
    mCode = code;
    mCredit = credit;
    mColor = QColor::fromRgb(
                qrand()%255,
                qrand()%255,
                qrand()%255
                );
}

RoutineItem::RoutineItem(const RoutineItem &another)
{
    mCode = another.mCode;
    mCredit= another.mCredit;
    mColor = another.mColor;
}
