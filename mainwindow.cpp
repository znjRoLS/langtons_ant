#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QtDebug>
#include <QRandomGenerator>
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Hello world!";


    pixels = new QRgb[sizeX*sizeY];
    for(int i = 0 ; i < sizeX*sizeY; i ++) pixels[i] = qRgb(0,0,0);
    image = new QImage((uchar*)pixels, sizeX, sizeY, QImage::Format_ARGB32);

    scene = ui->label;
    scene->_image = image;
    colors = {
        qRgb(0,0,0),
        qRgb(255,0,0),
        qRgb(0,255,0),
        qRgb(0,0,255),
        qRgb(127,0,0),
        qRgb(0,127,0),
        qRgb(0,0,127),
        qRgb(255,0,0),
        qRgb(255,0,255),
        qRgb(0,255,255),
        qRgb(255,255,255),
        qRgb(127,127,127),
    };

    this->setGeometry(0,0, sizeX, sizeY);

    qDebug() << scene->size();
    qDebug() << this->size();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(iter()));
    timer->start(freq);

    QTimer *timerrepaint = new QTimer(scene);
    connect(timerrepaint, SIGNAL(timeout()), scene, SLOT(repaint()));
    timerrepaint->start(freqRepaint);

    ant = new LangtonAntHexa("L1L2NUL2L1R2");

    //worker = new LangtonAntWorker(this, scale, sizeX, sizeY, ant, freq, pixmap, colors);
    //worker->start();
}

void MainWindow::iter() {
    if (iter_num++ % 100 == 0) {
        qDebug() << "Iter worker " << iter_num;
    }
    //QElapsedTimer timer;
    //timer.start();

    int x_offset = sizeX/2;
    int y_offset = sizeY/2;

    int x = 1, y= 1, color = 1;
    ant->Iterate(x,y,color);
    //qDebug() << timer.elapsed();

    x *= scale;
    y *= scale;
    x += x_offset;
    y += y_offset;

    //qDebug() << timer.elapsed();
    for (int xi = 0 ; xi < scale; xi ++) {
        for (int yi = 0 ; yi < scale; yi ++) {
            pixels[x+xi + (y+yi)*sizeX] = colors[color];
        }
    }

    //qDebug() << timer.elapsed()

}

void MainWindow::setRandomImage() {
    for (int i = 0 ; i < sizeX; i ++) {
        for (int j = 0 ; j < sizeY; j ++) {
//            uint r = QRandomGenerator::global()->bounded(255);
//            uint g = QRandomGenerator::global()->bounded(255);
//            uint b = QRandomGenerator::global()->bounded(255);
            uint v = QRandomGenerator::global()->bounded(16777215);
            //QRgb val = qRgb(r, g, b);

            image->setPixel(i,j, v);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
