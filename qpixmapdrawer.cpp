#include "qpixmapdrawer.h"
#include <QDebug>

#include <QPainter>
QPixmapDrawer::QPixmapDrawer(QWidget *parent) : QLabel (parent)
{

}

void QPixmapDrawer::paintEvent(QPaintEvent *) {
    if (iter_num++ % 100 == 0) {
        qDebug() << "Iter paint " << iter_num;
    }
    QPainter painter(this);
    painter.drawPixmap(0, 0, *_pixmap);
}
