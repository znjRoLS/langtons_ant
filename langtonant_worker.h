#pragma once

#include <QThread>
#include "langtonant.h"
#include <vector>
#include <QRgb>
#include <QPainter>
#include <QWidget>

using std::vector;

class LangtonAntWorker : public QThread
{
    Q_OBJECT
public:
    LangtonAntWorker(QWidget *parent, int scale, int sizeX, int sizeY, LangtonAnt *ant, int freq, QPixmap *pixmap, vector<QRgb> colors);

    void run() override;

private:
    LangtonAnt *_ant;
    int _freq;
    QPixmap *_pixmap;
    vector<QRgb> _colors;
    int iter_num = 0;
    int _sizeX;
    int _sizeY;
    int _scale;
    QPainter *_painter;
};
