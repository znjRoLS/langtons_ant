#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <QThread>
#include "langtonant.h"

using std::unordered_map;
using std::vector;
using std::pair;
using std::string;


class LangtonAntHexa
{
public:
    LangtonAntHexa(string program);

    void Iterate(int &x, int &y, int& color);

private:
    enum DIR {
        UPLEFT,
        LEFT,
        DOWNLEFT,
        DOWNRIGHT,
        RIGHT,
        UPRIGHT,
    };

    enum MOVE {
        N,
        L1,
        L2,
        U,
        R2,
        R1,
    };

    int _colors;
    vector<MOVE> _program;
    unordered_map<pair<int,int>,int> _table;

    int _x;
    int _y;
    DIR _dir;
};
