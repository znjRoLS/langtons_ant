#include "langtonanthexa.h"

#include <QDebug>

LangtonAntHexa::LangtonAntHexa(string program):
    _colors(program.size()),
    _program(program.size()),
    _x(0),
    _y(0),
    _dir(DIR::UPLEFT)
{
    for (int i = 0 ; i < program.size(); i ++) {
        if (program[i] == 'N') {
            _program[i] = N;
        } else if (program[i] == 'U') {
            _program[i] = U;
        } else {
            string c = program.substr(i,2);
            if (c == "R1") _program[i] = R1;
            else if (c == "R2") _program[i] = R2;
            else if (c == "L1") _program[i] = L1;
            else if (c == "L2") _program[i] = L2;
            i++;
        }

    }

}

void LangtonAntHexa::Iterate(int& x, int& y, int& color) {
    x = _x;
    y = _y;
    _table[{_x,_y}] = (_table[{_x,_y}] + 1) % _colors;
    color = _table[{_x, _y}];

    switch (_dir) {
        case UPLEFT: _y ++; _x--; break;
    case LEFT: _x --; _x --; break;
    case DOWNLEFT: _y--; _x --; break;
    case DOWNRIGHT: _y--; _x ++; break;
    case RIGHT: _x++; _x ++; break;
    case UPRIGHT: _y++; _x ++; break;
    }

    int cur_color = _table[{_x, _y}];

    //qDebug() << _dir << " " << cur_color << " " << _program[cur_color] << " " << _dir + _program[cur_color];
    int dir = _dir;
    dir += _program[cur_color];
    dir %= 6;
    _dir = (DIR)dir;
}
