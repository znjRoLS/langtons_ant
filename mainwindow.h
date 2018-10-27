#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "qpixmapdrawer.h"
#include <QPainter>
#include "langtonant.h"
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
    int sizeX = 2000;
    int sizeY = 2000;
    // microseconds
    int freq = 1000;
    // miliseconds
    int freqRepaint = 10;
    int scale = 5;
    int iter_num = 0;

    Ui::MainWindow *ui;
    QImage *image;
    QPixmap *pixmap;
    QPixmapDrawer *scene;
    LangtonAnt *ant;
    vector<QRgb> colors;

    LangtonAntWorker *worker;

    void setRandomImage();
};

#endif // MAINWINDOW_H
