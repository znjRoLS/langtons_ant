#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "qpixmapdrawer.h"
#include <QPainter>
#include "langtonant.h"

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
    int freq = 1;
    int freqRepaint = 100;
    int scale = 5;
    int iter_num = 0;

    Ui::MainWindow *ui;
    QImage *image;
    QPixmap *pixmap;
    QPainter *painter;
    QPixmapDrawer *scene;
    LangtonAnt *ant;
    vector<QRgb> colors;

    void setRandomImage();
};

#endif // MAINWINDOW_H
