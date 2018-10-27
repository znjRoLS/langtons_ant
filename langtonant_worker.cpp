#include "langtonant_worker.h"
#include <QDebug>
#include <QElapsedTimer>

LangtonAntWorker::LangtonAntWorker(QWidget *parent, int scale, int sizeX, int sizeY, LangtonAnt *ant, int freq, QPixmap *pixmap, vector<QRgb> colors):
    _ant(ant),
    _freq(freq),
    _pixmap(pixmap),
    _colors(colors),
    _sizeX(sizeX),
    _sizeY(sizeY),
    _scale(scale),
    _painter(new QPainter(_pixmap)),
    QThread(parent)
{

}

void LangtonAntWorker::run() {

    while(true) {
        qDebug() << "Iter worker " << iter_num++;

        //QElapsedTimer timer;
        //timer.start();

        int x_offset = _sizeX/2;
        int y_offset = _sizeY/2;

        int x = 1, y= 1, color = 1;
        _ant->Iterate(x,y,color);
        //qDebug() << timer.elapsed();

        x *= _scale;
        y *= _scale;
        x += x_offset;
        y += y_offset;

        //qDebug() << timer.elapsed();
        _painter->setBrush(QColor(_colors[color]));
        _painter->drawRect(x,y, _scale, _scale);
        //qDebug() << timer.elapsed()

        usleep(_freq);
    }

}
