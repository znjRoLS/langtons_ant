#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "qpixmapdrawer.h"
#include <QPainter>
#include "langtonant.h"
#include "langtonanthexa.h"
#include "langtonant_worker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void iter();

private:
    int sizeX = 400;
    int sizeY = 400;
    // microseconds for thread
    // milisecond for timer
    int freq = 1;
    // miliseconds
    int freqRepaint = 30;
    int scale = 1;
    int iter_num = 0;

    Ui::MainWindow *ui;
    QImage *image;
    QRgb* pixels;
    QPixmapDrawer *scene;
    LangtonAntHexa *ant;
    vector<QRgb> colors;

    LangtonAntWorker *worker;

    void setRandomImage();
};

#endif // MAINWINDOW_H
