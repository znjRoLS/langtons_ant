#include "qpixmapdrawer.h"
#include <QDebug>

#include <QPainter>
QPixmapDrawer::QPixmapDrawer(QWidget *parent) : QLabel (parent)
{

}

void QPixmapDrawer::paintEvent(QPaintEvent *) {
    qDebug() << "Iter paint " << iter_num ++;
    QPainter painter(this);
    painter.drawPixmap(0, 0, *_pixmap);
}
