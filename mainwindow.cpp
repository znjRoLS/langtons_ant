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

    pixmap = new QPixmap(sizeX, sizeY);
    scene = ui->label;
    scene->_pixmap = pixmap;
    colors = {qRgb(0,0,0), qRgb(255,0,0), qRgb(0,255,0), qRgb(0,0,255), qRgb(255,0,0), qRgb(255,0,255), qRgb(0,255,255), qRgb(255,255,255), qRgb(127,127,127)};

    this->setGeometry(0,0, sizeX, sizeY);

    qDebug() << scene->size();
    qDebug() << this->size();

//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(iter()));
//    timer->start(freq);

    QTimer *timerrepaint = new QTimer(scene);
    connect(timerrepaint, SIGNAL(timeout()), scene, SLOT(repaint()));
    timerrepaint->start(freqRepaint);

    ant = new LangtonAnt(9, "LRRRRRLLR");

    worker = new LangtonAntWorker(this, scale, sizeX, sizeY, ant, freq, pixmap, colors);
    worker->start();
}

void MainWindow::iter() {

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
