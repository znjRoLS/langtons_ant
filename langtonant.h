#pragma once

#include <vector>
#include <unordered_map>
#include <string>

using std::unordered_map;
using std::vector;
using std::pair;
using std::string;


namespace std {
template<>
struct hash<std::pair<int, int>> {
  inline size_t operator()(const std::pair<int, int> &v) const {
    std::hash<int> int_hasher;
    return int_hasher(v.first) ^ int_hasher(v.second);
  }
};
}


class LangtonAnt
{
public:
    LangtonAnt(int colors, vector<bool> program);
    LangtonAnt(int colors, string program);

    void Iterate(int &x, int &y, int& color);

private:
    enum DIR {
        UP,
        LEFT,
        DOWN,
        RIGHT,
    };

    int _colors;
    vector<bool> _program;
    unordered_map<pair<int,int>,int> _table;

    int _x;
    int _y;
    DIR _dir;
};
