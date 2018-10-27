#include "langtonant.h"

LangtonAnt::LangtonAnt(vector<bool> program):
    _colors(program.size()),
    _program(program),
    _x(0),
    _y(0),
    _dir(DIR::UP)
{

}

LangtonAnt::LangtonAnt(string program):
    _colors(program.size()),
    _program(program.size()),
    _x(0),
    _y(0),
    _dir(DIR::UP)
{
    for (int i = 0 ; i < program.size(); i ++) {
        char c = program[i];
        if (c == 'R') _program[i] = true;
        else if (c == 'L') _program[i] = false;
    }
}

void LangtonAnt::Iterate(int& x, int& y, int& color) {
    x = _x;
    y = _y;
    _table[{_x,_y}] = (_table[{_x,_y}] + 1) % _colors;
    color = _table[{_x, _y}];

    switch (_dir) {
        case UP: _y ++; break;
        case LEFT: _x --; break;
        case DOWN: _y--; break;
        case RIGHT: _x++; break;
    }

    if (_program[_table[{_x, _y}]]) {
        switch (_dir) {
            case UP: _dir = RIGHT; break;
        case LEFT: _dir = UP; break;
        case DOWN: _dir = LEFT; break;
        case RIGHT: _dir = DOWN; break;
        }
    } else {
        switch (_dir) {
            case UP: _dir = LEFT; break;
        case LEFT: _dir = DOWN; break;
        case DOWN: _dir = RIGHT; break;
        case RIGHT: _dir = UP; break;
        }
    }
}
