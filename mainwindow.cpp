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

    //image = new QImage(sizeX, sizeY, QImage::Format_RGB32);
    //scene->addPixmap(QPixmap::fromImage(*image));
    //ui->graphicsView->setScene(scene);
    //ui->graphicsView->setSceneRect(image->rect());

    pixmap = new QPixmap(sizeX, sizeY);
    scene = ui->label;
    //scene->setGeometry(0,0,sizeX, sizeY);
    painter = new QPainter(pixmap);
    //scene->SetPixmap(*pixmap);
    scene->_pixmap = pixmap;
    colors = {qRgb(0,0,0), qRgb(255,255,255)};

    this->setGeometry(0,0, sizeX, sizeY);

    qDebug() << scene->size();
    qDebug() << this->size();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(iter()));
    timer->start(freq);


    QTimer *timerrepaint = new QTimer(scene);
    connect(timerrepaint, SIGNAL(timeout()), scene, SLOT(repaint()));
    timerrepaint->start(freqRepaint);

    ant = new LangtonAnt(2, vector<bool>{true, false});

    for (int i = 0 ; i < sizeX; i ++) {
        for (int j = 0 ; j < sizeY; j ++) {
            //image->setPixel(i,j, 0);
            painter->setBrush(QColor(colors[0]));
            painter->drawPoint(i,j);
        }
    }
}

void MainWindow::iter() {
    qDebug() << "Iter " << iter_num++;

    QElapsedTimer timer;
    timer.start();

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
    painter->setBrush(QColor(colors[color]));
    painter->drawRect(x,y, scale, scale);
    //qDebug() << timer.elapsed();
//    if (iter_num % 100 == 0) {
//        scene->setPixmap(*pixmap);
//    }

    //scene->repaint();

    //qDebug() << timer.elapsed();

//    for (int xi = 0; xi < scale; xi ++) {
//        for (int yi = 0; yi < scale; yi ++) {
//            //image->setPixel(x+xi, y+yi, colors[color]);
//        }
//    }

    //image->setPixel(x, y, colors[color]);

    //scene->removeItem(scene->items().at(0));
    //scene->addPixmap(QPixmap::fromImage(*image));
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
